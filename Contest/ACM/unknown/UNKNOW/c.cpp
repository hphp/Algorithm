#include <stdio.h>
#include <string.h>

void dfs(char s[],int add)
{
	if(flag==1)
		return;
	int size=strlen(s);
	int sum =0;
	for(int i=0;i<size;i++)
	{
		sum+=s[i]-'0';
		sum*=2;
	}
	if(sum%n==0)
	{
		strcpy(ans,sum);
		flag=1;
	}
	
}

int main()
{
	while(scanf("%s%d",&ori,&n)!=EOF)
	{
		dfs(ori,0);
		printf("%s\n",ans);
	}
	return 0;
}
