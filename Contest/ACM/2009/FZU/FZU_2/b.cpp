#include <stdio.h>
#include <string.h>
#define N 100000

char s[N];
char ans[N];

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		int flag = 0;
		int size = strlen(s);
		if(s[0]>='a'&&s[0]<='z'){//||s[0]=='_'
			flag = 0;	
		}
		else flag =-1;
		for(int i=1;i<size;i++)
		{
		//	printf("%d\n",i);
			if(flag==-1)
				break;
			if(s[i]>='A'&&s[i]<='Z')
			{
				if(flag !=1)
				flag = 2;
				else flag = -1;
			}
			else if(s[i]=='_')
			{
				if(s[i-1]=='_')
				{
					flag = -1;
					break;
				}
				if(flag!=2)
				flag = 1;	
				else flag = -1;
			}
			else if(s[i]>='a'&&s[i]<='z')
			{
				;	
			}
			else flag = -1;
		}
		if(s[size-1]=='_')
			flag = -1;
		if(flag==-1)
			printf("Unknown!\n");
		else
		{
			for(int i=0;i<size;i++)
			{
				if(s[i]>='A'&&s[i]<='Z')
				{
					printf("_%c",s[i]-'A'+'a');
				}
				else if(s[i]>='a'&&s[i]<='z')
				{
					if(i)
					{
						if(s[i-1]=='_')	
							printf("%c",s[i]-'a'+'A');
						else printf("%c",s[i]);
					}
					else printf("%c",s[i]);
				}
			}		
			printf("\n");
		}
	}
}
