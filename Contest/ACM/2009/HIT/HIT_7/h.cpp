#include <stdio.h>
#include <string.h>
#define S 100

int main()
{
	char a[S],b[S];
	int rec[S];
	while(scanf("%s%s",a,b)!=EOF)
	{
		int sa=strlen(a);
		int sb=strlen(b);
		int suma=0,sumb=0;
		for(int i=0;i<sa;i++)
		{
			suma*=9;
			suma+=a[i]-'0';
		}
		for(int i=0;i<sb;i++)
		{
			sumb*=9;
			sumb+=b[i]-'0';
		}
		printf("%d %d\n",suma,sumb);
		int c=suma-sumb;
		int cnt=0;
		while(c)
		{
			if(c%10==0)
			{
				rec[cnt]=9;
				c-=10;
			}
			else rec[cnt]=c%10;
			c/=10;
			cnt++;
		}
		for(int i=cnt-1;i>=0;i--)
			printf("%d",rec[i]);
			printf("\n");
/*		int temp =c;
		while(temp)
		{
			if(temp%10==0)	
			{
					
			}
		}*/
	}
	return 0;
}
