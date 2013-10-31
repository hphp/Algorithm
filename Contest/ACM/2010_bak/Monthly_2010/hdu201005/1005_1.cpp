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
	int mx[2];
}seg[N][N*2];

class SegmentTree
{
	public :
		void build(int,int,int,int);
		int query(int,int,int,int,int);
		void insert(int,int,int,int,int,int);
};

void SegmentTree::build(int id,int root,int s,int e)
{
	for(int i=0;i<2;i++)
		seg[id][root].mx[i] = -MAX;
	if(s<e)
	{
		int mid = (s+e)/2;
		build(id,2*root,s,mid);
		build(id,2*root+1,mid+1,e);
	}
}

void SegmentTree::insert(int id,int root,int s,int e,int flag,int vl)
{
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s && fe <= e)
	{
		if(seg[id][root].mx[flag] < vl)
		{
			seg[id][root].mx[flag] = vl;	
		}
		return;
	}
	int mid = (fs+fe)/2;
	if( mid >= s)
	{
		insert(id,2*root,s,e,flag,vl);
	}
	if(mid < e)
	{
		insert(id,2*root+1,s,e,flag,vl);
	}
	seg[id][root].mx[flag] = Max(seg[id][2*root].mx[flag],seg[id][2*root+1].mx[flag]);
}

int SegmentTree::query(int id,int root,int s,int e,int flag)
{
	int fs = seg[id][root].s;
	int fe = seg[id][root].e;
	if(fs >= s && fe <= e)
	{
/*		if(seg[id][root].mx[flag] == 0 && flag == 1)
		{
			printf("******************%d %d\n",fs,fe);	
		}*/
		return seg[id][root].mx[flag] ;
	}
	int mid = (fs+fe)/2;
	int ans1 = -MAX,ans2=-MAX;
	if( mid >= s)
	{
		ans1 = query(id,2*root,s,e,flag);
	}
	if(mid < e)
	{
		ans2 = query(id,2*root+1,s,e,flag);
	}
	return Max(ans1,ans2);
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&T,&maxP,&w);
		for(int i = 1; i <= T; i ++)
		{
			scanf("%d %d %d %d",&b[i],&s[i],&maxb[i],&maxs[i]);	
		}
		for(int i= 0 ;i <= T; i ++)
			for(int j=0;j<=maxP;j++)
				best[i][j] =  -MAX;
		best[0][0] = 0;
		SegmentTree sgt = SegmentTree();
		for(int i =0 ;i <= T;i++)
			sgt.build(i,1,0,maxP);
		int i = 0 ;
		for(int j=0;j<=maxP;j++)
			{
				int tmp = -MAX;
				if(i+w+1<=T && best[i][j]>-MAX)
					tmp = best[i][j] + j*b[i+w+1];
				sgt.insert(i,1,j,j,0,tmp);
			}
		for(int j=maxP;j>=0;j--)
		{
			int tmp = -MAX;
			if(i+w+1<=T && best[i][j] > -MAX)
				tmp = best[i][j] + j*s[i+w+1];
			sgt.insert(i,1,j,j,1,tmp);
		}
		for(int i = 1; i <= T; i ++)
		{
			for(int j=0;j<=maxP;j++)
			{
				best[i][j] = Max(best[i-1][j],best[i][j]);
				int st = Max(j-maxb[i],0);
				int end = j;
				int cur = -MAX;
				if(i>=w+1)
				{
					cur = sgt.query(i-w-1,1,st,end,0);
					if(cur > -MAX)
						cur -= j*b[i];
				}
				best[i][j] = Max(cur,best[i][j]);
				st = j;
				end = Min(j+maxs[i],maxP);
				if(i>=w+1)
				{
					cur = sgt.query(i-w-1,1,st,end,1);
					if(cur > -MAX)
						cur -= j*s[i];
				/*	if(i == 5)
					{
						printf("dfsdfds %d %d %d %d\n",i-w-1,st,end,cur+j*s[i]);
					}*/
				}
				best[i][j] = Max(cur,best[i][j]);
//				best[i][j] = Max(bestb[i-w-1][j]-j*b[i],best[i][j]);
//				best[i][j] = Max(bests[i-w-1][j]-j*s[i],best[i][j]);
		//		if(best[i][j] > -MAX)
		//			printf("%d %d %d\n\n",i,j,best[i][j]);
			}
			for(int j=0;j<=maxP;j++)
			{
				int tmp = -MAX;
				if(i+w+1<=T && best[i][j]>-MAX)
					tmp = best[i][j] + j*b[i+w+1];
				sgt.insert(i,1,j,j,0,tmp);
			}
			for(int j=maxP;j>=0;j--)
			{
				int tmp = -MAX;
				if(i+w+1<=T && best[i][j]>-MAX)
					tmp = best[i][j] + j*s[i+w+1];
				sgt.insert(i,1,j,j,1,tmp);
			}
	/*		if(i == 4)
			{
				printf("dfdfdsf %d\n",bests[i][2]);
			}*/
		}
		int ans = 0;
		for(int j=0;j<=maxP;j++)
			if(best[T][j] > ans)
				ans = best[T][j];
		printf("%d\n",ans);
	}
	return 0;
}
