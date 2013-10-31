#include <stdio.h>
#include <string.h>
#define S 40
int ori[S][256];
int n;
char s[S];

void init(void)
{
	for(int i=0;i<S;i++)
		for(int j=0;j<60;j++)
			ori[i][j]=0;
}

int main()
{
	int tt=1;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			int size=strlen(s);
			for(int j=0;j<size;j++)
				ori[j][s[j]]++;
		}
		for(int i=0;i<n-1;i++)
		{
			scanf("%s",s);
			int size=strlen(s);
			for(int j=0;j<size;j++)
				ori[j][s[j]]--;
		}
		for(int i=0;i<S;i++)
		{
			s[i]='\0';
			for(int j=0;j<256;j++)
				if(ori[i][j]==1)
					s[i]=j;
		}
		printf("Scenario #%d\n",tt++);
		printf("%s\n\n",s);
	}
	return 0;
}
