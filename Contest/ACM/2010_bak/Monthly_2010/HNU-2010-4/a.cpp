#include <stdio.h>
#define N 20100
#define K 110

struct Seg
{
	int s,e;	
	int mn;
}seg[K][N*4];

void build(int root,int s,int e,int cur)
{
	seg[cur][root].s = s;
	seg[cur][root].e = e;	
	seg[cur][root].mn = MAX;
	if(s<e)
	{
		int mid = (s+e)/2;
		build(2*root,s,mid,cur);
		build(2*root+1,mid+1,e,cur);	
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&n,&k,&l);
		sum[0] = 0;
		for(int i=0;i<=k;i++)
			build(1,1,n,i);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			sum[i] = sum[i-1]+v[i];
		}
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int mn = query(1,s,e,i-1);
				if(mn < MAX)
					mn += (sum[j]-sum[]);
				if(mn < MAX)
				insert(1,s,e,i,mn);
			}
		}
		int mn = MAX;
		for(int i=1;i<=k;i++)
		{
			mn = Min(mn,query(1,1,n,i));
		}
		printf("")
	}	
	return 0;
}
