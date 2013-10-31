#include <stdio.h>
#define N 110
#define K 210

int knd[N][K][2];
int n,k;
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a;
		scanf("%d",&a);
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				for(int x=0;x<2;x++)
					knd[i][j][x] = 0;
		knd[1][0][0] = 1;
		knd[1][0][1] = 1;
		for(int i=2;i<=n;i++)
			for(int j=0;j<=k;j++)
			{
				knd[i][j][0] += knd[i-1][j][1];
				knd[i][j][0] += knd[i-1][j][0];
				knd[i][j][1] += knd[i-1][j-1][1];
				knd[i][j][1] += knd[i-1][j][0];
			}
		printf("%d %d\n",a,knd[n][k][0] + knd[n][k][1]);
	}
}
