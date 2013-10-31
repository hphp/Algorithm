#include <stdio.h>
#include <math.h>
#define LIM 10000
#define CON 1.55741
double abss(double a)
{
	if(a>0)
		a=-a;
		return a;
}
double L1,L2,v1,v2;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lf%lf%lf%lf",&L1,&L2,&v1,&v2);
	/*	L1*=100;
		L2*=100;
		v1*=100;
		v2*=100;*/
		double dif=L1;
		double ans;
		if(L1>10)
		{
			int ii;
			for(ii=1;ii<LIM*100;ii++)		
			{
				double i=ii*1.0/LIM;
				dif -= (1.0/LIM)*(v1/(tan(sin(i)*sin(i)))+v1/(tan(cos(i)*cos(i))));
		//		printf("%lf\n",dif);
				if(dif<=10)
					break;
			}
			ans=0;
			//printf("hei%d\n",ii);
			if(ii<LIM)
			{
				ans = L2;	
			}
			else
			{
				for(int j=1;j<=ii;j++)
				{
					double jj=j*1.0/LIM;
					ans += (1.0/LIM)*(v2*(CON/(tan(sin(jj)*sin(jj))*tan(cos(jj)*cos(jj)))-CON));
				}
			}
		}
		else ans = L2;
		printf("%lf\n",ans);
	}
	return 0;
}
