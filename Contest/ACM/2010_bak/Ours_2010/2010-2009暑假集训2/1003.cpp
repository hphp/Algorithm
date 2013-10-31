#include <stdio.h>
#include <vector>
#define N 2001 //结点总数 
#define E 2001*1001*4 //边数 
using namespace std;

struct Node
{
	int id;
	Node *next;
};
int tt;
Node edge[E];

struct Graph
{
	int pair;
	int n;
	Node node[N];
};

struct SC_Graph
{
	int n;
	bool sc_con[N][N];
//	vector <int> sc_next[N];
	vector <int> sc_contain[N];
};
SC_Graph sc_graph,re_sc_graph;

class Sat
{
	private:
		Graph re_graph,graph;
		int cnt,scnt;
		int belong[N];//to sign the bigger point which i belongs to;
		bool choose[N];//to sign whether the point is choosen
		//Inf inf[N]; special information;
		int post[N],rpost[N],pre[N];//the array is  used in the scr to record the preorder postorder of the visiting of the graph;
		int color[N];//the color we color to each point
		void init();//
		void add_edge(int,int);
		void dfs(Graph *,int);//to help complete scr;
		void scR();
		void re_build();
		bool judge();
		void topological_sort(SC_Graph *);
		void coloring(SC_Graph *);
		void dfs_color(int);
		void sorting(SC_Graph *,int);
		bool get_answer();
		void print();
	public:
		bool build();
		void solve();
};

int MAX(int a,int b)
{
	return a>b?a:b;
}

int MIN(int a,int b)
{
	return a<b?a:b;
}

void Sat::print(void)
{

}

bool Sat::get_answer(void)
{
	int count=0;
	for(int i=0;i<graph.n;i++)
		choose[i]=0;
	for(int i=0;i<graph.n;i++)
		if(color[belong[i]]==1)
		{
			choose[i]=1;
			count++;
		}
	if(count==graph.pair)
		return true;
		return false;	
}

void Sat::dfs_color(int cur)
{
	color[cur]=2;
	for(int j=0;j<re_sc_graph.n;j++)
	{
		if(sc_graph.sc_con[j][cur])
			if(color[j]==-1)
				dfs_color(j);
	}
}

void Sat::coloring(SC_Graph *g)
{
	for(int i=0;i<g->n;i++)
		color[i]=-1;
	for(int i=0;i<g->n;i++)
	{
		if(color[i]==-1)
		{
			color[i]=1;
			for(int j=0;j<sc_graph.sc_contain[i].size();j++)
			{
				int cur=sc_graph.sc_contain[i][j];
				int opsite=cur-1;
				if(cur%2==0)
					opsite=cur+1;
				if(color[belong[opsite]]==-1)
					dfs_color(belong[opsite]);
			}
		}
	}
}

void Sat::sorting(SC_Graph *g,int cur)
{
	pre[cur]=0;
	for(int i=0;i<g->n;i++)
	{
		if(i!=cur)
		if(sc_graph.sc_con[i][cur])
		{
			if(pre[i]==-1)
			{
				sorting(g,i);
			}
		}
	}
	post[cnt++]=cur;
}

void Sat::topological_sort(SC_Graph * g)
{
	int num=g->n;
	cnt=0;
	for(int i=0;i<num;i++)
		pre[i]=-1;
	for(int i=0;i<num;i++)
	{
		if(pre[i]==-1)
			sorting(g,i);
	}
}

bool Sat::judge(void)
{
	int num=graph.n;
	for(int i=0;i<num;i+=2)
	{
		if(belong[i]==belong[i+1])
			return 0;
	}
	return 1;
}

void Sat::dfs(Graph * g,int cur)
{
	pre[cur]=scnt;
	for(Node *tmp=g->node[cur].next;tmp!=NULL;tmp=tmp->next)
	{
		int next=tmp->id;
		if(pre[next]==-1)
			dfs(g,next);
	}
	post[cnt++]=cur;
}

void Sat::scR(void)
{
	for(int i=0;i<graph.n;i++)
	{
		pre[i]=-1;
		pre[i]=-1;
		cnt=0;
		scnt=0;
	}
	for(int i=0;i<graph.n;i++)
		if(pre[i]==-1)
			dfs(&re_graph,i);
	for(int i=0;i<graph.n;i++)
	{
		rpost[i]=post[i];
		pre[i]=-1;
	}
	cnt=0;
	scnt=0;
	for(int i=graph.n-1;i>=0;i--)
	{
		if(pre[rpost[i]]==-1)
		{
			dfs(&graph,rpost[i]);
			scnt++;
		}
	}
	re_sc_graph.n=sc_graph.n=scnt;
	for(int i=0;i<sc_graph.n;i++)
		(sc_graph.sc_contain[i]).clear();
	for(int i=0;i<graph.n;i++)
	{
		belong[i]=pre[i];
		(sc_graph.sc_contain[pre[i]]).push_back(i);
	}
}

void Sat::re_build(void)
{
	for(int i=0;i<sc_graph.n;i++)
		for(int j=0;j<sc_graph.n;j++)
			sc_graph.sc_con[i][j]=0;
	for(int i=0;i<graph.n;i++)
	{
		int belonged = belong[i];
		for(Node *tmp=graph.node[i].next;tmp!=NULL;tmp=tmp->next)
		{
			int next=belong[tmp->id];
			if(next!=belonged)
			{
				sc_graph.sc_con[belonged][next]=1;
			}
		}
	}
}

void Sat::solve(void)
{
	scR();
	int n;
	if(judge())
	{
		re_build();//to find the relations among new points;
		topological_sort(&sc_graph);//topological_sort();
		coloring(&sc_graph);// to color the one we choose;the one we won't choose will have an algorithm to delete;
		if(get_answer())//check whether we can get one
		{
			printf("YES\n");
			print();	
		}
		else printf("NO\n");
	}
	else // it can't get a 2SAT;because a contrary pair will be included 
	{
		printf("NO\n");	
	}
}

void Sat::add_edge(int a,int b)
{
	edge[tt]=graph.node[b];
	edge[tt].next=graph.node[a].next;
	graph.node[a].next=&edge[tt];
	tt++;
	edge[tt]=re_graph.node[a];
	edge[tt].next=re_graph.node[b].next;
	re_graph.node[b].next=&edge[tt];
	tt++;
}

void Sat::init(void)
{
	for(int i=0;i<graph.n;i++)
	{
		graph.node[i].next=NULL;
		graph.node[i].id=i;
		re_graph.node[i].next=NULL;
		re_graph.node[i].id=i;
	}
	tt=0;
}

bool Sat::build(void)
{
	int n;
	char sa[10],sb[10];
	scanf("%d",&n);
	graph.pair=n;
	graph.n=2*n;
	init();
	//build the graph, it is based on which point you must have if you choose one.
/*	for(int i=1;i<=n;i++)
	{
		scanf("%s%s%d",sa,sb,&inf[2*i-1].during);
		inf[2*(i-1)].during=inf[2*i-1].during;
		transfer(i,sa,sb);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				crossing(i,j);*/
	return 1;
}

int main()
{
	Sat sat;
	while(sat.build())
	{
		sat.solve();
	}
	return 0;
}
