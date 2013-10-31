#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1005;
vector<int>edge[maxn];
struct
{
	int e,fa,step;
}q[1005];
int used[maxn];
int p[maxn][maxn];
int dp[maxn][maxn];
int DP(int i,int j)
{
	if(dp[i][j]!=-1) return dp[i][j];
	int tmp=0;
	for(int k=0;k<edge[j].size();k++)
	{
		DP(p[p[i][j]][j],edge[j][k]);
		if(tmp<dp[p[p[i][j]][j]][edge[j][k]]+1)
			tmp=dp[p[p[i][j]][j]][edge[j][k]]+1;
			
	}
	if(tmp<dp[p[p[i][j]][j]][j]+1)
	{
		tmp=dp[p[p[i][j]][j]][j]+1;
	}
	dp[i][j]=tmp;
	return dp[i][j];
}
void bfs(int s)
{
	int from,to;
	int step;
	int f=0,r=0;
	q[f].e=s;
	q[f].fa=-1;
	q[f].step=0;
	used[s]=1;
	while(f<=r)
	{
		from=q[f].e;
		step=q[f].step;
		for(int i=0;i<edge[from].size();i++)
		{
			to=edge[from][i];
			if(!used[to])
			{
				used[to]=1;
				r++;
				q[r].e=to;
				q[r].fa=q[f].fa;
				if(q[r].fa==-1)
					q[r].fa=to;
				q[r].step=step+1;
				if(step<=1)
				{
					dp[s][to]=1;
				}
				p[s][to]=q[r].fa;
			}
		}
		f++;
	}
}
int main()
{
	int s,t,a,b;
	int n,m,i,j;
//	freopen("The police caught the thief12.in","r",stdin);
//	freopen("The police caught the thief12.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=-1)
	{
		scanf("%d%d",&s,&t);
		for(i=1;i<=n;i++)
		{
			edge[i].clear();
			dp[i][i]=0;
			for(j=i+1;j<=n;j++)
				dp[j][i]=dp[i][j]=-1;
		}
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		for(i=1;i<=n;i++)
			sort(edge[i].begin(),edge[i].end());
		for(i=1;i<=n;i++)
		{
			memset(used,0,sizeof(used));
			bfs(i);
		}
		int ans=DP(s,t);
		printf("%d\n",ans);
		
	}
	return 0;
}
