#include <stdio.h>
#include <map>
#define Min(a,b) ((a)<(b)?(a):(b))
#include <queue>
using namespace std;
#define N 100100

struct Record
{
	int stp;
	int id;
	int c;
	int frm;
};
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

bool operator < (Record a , Record b)
{
	if(a.stp < b.stp)
		return 1;
		if(a.stp > b.stp)
			return 0;
	if(a.c < b.c)
		return 1;
	return 0;
}

void bfs()
{
	int s = 0;
	int e = 1;
	Record r = Record{0,1,-1,-1};
	priority_queue<Record> pq;
	while(!pq.empty())
	{
		Record r = pq.top();
		pq.pop();
		int stp = r.stp;
		int id = r.id;
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
