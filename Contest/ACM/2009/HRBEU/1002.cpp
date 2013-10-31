#include <stdio.h>
#define N 30100

struct Node
{
	int sum;
	int under;
	int pre;
	int stop;
	int rank;
}node[N];
int n;

void init(void)
{
	for(int i=0;i<N;i++)
	{
		node[i].pre=i;
		node[i].under=0;
		node[i].sum=1;
		node[i].rank=0;
		node[i].stop=N;
	}	
}

int check(int x)
{
/*	if(sum!=0)
	{
		node[x].pos=sum-1;
	}*/
	if(node[x].pre==x)
		return x;
	return check(node[x].pre);	
}

int get(int a)
{
//	printf("%d %d %d\n",a,node[a].stop,node[a].under);
	if(node[a].pre==a)
		return node[a].under;
	return node[a].under+get(node[a].pre);	
}

int main()
{
	char s[3];
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i=0;i<n;i++)	
		{
			scanf("%s%d",s,&a);	
			if(s[0]=='M')
			{
				scanf("%d",&b);
				int pb=check(b);
				int pa=check(a);
				if(pa!=pb)
				{
						node[pa].pre=pb;
						node[pa].under=node[pb].sum;
						node[pb].sum+=node[pa].sum;
/*					if(node[pa].rank<=node[pb].rank)
					{
						node[pb].pre=pa;
						node[pa].under=node[pb].sum;
						node[pa].sum+=node[pb].sum;
					}
					else
					{
						node[pa].pre=pb;
						node[pa].under=node[pb].sum;
						node[pb].sum+=node[pa].sum;
						if(node[pa].rank==node[pb].rank)
							node[pb].rank++;
					}*/
				}
			}
			else
			{
				int ans=get(a);
				printf("%d\n",ans);		
			}
		}
	}
	return 0;
}

/*
20
M 1 6
M 2 4
M 3 5
M 8 9
M 8 1
C 8
C 9
C 1
M 3 8
C 5
M 2 1
C 4
*/
