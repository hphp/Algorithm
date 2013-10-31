#include <stdio.h>
#include <algorithm>
#define N 30100
#define MAX 1000000000000000000LL
#define M 11

typedef long long Int;

struct Veg
{
	int v;
	int a;
	Int d;
}veg[N];

int n,m,r;
Int t;
Int mn[N][M];
int suma[N];
Int msum[N],asum[N];

bool cmp(Veg a , Veg b)
{
	if(a.v > b.v)
		return 1;
	return 0;
}
int lst[N],head,tail;

double g(int k,int l,int j)
{
	return ((msum[k]-msum[l])+(l*asum[l]-k*asum[k]) + (mn[l][j]-mn[k][j]))*1.0/((l-k)*1.0);
}

void dp_init()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			mn[i][j] = MAX;
		for(int j=0;j<=m;j++)
		mn[0][j] = 0;
}

Int dp(int limt)
{
	dp_init();
	for(int j = 1 ;j <= m;j ++)
	{
		head = 1;
		tail = 1;
		lst[1] = 0;
		for(int i=1;i<=n;i++)
		{
			while((head < tail) && ((suma[i]-suma[lst[head]] > limt) || g(lst[head],lst[head+1],j-1) <=asum[i]))
				head++;
			int k = lst[head];
			if(suma[i]-suma[k] <= limt && mn[k][j-1] < MAX)
			{
				mn[i][j] = mn[k][j-1] + (msum[i]-msum[k])-k*(asum[i]-asum[k]) + (j==1?0:r);
			}
			if(mn[i][j-1] < MAX)
			{
				while((head < tail) && (g(lst[tail],i,j-1)<=g(lst[tail-1],lst[tail],j-1)))
					tail--;
				lst[++tail] = i;
			}
		}
	}
	Int mnn = mn[n][m];
	for(int j=1;j<=m;j++)
		mnn = mnn < mn[n][j] ? mnn:mn[n][j];
	return mnn;
}

int bi_find(int end)
{
	int s = 0 ;
	int e = end;
	if(dp(e) > t)
		return -1;
	if(dp(s) <= t)
		return 0;
	while(s + 1 < e)
	{
		int mid = (s+e)/2;
		Int tmp = dp(mid);
		if(tmp <= t)
			e = mid;
		else s = mid;
	}
	return e;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d%d%lld",&n,&m,&r,&t);
		m ++;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%lld",&veg[i].v,&veg[i].a,&veg[i].d);
		}
		std::sort(veg+1,veg+n+1,cmp);
		suma[0] = asum[0] = msum[0] = 0;
		for(int i=1;i<=n;i++)
		{
			suma[i]	= suma[i-1]+veg[i].a;
			asum[i]	= asum[i-1]+veg[i].d;
			msum[i] = i*veg[i].d + msum[i-1];
		}
		int ans = bi_find(suma[n]);
		if(ans >= 0)
			printf("%d\n",ans);
		else
			printf("I have no idea\n");
	}
	return 0;
}

/*
   2010-10-19
09:26
 */
