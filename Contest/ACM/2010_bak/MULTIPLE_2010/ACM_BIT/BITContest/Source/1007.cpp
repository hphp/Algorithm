#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define maxn 250
#define inf 1000000000
int map[maxn][maxn],flow[maxn][maxn],value[maxn][maxn];
int FindPath(int map[][maxn],int flow[][maxn],int n,int *pre)
{
	int q[maxn];
	int visit[maxn];
	memset(q,0,sizeof(q));
	memset(visit,0,sizeof(visit));
	int head=0;
	int tail=1;
	q[head]=0;
	pre[0]=-1;
	int flag=0;
	int min=inf;
	while(head<tail)
	{
		if(q[head]==n-1)
		{
			flag=1;
			break;
		}
		int t=q[head];
		for(int i=0;i<n;i++)
		{
			if(flow[t][i]<map[t][i]&&!visit[i])
			{
				visit[i]=1;
				pre[i]=t;
				q[tail++]=i;
			}
		}
		head++;
	}
	return flag;
}
int Edmond_Karp(int map[][maxn],int flow[][maxn],int n)
{
	int maxflow=0;
	int pre[maxn];
	while(FindPath(map,flow,n,pre))
	{
		int s=n-1;
		int min=inf;
		while(s!=0)
		{
			if(min>map[pre[s]][s]-flow[pre[s]][s])
				min=map[pre[s]][s]-flow[pre[s]][s];
			s=pre[s];
		}
		s=n-1;
		while(s!=0)
		{
			flow[pre[s]][s]+=min;
			flow[s][pre[s]]-=min;
			s=pre[s];
		}
		maxflow+=min;
		memset(pre,0,sizeof(pre));
	}
	return maxflow;
}

int rank[maxn];
int set[maxn];
typedef struct 
{
	int start;
	int end;
	int value;
	int capablity;
}E;
E road[5120];
bool comp(const E a,const E b)
{
	double rate1,rate2;
	rate1=(double)a.capablity/a.value;
	rate2=(double)b.capablity/b.value;
	return rate1>rate2;
}
void MakeSet(int n)
{
	for(int i=0;i<n+1;i++)
		set[i]=i;
}
int Find(int x)
{
	if(set[x]!=x)
		set[x]=Find(set[x]);
	return set[x];
}
void Union(int a,int b)
{
	int seta,setb;
	seta=Find(a);
	setb=Find(b);
	if(seta==setb)
		return;
	if(rank[seta]>rank[setb])
		set[setb]=seta;
	else
	{
		set[seta]=setb;
		if(rank[seta]==rank[setb])
			rank[setb]++;
	}
}
void Krustal(int r,int n)
{
	int a,b;
	MakeSet(n);
	int count=0;
	for(int i=0;i<r;i++)
	{
		a=road[i].start;
		b=road[i].end;
		if(Find(a)!=Find(b))
		{
			if((double)road[i].capablity/road[i].value>(double)map[a][b]/value[a][b])
			{
				map[a][b]=road[i].capablity;
				value[a][b]=road[i].value;
				map[b][a]=road[i].capablity;
				value[b][a]=road[i].value;
				Union(a,b);count++;
			}
		}
	}
}
int Connected(int n)
{
	int x=Find(1);
	for(int i=2;i<n+1;i++)
		if(x!=Find(i))
			return 0;
	return 1;
}
int main()
{
	bool flag[maxn];
	int n,m,s,v,t,r;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	int super[maxn];
	while(t--)
	{
		memset(value,0x77,sizeof(value));
		memset(map,0,sizeof(map));
		memset(flow,0,sizeof(flow));
		memset(flag,false,sizeof(flag));
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&s,&v);
			map[0][s]=v;
			super[i]=s;
			flag[s]=true;
		}//最大流多汇点建模
		for(int i=1;i<=n;i++)
			if(!flag[i])
				map[i][n+1]=inf;
		scanf("%d",&r);
		for(int i=0;i<r;i++)
			scanf("%d%d%d%d",&road[i].start,&road[i].end,&road[i].capablity,&road[i].value);
		sort(road,road+r,comp);
		Krustal(r,n);
		if(!Connected(n))
		{
			printf("No\n");
			continue;
		}
		Edmond_Karp(map,flow,n+2);
		int flag=0;
		for(int i=0;i<m;i++)
			if(flow[0][super[i]]<map[0][super[i]])
			{
				flag=1;
				break;
			}
			if(flag)
				printf("No\n");
			else
				printf("Yes\n");
	}
	return 0;
}