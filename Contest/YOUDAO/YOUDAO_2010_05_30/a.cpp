#include <stdio.h>
#include <string.h>
#define N 1000010
#define M 10

int ans[N*M],rec[N*M];
char s[N];

char stt[10] = {"100001"};
int part[10];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		getchar();
		gets(s);
		int size = strlen(s);
		int cnt = 0;
		for(int i=0;i<size;i++)
		{
			int cur = s[i];
			int cc = 0;
			while(cur)
			{
				part[cc] = cur%2;
				cur /= 2;
				cc ++;	
			}
			for(int j=7;j>=cc;j--)
				rec[cnt++] = 0;
			for(int j=cc-1;j>=0;j--)
				rec[cnt++] = part[j];
		}
	/*	for(int i=0;i<cnt;i++)
		{
			printf("%d",rec[i]);
		}
		printf("\n");*/
		
		int acnt = 0;

		int rst = 0;;
		for(int i=5;i<cnt;i++)
		{
			int j = i-5;
			int cc = 0;
			for(j=i-5;j<=i;j++,cc++)
			{
				if(rec[j]!=(stt[cc]-'0'))
					break;
			}
			if(j == i+1 && cc ==6)
			{
				for(int k=i-5;k<=i;k++)
					printf("%d",rec[k]);
		
				rst ++;
			}
		}


/*		for(int i=0;i<cnt-1;i+=2)
		{
			int cur = rec[i]*2 + rec[i+1];
			ans[acnt ++] = cur;
		}
		for(int i=0;i<acnt;i++)
			printf("%d",ans[i]);
			printf("\n");
		
		int rst = 0;
		for(int i=2;i<acnt;i++)
		{
			if(ans[i-2] == 2 &&  ans[i-1] == 0 && ans[i] == 1)
			{
				rst ++;
			}
		}*/
		printf("%d\n",rst);
	}
}
