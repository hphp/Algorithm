#include <stdio.h>
#include <math.h>
#define N 20100
#define Min(a,b) (D[a]<D[b]?a:b)
#define Max(a,b) (a>b?a:b)
#define P 200

int rmq[2*N][P];
int E[2*N],R[N],D[N],Ecnt; 
int tsroot[N];
struct Node
{
    int id;
    int dis;
    Node *next;
}node[N],edge[4*N];
int tt;
int n;
int leaf[N],lnum; 

void dfs(int curid,int deep,int len)
{
	E[Ecnt]=curid;
	R[curid]=Ecnt;
	D[curid]=deep;
	tsroot[curid]=len;
	Ecnt++;
	int flag=0; 
	for(Node *temp = node[curid].next;temp!=NULL;temp=temp->next)
	{
		int id=temp->id;
		int dis=temp->dis;
		if(R[id]==-1)
		{
			flag=1; 
			dfs(id,deep+1,len+dis);
			E[Ecnt]=curid;
			Ecnt++;
		}	
	}
	if(flag==0)
	{
		leaf[lnum]=curid;	
		lnum++;
	} 
}

void ST_prepro(void)
{
	for(int i=0;i<Ecnt;i++)
	{
		rmq[i][0]=E[i];	
	}
	int lim= (int)(log(Ecnt*1.0)/log(2.0));
	for(int i=1;i<=lim;i++)
	{
		for(int j=0;j<Ecnt;j++)
		{
			int next=j+(1<<i);
			if(next>Ecnt)
				break;
			int temp = j+(1<<(i-1));
			rmq[j][i]= Min(rmq[j][i-1],rmq[temp][i-1]);	
		}	
	}
}

void init(void)
{
	for(int i=0;i<=n;i++)
	{
		node[i].next=NULL;
		R[i]=-1;
	}
	lnum=0; 
	tt=0;
	Ecnt=0;	
} 

int Lca(int start,int to)
{
	int k = (int)(log((to-start+1)*1.0)/log(2.0));
	int temp = Min(rmq[start][k],rmq[to-(1<<k)+1][k]);
	return temp;
}

struct Ans
{
	int a;
	int b;
	int dis;	
};

Ans check(int s,int t)
{
	if(s==t)
	{
		Ans t= {leaf[s],leaf[s],0};
		return t;	
	}
	if(s>t)
	{
		Ans t={1,1,0};
		return t;
	}
	int mid=(s+t)/2;
	Ans A = check(s,mid);
	Ans B = check(mid+1,t);
	int a[5];
	int maxmax=Max(A.dis,B.dis);
	Ans T=A;
	if(A.dis<B.dis)
		T=B;
	Ans ans=T;
	 a[0]= A.a;	 a[1]=A.b;	 a[2]=B.a;	 a[3]=B.b;	
	 for(int i=0;i<2;i++)
	 {
			for(int j=2;j<4;j++)
			{
				if(i!=j);
				else continue;
				int start = R[a[i]]<R[a[j]]?R[a[i]]:R[a[j]];
				int to = R[a[i]]>R[a[j]]?R[a[i]]:R[a[j]];
				int lca = Lca(start,to);
				int curdis = tsroot[a[i]]+tsroot[a[j]]-2*tsroot[lca];
				if(curdis>maxmax)
				{
					ans.a=a[i];
					ans.b=a[j];
					ans.dis=curdis;
					maxmax=curdis;
				}
			}	
		}
	return ans;
} 

int main()
{
	for(int i=0;i<2*N;i++)
		edge[i].next=NULL;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
		init();
		for(int i=1;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);	
			edge[tt].id=b;
			edge[tt].dis=c;
			edge[tt].next=node[a].next;
			node[a].next=&edge[tt];
			tt++;
			edge[tt].id=a;
			edge[tt].dis=c;
			edge[tt].next=node[b].next;
			node[b].next=&edge[tt];
			tt++;
		}	
		dfs(1,0,0);
		if(lnum==1)
		{
			printf("%d\n",tsroot[leaf[0]]);
			continue;
		}
		ST_prepro();
		/*for(int i=0;i<lnum;i++)
			printf("%d ",leaf[i]);*/
		Ans ans = check(0,lnum-1);
		//printf("%d %d\n",ans.a,ans.b);
		printf("%d\n",ans.dis) ;
	}	
	return 0; 
}
