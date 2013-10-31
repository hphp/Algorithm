#include <stdio.h>
#define N 1100
#define M 11000
#define T 16
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAX (1<<29)
typedef long long LL;

int team[N],sump[T],sumv[T];
LL mx[M],rec[M];
int mem[T][N];
int p[N],v[N];
int n,m;

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&v[j]);
		for(int i=1;i<=n;i++)
			team[i] = -1;
		int t;
		scanf("%d",&t);
		for(int i=0;i<t;i++)
		{
			scanf("%d",&mem[i][0]);
			sump[i] = sumv[i] = 0;
			int j = 1;
			for(j=1;j<=mem[i][0];j++)
			{
				scanf("%d",&mem[i][j]);
				int id = mem[i][j];
				sump[i]+=p[id];
				sumv[i]+=v[id];
				team[id] = i;
			}
			scanf("%d",&mem[i][j]);
			sumv[i]+=mem[i][j];
		}
		for(int i=0;i<=m;i++)
			rec[i] = mx[i] = -MAX;
		rec[0] = mx[0] = 0;
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<=m;j++)
				mx[j] = rec[j];
			for(int k= m-sump[i];k>=0;k--)
				if(rec[k]>=0)
				if(rec[k+sump[i]] < rec[k]+sumv[i])
				{
					rec[k+sump[i]] = rec[k] +sumv[i];
				//	printf("%d %d\n",k+sump[i],rec[k+sump[i]]);
				}
			for(int j=1;j<=mem[i][0];j++)
			{
				int cur = mem[i][j];
				for(int k=m-p[cur];k>=0;k--)
				{
					if(mx[k]>=0)
					if(mx[k+p[cur]] < mx[k]+v[cur])	
						mx[k+p[cur]] = mx[k] + v[cur];
				}
			}	
			for(int j=0;j<=m;j++)
			{
				rec[j] = Max(rec[j],mx[j]);
			//	printf("hh %d ",rec[j]);
			}
		}
		for(int i=1;i<=n;i++)
			if(team[i]==-1)
			{
				for(int k=m-p[i];k>=0;k--)
					if(rec[k]>=0)
					if(rec[k+p[i]]<rec[k]+v[i])	
						rec[k+p[i]] = rec[k]+v[i];
			}
		LL ans = 0;
		for(int i=0;i<=m;i++)
			ans = Max(ans,rec[i]);
		printf("%lld\n",ans);
	}
	return 0;
}
