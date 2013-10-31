#include <stdio.h>
#include <math.h>
#define N 10100
#define P 210
struct Node
{
	int id;
	int value;
	Node * adj;
}node[N],edge[2*N];
int tt;
int belong[N];
__int64 tsroot[N];
int part,root[N];
int n,m;

int E[N*2],R[N],D[N],Ecnt,sum;
int rec_LCA[P][P],rmq[N][P];
int area,anum;

void Rmq_init(void)
{
	for(int i=0;i<=area;i++)
		for(int j=0;j<=area;j++)
			rec_LCA[i][j]=-1;
}

int Rmq(int part,int from,int to)
{
	if(rec_LCA[from][to]!=-1)
		return rec_LCA[from][to];
	if(from==to)
	{
		rec_LCA[from][to]=E[from+part*area];
	//	printf("%d %d %d\n",from,part,rec_LCA[from][to]);
		return rec_LCA[from][to];
	}
	else
	{
		int mid = (from+to)/2;
		int a=Rmq(part,from,mid);
		int b=Rmq(part,mid+1,to);
/*		if(R[a]==-1)
			R[a]=N*2;
		if(R[b]==-1)
			R[b]=N*2;*/
		int c = D[a]<D[b]?a:b;
		rec_LCA[from][to]=c;
		return rec_LCA[from][to];
	}
}

int LCA_get(int from,int to,int curpart)
{
	Rmq_init();
	int pf=from/area;
	int pt=to/area;
	if(pf==pt)
	{
		int absp=from;
		return Rmq(pf,from%area,to%area);
	}
	else
	{
		from=from%area;
		to=to%area;
		int minmin=n+1;
		D[minmin]=Ecnt;
		for(int i=pf+1;i<pt;i++)
			if(D[minmin]>D[rmq[curpart][i]])
				minmin=rmq[curpart][i];
		int temp = Rmq(pf,from,area-1);
		if(D[temp]<D[minmin])
			minmin=temp;
		Rmq_init();
		temp=Rmq(pt,0,to);
		if(D[temp]<D[minmin])
			minmin=temp;
		return minmin;
	}
}

void f_init(void)
{
	for(int i=0;i<=n;i++)
	{
		R[i]=-1;
		D[i]=Ecnt;
	}
	Ecnt=0;
	sum=0;
}

void LCA_dfs(int curroot,int deep)
{
	E[Ecnt]=curroot;
	R[curroot]=Ecnt;
	D[curroot]=deep;
	Ecnt++;
	for(Node *temp=node[curroot].adj;temp!=NULL;temp=temp->adj)
	{
		int id = temp->id;
		if(R[id]==-1)
			LCA_dfs(id,deep+1);
		E[Ecnt]=curroot;
		Ecnt++;
	}
}

void LCA_deal(int curpart)
{
	f_init();
	LCA_dfs(root[curpart],0);
/*	for(int i=0;i<Ecnt;i++)
		printf("%d ",E[i]);
	printf("e above\n");
	for(int j=1;j<=n;j++)
		printf("%d ",R[j]);
		printf("r above\n");*/
	area=(int)sqrt(1.0*Ecnt);
	anum=Ecnt/area+(Ecnt%area!=0);
	for(int i=0;i<anum;i++)
	{
		Rmq_init();
		int last=i*area+area-1;
		while(last>=Ecnt)
			last--;
		//printf("%d\n",last);
		rmq[curpart][i]=Rmq(i,0,last%area);
	//	printf("rmq%d\n",rmq[curpart][i]);
	}
}

void init(void)
{
	for(int i=0;i<=n;i++)
		belong[i]=-1;
		part=0;
	for(int i=0;i<=n;i++)
		node[i].adj=NULL;
		tt=0;
}

void dfs(int cur,__int64 len)
{
	belong[cur]=part;
	tsroot[cur]=len;
	for(Node *temp=node[cur].adj;temp!=NULL;temp=temp->adj)
	{
		int next=temp->id;
		if(belong[next]==-1)
		dfs(next,len+temp->value);
	}
}

int routing(int a,int b)
{
	f_init();
	LCA_dfs(root[belong[a]],0);
	area=(int)sqrt(1.0*Ecnt);
	anum=Ecnt/area+(Ecnt%area!=0);
	int pa=R[a];
	int pb=R[b];
	int minner=pa<pb?pa:pb;
	int maxxer=pa>pb?pa:pb;
	return LCA_get(minner,maxxer,belong[a]);
}

int main()
{
	int request;
	while(scanf("%d%d%d",&n,&m,&request)!=EOF)
	{
		int a,b,c;
		init();
		for(int i=0;i<m;i++)	
		{
			scanf("%d%d%d",&a,&b,&c);
			edge[tt].id=b;
			edge[tt].value=c;
			edge[tt].adj=node[a].adj;
			node[a].adj=&edge[tt];
			tt++;
			edge[tt].id=a;
			edge[tt].value=c;
			edge[tt].adj=node[b].adj;
			node[b].adj=&edge[tt];
			tt++;
		}
		for(int i=1;i<=n;i++)
		{
			if(belong[i]==-1)	
			{
		//		part++;
				root[part]=i;
				dfs(i,0);
				part++;
			}
		}
		for(int i=0;i<part;i++)
		//{
			LCA_deal(i);
			//for(int j=0;j<)
		/*for(int i=1;i<=n;i++)
			printf("%d ",belong[i]);
			printf("\n");*/
		for(int i=0;i<request;i++)
		{
			scanf("%d%d",&a,&b);
			if(belong[a]==belong[b])
			{
				int curlca = routing(a,b);
	//			printf(")
				__int64 ans = tsroot[a]-tsroot[curlca]+tsroot[b]-tsroot[curlca];
				printf("%I64d\n",ans);
			}
			else printf("Not connected\n");
		}
	}
	return 0;
}
