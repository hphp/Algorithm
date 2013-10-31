#include <stdio.h>
#define N 110000
#define Max(a,b) ((a)>(b)?(a):(b))

struct Segment
{
	int s,e;
	int cnt[2];
	int mxc[2];
	int lm,rm;
	int lmcnt,rmcnt;
	int ifchg,fc;	
	int ifexchg,exchgcnt;
}seg[N*4];

class SegmentTree
{
	private:
		void cover(int,int);
		void exchange(int);
		void momGetInfo(int);
	public:
		void build(int,int,int);
		void cover(int,int,int,int);
		void exchange(int,int,int);
		int query1(int,int,int);
		int queryc1(int,int,int);
};

void SegmentTree::build(int root,int s,int e)
{
	seg[root].s = s;
	seg[root].e = e;
	seg[root].cnt[0] = 0;
	seg[root].cnt[1] = 0;
	seg[root].mxc[0] = 0;
	seg[root].mxc[1] = 0;
	seg[root].lm = -1;
	seg[root].rm = -1;
	seg[root].lmcnt = 0 ;
	seg[root].rmcnt = 0;
	seg[root].ifchg = 0;
	seg[root].fc = -1;
	seg[root].ifexchg = 0;
	seg[root].exchgcnt = 0;
	if(s < e)
	{
		int mid = (s+e)/2;
		build(2*root,s,mid);
		build(2*root+1,mid+1,e);
	}
}

void SegmentTree::momGetInfo(int root)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	seg[root].ifchg  = 0;
	seg[root].ifexchg  = 0;
	seg[root].fc  = -1;
	seg[root].exchgcnt  = 0;
	for(int i=0;i<2;i++)
		seg[root].cnt[i] = seg[2*root].cnt[i]+seg[2*root+1].cnt[i];
//	int mxc[2];
	for(int i=0;i<2;i++)
		seg[root].mxc[i] = Max(seg[2*root].mxc[i],seg[2*root+1].mxc[i]);
	seg[root].lm = seg[2*root].lm;
	seg[root].rm = seg[2*root+1].rm;
	seg[root].lmcnt = seg[2*root].lmcnt;
	seg[root].rmcnt = seg[2*root+1].rmcnt;
	int flag = -1,mx = 0;
	if(seg[2*root].rm == seg[2*root+1].lm)
	{
		flag = seg[2*root].rm;
		mx = seg[2*root].rmcnt+seg[2*root+1].lmcnt;
	}
	if(flag >= 0)
	{
		seg[root].mxc[flag] = Max(seg[root].mxc[flag],mx);
	}
	int mid = (fs+fe)/2;
	if(seg[2*root].rm == seg[2*root+1].lm && seg[2*root].lmcnt == mid-fs+1)
	{
		seg[root].lmcnt = seg[2*root].lmcnt + seg[2*root+1].lmcnt;
	}
	if(seg[2*root].rm == seg[2*root+1].lm && seg[2*root+1].rmcnt == fe-mid)
	{
		seg[root].rmcnt = seg[2*root+1].rmcnt + seg[2*root].rmcnt;
	}
}

void SegmentTree::cover(int root,int cl)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	seg[root].ifchg = 1;
	seg[root].fc = cl;
	seg[root].ifexchg = 0;
	seg[root].exchgcnt = 0;
	seg[root].mxc[cl] = fe-fs+1;
	seg[root].mxc[1-cl] = 0;
	seg[root].cnt[cl] = fe-fs+1;
	seg[root].cnt[1-cl] = 0;
	seg[root].lm = cl;
	seg[root].rm = cl;
	seg[root].lmcnt = fe-fs+1;
	seg[root].rmcnt = fe-fs+1;	
}

void SegmentTree::cover(int root,int s,int e,int cl)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(s <= fs && fe <=e)
	{
		cover(root,cl);
		return ;
	}
/*	if(root == 6)
	{
		printf("hello motor %d %d %d %d\n",seg[root].ifchg,seg[root].fc,seg[root].ifexchg,seg[root].ifexchg);
	}*/
	if(seg[root].ifchg == 1)
	{
		cover(2*root,seg[root].fc);
		cover(2*root+1,seg[root].fc);
	}if(seg[root].ifexchg == 1)
	{
		seg[2*root].ifexchg = 1;
		seg[2*root+1].ifexchg = 1;
		seg[2*root].exchgcnt += seg[root].exchgcnt;
		seg[2*root+1].exchgcnt += seg[root].exchgcnt;
		exchange(2*root);
		exchange(2*root+1);
	}
	int mid = (fs+fe)/2;
	if(s <= mid)
		cover(2*root,s,e,cl);
	if(e > mid)
		cover(2*root+1,s,e,cl);
	momGetInfo(root);
}

