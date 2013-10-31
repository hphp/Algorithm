#include <stdio.h>

int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int n,m;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)break;
		n+=2;
		m++;
		int mcd=gcd(n,m);
		printf("%d %d\n",m/mcd,n/mcd);
	}
	return 0;
}
