#include <iostream>

using namespace std;

const int	MaxN = 10010;
const int	MaxM = 5010;
const int	INF = 1 << 30;

int		N, M, task;
int		value[MaxN], f[MaxN][MaxM], g[MaxN][MaxM];

int	sqr(int i) 
{
	return i * i; 
}

int	main()
{
//	freopen("in.txt" , "r" , stdin);
//	freopen("division.out" , "w" , stdout);

	scanf("%d", &task);
	for (int nowCase = 1; nowCase <= task; ++nowCase)
	{
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; ++i) scanf("%d", &value[i]);
		sort(value, value + N);

		for (int i = 0; i < N; ++i)
			for (int j = 1; j <= min(i + 1, M); ++j)
			{
				if (j == 1) 
				{
					f[i][j] = sqr(value[i] - value[0]);
					g[i][j] = i - 1;
					continue;
				}

				int lower = (i + 1 == j) ? 0 : g[i - 1][j];
				int upper = i - 1;

				g[i][j] = f[i][j] = INF;
				for (int k = lower; k <= upper; ++k)
				{
					int temp = f[k][j - 1] + sqr(value[i] - value[k + 1]);
					if (temp < f[i][j])
						f[i][j] = temp, g[i][j] = k;
				}
				if (f[i][j] == INF)
				{
					printf("%d %d %d %d\n", i, j, lower, upper);
				}
			}
		printf("Case %d: %d\n", nowCase, f[N - 1][M]);
	}
	return 0;
}
