#include <stdio.h>
#include <vector>
#define N 101000
typedef __int64 Int;
using namespace std;
int pre[N];
struct Node
{
	int id;
	Int v;	
};
vector <Node> son[N],next[N];
int n;
void init()
{
	for(int i=0;i<=n;i++)
	{
		pre[i] = -1;
		next[i].clear();
		son[i].clear();	
	}
}

void dfs(int cur)
{
	pre[cur] = 1;
	int size = next[cur].size();
	for(int i=0;i<size;i++)	
	{
		Node t = next[cur][i];
		if(pre[t.id] == -1)	
		{
			son[cur].push_back(t);
			dfs(t.id);	
		}
	}
}

Int ans,nans;
Int mx[N],bn[N];

void dp(int cur)
{
	int size = son[cur].size();
	if(size == 0)
	{
		mx[cur] = 0;
		bn[cur] = 1;
		if(mx[cur] > ans)
		{
			ans = mx[cur];
			nans = 1;	
		}
		return ;
	}
	Int mxmx = -1;
	int c = 0;
	Int rcd = 0;
	for(int i=0;i<size;i++)
	{
		Node t = son[cur][i];
		dp(t.id);
		Int v = mx[t.id] + t.v;
		if(v == mxmx)
		{
			c ++;
			rcd += bn[t.id];
		}
		else if(v > mxmx)
		{
			mxmx = v;
			c = 1;	
			rcd = bn[t.id];
		}
	}
	mx[cur] = mxmx;
	bn[cur] = rcd;
	if(c == 1)
	{
		Int mxx = -1;
		Int rcdd = 0;
		for(int i =0;i < size;i ++)	
		{
			Node t = son[cur][i];
			int id = t.id;
			Int v = mx[id]+t.v;
			if( v < mxmx && v == mxx)	
			{
				rcdd += bn[id];
			}
			else if(v < mxmx && v > mxx)
			{
				mxx = v;
				rcdd = bn[id];	
			}
		}
		if(rcdd > 0)
		{
			if(mxmx + mxx == ans)	
			{
				nans += (rcdd * rcd);
			}
			else if(mxmx + mxx > ans)
			{
				ans = mxmx + mxx;
				nans = (rcdd * rcd);
			}
		}
		else
		{
			if(mxmx == ans)	
			{
				nans += rcd;	
			}
			else if(mxmx > ans)
			{
				ans = mxmx;
				nans = rcd;	
			}
		}
	}
	else
	{
		Int aa=0;
		for(int i=0;i<size;i++)	
		{
			Node t= son[cur][i];
			int id = t.id;
			Int v = mx[t.id] + t.v;
			if(v == mxmx)
			{
				aa += (bn[id]*(rcd-bn[id]));
			}
		}
		aa/=2;
		if(mxmx + mxmx == ans)
		{
			nans += aa;	
		}
		else if(mxmx  + mxmx > ans)
		{
			ans = mxmx + mxmx;
			nans = aa;	
		}
	}
//	printf("%d %I64d %I64d %I64d %I64d\n",cur,mx[cur],bn[cur],ans,nans);
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int a,b;
	Int c;
	while(scanf("%d",&n)!=EOF)	
	{
		init();
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%I64d",&a,&b,&c);
			Node t = {a,c};
			next[b].push_back(t);
			Node tt = {b,c};
			next[a].push_back(tt);
		}
		dfs(1);
	/*	for(int i=1;i<=n;i++)
		{
			for(int j=0;j<son[i].size();j++)
				printf("%d ",son[i][j].id);
				printf("\n");
		}*/
		ans = -1;
		dp(1);
		printf("%I64d %I64d\n",ans,nans);
	}
}
/*
4
1 2 100
2 3 50
2 4 50
2010-06-16
10:20--10:45
*/
