#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 210

int grid[N][N];
int mx[N],num[N];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&m,&n);
		priority_queue <int> pq[2];
		init();
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=num[i];j++)
			{
				scanf("%d",&a);
				if(mx[i])
				{
					mx[i]	=a;
				}
			}
		int flag=0;
		for(int i=0;i<m;i++)
		{
			scanf("%s",s);
			switch(s[0])
			{
				case 'A':
				{
					scanf("%d",&a);
					
					break;
				}
				case 'T':
				{
					scanf("%d",&a);
					getnum[flag]+=num[a];
					if(mx[a]>maxget[flag])
						maxget[flag]=mx[a];
					break;
				}
				case 'C':
				{
					int a=maxget[flag]>maxget[1-flag]?flag:1-flag;
					int b=1-a;
					getsum[a]+=getsum[b];
					if(maxget[a]<maxget[b])
						maxget[a]=maxget[b];
					maxget[b]=0;
					getsum[b]=0;
					break;
				}
				case 'E':
				{
					maxget	
				}
			}
			flag=1-flag;
		}
	}
}
