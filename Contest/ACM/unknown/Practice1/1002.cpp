//09-10-04-12:28---12:36 fine!
#include <stdio.h>
#define N 100100
#define MAX (1<<30)
//#define lowbit(i) (i&(i^(i-1)))

typedef long long Int;
Int sum[N];
Int a[N];
int shorter[N];
int n;

/*void insert(int cur,int add)
{
	for(int i=cur;i<=n;i+=lowbit(i))
	{
		sum[i]+=add;		
	}
}

Int query(int cur)
{
	Int ans = 0;
	while(cur)
	{
		ans += sum[cur];
		cur -= lowbit(cur);
	}
	return ans;
}*/

void dp()
{
//	dp_init();
	Int mxmx = 0;
	a[0]=0;
	shorter[0] = -1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>a[i-1])	
		{
			shorter[i] = i-1;
		}
		else
		{
			int tmp = i-1;
			while(tmp && a[i]<=a[tmp])	
			{
				tmp = shorter[tmp];
			}
			shorter[i] = tmp;
		}
		int tmp = shorter[i];
		//printf("%d\n",tmp);
		int shtest = a[i];
		if(mxmx<a[i]*a[i])
			mxmx = a[i]*a[i];
//		Int sum1 = query(i);
		while(tmp>=0)
		{
			//Int sum2 = query(tmp);
			//Int stmp = (sum1-sum2)*shtest;
			Int stmp = (sum[i]-sum[tmp])*shtest;
			if(stmp > mxmx)
				mxmx = stmp;
			shtest = a[tmp];
			tmp = shorter[tmp];
		}
	}
	printf("%lld\n",mxmx);
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
		a[0] = 0;
		sum[0] = 0;
		for(int i=1;i<=n;i++)
			sum[i] = 0;
		for(int i=1;i<=n;i++)	
		{
			scanf("%lld",&a[i]);
		//	insert(i,a[i]);
			sum[i] = sum[i-1]+a[i];
		//	if(sum[i]<0)while(1);
		}
		dp();
	}
	return 0;
}
