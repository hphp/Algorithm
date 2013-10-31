#include <stdio.h>
#define N 200010
#define M 200010
int max[N],every[N];
int grid[M];
int n,m;

int MAX(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int a,maxmax;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=2;i<=n+1;i++)
		{
			every[i]=0;
			for(int j=2;j<=m+1;j++)
			{
				scanf("%d",&a);
				grid[j]=MAX(grid[j-1],grid[j-2]+a);
				if(every[i]<grid[j])
					every[i]=grid[j];
			}
		}
		maxmax=0;
		for(int i=2;i<=n+1;i++)
		{
			max[i]=MAX(max[i-1],max[i-2]+every[i]);
			if(max[i]>maxmax)
				maxmax=max[i];
		}
		printf("%d\n",maxmax);
	}
	return 0;
}

