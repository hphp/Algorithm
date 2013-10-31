#include <stdio.h>
#define N 110
#define L 1101
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define MAX (1<<28)

int mx[N][L];
int n,m,l;

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d%d",&n,&m,&l);
		int a,b;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=l;j++)
				mx[i][j] = -MAX;
			mx[0][0] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			for(int k=Min(i,m);k>0;k--)
			{
				for(int j=l;j>=a;j--)
				{
					mx[k][j] = Max(mx[k][j],mx[k-1][j-a]+b);
				}
			}
		}	
		int mxmx = 0;
		for(int k=0;k<=l;k++)
			mxmx = Max(mxmx,mx[m][k]);
		printf("%d\n",mxmx);
	}
}
