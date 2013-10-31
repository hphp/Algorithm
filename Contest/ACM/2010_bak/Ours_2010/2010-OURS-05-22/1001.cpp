#include <stdio.h>

int C(int s, int b)
{
	int cc = 1;
	int ans = 1;
	int tmp = b;
	while( cc <= s)
	{
		if(tmp >= b-s+1)
			ans *= tmp;
		ans /= cc;
		tmp --;
		cc ++;
	}
	while(tmp >= b-s+1)
	{
		ans *= tmp;
		tmp --;
	}
	return ans;
}
int n,a[200];
int flg[200],si[200];

int A(int a)
{
	int sum = 1;
	for(int i = 1; i <= a; i ++)
		sum *= i;
	return sum;
}
int main()
{
/*	int aa,b;
	while(scanf("%d %d",&aa,&b)!=EOF)
		printf("%d\n",C(aa,b));*/
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<20;i++)
			flg[i] = si[i] = 0;
		int sum =0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			si[a[i]] += a[i];
			sum += a[i];
		}
		int ans = 1;
		for(int i=1;i<=n;i++)
		{
				ans *= C(a[i],sum);
				sum -= a[i];
		//	printf("C:%d\n",C(a[i],sum));
		}
		for(int i=1;i<=n;i++)
		{
			if(flg[a[i]]==0 && si[a[i]] > a[i])	
			{
				ans /= A(si[a[i]]/a[i]);
			}
			flg[a[i]] = 1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
