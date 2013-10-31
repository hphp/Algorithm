#include<stdio.h>
#include <algorithm>
#define N 101000
#define abss(a) ((a)<0?(-(a)):(a))
#define Max(a,b) ((a)>(b)?(a):(b))
int a[N];
int n,d;
int cnt = 0;
int rec[N],real[N],rcnt;

struct Segment 
{
	int v;
	int s,e;
}seg[N*4];

class SegmentTree
{
	public:
		int query(int,int,int);
		void build(int,int,int);
		void insert(int,int,int,int);
};

void SegmentTree::build(int root,int s,int e)
{
	seg[root].s = s;
	seg[root].e = e;
	seg[root].v = 0;
	if(s >= e)return;
	int mid = (s+e)/2;
	build(2*root,s,mid);
	build(2*root+1,mid+1,e);
}

int SegmentTree::query(int root,int s,int e)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(s <= fs && e >= fe)
	{
		return seg[root].v;
	}
	int mid = (fs+fe)/2;
	int ans1 = 0 , ans2 = 0;
	if(mid >= s)
		ans1 = query(2*root,s,e);
	if(mid < e)
		ans2 = query(2*root+1,s,e);
	return Max(ans1,ans2);
}

void SegmentTree::insert(int root,int s,int e,int v)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(s <= fs && e >= fe)
	{
		if(seg[root].v < v)
			seg[root].v = v;
		return ;
	}
	int mid = (fs+fe)/2;
	if(mid >= s)
		insert(2*root,s,e,v);
	if(mid < e)
		insert(2*root+1,s,e,v);
	seg[root].v = Max(seg[2*root].v,seg[2*root+1].v);
}

int find(int cur)
{
	int s =1 ;
	int e = rcnt-1;
	while(s <= e)
	{
//		printf("%d %d\n",s,e);
		int mid = (s+e)/2;
		if(real[mid] == cur)
			return mid;
		if(real[mid] < cur)
			s = mid+1;
		else e = mid-1;
	}
}

int fl(int cur,int b)
{
	int s = 1;
	int e = b;
	if(cur-real[1] <= d)
		return 1;
	if(b == 1 || cur - real[b-1] > d)
		return b;
	while(s + 1 < e)
	{
		int mid = (s+e)/2;
		if(cur - real[mid] <= d)
			e = mid;
		if(cur - real[mid] > d)
			s = mid;
	}
	return e;
}

int fr(int cur,int b)
{
	int s = b;
	int e = rcnt-1;
	if(b == rcnt-1 || real[b+1] - cur > d)
		return s;
	if(real[e] - cur <= d)
		return e;
	while(s +1 < e)
	{
		int mid = (s+e)/2;
		if(real[mid] - cur <= d)
			s = mid;
		if(real[mid] - cur > d)
			e = mid;
	}
	return s;
}

int main()
{
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		int ans = 0;
		cnt = 0;
		SegmentTree sgt = SegmentTree();
		for(int i=1;i<=n;i++)	
		{
			scanf("%d",&a[i]);
			rec[cnt++] = a[i];
		}
		std::sort(rec,rec+cnt);
		rcnt = 1;
		for(int i=0;i<cnt;i++)
		{
			if(i==0 || (rec[i]!=rec[i-1]))
			{
				real[rcnt++] = rec[i];
			}
		}
/*		for(int i=1;i<rcnt;i++)
			printf("%d ",real[i]);
		printf("\n");*/
		sgt.build(1,1,rcnt-1);
		for(int i=1;i<=n;i++)
		{
			int b = find(a[i]);
			int l = fl(a[i],b);
			int r = fr(a[i],b);
		//	printf("%d\n",b);
		//	printf("%d %d\n",l,r);
			int aa = sgt.query(1,l,r)+1;
//			printf("%d ",aa);
			sgt.insert(1,b,b,aa);
			if(aa > ans)
				ans = aa;
		}
		printf("%d\n",ans);
	}
}
/*
10:20 2010-6-17
11:14 2010-6-17
*/