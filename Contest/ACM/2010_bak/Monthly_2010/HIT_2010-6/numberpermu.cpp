#include <stdio.h>
#define MOD 1000000007

typedef __int64 Int;

int main()
{
	int test;
	scanf("%d",&test);
	for(int tt=1;tt<=test;tt++)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		Int sum = 1;
		int mm = m , kk = k;
		for(int i=1;i<=k;i++)
		{
			sum *= mm;
//			sum = sum % (MOD*i);
			sum /= i;
			mm--;
		}
		printf("%I64d\n",sum);
		sum %= MOD;
		Int aa = 1;
		for(int i= n-k;i>0;i--)
		{
			aa *= i;
			aa %= MOD;
		}
		Int bb = 0;
		for(int j=0;j<n-m;j++)
		{
			Int bbb = 1;
			for(int i= n-m-j;i>0;i--)
			{
				bbb *= i;
				bbb %= MOD;
			}
			bb += bbb;
			bb %=MOD;
		}
		sum = sum *(aa-bb) %MOD;
		printf("Case %d: %I64d\n",tt,sum);
	}

}
