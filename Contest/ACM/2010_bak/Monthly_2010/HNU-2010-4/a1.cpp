#include <stdio.h>
#define N 20100
#define K 110
#define MAX (1<<30)
#define Min(a,b) ((a)<(b)?(a):(b))

int mn[N][K];
int n;
int v[N],sum[N];
int k,L;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&k,&L);
		sum[0] = 0;
		for(int i =1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			sum[i] = sum[i-1]+v[i];
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=k;j++)
				mn[i][j] = MAX;
		mn[0][0] = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
			{
				int tmp = MAX;
				if(i-L>=0)
					if(mn[i-L][j-1]<MAX)
						tmp = mn[i-L][j-1]+(sum[i]-sum[i-L])*j;
				int tmp1 = MAX;
				if(mn[i-1][j] < MAX)
					tmp1 = mn[i-1][j]+v[i]*j;
				mn[i][j] = Min(tmp,tmp1);
			}
		int ans = MAX;
		for(int i=1;i<=k;i++)
			if(ans > mn[n][i])
				ans = mn[n][i];
		printf("%d\n",ans);
	}
	return 0;
}                                 
