#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 2000
#define MAXM 500000

const int INF=(1<<29)-1;

typedef struct tNode
{
	int v,f;
	tNode *nxt,*rev;
}Edge;
Edge E[MAXN],mem[MAXM];
Edge *Cur[MAXN];
int n,M,S,T,N,eCnt;
int gap[MAXN],d[MAXN];
int flow,aug;
bool done;
int num[MAXM],nCnt;

typedef struct
{
	int s,e,p;
}Task;
Task Ta[505];

typedef struct
{
	int l,r;
}Interval;
Interval I[1005];

void init()
{
	S=0,T=n+nCnt+1,N=T-S+1;eCnt=0;
	for(int i=0;i<N;i++) E[i].nxt=NULL;
}

void Add_Edge(int u,int v,int f)
{
	Edge *p=&mem[eCnt++],*q=&mem[eCnt++];
	p->v=v,p->f=f,p->rev=q;
	p->nxt=E[u].nxt,E[u].nxt=p;
	q->v=u,q->f=0,q->rev=p;
	q->nxt=E[v].nxt,E[v].nxt=q;
}

void SAP(int u)
{
	if(u==T)
	{
		done=true;flow+=aug;
		return ;
	}
	Edge *p=NULL;
	int augOri=aug;
	for(p=Cur[u];p!=NULL;p=p->nxt)
	{
		if(p->f<=0) continue;
		if(d[p->v]+1==d[u])
		{
			Cur[u]=p;
			aug=min(aug,p->f);
			SAP(p->v);
			if(d[S]>=N) return ;
			if(done) break;
			aug=augOri;
		}
	}
	if(done) p->f-=aug,p->rev->f+=aug;
	else
	{
		if(!(--gap[d[u]])) d[S]=N;
		int minD=N;Cur[u]=E[u].nxt;
		for(p=Cur[u];p!=NULL;p=p->nxt)
			if(p->f>0) minD=min(minD,d[p->v]);
		d[u]=minD+1;gap[d[u]]++;
	}
}

int MaxFlow()
{
	for(int i=0;i<N;i++)
	{
		gap[i]=d[i]=0;
		Cur[i]=E[i].nxt;
	}
	gap[0]=N;flow=0;
	while(d[S]<N)
	{
		aug=INF;done=false;
		SAP(S);
	}
	return flow;
}

int main()
{
	freopen("d://task_input.in","r",stdin);
	freopen("d://lowesy.out","w",stdout);
	int _,cases=1;
	scanf("%d",&_);
	while(_--)
	{
		scanf("%d%d",&n,&M);
		int s,e,p,sum=0;nCnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&p,&s,&e);
			Ta[i].s=s,Ta[i].e=e,Ta[i].p=p;
			num[nCnt++]=s,num[nCnt++]=e;
			sum+=p;
		}
		sort(num,num+nCnt);
		nCnt=unique(num,num+nCnt)-num;
		init();
		if(nCnt==1) I[0].l=I[0].r=num[0];
		else
		{
			for(int i=0;i<nCnt-1;i++)
				I[i].l=num[i],I[i].r=num[i+1]-1;
			I[nCnt-1].l=I[nCnt-1].r=num[nCnt-1];
		}
		for(int i=1;i<=n;i++)
		{
			Add_Edge(S,i,Ta[i].p);
			for(int j=0;j<nCnt;j++)
			{
				if(Ta[i].s>I[j].r) continue;
				if(Ta[i].e<I[j].l) break;
				int left=max(I[j].l,Ta[i].s);
				int right=min(I[j].r,Ta[i].e);
				Add_Edge(i,n+j+1,right-left+1);
			}
		}
		for(int i=0;i<nCnt;i++)
			Add_Edge(i+1+n,T,M*(I[i].r-I[i].l+1));
		MaxFlow();
		printf("Case %d: ",cases++);
		puts(sum==flow?"Yes\n":"No\n");
	}
	return 0;
}