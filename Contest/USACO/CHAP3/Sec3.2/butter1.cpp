/*
ID: hanjiatong1
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#define P 810
#define N 510
#define C 100500
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;

struct Pasture
{
	int id;
	int dis;
};
	bool operator< (const Pasture& p1,const Pasture& p2)
	{
		return p1.dis > p2.dis;	
	}

struct Node
{
	int id;
	int v;
	Node * next;	
}node[P],edge[C*2];
int tt;
Node* pt[P][P];
int dis[P][P];
int p,n,c;
int home[N];

void init()
{
	tt = 0;
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=p;j++)
			pt[i][j] = NULL, dis[i][j] = MAX;	
		node[i].next = NULL;
		dis[i][i] = 0;
	}	
}

Node * add_edge(int a, int b ,int c)
{
	edge[tt].id = b;
	edge[tt].v = c;
	edge[tt].next = node[a].next;
	node[a].next = &edge[tt];
	tt++;
	return node[a].next;
}
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
int vst[P],mndis[P];
void SSSP(int st)
{
	for(int i=1;i<=p;i++)
	{
		vst[i] = 0 ;
		mndis[i] = MAX;
	}
	mndis[st] = 0;
	priority_queue<Pasture> pq;
	Pasture pst1 = {st,0};
	pq.push(pst1);
	while(!pq.empty())
	{
		Pasture pst2 = pq.top();
		pq.pop();
		int cur = pst2.id;
		if(vst[cur])continue;
		vst[cur] = 1;
		int v = pst2.dis;
	//	fout << "hei" << cur << " " << v << endl;
		for(Node * tmp = node[cur].next;tmp!=NULL;tmp=tmp->next)
		{
			int id = tmp->id;
		//	fout << "hello" << id << " " << dis[st][id] << " " << v + dis[cur][id] <<endl;
			if(v + dis[cur][id] < mndis[id])
			{
				mndis[id] = v + dis[cur][id];
				Pasture pp = {id,mndis[id]};
				pq.push(pp);
			}
		}
	}
	for(int i=1;i<=p;i++)
		dis[st][i] = mndis[i];
}

int main() {
    
    fin >> n >> p >> c;
    
    init();
    
    for(int i=1;i<=n;i++)
    {
		fin >> home[i];	
	}
	for(int i=0;i<c;i++)
	{
		int a,b,cc;
		// sc 了， 又多定义了一个c，结果此循环就是进入不了。。 
		fin >> a >> b >> cc;	
		pt[a][b] = add_edge(a,b,cc);
		pt[b][a] = add_edge(b,a,cc);
		dis[a][b] = dis[b][a] = cc;
	}
	for(int i=1;i<=n;i++)
		SSSP(home[i]);
	int mn = MAX;
    for(int i=1;i<=p;i++)
    {
		int sum =0;
		for(int j=1;j<=n;j++)
		{
			int np = home[j];
			sum += dis[np][i];
		}
		mn = Min(mn,sum);
	}
	fout << mn << endl;
    return 0;
}
/*
2010-09-09
7:24-8:22
第0个想法被我扼杀在摇篮里。武断的认为时间复杂度太高 
第一个想法搁浅。 
期间一直在和xiaoz探讨我的学习状况 
9:14-9:49
第0个想法再次验证，证明是对的我靠。
。。。
恩 对基础问题：单源最短路的时间复杂度了解太少。 
*/
