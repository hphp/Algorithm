#include <stdio.h>
#include <string.h>
#define l(a) (((a)>='a')&&((a)<='z')?1:0)
int main()
{
	char s[1000];
	while(scanf("%s",s)!=EOF)
	{
		int n = strlen(s);
		int ss = 0;
		for(int i=0;i<n;i++)
		{
			if(l(s[i]))
				ss++;
		}
		if(ss < n-ss)
		{
			for(int i=0;i<n;i++)
			{
				if(l(s[i]))
					s[i] = s[i]-'a'+'A';
			}
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(!l(s[i]))
					s[i] = s[i]-'A'+'a';
			}
			
			}
		printf("%s\n",s);
		
	}
	return 0;
}
