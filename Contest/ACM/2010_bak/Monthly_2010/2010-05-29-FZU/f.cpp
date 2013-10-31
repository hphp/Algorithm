#include <stdio.h>
#define N  500100
#define MAX 100000000000000000LL
#define Min(a,b) ((a)<(b)?(a):(b))

typedef __int64 Int;
Int bs[N],as[N],mbc[N],mac[N];
int n,a[N];

struct Node
{
	int id;
	int v;	
}node[N];

int lst[N];

void makeQueue()
{
	int head = 1 , tail = 1;
	lst[head] = 1;
	
	for(int i=1;i<=n;i++)
	{
		while(head <= tail && bs[i] <= bs[lst[tail]])
			tail --;
		lst[++tail]  = i;
	}
	
	mac[1] = mbc[n];
	for(int i=2;i<=n;i++)
	{
		while( head < tail && lst[head] < i)
			head ++;
		int cur = lst[head];
		mac[i] = bs[cur] - bs[i-1];
	}	
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int tt=1;tt<=test;tt++)
	{
		scanf("%d",&n);
		bs[0] = 0;
		mbc[0] = MAX;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			bs[i] = bs[i-1] + a[i];
			mbc[i] = Min(mbc[i-1],bs[i]);
		}
		as[n+1] = 0;
		mac[n+1] = MAX;
		for(int i=n;i>0;i--)
		{
			as[i] = as[i+1] + a[i];
//			mac[i] = Min(mac[i+1],as[i]);
		}
		
		makeQueue();
		
		/*for(int i=1;i<=n;i++)
		{
			printf("%d ",mbc[i]);
		}
		printf("\n");*/
		
		int cnt = 0;
		if(mbc[n] > 0)
			cnt ++;
		for(int i=2;i<=n;i++)
		{
			if(mac[i] <= 0)
				continue;
/*			if(mbc[i-1] <= 0)
				continue;*/
			if(as[i] + mbc[i-1] <= 0)
				continue;
			cnt ++;
		}
		printf("Case %d: %d\n",tt,cnt);
	}

	return 0;
	
}
/*
3
1 1 -1
8
1 1 1 -1 1 1 1 -1
3 -1 1 1
*/
