#include <stdio.h>
#define N 550
#define Min(a,b)  ((a)<(b)?(a):(b))
#define Max(a,b)  ((a)>(b)?(a):(b))
#define MAX (1<<29)


int grid[N][N],mindis[N][N];
int n;

struct Node
{
	int id;
	Node * next;
}node[N],edge[10*N];
int tt;

void smt(int start)
{
	int wt[N],st[N];
	for(int i=0;i<=n;i++)
	{
		wt[i]=MAX;
		st[i]=-1;
	}
	wt[start]=0;
	int min = start;
	int cur = start;
	while(cur != 0)
	{
		st[cur]=1;
		min = cur;
		cur = 0;
		for(Node * tmp = node[min].next;tmp!=NULL;tmp=tmp->next)
		{
			int i = tmp->id;
			if(st[i]==-1)	
			{
				if(wt[min]+grid[i][min]<wt[i])	
					wt[i]=wt[min]+grid[i][min];
				if(wt[i]<wt[cur])
					cur = i;
			}
		}
	}
	for(int i=1;i<=n;i++)
		mindis[start][i]=wt[i];
}

void init(void)
{
	tt = 0;
	for(int i=0;i<=n;i++)
	{
		node[i].next= NULL;
		for(int j=0;j<=n;j++)
			grid[i][j]=MAX;
		grid[i][i]=0;
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int m;
		scanf("%d%d",&n,&m);
		init();
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			if(grid[a][b]>c)
			{
				grid[a][b]=c;
				grid[b][a]=c;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j= 1;j<=n;j++)	
				if(grid[i][j]<MAX&&(i!=j))
				{
					edge[tt].id = j;
					edge[tt].next = node[i].next;
					node[i].next = &edge[tt];
					tt++;
				}
		}
		for(int i=1;i<=n;i++)
			smt(i);
		int a = 1,b=n;
		int ans = MAX;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				int maxmax = -1;
				for(int k = 1;k<=n;k++)	
				{
					int dis = Min(mindis[i][k],mindis[j][k]);
					if(dis>maxmax)
						maxmax = dis;
				}
				if(maxmax<ans)
				{
					ans = maxmax;
					a = i;
					b=j;
				}
			}
			printf("%d %d\n",a,b);
	}
	return 0;
}
