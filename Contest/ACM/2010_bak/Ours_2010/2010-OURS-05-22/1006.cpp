#include <stdio.h>
#define E 0.01

int n,m;
double p,R,S;

double getPrice()
{
	return (n*1.0*p+S*m*1.0)/(2.0*m);
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%lf%d%lf%lf",&n,&p,&m,&R,&S);
		double price = getPrice() + p-E;
		printf("price = %.2lf\n",price);
		int au = n - (int)(price/p)*m;
		printf("audiences = %d\n",au);
		double sum = au*(price-S) - R;
		printf("revenue %.2lf\n",sum);
		if(test!=1)printf("\n");
	}
	return 0;
}
