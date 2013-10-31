//09-11-01---
#include <stdio.h>
#define CON 2009
#define Max(a,b) ((a)>(b)?(a):(b))

typedef int Int;
Int pow(int a,int p)
{
	if(p==0)return 1;
	Int tmp = pow(a,p/2);
	if(p%2==0)
		return (tmp*tmp)%CON;
	else return ((tmp*tmp)%CON*a)%CON;
}

int main()
{
	int a;
	while(scanf("%d",&a)!=EOF)
	{
	/*	if(a<=3)
		{
			ans = a;	
		}
		else
		{
		if(a%3==0)
			ans = pow(3,a/3);
		else if(a%3==1)
			ans = pow(2,2)*pow(3,(a-4)/3)%CON;
		else if(a%3==2)
			ans = pow(2,1)*pow(3,(a-2)/3)%CON;
		}
		printf("%d\n",ans);*/
		int mxmx = a%CON;
		int ans;
		if(a<3)
			ans = a;
		else
		{
		for(int i=0;i<3;i++)
		{
			if(a-i*2<0)break;
			int t = (a-i*2)%3;
//			printf("2:%d 3:%d\n",i,(a-i*2)/3);
			if(t==0)
				ans = (pow(2,i)*pow(3,(a-i*2)/3))%CON;
//			printf("%d\n",pow(3,(a-i*2)/3));
//			printf("%d\n",ans);
		}
		}
		if(ans<mxmx)
			while(1);
		printf("%d\n",mxmx);
	}
	return 0;
}
