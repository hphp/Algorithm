//09-10-31-17:39---
#include <stdio.h>
#define N 3000001
typedef long long Int;
int a,b,c;
Int sum[N];

void priming()
{
	int half = N/2;
	for(int i=2;i<=half;i++)
	{
		if(sum[i]%2==0)
		{
			for(int j=2;i*j<N;j++)
			{
				sum[i*j] = 1+i*10;
			}	
		}
	}
}

int main()
{
	priming();
	for(int i=2;i<N;i++)
	{
		if(sum[i]%2==0)
			sum[i]=i-1;
		else
		{
		int tmp = sum[i]/10;
		if((i/tmp)%tmp==0)
		{
			sum[i] = sum[i/tmp]*tmp;
		}
		else sum[i] = sum[i/tmp]*(tmp-1);
		}
	}
	for(int i=2;i<N;i++)
		sum[i] += sum[i-1];
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		printf("%lld\n",sum[b]-sum[a-1]);
	}
	return 0;
}
