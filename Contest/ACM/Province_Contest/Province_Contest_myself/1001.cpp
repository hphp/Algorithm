#include <stdio.h>
#define MAX 4000010
#define N 10010

struct Node
{
	int id;
	int vl;
	Node *next;
}node[N],edge[2*N];
int pre[N];
int prime[MAX],n,count,tt;

void init(void)
{
	for(int i=1;i<=n;i++)
	{
		pre[i]=-1;
		node[i].id=i;
		node[i].next=NULL;
	}
	tt=0;
		count=0;
}

int dfs(int cur)
{
	pre[cur]=1;
	int max=0;
	for(Node *tmp=node[cur].next;tmp!=NULL;tmp=tmp->next)
	{
		int id=tmp->id;
		if(pre[id]!=1)
		{
			int temp=dfs(id);
			if(max<temp)
				max=temp;
		}
	}
	if(prime[node[cur].vl]==1)
		return MAX;
	else
	{
		if(max<node[cur].vl)
		{
			count++;
	//		printf("%d %d\n",cur,max);
			return node[cur].vl;
		}
		else return max;
	}
}

void booling(void)
{
	int half=MAX/2;
	int temp;
	for(int i=2;i<half;i++)
		if(prime[i]==0)	
			for(int j=2;(temp=i*j)<MAX;j++)
				prime[temp]=1;
}

int main()
{
	booling();
/*	for(int i=0;i<10;i++)
		if(prime[i]==0)
			printf("%d ",i);
			printf("\n");*/
	int a,b;
	int test=1;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i=1;i<=n;i++)
			scanf("%d",&node[i].vl);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			edge[tt].id=b;
			edge[tt].next=node[a].next;
			node[a].next=&edge[tt];
			tt++;
			edge[tt].id=a;
			edge[tt].next=node[b].next;
			node[b].next=&edge[tt];
			tt++;
		}
		dfs(1);
		printf("Scenario #%d\n%d\n\n",test++,count);
	}
	return 0;
}
