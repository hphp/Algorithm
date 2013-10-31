#include <stdio.h>
#include <algorithm>
#include <map>
#define Min(a,b) ((a)<(b)?(a):(b))
//#include <queue>
using namespace std;
#define N 100100

struct Q
{
	int stp;
	int id;
	int c;
}queue[N],R[N];
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

void add_edge(int s,int b, int c)
{
	edge[tt].id = b;
	edge[tt].c = c;
	edge[tt].next = node[s].next;
	node[s].next = &edge[tt];
	tt ++;
}
int vst[N];
int same[N];
void bfsinit()
{
	for(int i=0;i<=n;i++)
		vst[i] = 0 , mn[i] = (1<<28) , same[i] = i;
}

int frm[N],cl[N];

bool bfscmp(Q a , Q b)
{
	if(a.c < b.c)
		return 1;
		return 0;
}
int pos[N];
void bfs()
{
	bfsinit();
	int s = 0 ; 
	int e = 1;
	queue[s].id = 1;
	queue[s].stp = 0;
	frm[1] = -1;
	same[1] = 1;
	mn[1] = 0 ;
	vst[1] = 1;
	while(s < e)
	{
		int id = queue[s].id;
		int stp = queue[s].stp;
		int cnt = 0;
		int cid = id;
		while((s < e) && (same[cid] == id))
		{
			//printf("%d\n",cid);
			for(Node * tmp = node[cid].next ; tmp != NULL ; tmp = tmp->next)
			{
				int nid = tmp->id;
				int c = tmp->c;
				if(vst[nid])continue;
				if(mn[nid] == stp + 1)
				{
					if(cl[nid] > c)
					{
						frm[nid] = cid;
						cl[nid] = c;
						R[pos[nid]].c = c;
					}
				}
				else if(mn[nid] > stp + 1)
				{
					mn[nid] = stp + 1;
					frm[nid] = cid;
					cl[nid] = c;
					pos[nid] = cnt;
					R[cnt].id = nid;
					R[cnt].c = c;
			//		printf("%d ",nid);
					cnt ++;
				}
			}
//			printf("\n");
			s ++;
			cid = queue[s].id;
		}
	//	printf("hi\n");
		sort(R,R+cnt,bfscmp);
		for(int i = 0 ;i < cnt ; i ++)
		{
			queue[e].id = R[i].id;
			vst[R[i].id] = 1;
			if(R[i].id == n)return;
			queue[e].stp = stp + 1;
			e ++;
			same[R[i].id] = R[i].id;
			if(i && (cl[R[i].id] == cl[R[i-1].id]))
				same[R[i].id] = same[R[i-1].id];
		}
	}
}
/*
void bfs()
{
	bfsinit();
	int s = 0;
	int e = 1;
	frm[1] = -1;
	Q q = {0,1,-1};
	priority_queue<Q> pq;
	pq.push(q);
	mn[1] = 0;
	while(!pq.empty())
	{
		Q cur = pq.top();
		pq.pop();
		int stp = cur.stp;
		int id = cur.id;
//		printf("%d %d %d\n",id,stp,cur.c);
		if(vst[id])
		{
			continue;
		}
		if(id == n)return;
		vst[id] = 1;
		for(Node *tmp = node[id].next ; tmp != NULL ; tmp = tmp->next)
		{
			int cur = tmp->id;
			if(stp + 1 < mn[cur])
			{
				mn[cur] = stp+1;
				frm[cur] = id;
				cl[cur] = tmp->c;
				Q tt = {stp+1,cur,cl[cur]};
			//	printf("%d ",cur);
				pq.push(tt);
				e++;
			}
		}
//		printf("\n");
	}
}
*/
int back(int lst)
{
	int cnt = 0;
	while(frm[lst] != -1)
	{
		rec[cnt++] = cl[lst];
		lst = frm[lst];
	}
	return cnt;
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
		int cc = 0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a == b)continue;
			add_edge(a,b,c);
			add_edge(b,a,c);
		}

		
		bfs();
		int cnt = back(n);
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

总共调了 近40分钟吧。呵呵。。。真是无语， 
-- 发现是思路错了，两种思路都有问题~
 
-- 22:24 AC AC  加速，加速，加速，红色，perfect 好喜欢呀好喜欢！
*/
/*
6 6 
1 2 1
1 3 1
2 4 4
3 5 5
5 6 1
4 6 10

6 8
1 2 1
1 3 1
2 4 2
3 4 1
2 5 3
3 5 1
4 6 10
5 6 50

6 10
1 2 1
1 3 1
2 4 2
3 4 1
2 5 3
3 5 1
4 6 10
5 6 50
2 5 1
5 6 2
*/
