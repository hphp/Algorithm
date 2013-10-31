//09-11-01-11:14--
#include <stdio.h>
#include <string.h>
#define S 100

typedef int Int;

int transmit(char a[],char c[])
{
	int sa = strlen(a);
	int pa = sa-1;
	for(int i=0;i<=sa;i++)
		c[i] = '0';
	c[sa+1] = '\0';
	while(pa>-1)
	{
		c[pa+1] += a[pa]-'0';
		if(c[pa+1]=='9')
		{
			c[pa+1]='0';
			c[pa]++;
		}
		pa--;
	}
	int sum =0;
	for(int i=0;i<=sa;i++)
	{
		sum *= 9;
		sum += c[i]-'0';
	}
	return sum;
}

int main()
{
	char a[S],b[S],c[S],d[S];
	while(scanf("%s %s",a,b)!=EOF)
	{
		Int aa = transmit(a,c);
		Int bb = transmit(b,d);
		Int cc = aa-bb;
		char ans[S];
		int cnt =0;
		while(cc)
		{
			ans[cnt++] = cc%9+'0';
			cc/=9;
		}
		ans[cnt] = '\0';
		for(int i=0;i<cnt;i++)
		{
			if(ans[i]<'0')
			{
				if(i<cnt-1)
				{
				ans[i] = '8';
				ans[i+1]--;
				}
			}
			else if(ans[i]=='0')
			{
				if(i<cnt-1)
				{
				ans[i] = '9';
				ans[i+1]--;
				}
			}
		}
		for(int i=cnt-1;i>=0;i--)
		{
			if(ans[i]>'0')
			printf("%c",ans[i]);
		}
			printf("\n");
	}
	return 0;
}
