#include <stdio.h>
#define N 2010
#define MAX 1<<29

int min[N];
bool grid[N][N];
struct Road
{
	int start;
	int end;
	int d;
}road[N];
int n,m,a;

void init(void)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			grid[i][j]=0;
}

void dp(void)
{
	min[1]=road[1].d;
	for(int i=2;i<=n;i++)
	{
		min[i]=MAX;
		for(int j=1;j<i;j++)
		{
			if(grid[i][j])
			{
				if(min[j]+road[i].d<min[i])
					min[i]=min[j]+road[i].d;
			}
		}
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&road[i].start,&road[i].end,&road[i].d);
			for(int j=1;j<i;j++)
			{
				if(road[j].end>=road[i].start)
					grid[i][j]=1;
			}
		}
		dp();
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);
			if(min[a]<MAX)
			printf("%d\n",min[a]);
			else printf("-1\n");
		}
	}
	return 0;
}
