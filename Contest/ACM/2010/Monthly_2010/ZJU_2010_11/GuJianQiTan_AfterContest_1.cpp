#include <stdio.h>
#include <algorithm>
#define N 1010
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;

struct Mon
{
	int id;
	int v;
}mon[N*N];

struct Segment
{
	int s,e;
	bool color;
	int add;
}seg[N*4];
int cake[N];
int n;
int f[N];

bool cmp(Mon a , Mon b)
{
	if(a.v<b.v)
		return 1;
	if(a.v>b.v)
		return 0;
	if(a.id > b.id)
		return 1;
	return 0;
}

void build(int root,int s,int e)
{
	seg[root].s = s;
	seg[root].e = e;
	seg[root].color = 0;
	seg[root].add = 0;
	if(s < e)
	{
		int mid = (s+e)/2;
		build(2*root,s,mid);
		build(2*root+1,mid+1,e);
	}
}

int query(int root,int s,int e)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s && fe <= e)
		return seg[root].add;
	if(seg[root].color)
	{
		seg[2*root].color = 1;
		seg[2*root].add += seg[root].add;
		seg[2*root+1].color = 1;
		seg[2*root+1].add += seg[root].add;
		seg[root].color = 0;
		seg[root].add = 0;
	}
	int mid = (fs+fe)/2;
	if(mid >= s)
		return query(2*root,s,e);
	if(mid < e)
		return query(2*root+1,s,e);
}

void insert(int root,int s , int e , int add)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s && fe <= e)
	{
		seg[root].add += add;
		seg[root].color = 1;
		return;
	}
	if(seg[root].color)
	{
		seg[2*root].color = 1;
		seg[2*root].add += seg[root].add;
		seg[2*root+1].color = 1;
		seg[2*root+1].add += seg[root].add;
		seg[root].color = 0;
		seg[root].add = 0;
	}
	int mid = (fs+fe)/2;
	if(mid >= s)
	{
		insert(2*root,s,e,add);
	}
	if(mid < e)
	{
		insert(2*root+1,s,e,add);
	}

}
int cnt ;

int main()
{
	int tc;
	scanf("%d",&tc);
	int a,b;
	while(tc--)
	{
		scanf("%d",&n);
		cnt = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			for(int j=0;j<a;j++)
			{
				scanf("%d",&b);
				mon[cnt].id = i;
				mon[cnt].v = b;
				cnt ++;
			}
		}
		std::sort(mon,mon+cnt,cmp);
		//	build(1,1,n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			cake[i] = a;
			f[i] = i;
			//		insert(1,i,i,cake[i]);
		}
		int ans = 0;
		f[0] = -1;
		for(int i=0;i<cnt;i++)
		{
			int id = mon[i].id;
			int v = mon[i].v;
			int ff = f[id];
			int csum = 0;
			while((ff>0)&&(csum < v))
			{
				csum += cake[ff];
				if(csum >= v)break;
				ff = f[ff-1];
			}
			if(csum >= v)
			{
				int fff = f[id];
				while((fff>=ff)&&(v>0))
				{
					if(cake[fff] <= v)
					{
						v -= cake[fff];
						cake[fff] = 0;
					}
					else
					{
						cake[fff] -= v;
						v = 0;
						break;
					}
					fff = f[fff-1];
				}
				f[id] = ff;
				ans++;
			}
			else f[id] = -1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
