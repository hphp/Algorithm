#include <stdio.h>
#include <cstring>
#define MAX 1<<30
#define N 29

char ans[N],ori[N];
int n;int size;

bool fit(char next[],int cur)
{
	int cnt=0;
	while(cur)
	{
		int a=cur%2;
		cur=cur/2;
		next[cnt]=a+'0';
		cnt++;
	}
	next[cnt]='\0';
//	printf("next:%s\n",next);
	//scanf("%d\n",n);
	int flag=0;
	int count=0;
	int cnt0=0;
	for(int i=cnt-1;i>=0;i--)
	{
		if(next[i]==ori[cnt0])
		{
			cnt0++;
			if(cnt0==size)
			{
				flag=1;break;
			}
		}
	}
	return flag;
}

int main()
{
	while(scanf("%s%d",ori,&n)!=EOF)
	{
		int num =0;
		size=strlen(ori);
		for(int i=0;i<size;i++)
		{
			num*=2;
			num+=ori[i]-'0';
		}
//		printf("%d\n",num);
		//scanf("%d",&n);
		for(int i=num;i<=MAX;i++)
		{
			if((i%n)==0)
			{
//				printf("%d\n",i%num);
				if(fit(ans,i))
				{
					break;
				}
			}
		}
		char s[N];
		size=strlen(ans);
		for(int i=0;i<size;i++)
			s[size-1-i]=ans[i];
			s[size]='\0';
		printf("%s\n",s);
	}
	return 0;
}
