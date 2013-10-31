//
#include <stdio.h>
#include <string.h>
#define S 10000

char s[S];
int num;
int kind;
char ans[4][S]={"It's a URL!","It's a path in Windows system!","It's a path in Unix-like systems!"};

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		fgets(s);
		int size = strlen(s);
		int flag = 0;//start;
		num = 0;
		for(int i=0;i<size;i++)
		{
			if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
			{
				if(flag==0)
					flag = -1;//letter
				else if(flag==-3)
				{
					flag = 2-num;
					break;
				}
			}
			if(s[i]==':')
			{
				if(flag==-1)
				{
					flag = -3;// 1 or 2stm; 
				}
			}
			if(s[i]=='\\'||s[i]=='/')
			{
				if(flag==0)	
				{
					flag = 3;break;			
				}
				else if(flag==-3)
				{
					num++;
					if(num==2)
					{
						flag = 1;
						break;
					}
				}
			}
		}
		printf("%s\n",ans[1+flag]);
		for(int i=0;i<size;i++)
		{
			if(flag==1||flag==2)	
			{
				if(s[i]=='\\')	
					printf("/");
				else printf("%c",s[i]);
			}
			else 
			{
				if(s[i]=='/')	
					printf("\\");
				else printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
