#include <cstdio>
#include <cstring>

int main()
{
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		int n, m, k, x, sum = 0;
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &x);
			sum += x;
		}
		printf("Case %d: %.5f\n", t_case, (double)sum / n * m);
	}
	return 0;
}
