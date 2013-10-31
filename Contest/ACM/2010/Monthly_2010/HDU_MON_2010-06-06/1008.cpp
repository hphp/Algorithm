#include <stdio.h>
#include <math.h>
#define N 700000
typedef __int64 Int;
int main()
{
	Int n;
	while(scanf("%I64d",&n)!=EOF)
	{
		Int sum =0 ;
		for(int i=1;i<=n;i++)
			sum += i;
			
		Int b = sum * 4;
		Int c = b + 1;
		Int a = (Int)sqrt(b+c);
		printf("%I64d %I64d\n",a+b+c-3,c);
	}
}
