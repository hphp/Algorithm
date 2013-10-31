#include <stdio.h>
#define N 1100
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAX (1<<28)

int need[N];
int cake[N];
int m;
int mx[N*23];

int main()
{
	int tc;
	scanf("%d",&tc);
	int n,a;
	while(tc--)
	{
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&n);
			need[i]=0;
			for(int j=0;j<n;j++)
			{
				scanf("%d",&a);
				need[i] +=a;
			}
		}
		cake[0] = 0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&a);
			cake[i] = cake[i-1]+a;
		}
		for(int i=0;i<=cake[m];i++)
			mx[i] = -MAX;
		mx[0] = 0;
		for(int i=1;i<=m;i++)
		{
			for(int j=cake[i];j>=need[i];j--)
			{
				mx[j] = Max(mx[j-need[i]]+1,mx[j]);
			}
		}
		int mxmx = 0;	
		for(int i=0;i<=cake[m];i++)
			mxmx = Max(mx[i],mxmx);
		printf("%d\n",mxmx);
	}
	return 0;
}
