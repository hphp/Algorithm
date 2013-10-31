#include <stdio.h>
#define N 1010000
typedef int Int;
Int sum[N];
Int r[N];
int main()
{
	r[1] = 1;
	sum[1] = 1;
	for(int i=2;i<=N;i++)
	{
		r[i] = sum[i/2] + 1;
		sum[i] = sum[i-1] + r[i];
	}
	int a;
	int tc;
	scanf("%d",&tc);
	int tt = 0;
	while(tc--)
	{
		scanf("%d",&a);
		tt ++;
		printf("%d %d\n",tt,r[a]);
	}
}
