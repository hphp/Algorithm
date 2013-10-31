#include <stdio.h>
#define N 201000
#define Max(a,b) ((a)>(b)?(a):(b))

int mx[N];
int n,v[N];
int cur[N];
int m;

int main()
{
	int a;
	while(scanf("%d%d",&n,&m)!=EOF)	
	{
		for(int i=1;i<=n;i++)
		{
			cur[0] = 0;
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&a);
				if(j == 1)cur[j] = Max(a,0);
				else
				cur[j] = Max(cur[j-1],cur[j-2]+a);
			}
			v[i] = cur[m];
		}
		mx[1] = Max(v[1],0);
		for(int i=2;i<=n;i++)
		{
			mx[i] = Max(mx[i-1],mx[i-2] + v[i]);
		}
		printf("%d\n",mx[n]);
	}
	return 0;
}