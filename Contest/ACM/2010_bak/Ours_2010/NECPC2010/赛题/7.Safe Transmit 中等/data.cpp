#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
	freopen("in.in","w",stdout);
	int T = 10;
	int n, m, p;
	int a,b;
	char c;
	int i,j;
	
	while(T--)
	{
		if(T!=1)
		{
			n = 6;
		}
		else 
		{
			n = 500;
		}
		printf("%d\n",n);
		m = (rand()%n)*(rand()%n);
		if(T<=1)
		{
			m = n*n;
		}
		printf("%d\n",m);
		
		for(i=0; i<m; ++i)
		{
			a = rand()%n + 1;
			b = rand()%n + 1;
			if(a == b)
				b = b+3%n;
			c = (rand())%3+1;
			printf("%d %d %c\n", a, b, c+'A');
		}
		
		p = (rand()%n)*(rand()%n);
		if(T==1)
		{
			p = n*n;
		}
		
		if(p ==0)
			p = 1;
		printf("%d\n",p);
		for(i=0; i<p; ++i)
		{
			a = rand()%n + 1;
			b = rand()%n + 1;
			if(a == b)
			{
				b = (b+3)%n+1;
			}
			printf("%d %d\n", a, b);
		}
	}
}
