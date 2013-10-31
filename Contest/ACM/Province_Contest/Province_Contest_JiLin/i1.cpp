#include <stdio.h>
#define N 100100
#define MAXX 1000000000

int MAX(int a,int b)
{
	return a>b?a:b;
}

int max[N][4],a[N],n;
int maxmax;

void dp(void)
{
	maxmax=0;
	max[0][0]=0;
	max[0][1]=-MAXX;
	max[0][2]=-MAXX;
	max[0][3]=-MAXX;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])
		{
			max[i][0]=1;
			max[i][1]=MAX(max[i-1][1]+1,max[i-1][0]+1);
			max[i][2]=-MAXX;
			max[i][3]=MAX(max[i-1][3]+1,max[i-1][2]+1);
		}
		else
		{
			max[i][0]=max[i-1][0]+1;
			max[i][1]=-MAXX;
			max[i][2]=MAX(max[i-1][1]+1,max[i-1][2]+1);
			max[i][3]=-MAXX;
		}
		if(max[i][3]>maxmax)
			maxmax=max[i][3];
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		dp();
		printf("%d\n",maxmax);
	}
	return 0;
}
/*
18
2 3 2 1 2 3 2 1 2 3 2 1 0  -1 1 2 3 4 
10
1 2 3 4 5 6 7 8 9 10

*/
