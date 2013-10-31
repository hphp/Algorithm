#include <stdio.h>
long long s(long long int i)
{
	int sum = 0;
	while(i)
	{
		int t = (i%10);
		sum += (i%10);
		i/=10;	
	}
	return sum;
}
long long ss(long long int i)
{
	int sum = 0;
	while(i)
	{
		int t = (i%10);
		if(t > 3)return 0;
		sum += (i%10);
		i/=10;	
	}
	return sum;
}

int main()
{
		int sum = 0 ;
	for(long long i=1;i<1000000000;i++)
	{
		{
			long long int t = ss(i);
		if( t != 0 && (s(i*i) == t*t))
		{
			printf("%lld,",i);
			sum ++;
		}
		}
	}
	printf("\n%d\n",sum);
	return 0;
}
