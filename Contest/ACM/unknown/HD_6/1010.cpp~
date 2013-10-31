#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1010
#define M 10010

int n,m;
int tt;
struct Node
{
	int id;
	Node *arr;
}node[M],edge[100*M];

struct Inf
{
	int x,y;
	int arrt;
}inf[M];

int mearn[M];

bool cmp(Inf a,Inf b)
{
	if(a.arrt<=b.arrt)
		return 1;
		return 0;
}

int abss(int a)
{
	if(a<0)
		return -a;
		return a;
}

void dp_init(void)
{
	for(int i=0;i<m;i++)
	{
		if(inf[i].arrt==0)	
			mearn[i]=1;
		else mearn[i]=-1;
	}
}

void init(void)
{
	tt=0;
	for(int i=0;i<m;i++)
		node[i].arr=NULL;
}

int dp(int cur)
{
	if(mearn[cur]>-1)
		return mearn[cur];
	mearn[cur]=1;
	for(Node *temp=node[cur].arr;temp!=NULL;temp=temp->arr)
	{
		int next=temp->id;
		int ans=dp(next);
		if(ans+1>mearn[cur])
			mearn[cur]=ans+1;
	}
	return mearn[cur];
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		init();
		for(int i=0;i<m;i++)	
		{
			node[i].id=i;
		//	node[i].arr=NULL;
			scanf("%d%d%d",&inf[i].arrt,&inf[i].x,&inf[i].y);
		}
		sort(inf,inf+m,cmp);
		/*for(int i=0;i<m;i++)
			printf("%d %d\n",inf[i].arrt,inf[i].x);*/
		for(int i=m-1;i>0;i--)
		{
			for(int j=i-1;j>=0;j--)	
			{
				int dif1=inf[i].arrt-inf[j].arrt;
				int dif2=abs(inf[i].x-inf[j].x)+abs(inf[i].y-inf[j].y);
				if(dif1>=dif2)	
				{
					edge[tt].id=j;
					edge[tt].arr=node[i].arr;
					node[i].arr=&edge[tt];
					tt++;
				}
			}
		}
		dp_init();
		int maxmax=0;
		for(int i=m-1;i>=0;i--)
		{
			int ans=dp(i)	;
			if(ans>maxmax)
				maxmax=ans;
		}
		printf("%d\n",maxmax);
	}
	return 0;
}
