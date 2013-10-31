#include <stdio.h>
#define N 2010
#define MAX (1<<28)

struct Node
{
	int s,e;
	int v;
}node[N];

int con[N][N];
int mn[N];
int flag[N];
int a,n,m;

void spa(int st)
{
	for(int j=0;j<=n;j++)	
	{
		mn[j] = MAX;
		flag[j] = -1;
	}
	mn[st] = node[st].v;
	int min = st;
	int cur = st;
	while(cur != 0)
	{
		flag[cur] = 1;
		min = cur;
		cur = 0;
		for(int j=1;j<=n;j++)
		{
			if(flag[j] == -1)
			{
				if(mn[min] < MAX && con[min][j] && mn[min] + node[j].v < mn[j])
				{
					mn[j] = mn[min] + node[j].v;
				}
				if(mn[j] < mn[cur])
					cur = j;
			}
		}
	}
}

void node_init()
{
	for(int i=0;i<=n;i++)
		for(int j =0;j<=n;j++)
			con[i][j] = 0;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		node_init();
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&node[i].s,&node[i].e,&node[i].v);
			for(int j=1;j<i;j++)
			{
				if(node[j].e >= node[i].s && node[j].e <= node[i].e)
					con[j][i] = 1;
			}
		}
		spa(1);
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);
			if(mn[a] == MAX)
				mn[a] = -1;
			printf("%d\n",mn[a]);
		}
	}
	return 0;
}
