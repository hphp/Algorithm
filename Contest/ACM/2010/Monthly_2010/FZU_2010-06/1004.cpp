#include <stdio.h>
#include <vector>
using namespace std;
#define N 1020
#define E 520

vector<int> next[N*2];
int cnt = 0;
int pre[N],f[N];
int flag =0;
void dfs(int cur)
{
	if(flag == 1)
		return;
	pre[cur] = cnt++;
//	printf("%d %d\n",cur,pre[cur]);
	int size = next[cur].size();
	for(int i=0;i<size;i++)	
	{
		int id = next[cur][i];
		if(pre[id]==-1)
		{
			f[id] = cur;
			dfs(id);
		}
		else if(f[cur] != id && pre[id] < pre[cur])
		{
		//	printf("%d %d %d %d\n",cur,id,pre[cur],pre[id]);
			flag = 1;
			return ;
		}
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	for(int tt = 1; tt <= test; tt++)
	{
		int n,m,e1,e2,a,b;
		scanf("%d%d",&n,&m);
		scanf("%d%d",&e1,&e2);
		for(int i=0;i<n+m;i++)
			next[i].clear();
		for(int i=0;i<e1;i++)	
		{
			scanf("%d%d",&a,&b);
			next[a].push_back(b+n);
		}
		for(int i=0;i<e2;i++)	
		{
			scanf("%d%d",&a,&b);
			next[a+n].push_back(b);
		}
		flag =0;
		cnt = 0;
		for(int i=0;i<n+m;i++)
		{
			for(int ei=0;ei<n+m;ei++)
				pre[ei] = -1;
				dfs(i);
		}
		printf("Case %d: ",tt);
		if(flag == 0)
			printf("Impossible\n");
		else printf("Possible\n");
	}
}
/*
Case 1: Impossible Case 2: Possible */
