#include <stdio.h>
#define N 3010
typedef __int64 Int;
Int mxearn[N];
int price[N];
int n;
int s,p;

void dp_init(void)
{
	mxearn[0]=p;
}

void dp(void)
{
	dp_init();
	for(int i=1;i<=n;i++)
	{
		mxearn[i]=mxearn[i-1];
		for(int j=1;j<i;j++)
		{
			Int temp;
			if(mxearn[j-1]>=price[j])
				temp = (mxearn[j-1]/price[j])*price[i]+mxearn[j-1]%price[j]-s;
			else temp = 0;
			if(temp>mxearn[i])
				mxearn[i]=temp;
		}
	//	printf("%lld\n",mxearn[i]);
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		scanf("%d%d",&s,&p);
		s *= 100;
		p *= 100;
		if(!n)break;
		for(int i=1;i<=n;i++)
		{
			double a;
			scanf("%lf",&a);
			price[i]=(int)((a+0.005)*100);
		//	printf("%lld ",price[i]);
		}
		//printf("\n");
		dp();
		double ans = (mxearn[n]-p)/100.0;
		printf("%.2lf\n",ans);
	}
	return 0;
}
