#include <stdio.h>
#define N 101000
#define lowbit(x) ((x) & (-(x)))

int C[N];

void init()
{
	for(int i=0;i<N;i++)
	{
		C[i] = 0;
	}
}

void insert(int cur,int v)
{
	for(int i=cur;i<N;i+=lowbit(i))
	{
		C[i] += v;
	}
}

int query(int cur)
{
	int sum =0;
	while(cur)
	{
		sum += C[cur];
		cur -= lowbit(cur);
	}
	return sum;
}
int k;
int find(int ba , int st)
{
	if(query(st)-ba >= k)
		return st;
	int s = st;
	int e = N-1;
	while(s+1<e)
	{
		int mid = (s+e)/2;
		int cur = query(mid) - ba;
//		printf("%d %d\n",mid,cur);
		if(cur < k)
			s = mid;
		if(cur >= k)
			e = mid;
	}
	return e;
}

int main()
{
	int a,m,s;
	while(scanf("%d",&m)!=EOF)
	{
		init();
		for(int i=0;i<m;i++)
		{
			scanf("%d",&s);
			if(s == 0)
			{
				scanf("%d",&a);
				insert(a,1);
			}
			else if(s == 1)
			{
				scanf("%d",&a);
				int l = query(a);
				int r = 0;
				if(a > 1)
					r = query(a-1);
//				printf("%d %d\n",l,r);
				if(l - r == 0)
					printf("No Elment!\n");
				else
					insert(a,-1);
			}
			else if(s ==2)
			{
				scanf("%d%d",&a,&k);
				int ba = query(a);
				int left = query(N-1) - ba;
//				printf("ba:%d left:%d\n",ba,left);
				if(left < k)
					printf("Not Find!\n");
				else
				{
					int ans = find(ba,a+1);
					printf("%d\n",ans);
				}
			}
		}
	}
	return 0;
}
