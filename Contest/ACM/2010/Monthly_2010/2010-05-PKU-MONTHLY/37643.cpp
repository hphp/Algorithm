#include <stdio.h>
#include <algorithm>
#define N 110000
#define abss(a) ((a)<0?(-(a)):(a))
typedef unsigned __int64 INT;
#define MAX ((1<<30))

INT dis[N];
int flag[N];
struct Node
{
	int id;
	int v;
	Node * next;
}node[N],edge[N*2];
int tt;
int n ;

void add_edge(int a,int b,int c)
{
	edge[tt].id = b;
	edge[tt].v = c;
	edge[tt].next = node[a].next;
	node[a].next = & edge[tt];
	tt ++;
}

void dfs(int cur)
{
	flag[cur] = 1;
	for(Node * tmp = node[cur].next ; tmp != NULL ; tmp = tmp->next)	
	{
		int id = tmp->id;
		if(flag[id] == -1)
		{
			dis[id] = dis[cur]^(tmp->v);
			dfs(id);
		}
	}
}

/*int mxx[N],mnn[N];
int mxmx;

void dp(int cur)
{
	if(flag[cur] != -1)
		return;
	flag[cur] = 1;
	mxx[cur] = 0;
	mnn[cur] = MAX;
	dis[cur] = 0;
	for(Node * tmp = node[cur].next ; tmp != NULL ; tmp = tmp->next)
	{
		int id = tmp->id;
		if(flag[id] == -1)
		{
			dp(id);
			dis[id] = 
			if(mxx[id] > mxx[cur])	
				mxx[cur] = mxx[id];
			if(mnn[id] < mnn[cur])
				mnn[cur] = mnn[id];
		}
	}
	if(mnn[cur] >= MAX)return;
	if((mxx[cur]^mnn[cur]) > mxmx)
		mxmx =(mxx[cur]^mnn[cur]);
	return ; 
}*/

struct NN
{
	NN * next[2];
	NN()
	{
		for(int i=0;i<2;i++)
			next[i] = NULL;	
	}
}* root , nn[N*35];
int ntt;

inline void insert()
{
	INT cur ;
	for(int jj = 1 ; jj <= n ; jj ++)
	{
		cur = dis[jj];
		NN * tmp = root;
		int i = 32;
		while( i >= 0)
		{
	//		printf("1:%d %d\n",cur,flag);
			int flag = (cur >> i)%2;
	//		printf("2:%d %d\n",cur,flag);
			if(tmp->next[flag] == NULL)
			{
				tmp->next[flag] = & nn[ntt];
				nn[ntt].next[0] = nn[ntt].next[1] = NULL;
				ntt ++;
			}
			tmp = tmp->next[flag];
			i -- ;
		}
	}
}

inline INT Query(INT cur)
{
	NN * tmp = root;
	int i = 32;
	INT sum = cur;
//	printf("cur : %u\n",cur);
	cur = ~ cur;
//	printf("%u\n",cur);
	while(i >= 0 && tmp != NULL)
	{
		int flag = (cur >> i) % 2;
//		printf("%u %u\n",cur,flag);
		if(tmp -> next[flag] == NULL)
		{
			sum = sum ^ ((flag)<<i);
		//	printf("%u ",sum);
			tmp = tmp -> next[1-flag];
		}
		else
			tmp = tmp->next[flag];
		i --;
	}
//	printf("%u\n",sum);
	return sum;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			flag[i] = -1;
			node[i].next = NULL;
		}
		tt = 0;
		int a,b;
		int c;
		for(int i=1;i<n;i++)
		{
			scanf("%d %d %d",&a,&b,&c);
			a ++;
			b ++;
			add_edge(a,b,c);
			add_edge(b,a,c);
		}
		dis[1] = 0;
		dfs(1);
		ntt = 0;
		root = & nn[ntt];
		nn[ntt].next[0] = nn[ntt].next[1] = NULL;
		ntt ++;
		insert();
/*		for(int i=1;i<=n;i++)
		{
			insert(dis[i]);
		}*/
		INT mxmx = 0;
	//	printf("good luck to you \n");
		for(int i = 1; i <= n ; i ++)
		{
			INT get = Query(dis[i]);
//			printf("%u\n",get);
			if(get > mxmx)
				mxmx = get;
		}
		printf("%I64u\n",mxmx);
	}
	return 0;
}
