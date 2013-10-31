#include <stdio.h>
#include <vector>
#include <algorithm>

#define N 1100
#define M 21000

int n, m;
int max[2][M];
int v[N], cnt[N], add[N], pt[N];
int p[N][N];

void dp()
{
	int q = 0;
	for (int j = 0; j <= m; j++)
		max[q][j] = -1;
	max[q][v[1]] = 0;
	int cur = v[1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			max[1-q][j] = -1;
		for (int j = 0; j <= cur; j++)
			if (max[q][j] != -1)
			{
				if (max[1-q][j+v[i+1]] < max[q][j])
					max[1-q][j+v[i+1]] = max[q][j];
				int get = 0;
				for (int k = pt[i]; k < cnt[i]; k++)
				{
					get += p[i][k];
					if (get > j)
						break;
					if (max[1-q][j-get+v[i+1]] < max[q][j]+k-pt[i]+1)
						max[1-q][j-get+v[i+1]] = max[q][j]+k-pt[i]+1;
				}
			}
		cur += v[i+1];
		q = 1-q;
	}

	int best = 0;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (max[q][j] > best)
				best = max[q][j];
	for (int i = 1; i <= n; i++)
		best += add[i];
	printf("%d\n", best);
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int cc = 0; cc < test; cc++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &cnt[i]);
			for (int j = 0; j < cnt[i]; j++)
			{
				scanf("%d", &p[i][j]);
			}

			std::sort(p[i], p[i]+cnt[i]);
		}

		m = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &v[i]);
			pt[i] = 0;
			add[i] = 0;
			while (pt[i]<cnt[i] && p[i][pt[i]]<=1 && v[i])
			{
				add[i]++;
				v[i] -= p[i][pt[i]];
				pt[i]++;
			}
			m += v[i];
		}
		v[n+1] = 0;
		add[n+1] = 0;

		dp();
	}

	return 0;
}

