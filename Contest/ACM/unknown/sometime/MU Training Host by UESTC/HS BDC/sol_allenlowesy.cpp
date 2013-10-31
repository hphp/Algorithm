#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAXN 35
#define MAXM 50000

const int INF=(1<<29)-1;

typedef struct tNode
{
	int v,f;
	tNode *nxt,*rev;
}Edge;
Edge E[MAXN],mem[MAXM];
int n,N,S,T,eCnt;
int outDeg[MAXN],inDeg[MAXN];
int d[MAXN],gap[MAXN];
int aug,flow;
bool done,vst[MAXN],G[MAXN][MAXN];

void init()
{
	S=0,T=27,N=T-S+1;eCnt=0;
	for(int i=0;i<N;i++)
		E[i].nxt=NULL;
	memset(inDeg,0,sizeof(inDeg));
	memset(outDeg,0,sizeof(outDeg));
	memset(vst,0,sizeof(vst));
	memset(G,0,sizeof(G));
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
		flow+=aug;done=true;
		return ;
	}
	Edge *p=NULL;
	int minD=N+1,augOri=aug;
	for(p=E[u].nxt;p;p=p->nxt)
	{
		if(p->f<=0) continue;
		if(d[p->v]+1==d[u])
		{
			if(aug>p->f) aug=p->f;
			SAP(p->v);
			if(d[S]>=N) return ;
			if(done) break;
			aug=augOri;
		}
		minD=min(minD,d[p->v]);
	}
	if(done) p->f-=aug,p->rev->f+=aug;
	else
	{
		gap[d[u]]--;
		if(!gap[d[u]]) d[S]=N;
		d[u]=minD+1;
		gap[d[u]]++;
	}
}

int MaxFlow()
{
	memset(gap,0,sizeof(gap));
	memset(d,0,sizeof(d));
	flow=0;gap[0]=N;
	while(d[S]<N)
	{
		aug=INF;done=false;
		SAP(S);
	}
	return flow;
}

void dfs(int u,int &cnt)
{
	vst[u]=true;cnt++;
	for(int v=1;v<=26;v++)
		if(G[u][v]&&!vst[v])
			dfs(v,cnt);
}

int main()
{
	int cases,t=1;
	scanf("%d",&cases);
	while(cases--)
	{
		init();
		scanf("%d",&n);
		char word[100];
		int type,m=0;
		for(int i=0;i<n;i++)
		{
			scanf("%s%d",word,&type);
			int u=word[0]-'a'+1;
			int v=word[strlen(word)-1]-'a'+1;
			if(type) Add_Edge(u,v,1);
			G[u][v]=G[v][u]=true;
			if(!vst[u]) vst[u]=true,m++;
			if(!vst[v]) vst[v]=true,m++;
			outDeg[u]++,inDeg[v]++;
		}
		printf("Case %d: ",t++);
		int cnt=0,st=-1;
		for(int i=1;i<=26&&st==-1;i++)
			if(vst[i]) st=i;
		if(st==-1) { printf("Poor boy!\n"); continue; }
		memset(vst,0,sizeof(vst));
		dfs(st,cnt);
		if(cnt!=m) { printf("Poor boy!\n"); continue; }
		bool f=true;
		int s=-1,t=-1,sum=0;
		for(int i=1;i<=26&&f;i++)
		{
			int val=inDeg[i]-outDeg[i];
			if(val%2)
			{
				if(val<0)
				{
					if(s==-1) s=i;
					else { f=false; break; }
				}
				else
				{
					if(t==-1) t=i;
					else { f=false; break; }
				}
			}
			else
			{
				if(val<0) Add_Edge(S,i,-val/2),sum+=-val/2;
				else if(val>0) Add_Edge(i,T,val/2);
			}
		}
		if(s!=-1&&t==-1) f=false;
		if(s==-1&&t!=-1) f=false;
		if(!f) { printf("Poor boy!\n"); continue; }
		if(s!=-1&&t!=-1)
		{
			Add_Edge(s,t,1);
			outDeg[s]++,inDeg[t]++;
			int val=inDeg[s]-outDeg[s];
			if(val<0) Add_Edge(S,s,-val/2),sum-=val/2;
			else if(val>0) Add_Edge(s,T,val/2);
			val=inDeg[t]-outDeg[t];
			if(val<0) Add_Edge(S,t,-val/2),sum-=val/2;
			else if(val>0) Add_Edge(t,T,val/2);
		}
		MaxFlow();
		if(flow==sum) printf("Well done!\n");
		else printf("Poor boy!\n");
	}
	return 0;
}