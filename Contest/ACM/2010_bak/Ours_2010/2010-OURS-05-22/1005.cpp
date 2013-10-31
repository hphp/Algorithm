#include <stdio.h>
#include <vector>
using namespace std;

void init()
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;++)
			con[i][j] = 0; 	
		vec[i].clear();
		pre[i] = -1;
	}
	cnt = 0;
	scnt = 0;
	stop = 0;
}

vector<int> vec[V];
int id[V], pre[V], low[V], s[V], stop, cnt, scnt;
void tarjan(int v, int n) // vertex: 0 ~ n-1
{
	int t, minc = low[v] = pre[v] = cnt++;
	vector<int>::iterator pv;
	s[stop++] = v;
	for (pv = vec[v].begin(); pv != vec[v].end(); ++pv) {
	if(-1 == pre[*pv]) tarjan(*pv, n);
	if(low[*pv] < minc) minc=low[*pv];
	}
	if(minc < low[v]) {
	low[v] = minc; return;
	}
	do {
	id[t = s[--stop]] = scnt; low[t] = n;
	} while(t != v);
	++scnt; // 强连通分量的个数
}

void dp(int cur)
{
	
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		init();
		for(int i=0;i<n;i++)
		{
			scanf("%s %s",s[0],s[1]);
			for(int k=0;k<2;k++)
			{
				int j =0 ;
				for(;j<ex;j++)
					if(strcmp(s[k],rec[j].s) == 1)
						break;
				if(j == ex)
				{
					strcpy(rec[ex++].s,s[k]);
				}
					idd[k] = j;
			}
			vec[idd[0]].push_back(idd[1]);
		}
		
		for(int i=0;i<ex;i++)
			if(pre[i] == -1)
				tarjan(i,ex);
		
		for(int i=0;i<ex;i++)
		{
			for(int j=0;j<vec[i].size();j++)
			{
				int cur = vec[i][j];
				if(id[i] != id[j])
					con[id[i]][id[j]] = 1;
			}
		}
		
		for(int i=0;i<bcnt;i++)
		{
			dp(i);
		}
	}
	return 0;
}
