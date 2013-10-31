#include <stdio.h>
#include <string.h>

#define N 11000

char s[N];
char des[N];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%s",s);
		int size = strlen(s);
		int cnt = 0;
		for(int i=0;i<size;i++)
		{
			if(s[i]>='0' && s[i] <= '9')
			{
				;
			}
			else 
				des[cnt++] = s[i];
		}
		des[cnt] = '\0';
		printf("%s\n",des);
	}
	return 0;
}
