#include <stdio.h>
int num(int c)
{
	int sum = 0;
	while(c)
	{
		sum += c%10;
		c/=10;	
	}
	return sum;
}

int main()
{
	int ans = 0;
	for(int i=1;i<=100000;i++)
	{
				bool flag = 0;
				for(int j=1;j<=10000;j++)
				{
					int c = i*j;
					if(num(c) == j)
					{
						flag = 1;
						break;
					}
				}
				if(!flag)
					ans++;
	}
	printf("%d\n",ans);
	return 0;
}

