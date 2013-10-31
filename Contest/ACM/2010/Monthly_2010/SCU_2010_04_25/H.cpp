#include <stdio.h>
#include <algorithm>
#define N 30100
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAX (1<<20)

int h[N];
int conh[N];
int should[2] = {-MAX,0};
struct Seg
{
	int s,e;
	int v[2];//0 low 1 hight
}seg[N*4];

class SegmentTree
{
	public :
		void build(int,int,int);
		void insert(int,int,int,int,int);
		int query(int,int,int,int);	
};

void SegmentTree::build(int root,int s,int e)
{
	seg[root].s = s;
	seg[root].e = e;
	seg[root].v[0] = 0;
	seg[root].v[1] = -1;
	if(s<e)
	{
		int mid = (s+e)/2;
		build(2*root,s,mid);
		build(2*root+1,mid+1,e);
	}
}

void SegmentTree::insert(int root,int s,int e,int flag,int vl)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s && fe <= e)
	{
		if(seg[root].v[flag] < vl)
		{
			seg[root].v[flag] = vl;
		}
		return;
	}
	int mid = (fs+fe)/2;
	if(mid >= s)
		insert(2*root,s,e,flag,vl);
	if(mid < e)
		insert(2*root+1,s,e,flag,vl);
	seg[root].v[flag] = Max(seg[2*root].v[flag],seg[2*root+1].v[flag]);
}

int SegmentTree::query(int root,int s,int e,int flag)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s && fe <= e)
	{
		return seg[root].v[flag];
	}
	int mid = (fs+fe)/2;
	int ans1 = -1,ans2=-1;
	if(mid >= s)
		ans1 = query(2*root,s,e,flag);
	if(mid < e)
		ans2 = query(2*root+1,s,e,flag);
	return Max(ans1,ans2);
}

int rcnt ,real[N];

int find(int cur)
{
	int s = 1;
	int e = rcnt -1;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(real[mid] == cur)
			return mid;
		if(real[mid] < cur)
			s = mid+1;
		else e = mid-1;
	}
	return -1;
}

int n;
int rec[N];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		int cnt = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&h[i]);
			rec[cnt++] = h[i];
		}
		std::sort(rec,rec+cnt);
		rcnt = 1;
		for(int i=0;i<cnt;i++)
			if(i == 0 || rec[i]!=rec[i-1])
			{
				real[rcnt++] = rec[i];
			}
		for(int i=0;i<n;i++)
			conh[i] = find(h[i]);
		SegmentTree sgt = SegmentTree();
		sgt.build(1,0,n);
		for(int i=0;i<n;i++)
		{
			int cur = sgt.query(1,conh[i]+1,n,1);
			if(cur >= 0)
				sgt.insert(1,conh[i],conh[i],0,cur+1);
//			printf("to be low %d ",cur);
			cur = sgt.query(1,0,conh[i]-1,0);
			if(cur >= 0)
				sgt.insert(1,conh[i],conh[i],1,cur+1);
	//		printf("to be high %d\n",cur);
		}
		int ans = Max(sgt.query(1,0,n,0),sgt.query(1,0,n,1));
		printf("%d\n",ans);
	}
	return 0;
}
