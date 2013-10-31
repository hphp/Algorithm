#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define Max(a,b) 	(a>b?a:b)
#define N 400010
#define MAX 100000
typedef int Int;
int n,T,len[N];
Int mn[N][2],ans,sum[N];
int echmost;

bool cmp(int a,int b)
{
	if(a<b)
		return 1;
		return 0;
}

void dp_init(void)
{
	for(int i=0;i<=n;i++)
		mn[i][0]=MAX;
	mn[0][0]=0;
}

void dp(void)
{
	dp_init();
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		mn[i][1-flag]=MAX;
		if(i>=T)
		for(int j=Max(i-T-echmost,0);j<=i-T;j++)	
		{
			Int temp = mn[j][flag]+sum[i]-sum[j]-(i-j)*len[j+1];
			if(temp<mn[i][1-flag])
			{
				mn[i][1-flag]=temp;
				printf("%d %d %d\n",i,j,mn[i][1-flag]);
			}
		}
		for(int )
		flag = 1-flag;
	}
	ans = mn[n][1-flag];
}

int main()
{
	while(scanf("%d%d",&n,&T)!=EOF)
	{
		echmost = n%T;
		for(int i=1;i<=n;i++)	
		{
			scanf("%d",&len[i]);
		}
		sort(len+1,len+n+1,cmp);
	/*	for(int i=1;i<=n;i++)
			printf("%d",len[i]);*/
		sum[0]=0;
		for(int i=1;i<=n;i++)
			sum[i]=sum[i-1]+len[i];
		dp();
		printf("%d\n",ans);
	}
}
