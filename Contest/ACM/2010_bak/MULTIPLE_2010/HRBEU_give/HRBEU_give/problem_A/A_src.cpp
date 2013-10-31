#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;
const int inf=9999999;
const int N=510;
struct Node
{
	int id,flow;
	Node *next;
};
Node node[N],edge[1000000],*mat[N],*out[N];
int level[N],que[N],path[N];
bool vis[N];
int S,T,edge_n;
void initial(int N)
{
	for(int i=0;i<=N;i++)
		node[i].next=NULL;
	edge_n=0;
}
void addedge(int fr,int to,int flow)
{
	edge[edge_n].id=to;
	edge[edge_n].flow=flow;
	edge[edge_n].next=node[fr].next;
	node[fr].next=&edge[edge_n];
	edge_n++;
	edge[edge_n].id=fr;
	edge[edge_n].flow=0;
	edge[edge_n].next=node[to].next;
	node[to].next=&edge[edge_n];
	edge_n++;
}
bool maxflowlevel()
{
	for(int i=0;i<N;i++)
		level[i]=-1;
	level[S]=1;
	int front=1,rear=1;
	que[1]=S;
	while(front<=rear)
	{
		int v=que[front++];
		for(Node *temp=node[v].next;temp;temp=temp->next)
		{
			int id=temp->id,flow=temp->flow;
			if(flow>0&&level[id]==-1)
			{
				level[id]=level[v]+1;
				que[++rear]=id;
				if(id==T) return true;	
			}	
		}
	}
	return false;
}
Node *reverse(Node *pp)
{
	return ((pp-edge)^1)+edge;
}
int maxflow()
{
	int ans=0,pos=0;
	while(maxflowlevel())
	{
		int v=S;
		pos=0;
		for(int i=0;i<N;i++)
			out[i]=node[i].next,vis[i]=false;
		path[++pos]=S;vis[S]=true;
		while(pos)
		{
			if(path[pos]==T)
			{
				int maxt=inf;
				for(int i=1;i<pos;i++)
					maxt=min(maxt,mat[path[i]]->flow);
				ans+=maxt;
				int pt;
				for(int i=1;i<pos;i++)
				{
					mat[path[i]]->flow-=maxt;
					reverse(mat[path[i]])->flow+=maxt;
					if(mat[path[i]]->flow==0)
						pt=i;	
				}
				pos=pt;
			}
			else
			{
				bool flag=true;
				int x=path[pos];
				for(Node *temp=out[x];temp;temp=temp->next)
				{
					int id=temp->id,flow=temp->flow;
					if(!vis[id]&&level[id]==level[x]+1&&flow>0)
					{
						out[x]=temp->next;
						mat[x]=temp;
						path[++pos]=id;
						flag=false;
						break;	
					}
				}
				if(flag)
				{
					vis[x]=true;
					pos--;
				}
			}	
		}
	}
	return ans;
}
bool readIn()
{
	int N,M;
	if(scanf("%d%d",&N,&M)==EOF)
		return false;
	S=0,T=N+1;
	initial(T);
	int a,b,c;
	for(int i=1;i<=N;i++)
		scanf("%d",&a),addedge(S,i,a);
	for(int i=1;i<=N;i++)
		scanf("%d",&a),addedge(i,T,a);	
	for(int i=1;i<=M;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		addedge(a,b,c);
		addedge(b,a,c);	
	}
	return true;
}
int main()
{
	//int now = clock();
	freopen("A_in.in","r",stdin);
	freopen("A_out.out","w",stdout);
	while(readIn())
	{
		printf("%d\n",maxflow());
	}
	//printf("%dms\n",clock()-now);
}
