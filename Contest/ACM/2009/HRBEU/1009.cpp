#include <stdio.h>
#define N 100000
int n;

int dealing(int cur)
{
	if(cur==1)
		return 2%n;
	return (2*dealing(cur-1)%n-1%n)%n;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		int sum=1;
		int ans=1;
		int mid=(n-1)/2;
		while(mid)
		{
			ans=((ans%n)*(ans%n))
			mid=mid/2;
		}
		ans=(ans%n+1%n)%n;
		printf("%d\n",ans);
	//	printf("%d\n",dealing(n));
//		printf("%lld\n",((1<<(n-1))%n+1%n)%n);
	}	
	return 0;
}
