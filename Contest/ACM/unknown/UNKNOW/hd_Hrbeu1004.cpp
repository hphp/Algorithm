#include <stdio.h>

typedef int NumberType;

/*NumberType optimized_pow_n(NumberType x, unsigned int n)
{
	int a=n+1;
    NumberType pw = 1;


    while (n > 0) {
        if (n & 1)    
		{    // n & 1 等价于 (n % 2) == 1
            pw *= x%a;
            pw %= a;
		}
        x *= x%a;
        x %= a;
        n >>= 1;        // n >>= 1 等价于 n /= 2
    }

    return pw;
}*/
int n;

__int64 deal(int k)
{
	if(k==0)
		return 1;
	if(k%2==0)
	{
		__int64 temp=deal(k/2);
		return (temp*temp)%n;	
	}	
	else
	{
		__int64 temp=deal((k-1)/2);
		__int64 ans=(((temp*temp)%n)*(2%n))%n;
		return ans;
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
		printf("%d\n",(deal(n-1)+(1%n))%n);	
	}	
	return 0;
}

