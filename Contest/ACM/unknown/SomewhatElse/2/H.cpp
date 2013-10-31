#include <stdio.h>
#define N 1010
#define M 4010

int vst[N][2];
int avl[N][2];

struct Vote
{
	int bill;
	bool va;
}v[M][2];

struct Node
{
	int manid;
	Node * next;
}vote[N][2],edge[M*10];
int tt;

int n , m;
void edge_init()
{
	tt = 0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<2;j++)
			vote[i][j].next = NULL;
}

void add_edge(int bill,int man,bool ans)
{
	edge[tt].manid = man;
	edge[tt].next = vote[bill][ans].next;
	vote[bill][ans].next = &edge[tt];
	tt++;
}

bool fflag = 0;

void dfs(int bill , int va)
{
	if(avl[bill][va] >= 0)
	{
		if(avl[bill][va] == 0)
			fflag = 1;
		return;
	}
	if(fflag)return;
	vst[bill][va] = 1;
//	printf("hello %d %d\n",bill,va);
	for(Node * tmp = vote[bill][!va].next ; tmp != NULL ; tmp = tmp->next)
	{
		int mid = tmp->manid;
		int ab = bill , ava =  !va;
		for(int j=0;j<2;j++)
			if(v[mid][j].bill!=bill)
			{
				ab = v[mid][j].bill;
				ava = v[mid][j].va;
			}
//		printf("%d %d\n",ab, ava);
		if(!vst[ab][ava])
		{
//			printf("%d 888 %d\n",!ava,vst[ab][!ava]);
			if(vst[ab][!ava])
			{
				fflag = 1;
				return;
			}
			else
			{
				dfs(ab,ava);
			}
		}
		if(fflag)return;
	}
	vst[bill][va] = 2;
}

char stdd[4] = "NY?";
int rans[N],ans;

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		edge_init();
		ans = 0;
		for(int i =0 ; i < m ; i ++)
		{
			for(int j=0;j<2;j++)
			{
				int a;
				char s[10];
				scanf("%d%s",&a,s);
				v[i][j].bill = a;
				if(s[0] == 'Y')
				{
					v[i][j].va = 1;
				}
				else v[i][j].va = 0;
				add_edge(a,i,v[i][j].va);
			}
			if(v[i][0].bill == v[i][1].bill)
				if(v[i][0].va != v[i][1].va)
					ans = -1;
		}
		if(ans == -1)
		{
			;
		}
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=0;j<2;j++)
					avl[i][j] = -1;
			ans = 0;
			for(int i=1;i<=n;i++)
			{
				for(int ss = 0 ; ss < 2 ; ss ++)
				{
					if(avl[i][ss] == -1)
					{
	/*					if(vote[i][ss].next == NULL)
							avl[i][ss] = 1;
						else
	*/
						{
							fflag = 0;
							for(int j=0;j<=n;j++)
								vst[j][0] = vst[j][1] = 0;
							dfs(i,ss);
							for(int j=0;j<=n;j++)
								for(int k = 0 ; k < 2; k ++)
								{
									if(vst[j][k] == 2)
									{
										avl[j][k] = 1;
									}
									if(vst[j][k] == 1)
									{
										avl[j][k] = 0;
									}
								}
						}
					}
				}
				if(!(avl[i][0]||avl[i][1]))
				{
					ans = -1;
				}
				else if(((avl[i][0]&&avl[i][1])))
					rans[i] = 2;
				else if(avl[i][0])
					rans[i] = 0;
				else rans[i] = 1;
			}
		}
		if(ans >= 0)
		{
			for(int i=1;i<=n;i++)
				printf("%c",stdd[rans[i]]);
				printf("\n");
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

/*
14:04

5 4
1 Y 2 N
1 N 2 N
1 Y 3 Y
1 Y 2 Y

5 4
1 Y 2 N
1 N 2 N
1 Y 3 Y
5 Y 5 N

5 4
1 Y 2 N
1 N 2 N
1 Y 3 Y
1 Y 2 Y

5 6
1 Y 2 N
1 N 2 N
1 Y 3 Y
5 Y 5 Y
1 N 4 N 
1 N 3 N 


5 8
1 Y 2 N
1 N 2 N
1 Y 3 Y
5 Y 5 Y
1 N 4 N 
1 N 3 N 
1 N 3 Y
1 Y 3 N

1 2
 1 Y 1 Y
 1 Y 1 Y
1 2
1 N 1 N 
1 Y 1 Y 

1 2
 1 Y 1 Y
 1 Y 1 Y
1 2
1 N 1 N 
1 Y 1 N 

7 6 
1 Y 4 N
1 N 4 N
3 Y 4 N
1 N 5 Y
1 N 5 Y
3 N 5 N

7 7 
1 Y 4 N
1 N 4 N
3 Y 4 N
1 N 5 Y
1 N 5 Y
5 N 6 Y
5 Y 6 N


7 8 
1 Y 4 N
1 N 4 N
3 Y 4 N
1 N 5 Y
1 N 5 Y
5 N 6 Y
5 Y 6 N
5 Y 6 Y
*/
