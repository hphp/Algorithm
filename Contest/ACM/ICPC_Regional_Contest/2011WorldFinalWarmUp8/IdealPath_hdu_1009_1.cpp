#include <stdio.h>
#include <algorithm>
#include <map>
#define Min(a,b) ((a)<(b)?(a):(b))
//#include <queue>
using namespace std;
#define N 100100

struct Record
{
	int stp;
	int id;
	int frm;
	int c;
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
int n,m;

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
}
int vst[N];
void bfsinit()
{
	for(int i=0;i<=n;i++)
		vst[i] = 0 , mn[i] = (1<<28);
}

int bfs()
{
	bfsinit();
	int s = 0;
	int e = 1;
	
	queue[s].stp = 0;
	queue[s].id = 1;
	queue[s].frm = -1;
	queue[s].c = -1;
	mn[1] = 0;
	while(s < e)
	{
		int stp = queue[s].stp;
		int id = queue[s].id;
		if(vst[id])
		{
			s++;
			continue;
		}
		vst[id] = 1;
		for(Node *tmp = node[id].next ; tmp != NULL ; tmp = tmp->next)
		{
			int cur = tmp->id;
			if(stp + 1 < mn[cur])
			{
				mn[cur] = stp+1;
				queue[e].id = cur;
				queue[e].c = tmp->c;
				queue[e].frm = s;
				queue[e].stp = stp+1;
				if(cur == n)
					return e;
				e++;
			}
		}
		s++;
	}
}

void back(int lst)
{
	while(queue[lst].frm != -1)
	{
		rec[cnt++] = queue[lst].c;
		lst = queue[lst].frm;
	}
}

struct Edge
{
	int a,b,c;
}recc[N*2*2],ane[N*4];

bool cmp(Edge a , Edge b)
{
	if(a.a < b.a)
	return 1;
	if(a.a > b.a)
	return 0;
	if(a.b < b.b)
	return 1;
	if(a.b > b.b)
	return 0;
	if(a.c < b.c)
	return 1;
	return 0;
}

bool acmp(Edge a , Edge b)
{
	if(a.a < b.a)
		return 1;
		if(a.a > b.a)
			return 0;
	if(a.c < b.c)
		return 1;
		return 0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	int a,b,c;
	while(tc--)
	{
		scanf("%d%d",&n,&m);
		init();
//		map<Int,Node*> mp;
		int cc = 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a == b)continue;
			recc[cc].a = a;
			recc[cc].b = b;
			recc[cc].c = c;
			cc ++;
			recc[cc].a = b;
			recc[cc].b = a;
			recc[cc].c = c;
			cc ++;
/*			
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
			*/
		}
		
		sort(recc,recc+cc,cmp);
		
		int p = 0;
		int cp = 0;
		while(p < cc)
		{
			int a = recc[p].a;
			while(recc[p].a == a)
			{
				int b = recc[p].b;
				int c = recc[p].c;
				ane[cp].a = a;
				ane[cp].b = b;
				ane[cp].c = c;
				cp ++;
				int pp = p;
				while((recc[p].b == recc[pp].b) && (recc[p].a == a))pp++;
				p = pp;
			}
		}
		
		sort(ane,ane+cp, cmp);
		
		p = 0 ; 
		while(p < cp)
		{
			add_edge(ane[p].a,ane[p].b,ane[p].c);
			p ++;
		}
		
		
		int lst = bfs();
		cnt = 0;
		back(lst);
		printf("%d\n",cnt);
		for(int i=cnt-1;i>=0;i--)
		{
			printf("%d",rec[i]);
			if(i)printf(" ");
		}
		printf("\n");
	}
	return 0;
}
/*
2011-01-22 - 
16:00 - 16:10
想好了 准备写
16:40 写完 ，发现想法有问题
16:56 重新写完 调试
17:01 过掉样例，提交，比赛结束。 
*/
