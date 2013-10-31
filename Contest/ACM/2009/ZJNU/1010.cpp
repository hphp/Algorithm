#include <stdio.h>
#define N 40110
#define CON 1000003
typedef int Int ;
Int pow[N];

Int get(int cur)
{
	if(cur==0)
		return 1;
//	if(pow[cur])
//		return pow[cur];
	if(cur%2==0)
	{
		Int temp = get(cur/2);
		return (temp*temp)%CON;
	}
	else
	{
		Int temp = get((cur-1)/2)	;
		return (((2*temp)%CON)*temp)%CON;
	}
}

void booling(void)
{
	pow[0]=1;
	for(int i=1;i<N;i++)
	{
		pow[i]=get(i);
		if(i<10)
		printf("%d\n",pow[i]);
	}
	printf("%d\n",pow[40000]);
}

int main()
{
	booling();
	int test;
	scanf("%d",&test);
	for(int tt=1;tt<=test;tt++)
	{
		int n,a;
		scanf("%d",&n)	;
		Int ans=0;
		for(int i=1 ;i<=n;i++)
		{
			scanf("%d",&a)	;
			ans += (pow[a])%CON;
			ans %= CON;
		}
		ans = ans/n;
		ans = ans%CON;
		printf("Case %d:%d\n",tt,ans);
	}
	return 0;
}
