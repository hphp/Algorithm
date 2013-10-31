#include <stdio.h>
#define N 219
#define M 210
#define K 21

__int64 posb[N][M][K][2];
int n,m,k;
__int64 ans;

void dp_init(void)
{
	posb[0][0][1][1]=1;
	posb[0][1][1][0]=1;
}

void dp(void)
{
	dp_init();
	for(int i=1;i<n;i++)
		for(int j=0;j<=m;j++)
		{
			if(j>i)break;
			for(int kk=0;kk<=k;kk++)
			{
				if(kk>i)
					break;
				posb[i][j][kk][0]=posb[i][j][kk][1]=0;
				if(j)
				posb[i][j][kk][0]=posb[i-1][j-1][kk][0];
				if(j&&kk)
				posb[i][j][kk][0]+=posb[i-1][j-1][kk-1][1];
				posb[i][j][kk][1]=posb[i-1][j][kk][1];
				if(kk)posb[i][j][kk][1]+=posb[i-1][j][kk-1][0];		
			}
		}
	ans=posb[n-1][m][k][0]+posb[n-1][m][k][1];
}

int main()
{
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		dp();
		printf("%I64d\n",ans);
	}
	return 0;
}
