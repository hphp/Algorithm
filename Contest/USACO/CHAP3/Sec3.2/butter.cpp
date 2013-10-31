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

int main() {
    ofstream fout ("butter.out");
    ifstream fin ("butter.in");
    
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

/*	for(int i=1;i<=p;i++)
	{
		for(Node * tmp = node[i].next ; tmp != NULL ; tmp = tmp->next)
			fout << tmp->id << " ";
		fout << endl;
	}
*/
	
	for(int i=1;i<=p;i++)
	{
		for(Node * tmp = node[i].next ; tmp != NULL; tmp = tmp->next)
		{
			int a = tmp->id;
			int vai = dis[a][i];
			for(Node * tmp2 = node[i].next ; tmp2 != NULL; tmp2 = tmp2->next)
			{
				int b = tmp2->id;
				int vbi = dis[b][i];
				if(dis[a][b] == MAX)
				{
					add_edge(a,b,vai+vbi);
				}
				dis[a][b] = Min(dis[a][b],vai+vbi);
			}
		}
	}
/*
	for(int i=1;i<=p;i++)
	{
		for(int j=1;j<=p;j++)
			fout << dis[i][j] << " ";
		fout << endl;	
	}
*/
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
7:24-
*/
