#include <stdio.h>
#include <string.h>
#define N 1010000
char a[N],c[N];

bool avl(char aa)
{
	return ((aa>='a'&&aa<='z')||(aa>='A'&&aa<='Z'));
}
int main()
{
/*	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);*/
	int flag = 0;
	while(gets(a))
	{
		if(strlen(a) == 0)
		{
			printf("\n");
			continue;
		}
		int p = 0;
		int size = strlen(a);
		int ap = 0;
		while(p <= size)
		{
			if(!(avl(a[p])))
			{
				c[ap] = '\0';
				if(ap==0); else { printf("%c",c[0]);
					if(ap > 2)
						printf("%d",ap-2);
					if(ap > 1)
						printf("%c",c[ap-1]);
				}
				ap = 0;
				printf("%c",a[p]);
			}
			else c[ap++] = a[p];
			p ++;
/*			if(a[p] == ' ')
			{
				printf(" ");
				flag = 1;
				cnt = 0;
			}
			else if((a[p]>='a' && a[p]<='z')||(a[p]>='A'&&a[p]<='Z'))
			{
				if(flag == 0)
					cnt ++;
				else if(flag == 1)
				{
					printf("%c",a[p]);
					flag = 0;
				}
			}*/
		}
		printf("\n");
	}
}
