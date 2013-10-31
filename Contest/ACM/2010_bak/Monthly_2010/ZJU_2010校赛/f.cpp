#include <stdio.h>
#define N 40
#define Min(a,b) ((a)<(b)?(a):(b))
#define MAX (1<<28)

int grid[N][N][N],edge[N];
int mn[N],f[N];
int path[N][N*N][N];
int n,m;
int s,t;
int rec[N];
int cc[N];
int rr[N];
int mnn[N][N];
int plen[N][N*N];

void spa(int id,int st)
{
	for(int i=0;i<=n;i++)
	{
		mn[i] = MAX;
		f[i]=0;
	}
	mn[st] = 0;
	int cur = st;
	int min = cur;
	while(cur!=0)
	{
		f[cur] = 1;
		min = cur;
		cur = 0;
		for(int j=1;j<=n;j++)
		{
			if(f[j]==0)
			{
				if(grid[id][min][j]&&mn[min]+1<mn[j])
					mn[j] = mn[min]+1;
				if(mn[j]<mn[cur])
					cur = j;
			}
		}
	}
}

void dfs(int id,int cur,int cnt)
{
	rec[cnt] = cur;
	if(cnt == mn[t]&&cur==t)
	{
		for(int j=0;j<=cnt;j++)
		path[id][cc[id]][j] = rec[j];
		plen[id][cc[id]] = cnt;
		cc[id]++;
		return;
	}
	else if(cnt==mn[t]+1)
	{
		if(cur == t)
		{
			for(int j=0;j<=cnt;j++)
			path[id][cc[id]][j] = rec[j];
			plen[id][cc[id]] = cnt;
			cc[id]++;
		}
		return;
	}
	f[cur] = 1;
	for(int j=1;j<=n;j++)
		if(f[j]==0&&grid[id][cur][j])
		{
			dfs(id,j,cnt+1);
		}
	f[cur]=0;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d %d",&n,&m,&s,&t);
		int a,b;
		int sum = 0;
		for(int i=0;i<=m;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=n;k++)
				{
					grid[i][j][k] = 0;
				}
		for(int i=1;i<=m;i++)
		{
			cc[i] = 0;	
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&edge[i]);
			for(int j=0;j<edge[i];j++)
			{
				scanf("%d %d",&a,&b);
				grid[i][a][b] = 1;
				grid[i][b][a] = 1;
			}
			spa(i,s);
			for(int j=1;j<=n;j++)
				f[j] = 0;
			dfs(i,s,0);
			rr[i] = mn[t];
		}
		for(int i=0;i<=m;i++)
			for(int j=0;j<cc[i];j++)
				mnn[i][j] = MAX;
		for(int k=0;k<cc[1];k++)
			mnn[1][k] = plen[1][k];
		for(int i=2;i<=m;i++)
		{
			for(int k=0;k<cc[i];k++)
			{
				for(int kk=0;kk<cc[i-1];kk++)
				{
					int add =0;
					if(plen[i][k] == plen[i-1][kk])
					{
						for(int j=0;j<=plen[i][k];j++)
						{
							if(path[i][k][j]!=path[i-1][kk][j])
							{
								add = 1;
								break;
							}
						}
					}
					else add = 1;
					mnn[i][k] = Min(mnn[i-1][kk]+add+plen[i][k],mnn[i][k]);
				}
			}
		}
		int ans = MAX;
		for(int i=0;i<cc[m];i++)
			ans = Min(mnn[m][i],ans);
		printf("%d\n",ans);
	}
	return 0;
}
