#include <stdio.h>
#define N 310
#define E N*N
#define MAX (1<<27)
#define Max(a,b) ((a)>(b)?(a):(b))

struct Node
{
	int id;
	int v;
	Node * next;
}node[N],edge[E],nlt[2][N],elt[2][E];
int tt;
int pre[2][N],pos[2][N],cnt[2];
int mx[N][N];
int s[2],e[2];
int n,m;


void add_edge(Node * node,Node * edge,int a,int b,int c)
{
	edge[tt].id = b;
	edge[tt].v = c;
	edge[tt].next = node[a].next;
	node[a].next = & edge[tt];
	tt ++;	
}

void spa(int flag)
{
	int st = s[flag];
	int mdis[N];
	int sign[N];
	for(int i=0;i<=n;i++)
	{
		mdis[i] = MAX;
		sign[i] = -1;
	}
	int min = st;
	mdis[st] = 0;
	int cur = st;
	cnt[flag] = 1;
	while(cur > 0)
	{
		sign[cur] = 1;
		pre[flag][cnt[flag]] = cur;
		pos[flag][cur] = cnt[flag];
		cnt[flag] ++;
		min = cur;
		cur = 0;
		if(e[flag] == min)break;
		for(Node * tmp = node[min].next ; tmp != NULL ; tmp = tmp->next)
		{
			int id = tmp->id;
			if(sign[id] != -1)continue;
			int v = tmp->v;
			if(mdis[id] > mdis[min] + v)
			{
				mdis[id] = mdis[min]+v;	
			}
		}
		for(int i=1;i<=n;i++)
			if(sign[i] == -1)
			{
				if(mdis[i] < mdis[cur])
					cur = i;
			}
	}
	for(int i=1;i<=n;i++)
	{
		for(Node * tmp = node[i].next ; tmp != NULL; tmp = tmp->next)
		{
			int id = tmp -> id;
			if(pos[flag][id] < pos[flag][i] && (mdis[id] + tmp->v == mdis[i]))
			{
				add_edge(nlt[flag],elt[flag],i,id,tmp->v);
			}
		}
	}
/*	for(int i=0;i<cnt[flag];i++)
	{
		printf("hello %d\n",pre[flag][i]);
		int cur = pre[flag][i];
		for(Node * tmp = nlt[flag][cur].next ; tmp != NULL ; tmp = tmp->next)
		{
			int id = tmp -> id;
			printf("%d ",id);
		}
		printf("\n");
	}
	printf("\n");*/
}


void init()
{
	for(int i=0;i<=n;i++)
	{
		node[i].next = NULL;
		nlt[0][i].next = NULL;
		nlt[1][i].next = NULL;
	}
	tt = 0;
}

void dp()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mx[i][j] = -MAX;
	mx[s[0]][s[1]] = 0;
	for(int i=1;i<cnt[0];i ++)
	{
		int ii = pre[0][i];
		for(int j=1;j<cnt[1];j++)
		{
			int add = 0;
			int jj = pre[1][j];
			for(Node * tmp = nlt[0][ii].next ; tmp != NULL ; tmp = tmp->next)
			{
				int id = tmp->id;
				if(mx[ii][jj] < mx[id][jj])
					mx[ii][jj] = mx[id][jj];
			}
			for(Node * tmp = nlt[1][jj].next ; tmp != NULL ; tmp = tmp->next)
			{
				int id = tmp->id;
				if(mx[ii][jj] < mx[ii][id])
					mx[ii][jj] = mx[ii][id];
			}
			int mxmx = 0;
			if(ii == jj)
			{
				add = 1;	
			}
			for(Node * tmp = nlt[0][ii].next ; tmp != NULL ; tmp = tmp->next)
			{
				int id = tmp->id;
				for(Node * tmpp = nlt[1][jj].next ; tmpp != NULL;  tmpp = tmpp->next)
				{
					int idd = tmpp->id;
					if(mx[id][idd] > mxmx)
						mxmx = mx[id][idd];
				}
			}
			if(mxmx > -MAX)
				mx[ii][jj] = Max(mx[ii][jj],add + mxmx);
		}	
	}
}

int main()
{
	int a,b,c;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			add_edge(node,edge,a,b,c);
			add_edge(node,edge,b,a,c);
		}
		for(int i=0;i<2;i++)
			scanf("%d %d",&s[i],&e[i]);
		tt = 0;
		spa(0);
		spa(1);
		dp();
/*		int mxmx = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(mx[i][j] > mxmx)
					mxmx = mx[i][j];*/
		printf("%d\n",mx[e[0]][e[1]]);
/*		while(scanf("%d %d",&a,&b)!=EOF)
		{
			if(!(a||b))break;
			printf("%d\n",mx[a][b]);	
		}*/
	}
	return 0;
}
/*
6 6
1 2 1
2 3 1
3 4 1
4 5 1
1 5 2
4 6 3
1 6 2 4
6 6
1 2 1
2 3 1
3 4 1
4 5 1
1 5 2
4 6 3
2 3 1 4

*/
