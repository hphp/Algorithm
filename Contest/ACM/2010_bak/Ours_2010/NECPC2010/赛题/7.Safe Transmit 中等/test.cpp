#include <stdio.h>

#define N 1100

int n, m, cnt;
int con[N][N];
int sign[3][N];

int deal(int a, int b)
{
	for (int i = 0; i < 3; i++)
		if (sign[i][a] == sign[i][b])
			return i;
	return 3;
}

void dfs(int type, int w)
{
	sign[type][w] = cnt;
	for (int i = 1; i <= n; i++)
		if (con[w][i]<=type && sign[type][i]==0)
			dfs(type, i);
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("test.out","w",stdout);
	bool first = 1;
	while (1)
	{
		if (scanf("%d %d", &n, &m) == EOF)
			break;
		
		if (!first)
			printf("\n");
		first = 0;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				con[i][j] = 3;
	
		for (int i = 0; i < m; i++)
		{
			int a, b;
			char type;
			scanf("%d %d %c", &a, &b, &type);
			int c = type - 'A';
			if (c < con[a][b])
				con[a][b] = con[b][a] = c;
		}

		for (int i = 0; i < 3; i++)
		{
			for (int j = 1; j <= n; j++)
				sign[i][j] = 0;
			
			cnt = 0;
			for (int j = 1; j <= n; j++)
				if (sign[i][j] == 0)
				{
					cnt++;
					dfs(i, j);
				}
		}
		
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			printf("%c\n", deal(a, b) + 'A');
		}
	}

	return 0;
}
