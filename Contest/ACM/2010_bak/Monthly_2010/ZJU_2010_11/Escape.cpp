#include <stdio.h>
#include <math.h>
#define p2(a) ((a)*(a))
#define abss(a) ((a)>0?(a):(-(a)))
#define MAX (-(1<<28))
#define Max(a,b) ((a)>(b)?(a):(b))
#define N 110
#define NN 1210
#define T 1100

int mx[N][T];
int n;
struct CG
{
	int cost;
	int get;
}cg[N][NN];
int ccnt[N];
int ti[N];
int stx[N],sty[N];
int a,x[10],y[19],c[19];
int cgcnt = 0;
bool vst[10];
int rec[10];

int dis(int x,int y,int xx,int yy)
{
	return (abss(x-xx)+abss(y-yy));
}

void dfs(int id,int cur,int curn,int f)
{
	vst[cur] = 1;
	rec[curn] = cur;
	if(cur == f)
	{
		int csum = 0;
		int r = 0;
		for(int i=1;i<=curn;i++)
		{
			int cc = rec[i];
			int aa = rec[i-1];
			r += dis(x[aa],y[aa],x[cc],y[cc]);
			//printf("hello %d ",cc);
			csum += c[cc];
		}
//		printf("\n");
//		if(r <= ti[id])
		{
		cg[id][cgcnt].cost = r;
		cg[id][cgcnt++].get = csum;
		}
		vst[cur] = 0;
		return;	
	}
	for(int j=0;j<a;j++)
	{
		if(!vst[j])
			dfs(id,j,curn+1,f);
	}
	vst[cur] = 0;
}

void dp_init()
{
	for(int j=0;j<=n;j++)
	for(int i=0;i<T;i++)
		mx[j][i] = MAX;
	mx[0][0] = 0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		scanf("%d%d",&stx[0],&sty[0]);
		for(int i=n;i>0;i--)
			scanf("%d%d",&stx[i],&sty[i]);
		for(int i=n;i>0;i--)
		{
			scanf("%d",&a);
			for(int j=0;j<a;j++)
			{
				scanf("%d%d%d",&x[j],&y[j],&c[j]);
			}
		}
		for(int i=n;i>0;i--)
		{
			int a = rra[i];
			for(int j=0;j<a;j++)
				x[j] = rrx[i][j],y[j] = rrx[i][j];
			x[a] = stx[i],y[a] = sty[i];c[a] = 0;
			a++;
			x[a] = stx[i-1],y[a] = sty[i-1];c[a] = 0;
			for(int j=0;j<=a;j++)
				vst[j] = 0;
			cgcnt = 0;
			dfs(i,a,0,a-1);
			ccnt[i] = cgcnt;
		/*	for(int k=0;k<cgcnt;k++)
			{
				//printf("hi:%d %d\n",cg[i][k].cost,cg[i][k].get);
			}*/

		}
		for(int i=n;i>0;i--)
			scanf("%d",&ti[i]);
		dp_init();
		for(int i=1;i<=n;i++)
		{
			for(int j=ti[i];j>=0;j--)
			{
				for(int k=0;k<ccnt[i];k++)
				{
					if(cg[i][k].cost > j)continue;
					mx[i][j] = Max(mx[i][j],mx[i-1][j-cg[i][k].cost]+cg[i][k].get);
			//		printf("%d %d %d %d\n",i,j,k,mx[i][j]);
				}
			}
		}
		int ans = MAX;
		for(int j=0;j<=ti[n];j++)
			ans = Max(ans,mx[n][j]);
		if(ans >= 0)
		printf("%d\n",ans);
		else printf("I'm doomed, though I fought bravely\n");
	}
	return 0;
}
