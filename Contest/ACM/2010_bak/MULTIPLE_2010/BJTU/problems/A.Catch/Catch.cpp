#include <iostream>
#include <vector>

using namespace std;

const int	MaxN = 10000 + 100;

int		N, M, S;
int		queue[MaxN], color[MaxN];
vector<int>	edgeList[MaxN];

bool	BFS(int st)
{
	bool ret = 1;
	queue[0] = st; color[st] = 1;

	for (int op = 0, cl = 1; op < cl; )
	{
		int u = queue[op++];
		for (int i = 0; i < edgeList[u].size(); ++i)
		{
			int v = edgeList[u][i];
			if (color[v] && (color[u] == color[v])) ret = 0;
			if (!color[v]) 
			{
				color[v] = 3 - color[u];
				queue[cl++] = v;
			}
		}
	}
	return ret;
}

int	main()
{
	int task;
	scanf("%d", &task);
	for (int nowCase = 1; nowCase <= task; ++nowCase)
	{
		scanf("%d %d %d", &N, &M, &S);
		for (int i = 0; i < MaxN; ++i) edgeList[i].clear();
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			scanf("%d %d", &u, &v);
			edgeList[u].push_back(v);
			edgeList[v].push_back(u);
		}

		memset(color, 0, sizeof(color));

		bool checked = BFS(S);
		
		for (int i = 0; i < N; ++i) if (!color[i]) checked = 1;
		printf("Case %d: %s\n", nowCase, checked ? "NO" : "YES");
	}
	return 0;
}
