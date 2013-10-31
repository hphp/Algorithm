#include <stdio.h>
#include <string.h>
#define N 2000001
int num[300];
char s[N][8];
int n;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		n = n*2  - 1;
		gets(s[0]);
		for(int i=0;i<n;i++)
		{
			gets(s[i]);
//			printf("%s\n",s[i]);
		}
		char ans[9] = "";
		for(int i=0;i<7;i++)
		{
			for(int j=0;j<300;j++)
				num[j] = 0;
			for(int j=0;j<n;j++)
			{
//				printf("%d ",s[j][i]);
				num[s[j][i]]++;
			}
//			printf("hei");
			int k = 0;
			for(k=0;k<300;k++)
			{
//				printf("%d ",num[k]);
				if((num[k]%2) == 1)
					break;
			}
			ans[i] = k;
//			printf("hi:%c\n",k);
		}
		ans[7] = '\0';
		printf("%s\n",ans);
	}
	return 0;
}
