#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#define N 10*10*11
#define M 12
#define S 30

using namespace std;

struct Person
{
	int big,small;
	char name[S];
}ps[N];


struct Node
{
	int id;
	Node * ifr;
	Node * bhd;
}node[N];

Node * lb[M];
Node * ls[M][M];
Node * head;
Node * tail;
int n,m[M],q,p;
int cnt;

bool cmpByName(Person a, Person b)
{
	if(strcmp(a.name,b.name)<0)
		return 1;
	else if(strcmp(a.name,b.name)>0)
		return 0;
		return 0;
/*	if(a.big < b.big)
		return 1;
	else if(a.big > b.big)
		return 0;
	if(a.small < b.small)
		return 1;
		return 0;*/
}

int find(char name[])
{
	int s = 0;
	int e =  cnt-1;
	while(s <= e)
	{
		int mid = (s+e)/2;
//		printf("mid : %d)",mid);
		if(strcmp(ps[mid].name,name)==0)
			return mid;
		if(strcmp(ps[mid].name,name) < 0)
			s = mid+1;
		else e = mid-1;
	}
	return -1;
}

void insert(int id)
{
	int big = ps[id].big;
	int small = ps[id].small;
//	printf("%d %d\n",big,small);
	if(ls[big][small]!=NULL)
	{
		Node * next = ls[big][small]->bhd;
		Node * frt = ls[big][small];
		node[id].ifr = frt;
		node[id].bhd = next;
		if(next != NULL)
			next->ifr = & node[id];
		frt->bhd = &node[id];
		ls[big][small] = &node[id];
		lb[big] = & node[id];
		if(node[id].bhd == NULL)
		{
			tail = & node[id];	
		}
		return ;
	}
	else if(lb[big] != NULL)
	{
		Node * next = lb[big]->bhd;
		Node * frt = lb[big];
		node[id].ifr = frt;
		node[id].bhd = next;
		if(next != NULL)
			next->ifr = & node[id];
		frt->bhd = & node[id];
		ls[big][small] = & node[id];
		lb[big] = & node[id];
		if(node[id].bhd == NULL)
		{
			tail = &node[id];	
		}
		return ;
	}
	else
	{
		if(head == NULL)
		{
			head = & node[id];
			tail = & node[id];
			ls[big][small] = & node[id];
			lb[big] = & node[id];
		}
		else
		{
			node[id].ifr = tail;
			tail->bhd = &node[id];
			tail = &node[id];
			ls[big][small] = & node[id];
			lb[big] = & node[id];
		}
	}
}

void out(int num)
{
	int cc = 0;
	Node * tmp = head;
	while(cc < num)
	{
		tmp = head;
		printf("%s\n",ps[head->id].name);
		cc ++;
		Node * next = tmp->bhd;
		if(next != NULL)
		{
			int tb = ps[tmp->id].big;
			int ts = ps[tmp->id].small;
			int nb = ps[next->id].big;
			int ns = ps[next->id].small;
			if(lb[tb] == tmp)
			{
				if(nb != tb)
				{
					lb[tb] = NULL;
				}
				else
				{
					lb[tb] = next;
				}
			}
			if(ls[tb][ts] == tmp)
			{
				if(ns != ts)
				{
					ls[tb][ts] = NULL;	
				}
				else
				{
					ls[tb][ts] = next;
				}
			}
			next->ifr = NULL;
		}
		tmp->ifr = NULL;
		tmp->bhd = NULL;
		head = next;
	}
}

void init()
{
	for(int i=0;i<=n;i++)
	{
		lb[i] = NULL;
		for(int j=0;j<=m[i];j++)
			ls[i][j] = NULL;
	}
	for(int i=0;i<cnt;i++)
	{
		node[i].id = i;
		node[i].ifr = NULL;
		node[i].bhd = NULL;	
	}
	head = NULL;
	tail = NULL;
}

int main()
{
	freopen("1007.in","r",stdin);
	freopen("1007.out","w",stdout);
	char name[S],s[S];
	int num;
	int tt = 0;
	while(scanf("%d",&n)!=EOF)
	{
		cnt = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m[i]);
			for(int j=1;j<=m[i];j++)
			{
				scanf("%d",&p);
				for(int k=1;k<=p;k++)
				{
					scanf("%s",ps[cnt].name);
					ps[cnt].big = i;
					ps[cnt].small = j;
					cnt ++;
				}
			}
		}
		std::sort(ps,ps+cnt,cmpByName);
	//	for(int i=0;i<cnt;i++)
	//		printf("%s\n",ps[i].name);
		printf("Scenario #%d\n",++tt);
		scanf("%d",&q);
		init();
		for(int i=0;i<q;i++)
		{
			scanf("%s",s);
			if(s[0] == 'i')
			{
				scanf("%s",name);
				int id = find(name);
		//		printf("%d\n",id);
				insert(id);
			}
			else if(s[0] == 'o')
			{
				scanf("%d",&num);
				out(num);
			}
		}
		printf("\n");
	}
	return 0;
}
/*
2
2
2 a b
2 c d
2
2 e f
2 g h

15
in a
in f
in c
in b
in d
out 2
out 1
in c
in b
in e
in h
in g
out 1
out 2
out 3

2
2
2 a b
2 c d
2
2 e f
2 g h

22
in a
in f
in c
in b
in d
out 2
out 1
in c
in b
in e
in h
in g
out 1
out 2
out 3
in h
in e 
in a
in f
out 1 
out 2
out 1
*/