void SegmentTree::exchange(int root)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	/*if(fs == 7 && fe == 7)
	{
		printf("exchg cnt %d\n",seg[root].exchgcnt);
	}*/
	if(seg[root].exchgcnt%2 == 1)
	{
		int cl = 0;
		int tt = seg[root].mxc[cl]; 
		seg[root].mxc[cl] = seg[root].mxc[1-cl];
		seg[root].mxc[1-cl] = tt;
		tt = seg[root].cnt[cl];
		seg[root].cnt[cl] = seg[root].cnt[1-cl];
		seg[root].cnt[1-cl] = tt;
		seg[root].lm = 1-seg[root].lm;
		seg[root].rm = 1-seg[root].rm;
	}
}

void SegmentTree::exchange(int root,int s,int e)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(s <= fs && fe <=e)
	{
		if(seg[root].ifchg==1)
		{
			cover(root,seg[root].fc);
		}
		seg[root].ifexchg = 1;
		seg[root].exchgcnt ++;
		exchange(root);
		return ;
	}
	if(seg[root].ifchg == 1)
	{
		cover(2*root,seg[root].fc);
		cover(2*root+1,seg[root].fc);
	}
	if(seg[root].ifexchg == 1)
	{
		seg[2*root].ifexchg = 1;
		seg[2*root+1].ifexchg = 1;
		seg[2*root].exchgcnt += seg[root].exchgcnt;
		seg[2*root+1].exchgcnt += seg[root].exchgcnt;
		exchange(2*root);
		exchange(2*root+1);
	}
	int mid = (fs+fe)/2;
	if(s <= mid)
		exchange(2*root,s,e);
	if(e > mid)
		exchange(2*root+1,s,e);
	momGetInfo(root);
}

int SegmentTree::query1(int root,int s,int e)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(s <= fs && fe <=e)
	{
	/*	if(root == 3)
		{
			printf("%d\n",seg[root].cnt[1]);
		}*/
		return seg[root].cnt[1];
	}
	if(seg[root].ifchg == 1)
	{
		cover(2*root,seg[root].fc);
		cover(2*root+1,seg[root].fc);
	}
	else if(seg[root].ifexchg == 1)
	{
		seg[2*root].ifexchg = 1;
		seg[2*root+1].ifexchg = 1;
		seg[2*root].exchgcnt += seg[root].exchgcnt;
		seg[2*root+1].exchgcnt += seg[root].exchgcnt;
		exchange(2*root);
		exchange(2*root+1);
	}
	int mid = (fs+fe)/2;
	int ans1 = 0 , ans2 = 0;
	if(s <= mid)
		ans1 = query1(2*root,s,e);
	if(e > mid)
		ans2 = query1(2*root+1,s,e);
	momGetInfo(root);
	return ans1+ans2;
}

int SegmentTree::queryc1(int root,int s,int e)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(s <= fs && fe <=e)
	{
		return seg[root].mxc[1];
	}
	if(seg[root].ifchg == 1)
	{
		cover(2*root,seg[root].fc);
		cover(2*root+1,seg[root].fc);
	}
	if(seg[root].ifexchg == 1)
	{	
		seg[2*root].ifexchg = 1;
		seg[2*root+1].ifexchg = 1;
		seg[2*root].exchgcnt += seg[root].exchgcnt;
		seg[2*root+1].exchgcnt += seg[root].exchgcnt;
		exchange(2*root);
		exchange(2*root+1);
		seg[root].ifexchg = 0;
		seg[root].exchgcnt = 0;
	}
	int mid = (fs+fe)/2;
	int ans1 = 0 , ans2 = 0;
	if(s <= mid)
		ans1 = queryc1(2*root,s,e);
	if(e > mid)
		ans2 = queryc1(2*root+1,s,e);
	int ans = Max(ans1,ans2);
/*	if(root == 1)
	{
		printf("left:l:%d cl:%d r:%d cr:%d\n",seg[2*root].lm,seg[2*root].lmcnt,seg[2*root].rm,seg[2*root].rmcnt);
		printf("right : l:%d cl:%d r:%d cr:%d\n",seg[2*root+1].lm,seg[2*root].lmcnt,seg[2*root+1].rm,seg[2*root+1].rmcnt);
	}*/
	if(seg[2*root].rm == seg[2*root+1].lm && seg[2*root].rm == 1)
		ans = ans1+ans2;
	momGetInfo(root);
	return ans;
}

int main()
{
	int test;
	int n,m,a,b,sign;
	scanf("%d",&test);
	while(test--)
	{
		SegmentTree sgt = SegmentTree();
		scanf("%d%d",&n,&m);
		sgt.build(1,0,n-1);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			sgt.cover(1,i,i,a);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%d %d %d",&sign,&a,&b);
			int ans = -1;
			switch(sign)
			{
				case 0:
					sgt.cover(1,a,b,0);
					break;
				case 1:
					sgt.cover(1,a,b,1);
					break;
				case 2:
					sgt.exchange(1,a,b);
					break;
				case 3:
					ans = sgt.query1(1,a,b);
					break;
				case 4:
					ans = sgt.queryc1(1,a,b);
					break;
			}
			if(ans >= 0)
				printf("%d\n",ans);
		}
	}
	return 0;	
}
