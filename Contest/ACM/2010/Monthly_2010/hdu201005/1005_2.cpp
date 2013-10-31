#include <stdio.h>
#define N 2100
#define MAX (1<<29)
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

int deck2[N*3],deck1[N*3];

int ans1[N*3];

int head1,head2,tail1,tail2;

void insert(int x,int * a)
{
	while(head2<=tail2&&a[x]>a[deck2[tail2]])tail2--;
	deck2[++tail2]=x;
}

void getMax(int * a,int k,int n,int * ans2)
{
		head1=1,head2=1,tail1=1,tail2=1;
		deck1[1]=1;
		deck2[1]=1;
		int i;
		for(i=2;i<=k;i++)
		{
			while(head2<=tail2&&a[i]>a[deck2[tail2]])tail2--;
			deck2[++tail2]=i;	
		}
		int cnt=1;
		ans1[1]=a[deck1[1]];//min
		ans2[1]=a[deck2[1]];//max
		for(;i<=n;i++)
		{
			while(head2<=tail2&&a[i]>a[deck2[tail2]])tail2--;
			deck2[++tail2]=i;
			if(deck1[head1]==i-k) head1++;
			if(deck2[head2]==i-k) head2++;
			ans1[++cnt]=a[deck1[head1]];
			ans2[cnt]=a[deck2[head2]];	
		}
		/*for(int i=1;i<=n;i++)
			printf("%d ",ans2[i]);
			printf("hello\n");*/
}

int bestb[N*4],bests[N*4];
int recb[N*4],recs[N*4];

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
/*		for(int i =0 ;i <= T; i ++)
			for(int j=0;j<=maxb[i];j++)
				best[i][j] = -j*b[i];*/
		best[0][0] = 0;
		int aa[N*4];
		int bb[N*4];
		for(int i=0;i<N*3;i++)
		{
			aa[i] = bb[i] = -MAX;
			recb[i] = -MAX;
			recs[i] = -MAX;
		}
		for(int i = 1; i <= T; i ++)
		{
			if(i>=w+1)
			{
		//		printf("%d\n",i);
				int cur = 0;
				for(int j=0;j<=maxb[i]+1;j++)
					aa[j] = -MAX;
				for(int j=maxb[i]+2;j<=maxP+maxb[i]+2;j++)
				{
//					aa[j] = Max(best[i-1-w][(j-maxb[i]-2)]+b[i]*(j-maxb[i]-2),recb[j-maxb[i]-2]);
					if(best[i-1-w][j-maxb[i]-2] > -MAX)
					aa[j] = best[i-1-w][j-maxb[i]-2]+b[i]*(j-maxb[i]-2);
//					recb[j-maxb[i]-2] = Max(recb[j-maxb[i]-2],aa[j]);
				}
				for(int j=maxb[i]+maxP+2+1;j<=maxP+2*maxb[i]+1+1;j++)
					aa[j] = -MAX;
				getMax(aa,maxb[i]+1,maxP+2*maxb[i]+1+1,bestb);
				for(int j=0;j<=maxs[i]+1;j++)
					bb[j] = -MAX;
				int curr = maxP;
				for(int j=maxs[i]+2;j<=maxs[i]+maxP+1+1;j++,curr--)
				{
//					bb[j] = Max(best[i-1-w][curr]+s[i]*curr,recs[curr]);
					if(best[i-1-w][curr] > -MAX)
					bb[j] = best[i-1-w][curr]+s[i]*curr;
//					recb[curr] = Max(recb[curr],bb[j]);
				}
				for(int j=maxs[i]+maxP+2+1;j<=2*maxs[i]+maxP+2;j++)
					bb[j] = -MAX;
				getMax(bb,maxs[i]+1,maxP+2*maxs[i]+2,bests);
			}
			for(int j=0;j<=maxP;j++)
			{
				best[i][j] = Max(best[i-1][j],best[i][j]);
				if(i>=w+1)
				{
					int st = j+2;
					int cur = bestb[st];
					if(cur > -MAX)
						cur -= j*b[i];
					best[i][j] = Max(cur,best[i][j]);
					st = 2+maxP-j;
					cur = bests[st];
					if(cur > -MAX)
						cur -= j*s[i];
					best[i][j] = Max(cur,best[i][j]);
				}
			}
//			sum += maxb[i+1];
//			sum = Min(maxP,sum);
		}
		int ans = 0;
		for(int j=0;j<=maxP;j++)
			if(best[T][j] > ans)
				ans = best[T][j];
		printf("%d\n",ans);
	}
	return 0;
}
