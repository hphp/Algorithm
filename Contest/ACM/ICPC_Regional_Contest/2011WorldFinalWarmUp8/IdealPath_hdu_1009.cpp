#include <stdio.h>
#include <map>
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
#define N 100100

struct Queue
{
	int stp;
	int id;
	int frm;
}queue[N];
int mn[N];
struct Node
{
	int id;
	int c;
	Node *next;
}node[N],edge[4*N];
int tt = 0;

int rec[N];int cnt;

void init()
{
	for(int i=0;i<=n;i++)
		node[i].next = NULL;
		tt = 0;
}

void add_node(int s,int b, int c)
{
	edge[tt].id = b;
	edge[tt].c = c;
	edge[tt].next = node[s].next;
	node[s].next = &edge[tt];
	tt ++;
	return node[s].next;
}

void bfs()
{
	int s = 0;
	int e = 1;
	queue[s].stp = 0;
	queue[s].id = 1;
	queue[s].frm = -1;
	mn[1] = 0;
	while(s < e)
	{
		int stp = queue[s].stp;
		int id = queue[s].id;
		for(Node *tmp = node[id].next ; tmp != NULL ; tmp = tmp->next)
		{
			int cur = tmp->id;
			if(stp +1 == mn[cur])
			{
				int c = 
			}
			if(stp + 1 < mn[cur])
			{
				mn[cur] = stp+1;
				queue[e].id = cur;
				queue[e].frm = s;
				queue[e].stp = stp+1;
				e++;
			}
		}
	}
}

int main()
{
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&n,&m);
		init();
		map<Int,Node*> mp;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a == b)continue;
			Int cur = a * N + b;
			Int acur = b*N + a;
			if(mp[cur] == NULL)
			{
				mp[cur] = add_node(a,b,c);
				mp[acur] = add_node(b,a,c);
			}
			else
			{
				mp[acur]->c = mp[cur]->c = Min(mp[cur]->c,c);
			}
		}
		int lst = bfs();
		back(lst);
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++)
		{
			if(i)printf(" ");
			printf("%d",rec[i]);
		}
	}
	return 0;
}
