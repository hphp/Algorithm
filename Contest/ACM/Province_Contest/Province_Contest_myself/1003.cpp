#include <stdio.h>
#define N 110
#define M 110
#define T 110

int max[N][T],n,m,t,b[N][M],maxmax;

void init(void)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			b[i][j]=0;
}

int MAX(int a,int b,int c)
{
	return (a>b?a:b)>c?(a>b?a:b):c;
}

void dp(void)
{
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=t+1;j++)
			max[i][j]=0;
	maxmax=0;
	max[1][0]=b[1][1];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(j<=i+1)
			{
				for(int k=1;k<=t;k++)
				{
					if(k!=0)
					{
						if(k+1>=j) 
							max[j][k]=MAX(max[j-1][k-1],max[j][k],max[j+1][k-1])+b[j][i];
					}
					if(maxmax<max[j][k])
					{
						maxmax=max[j][k];
		//				printf("%d %d %d %d\n",j,k,max[j][k],b[j][i]);
					}
				}
			}
		}
	}
}

int main()
{
	int tt=1,a,bb;
	while(scanf("%d%d%d",&n,&m,&t)!=EOF)
	{
		init();
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&bb);
			b[a][i]=bb;
		}
		dp();
		printf("Scenario #%d\n%d\n\n",tt++,maxmax);
	}
	return 0;
}
