#include <stdio.h>

int swap(int & a , int & b)
{
	int t = a;
	a = b;
	b = t;	
}

int gcd(int a,int b)
{
	if(a < b)
		swap(a,b);
	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main()
{
	int n,m;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		if(!(n||m))break;
		n ++ ; 
		m += 2 ;
		int gcdr = gcd(m,n);
	//	printf("%d\n",gcdr);
		printf("%d %d\n",n/gcdr,m/gcdr);
	}
	return 0;
}
