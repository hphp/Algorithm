#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 256;
const int oo = 0x7f7f7f7f;

void checkmin(int &a, int b) { if (b < a) a = b; }

struct Edge
{
	int v, c;
	Edge *next;
} e[MAX * 2], *adj[MAX];
int e_cnt;

void add_edge(int u, int v, int c)
{
	e[e_cnt].v = v; e[e_cnt].c = c;
	e[e_cnt].next = adj[u]; adj[u] = &e[e_cnt++];
}

bool vst[MAX];
int dp[MAX][3][MAX], size[MAX], N;

void dfs(int u)
{
	vst[u] = true;
	int (*cur)[MAX] = dp[u];
	fill(cur[0], cur[0] + size[u] + 1, +oo);
	fill(cur[1], cur[1] + size[u] + 1, +oo);
	fill(cur[2], cur[2] + size[u] + 1, +oo);
	cur[0][0] = cur[0][1] = 0;
	cur[1][0] = cur[1][1] = 0;
	cur[2][0] = cur[2][1] = 0;
	for (Edge *p = adj[u]; p; p = p->next)
	{
		if (vst[p->v] == false)
		{
			dfs(p->v);
			int (*son)[MAX] = dp[p->v];
			for (int f = size[u]; f >= 0; f--)
			{
				for (int n = 2; n >= 0; n--)
				{
					for (int s = 0; s <= size[p->v] && s <= f; s++)
					{
						for (int m = 0; m <= n; m++)
						{
							checkmin(cur[n][f],
								cur[n - m][f - s] + son[m][s] + (m == 1 ? p->c : p->c * 2));
						}
					}
				}
			}
		}
	}
}

void count(int u)
{
	vst[u] = true;
	size[u] = 1;
	for (Edge *p = adj[u]; p; p = p->next)
	{
		if (vst[p->v] == false)
		{
			count(p->v);
			size[u] += size[p->v];
		}
	}
}

int main()
{
	int T, P, Q, u, v, c, res[MAX];
	scanf("%d", &T);
	for (int ct = 1; ct <= T; ct++)
	{
		scanf("%d %d", &N, &P);
		e_cnt = 0;
		fill(adj, adj + N, (Edge*)NULL);
		for (int i = 0; i < N - 1; i++)
		{
			scanf("%d %d %d", &u, &v, &c);
			add_edge(u - 1, v - 1, c);
			add_edge(v - 1, u - 1, c);
		}
		fill(vst, vst + N, false);
		count(0);
		fill(vst, vst + N, false);
		dfs(0);
		fill(res, res + N + 1, +oo);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= size[i]; j++)
			{
				for (int k = 0; k <= 2; k++)
				{
					checkmin(res[j], dp[i][k][j]);
				}
			}
		}
		printf("Case %d:\n", ct);
		scanf("%d", &Q);
		while (Q--)
		{
			scanf("%d", &c);
			for (int i = N; i >= 0; i--)
			{
				if (res[i] < +oo && P - i * c >= res[i])
				{
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}
