#include <stdio.h>
#define N 2100
#define MAX (1<<20)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int best[N][N];

int b[N],s[N];
int maxb[N],maxs[N];
int maxP;
int T,w;

struct Segment
{
	int s,e;
	int mx[2];
}seg[N*4];

class SegmentTree
{
	public :
		void build(int,int,int);
		int query(int,int,int,int);
		void insert(int,int,int,int,int);
};

void SegmentTree::build(int root,int s,int e)
{
	seg[root].s = s;
	seg[root].e = e;
	for(int i=0;i<2;i++)
		seg[root].mx[i] = -MAX;
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
		if(seg[root].mx[flag] < vl)
		{
			seg[root].mx[flag] = vl;	
		}
		return;
	}
	int mid = (fs+fe)/2;
	if( mid >= s)
	{
		insert(2*root,s,e,flag,vl);
	}
	if(mid < e)
	{
		insert(2*root+1,s,e,flag,vl);
	}
	seg[root].mx[flag] = Max(seg[2*root].mx[flag],seg[2*root+1].mx[flag]);
}

int SegmentTree::query(int root,int s,int e,int flag)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s && fe <= e)
	{
/*		if(seg[id][root].mx[flag] == 0 && flag == 1)
		{
			printf("******************%d %d\n",fs,fe);	
		}*/
		return seg[root].mx[flag] ;
	}
	int mid = (fs+fe)/2;
	int ans1 = -MAX,ans2=-MAX;
	if( mid >= s)
	{
		ans1 = query(2*root,s,e,flag);
	}
	if(mid < e)
	{
		ans2 = query(2*root+1,s,e,flag);
	}
	return Max(ans1,ans2);
}


SegmentTree sgt = SegmentTree();

void buildSeg(int i)
{
	for(int j=0;j<=maxP;j++)
	{
		if(best[i][j]>-MAX)
		{
			int tmp = best[i][j] + j*b[i+w+1];
			sgt.insert(1,j,j,0,tmp);
			tmp = best[i][j] + j*s[i+w+1];
			sgt.insert(1,j,j,1,tmp);
		}
	}	
}
	int summ[N];

int main()
{
	int test;
	scanf("%d",&test);
	for(int tt = 0 ; tt < test; tt ++)
	{
		scanf("%d %d %d",&T,&maxP,&w);
		for(int i = 1; i <= T; i ++)
		{
			scanf("%d %d %d %d",&b[i],&s[i],&maxb[i],&maxs[i]);	
//			summ[i] = summ[i-1]+maxb[i];
		}
		for(int i= 0 ;i <= T; i ++)
			for(int j=0;j<=maxP;j++)
				best[i][j] =  -MAX;
		best[0][0] = 0;
		sgt.build(1,0,maxP);
		int sum = maxb[1] ;
		for(int i =0 ;i <= T; i ++)
			for(int j=0;j<=maxb[i];j++)
				best[i][j] = -j*b[i];
		for(int i = 1; i <= T; i ++)
		{
			if(i>=w+1)
			{
				int ei = i-w-1;
				for(int j=0;j<=sum;j++)
				{
					if(best[ei][j]>-MAX)
					{
						int tmp = best[ei][j] + j*b[ei+w+1];
						sgt.insert(1,j,j,0,tmp);
						tmp = best[ei][j] + j*s[ei+w+1];
						sgt.insert(1,j,j,1,tmp);
					}
				}	
			}
			for(int j=0;j<=sum;j++)
			{
				best[i][j] = Max(best[i-1][j],best[i][j]);
				int st = Max(j-maxb[i],0);
				int end = j;
				if(i>=w+1)
				{
					int cur = sgt.query(1,st,end,0);
					if(cur > -MAX)
						cur -= j*b[i];
					best[i][j] = Max(cur,best[i][j]);
					st = j;
					end = Min(j+maxs[i],maxP);
					cur = sgt.query(1,st,end,1);
					if(cur > -MAX)
						cur -= j*s[i];
					best[i][j] = Max(cur,best[i][j]);
				}
			}
			sum += maxb[i+1];
			sum = Min(maxP,sum);
		}
		int ans = 0;
		for(int j=0;j<=maxP;j++)
			if(best[T][j] > ans)
				ans = best[T][j];
		printf("%d\n",ans);
	}
	return 0;
}
