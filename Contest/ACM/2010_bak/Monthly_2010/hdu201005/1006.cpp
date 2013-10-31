#include <stdio.h>
#include <algorithm>
#define N 110000
#define MAX (1<<20)
#define pi 3.1415926
double a[N];
int n;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		double sum ;
		scanf("%d%lf",&n,&sum);
		sum = sum*2*pi;
		for(int i = 0; i < n ;i ++)
		{
			scanf("%lf",&a[i]);
		}
		double avr = sum/n;
		std::sort(a,a+n);
		double min = 0.000000;
		for(int i = 0; i <n ;i ++)
		{
			if(i > 0 && a[i]-a[i-1] > min)
			{
				min = a[i]-a[i-1];
			}
		}
		if( n == 1 || min < 0.000000001)
		{
			printf("Inf\n");
		}
		else
		{
			printf("%.3lf\n",avr/min);
		}
	}	
	return 0;
}
