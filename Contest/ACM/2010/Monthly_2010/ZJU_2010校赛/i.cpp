#include <stdio.h>
#define N 11
#define STM (1<<N)

int n,rec[N],ans;
int grid[N][N];
int flag[N];
int m;

void dfs(int cur,int cnt)
{
	if(cnt == n)
	{
		if(grid[rec[1]][cur])
		{
			ans =1;
		}
		return;
	}
	rec[cnt] = cur;
	flag[cur] = 1;
	for(int i=1;i<=n;i++)
		if(flag[i]==0&&grid[cur][i])
		{
			dfs(i,cnt+1);
			if(ans==1)return;
		}
}

int main()
{
	int in[N];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0;i<=n;i++)
		{
			flag[i] = 0;
			for(int j=0;j<=n;j++)
				grid[i][j] = 0;
			in[i] = 0;
		}
		int a,b;
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&a,&b);
			in[a]++;
			in[b]++;
			grid[a][b] = 1;
			grid[b][a] = 1;
		}
		if(n!=m)
		{
			printf("NO\n");
			continue;
		}
		int i=1;
		for(;i<=n;i++)
			if(in[i]!=2)
			{
				break;
			}
		if(i!=n+1)
		{
			printf("NO\n");
			continue;
		}
		int flagg = 0;
		ans = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				flag[j] = 0;
			dfs(i,1);
			if(ans == 1)
			{
				flagg = 1;break;
			}
		}
		if(flagg)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
