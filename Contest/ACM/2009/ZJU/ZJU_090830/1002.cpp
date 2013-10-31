#include <stdio.h>
#include <stdlib.h>
#define N 2100

int grid[N][N];

struct Node
{
	int id;
	Node * next;
}edge[100000];
int tt;
int son[N];

struct Graph
{
	Node node[N];
	int sc[N];
}*G,*reG;
int n,cnt0,cnt1;

int post[N],postR[N],part;
int pre[N],ans,con[N][N];

void init(void)
{
	tt=0;
	for(int i=0;i<n;i++)
	{
		(G->node[i]).next=NULL;
		(reG->node[i]).next=NULL;
	}
}

void SCdfs(Graph * G,int cur)
{
	G->sc[cur]=cnt1;
	for(Node *temp = (G->node[cur]).next;temp!=NULL;temp=temp->next)
	{
		int id = temp->id;
		if(G->sc[id]==-1)	
			SCdfs(G,id);
	}
	post[cnt0++]=cur;
}

void Graphsc()
{
	cnt0 = 0;
	cnt1 = 0;
	for(int i=0;i<n;i++)
		reG->sc[i]=-1;
	for(int i=0;i<n;i++)
		if(reG->sc[i]==-1)
			SCdfs(reG,i);
	cnt0 = 0;
	cnt1 = 0;
	for(int i=0;i<n;i++)
		G->sc[i]=-1;
	for(int i=0;i<n;i++)
		postR[i]=post[i];
	for(int i = n-1;i>=0;i--)
		if(G->sc[postR[i]]==-1)	
		{
			SCdfs(G,postR[i]);
			cnt1++;
		}
	part = cnt1;
}


void dfs(int curid)
{
	for(int i=0;i<part;i++)
		if(con[curid][i]==1&&curid!=i)
		{
		//printf("shit\n");
			if(pre[i]==-1)
			{
				//printf("%d %d\n",curid,i);
				ans++;
				pre[i]=1;
				dfs(i);
			}
		}	
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
	//	scanf("%d",&n);
		G = (Graph *)malloc(sizeof(Graph));
		reG = (Graph *)malloc(sizeof(Graph));
		init();
		for(int i=0;i<n;i++)	
		{
			for(int j=0;j<n;j++)	
			{
				scanf("%d",&grid[i][j]);
				if(i==j)
					grid[i][j]=0;
				if(grid[i][j]==1)
				{
					edge[tt].id = j;
					edge[tt].next = (G->node[i]).next;
					(G->node[i]).next = &edge[tt];
					tt++;
					edge[tt].id = i;
					edge[tt].next= (reG->node[j]).next;
					(reG->node[j]).next = &edge[tt];
					tt++;
				}
			}
		}
/*		for(int i=0;i<tt;i++)
			printf("%d\n",edge[i].id);*/
/*		for(int i=0;i<n;i++)
		{
			for(Node *temp = (G->node[i]).next;temp!=NULL;temp=temp->next)
				printf("*%d*",temp->id);
				printf("\n");
		}*/
		Graphsc();
		for(int i=0;i<part;i++)
			son[i]=0;
		for(int i=0;i<n;i++)
		{
			son[G->sc[i]]++;
		}
		int sum = 0; 
		for(int i=0;i<part;i++)
			if(son[i]>1)
			sum += son[i];
		for(int i=0;i<n;i++)
			pre[i]=-1;
		for(int i=0;i<part;i++)
			for(int j=0;j<part;j++)
				con[i][j]=0;
		ans = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(grid[i][j]==1)
				{
					con[G->sc[i]][G->sc[j]]=1;
		//			printf("*%d %d %d %d)\n",i,j,G->sc[i],G->sc[j]);
				}
		for(int i =0;i<part;i++)
			if(pre[i]==-1)
				dfs(i);
	//	printf("%d %d\n",sum,ans);
			printf("%d\n",sum+ans);
		/*sort(node,node+n,cmp);
		for(int i=0;i<n;i++)
		{
			int id = node[i].id;
			dfs(id);
		}*/
	}
	return 0;
}
