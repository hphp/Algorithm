#include <stdio.h>
#define E 0.01
#define avl(e) ((e)>=0&&((e)<=mxe)?1:0)

int n,m;
double p,R,S;
int mxe;

double getPrice()
{
	return (n*1.0*p+S*m*1.0)/(2.0*m);
}

int getBei()
{
	return (int)((n*p+0.01*m+S*m-0.01*m)/(2*m*p));
//	return 	(int)((n*p-0.01*p+m*S)/(2*(m*p)));
}

int mv[12]= {-5,-4,-3,-2,-1,0,1,2,3,4};

double Rev(double prc , int rm)
{
	if(rm < 0)
		rm = 0;
	return (prc-S)*rm - R;
}

int div(int a,int b)
{
	return a/b+((a%b==0)?0:1);	
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%lf%d%lf%lf",&n,&p,&m,&R,&S);
		mxe = div(n,m);
		int bei = getBei() ;
//		printf("%d\n",bei);
		double ans = -R;
		double price = mxe*p+p-E;
		int au = 0;
		for(int i=0;i<10;i++)
		{
			int b= bei+mv[i];
			if(avl(b))
			{
				double tmp = Rev(p*b +p - E,n-m*b);
				if(tmp > ans)
				{
					ans = tmp;
					price = p*b+p - E;
					au = (n - m*b < 0)?0:n-m*b;
				}
			}
		}
		printf("price = %.2lf\n",price);
		printf("audiences = %d\n",au);
		printf("revenue = %.2lf\n",ans);
		if(test!=0)printf("\n");
	}
	return 0;
}

/*
File #1
John needs 1 floppies.

File #2
John needs 5 floppies.
File #3
John needs 41 floppies.
price = 6.09

audiences = 400

revenue = 636.00
price = 13.99
5 0.01 1 1 1000
*/
