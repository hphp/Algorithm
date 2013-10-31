#include <stdio.h>
#include <math.h>
#include <algorithm>
#define pow(a) ((a)*(a))
#define gen2 1.414214
#define E 0.0001

double x[5],y[5];

double DIS(int i,int j)
{
	return sqrt(pow(x[i]-x[j])+pow(y[i]-y[j]));
}

double dian(double x1,double x2,double y1,double y2)
{
	return x1*x2+y1*y2;
}

int near(double a, double b)
{
//	printf("\nhello%lf %lf\n",a,b);
	if(a >= b-E && a <= b+E)
		return 1;
	return 0;
}
int a[19];

int formZ(int a,int b,int c)
{
	double xx0 = x[a]-x[b];
	double xx1 = x[c]-x[b];
	double yy0 = y[a]-y[b];
	double yy1 = y[c]-y[b];
	if(near(dian(xx0,xx1,yy0,yy1),0.0)==1)
		return 1;
		return 0;
}

int pan()
{
	int flag = 0;
int i=1;
		for(;i<3;i++)
		{
			if(near(DIS(a[i-1],a[i]),DIS(a[i],a[i+1])) == 0)
			{
				if(formZ(a[i-1],a[i],a[i+1])==0)return 0;
		//		printf(" %d %d %d %d %lf %lf\n",a[i-1],a[i],a[i],a[i+1],DIS(a[i-1],a[i]),DIS(a[i],a[i+1]));
				return 0;
			}
		}
		if(i == 3)
		{
			if(near(DIS(a[i-1],a[i]),DIS(a[i],a[0])) == 0)
			{
		//		printf(" 2: %d %d %d %d %lf %lf\n",a[i-1],a[i],a[i],a[i+1],DIS(a[i-1],a[i]),DIS(a[i],a[i+1]));
				return 0;
			}
		}
		if(near(DIS(a[0],a[2]),DIS(a[0],a[1])*gen2) == 0)
		{
		//		printf(" 3 : %d %d %d %d %lf %lf\n",a[i-1],a[i],a[i],a[i+1],DIS(a[i-1],a[i]),DIS(a[i],a[i+1]));
			return 0;
		}
		if(near(DIS(a[1],a[3]),DIS(a[0],a[1])*gen2) == 0)
		{
		//		printf("4: %d %d %d %d %lf %lf\n",a[i-1],a[i],a[i],a[i+1],DIS(a[i-1],a[i]),DIS(a[i],a[i+1]));
			return 0;
		}
		return 1;

}


int main()
{
	int test;
	scanf("%d",&test);
	//printf("%lf\n",sqrt(2.0));
	for(int tt = 1 ; tt <= test ;tt ++)
	{
		for(int i=0;i<4;i++)
		{
			scanf("%lf %lf",&x[i],&y[i]);
		}
		a[0] = 0;
		a[1] = 2;a[2] = 1;a[3] = 3;
		int flag = 0;
		if(pan())flag=1;
		a[0] = 0;
		a[1] = 1;a[2] = 2;a[3] = 3;
		if(pan())flag=1;
		a[0] = 0;
		a[1] = 1 ; a[2] = 3;a[3] = 2;
		if(pan())flag=1;
		if(tt != 1)printf("\n");
		if(flag == 1)
			printf("Case %d:\nYes\n",tt);
		if(flag == 0)
			printf("Case %d:\nNo\n",tt);
	}
}

