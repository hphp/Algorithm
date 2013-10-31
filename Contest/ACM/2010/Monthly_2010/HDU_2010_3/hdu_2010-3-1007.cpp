#include <stdio.h>
#define N 110
#define C 10100
#define MAX (1<<29)

int mn[C],mdis[N];
int n;
int dis[N][N];
int pow[N];

void SPA()
{
	int rec[N],flag[N];
	for(int i=0;i<=n+1;i++)
	{
		mdis[i] = MAX;
		flag[i] = 0;
		dis[i][n+1] = dis[n+1][i] = MAX;
	}
	mdis[0] = 0 ;
	int cur = 0;
	int min = 0;
	while(cur != n+1)
	{
		flag[cur] = 1;
		min = cur;
		cur = n+1;
		for(int j=1;j<=n;j++)
		{
			if(flag[j] == 0)
			{
				if(mdis[min] + dis[min][j] < mdis[j])
				{
					mdis[j]	= mdis[min] + dis[min][j];
				}	
				if(mdis[j] < mdis[cur])
					cur = j;
			}	
		}
	}
	return;
}

int main()
{
	int test,m,a,b,c;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				dis[i][j] = MAX;
		int spow = 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(dis[a][b]>c)
			{
				dis[a][b] = c;
				dis[b][a] = c;
			}	
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&pow[i]);
			spow += pow[i];
		}
		SPA();
			for(int j=0;j<=spow;j++)
				mn[j] = MAX;
		mn[0] = 0;
		int curm = 0;
		int hpow = spow/2+1;
		int ans = MAX;
/*		for(int i=1;i<=n;i++)
			printf("%d ",mdis[i]);
			printf("%d\n",hpow);
*/
		for(int i=1;i<=n;i++)
		{
			if(mdis[i]>=MAX)continue;
			for(int j=curm;j>=0;j--)
			{
				if(mn[j] == MAX)continue;
				if(mdis[i] + mn[j] < mn[j+pow[i]])
				{
					mn[j+pow[i]] = mdis[i] + mn[j];	
					if(j+pow[i]>=hpow)
						if(mn[j+pow[i]]<ans)
							ans = mn[j+pow[i]];
				}	
			}
			curm += pow[i];
		}
		if(ans < MAX)
			printf("%d\n",ans);
		else printf("impossible\n");
	}
	return 0;
}
