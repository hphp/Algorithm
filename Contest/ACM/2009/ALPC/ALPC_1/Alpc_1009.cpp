#include <stdio.h>
#define N 219
#define M 218
#define K 25

__int64 posb[N][M][K][2];
int n,m,k;
__int64 ans[N][M][K];

void dp_init(void)
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			for(int kk=0;kk<K;kk++)
			{
				posb[i][j][kk][0]=posb[i][j][kk][1]=0;
				ans[i][j][kk]=0;
			}
	posb[1][0][1][1]=1;
	posb[1][1][1][0]=1;
	ans[1][0][1]=1;
	ans[1][1][1]=1;
//	ans[1][1][1]=1;
//	ans[1][0][1]=1;
}

void dp(void)
{
	dp_init();
	for(int i=2;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			if(j>i+1)break;
			for(int kk=0;kk<=k;kk++)
			{
				if(kk>i+1)
					break;
				posb[i][j][kk][0]=posb[i][j][kk][1]=0;
				if(j)
				posb[i][j][kk][0]=posb[i-1][j-1][kk][0];
				if(j&&kk)
				posb[i][j][kk][0]+=posb[i-1][j-1][kk-1][1];
				posb[i][j][kk][1]=posb[i-1][j][kk][1];
				if(kk)posb[i][j][kk][1]+=posb[i-1][j][kk-1][0];		
				ans[i][j][kk]=posb[i][j][kk][0]+posb[i][j][kk][1];
			}
		}
//	ans=posb[n-1][m][k][0]+posb[n-1][m][k][1];
}

int main()
{
	n=N-1;
	m=M-1;
	k=K-1;
	dp();
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		printf("%I64d\n",ans[n][m][k]);
	}
	return 0;
}
