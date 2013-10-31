#include <stdio.h>
#define N 901000000


int main()
{
//	double sum = 0;
	freopen("1007.in","r",stdin);
	freopen("1007.out","w",stdout);
	for(int k=5;k<=100;k++)
	{
		double lim = 100.0/k;
		double sum =0;
		for(int i=1;i<N;i++)
		{
			sum = sum+1.0/i;
			if(sum>=lim)
			{
				printf("%d,",i);
				break;
			}
		}
	}
//	printf("%lf\n",sum);
//	printf("bac\n");
	return 0;
}
