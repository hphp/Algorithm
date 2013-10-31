#include <stdio.h>
#define N 50100
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))

typedef int Int;

int mbc[N],mac[N];
int v[N];
int rec[N];
int cnt;

int n;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		int flag = 1;
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			if(v[i] < 0)
			{
				flag = 1;	
			}	
			if(flag == 1 && v[i]>0)
			{
				rec[cnt ++ ] = i;
				flag = 0;
			}
		}
		/*
			for(int i=0;i<cnt;i++)
			printf("%d ",rec[i]);
			printf("\n");
		*/
		Int mx = -MAX;
		for(int i=0;i<cnt;i++)
		{
			int st = rec[i];
		//	printf("hei %d\n",st);
			Int a = 0;
			mbc[st-1] = -MAX;
			for(int j=st;j<=n;j++)
			{
				if(a > 0)
					a += v[j];
				else a = v[j];
				mbc[j] = Max(mbc[j-1],a);
			}
			
			mbc[0] = mbc[n];
			for(int j=1;j<st;j++)
			{
				if(a > 0)
					a += v[j];
				else a = v[j];
				mbc[j] = Max(mbc[j-1],a);
			}
			
			a = 0;
			mac[st] = -MAX;
			for(int j=st-1;j>0;j--)
			{
				if(a > 0)
					a += v[j];
				else a = v[j];
				mac[j] = Max(mac[j+1],a);
			}
			mac[n+1] = mac[1];
			for(int j=n;j>=st;j--)
			{
				if(a > 0)
					a += v[j];
				else a = v[j];
				mac[j] = Max(mac[j+1],a);
			}
			
			for(int j=st;j<=n;j++)
			{
				if(mbc[j] + mac[j+1] > mx)
				{
				//	printf("%d %d %d\n",j,mbc[j],mac[j+1]);
					mx = mbc[j] + mac[j+1];
				}
			}
			for(int j=1;j<st-1;j++)
			{
				if(mbc[j] + mac[j+1] > mx)
				{
				//	printf("2 %d %d %d\n",j,mbc[j],mac[j+1]);
					mx = mbc[j] + mac[j+1];	
				}
			}
		}
		printf("%d\n",mx);
	}		
	return 0;
}
