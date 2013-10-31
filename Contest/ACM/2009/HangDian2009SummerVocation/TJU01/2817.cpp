//2009-10-31--8:46--
#include <stdio.h>
#define CON 200907
typedef __int64 Int;

Int pow(int q,int n)
{
	if(n==0)return 1;
	Int tmp = pow(q,n/2);
	if(n%2==1)
		return (((tmp*tmp)%CON)*(q%CON))%CON;
	else
		return tmp*tmp%CON;	
}

int main()
{
	int test;
	scanf("%d",&test);
	Int a,b,c,d;
	while(test--)
	{
		scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&d);
		Int ans;
		if(b-a==c-b)
		{
			ans = (a+((d-1)%CON)*((b-a)%CON)%CON)%CON;
		}
		else
		{
			ans = (a%CON*pow(b/a,d-1))%CON;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
