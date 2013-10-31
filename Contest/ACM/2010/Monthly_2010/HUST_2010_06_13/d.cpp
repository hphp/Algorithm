#include <stdio.h>

int gcd(int a,int b)
{
	if(a == 0)
		return b;
	return gcd(b%a,a);
	
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)	
	{
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			if(i%3==0)
			{
				if(i <= m)
					cnt ++;
			}
			else
			{
				if(i%3==1)
				{
					if(i+1<=m)
						cnt++;
				}
				else
				{
					if(i-1<=m)
						cnt++;
				}
			}
		}
		int cm = gcd(cnt,n*m);
		
		printf("%d/%d\n",cnt/cm,n*m/cm);
	}
	return 0;
}
