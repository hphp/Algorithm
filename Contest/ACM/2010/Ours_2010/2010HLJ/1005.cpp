#include <stdio.h>
#define N 210

int grid[N][N];
int mn[N];
int n,m;
int time[N];

int dp(int cur)
{
	if(mn[cur] >= 0)
		return mn[cur];
	int mxmx = 0;
	for(int i=1;i<=n;i++)
	{
		if(grid[i][cur]==1)
		{
			int tt = dp(i);
			if(tt > mxmx)
				mxmx = tt;
		}
	}
	mn[cur] = mxmx + time[cur];
	return mn[cur];
}

int flag;
int pre[N];

void dfs(int cur)
{
	if(pre[cur] == 1)
	{
		flag = 1;return;	
	}
	pre[cur] = 1;
	for(int i=1;i<=n;i++)
	{
		if(grid[cur][i]==1)
		{
			dfs(i);
			if(flag == 1)
			return;
		}	
	}
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&time[i]);
			mn[i] = -1;
			for(int j=0;j<=n;j++)
				grid[i][j] = 0;
		}
		int a,b;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			grid[a][b] = 1;// a should be done before b	
		} 
		
		for(int i=1;i<=n;i++)
			pre[i] = -1;
		flag = 0;
		int cur = 1;
		while(cur != 0)
		{
			for(int i=1;i<=n;i++)
				if(pre[i] == -1)
				{
					dfs(i);
				}	
		}
/*		flag = 0;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				pre[j] = -1;
			dfs(i);
			if (flag == 1)
				break;
		}*/
		if(flag == 1) 
		{
			printf("What a cup!\n");
			continue;
		}
		else
		{
			int mxmx = 0;
			for(int i=1;i<=n;i++)
			{
				int tmp = dp(i);
				if(tmp > mxmx)
					mxmx = tmp;
			}
			printf("%d\n",mxmx);
		}
	}
	return 0;
}
