//2010-05-10-16:47--18:48
//19:54--20:17

//----total : 140min
#include <stdio.h>
#include <algorithm>
#define N 110000
#define MOD 9901
#define MAX (1<<20)

int rec[N],real[N],cnt,map[N];
int kind[N],last[N],lh[N];
int n,h[N];
int difH;
int st;

int bifind(int cur)
{
	int s = st;
	int e = cnt-1;
	while(s <= e)
	{
		int mid = (s+e)/2;
		if(real[mid] == cur)
			return mid;
		if(real[mid] < cur)
			s = mid + 1;
		else e = mid-1;
	}
	return -1;
}

int findByDif(int st , int ed,int h)
{
	int s = st;
	int e = ed;
	int mid = ed;
	if(h - real[s] <= difH)
	{
		return s;	
	}
	while(s + 1 < e)
	{
		mid = (s+e)/2;
		int dif = h - real[mid];
		if(dif == difH)
			return mid;
		if(dif > difH)
			s = mid;
		else e = mid;
	}
	return e;
}

int findBy(int st,int ed,int h)
{
	int s = st;
	int e = ed;
	if(real[ed] - h <= difH)
		return ed;
	int mid = st;
	while(s + 1 < e)
	{
		mid = (s+e)/2;
		int dif = real[mid] - h ;
		if(dif == difH)
			return mid;
		if(dif > difH)
			e = mid;
		else s = mid;
	}
	return s;
}

struct Segment
{
	int s,e;
	int v;	
}seg[2][N*4];

class SegmentTree
{
	public:
		void build(int,int,int,int);
		void insert(int,int,int,int,int);
		int query(int,int,int,int);	
};

void SegmentTree::build(int flag,int root,int s,int e)
{
	seg[flag][root].s = s;
	seg[flag][root].e = e;
	seg[flag][root].v = 0;
	if(s < e)
	{
		int mid = (s+e)/2;
		build(flag,2*root,s,mid);
		build(flag,2*root+1,mid+1,e);	
	}
}

void SegmentTree::insert(int flag,int root,int s,int e,int add)
{
	int fs = seg[flag][root].s;
	int fe = seg[flag][root].e;
	if(fs >= s && fe <= e)
	{
		seg[flag][root].v += add;
		seg[flag][root].v %= MOD;
		return ;	
	}
	int mid = (fs+fe)/2;
	if(mid >= s)
		insert(flag,2*root,s,e,add);
	if(e > mid)
		insert(flag,2*root+1,s,e,add);
	seg[flag][root].v = seg[flag][2*root].v + seg[flag][2*root+1].v;
	seg[flag][root].v %= MOD;
}

int SegmentTree::query(int flag,int root,int s,int e)
{
	int fs = seg[flag][root].s;
	int fe = seg[flag][root].e;
	if(fs >= s && fe <= e)
	{
		return seg[flag][root].v;	
	}
	int mid = (fs+fe)/2;
	int ans1 = 0 , ans2 = 0;
	if(mid >= s)
		ans1 = query(flag,2*root,s,e);
	if(e > mid)
		ans2 = query(flag,2*root+1,s,e);
	return (ans1+ans2)%MOD;
}



int main()
{
	while(scanf("%d %d",&n,&difH)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&h[i]);
			rec[i] = h[i];
		}
		std::sort(rec+1,rec+n+1);
		real[0] = -MAX;
		cnt = st = 1;
		for(int i=1;i<=n;i++)
		{
			if(i == 1 || rec[i] != rec[i-1])
			{
				real[cnt] = rec[i];
				cnt ++;
			}
		}
		SegmentTree sgt[2];
		sgt[0].build(0,1,0,cnt);
		sgt[1].build(1,1,0,cnt);
		for(int i=1;i<=n;i++)
		{
			map[i] = bifind(h[i]);
	//		printf("%d ",map[i]);
			last[i] = findByDif(1,map[i],h[i]);
			lh[i] = findBy(map[i],cnt-1,h[i]);
	//		printf("%d %d\n",last[i],lh[i]);
			int part1 = sgt[0].query(0,1,last[i],lh[i]);
			int part2 = sgt[1].query(1,1,last[i],lh[i]);
//			if(last[i]!=0)
//			printf("%d %d\n",part1,part2);
			kind[map[i]] = (part1+part2);
			kind[map[i]] %= MOD;
			sgt[0].insert(0,1,map[i],map[i],1);
			sgt[1].insert(1,1,map[i],map[i],kind[map[i]]);
//			printf("%d\n",kind[map[i]]);
		}
//		printf("\n");
		int ans = sgt[1].query(1,1,1,cnt-1);
		printf("%d\n",ans);
	}
	return 0;
}

