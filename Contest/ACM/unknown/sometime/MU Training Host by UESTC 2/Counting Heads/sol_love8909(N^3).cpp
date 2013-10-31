#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 256;

int N, g;
int x[MAX], y[MAX], f[MAX];
int sx[MAX], sy[MAX], rx[MAX], ry[MAX];

int main()
{
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%d %d", &N, &g);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &x[i], &y[i], &f[i]);
			sx[i] = x[i]; sy[i] = y[i];
		}
		sort(sx, sx + N);
		sort(sy, sy + N);
		for (int i = 0; i < N; i++)
		{
			rx[i] = N - (lower_bound(sx, sx + N, x[i]) - sx);
			ry[i] = N - (lower_bound(sy, sy + N, y[i]) - sy);
		}
		int res = 0;
		for (int i = 1; i <= N; i++) //第一场排名i及i以上的晋级
		{
			for (int j = 1; j <= N; j++) //第二场排名j及j以上的晋级
			{
				int r1[2] = {0, 0}, r2[2] = {0, 0}, b[2] = {0, 0};
				for (int k = 0; k < N; k++)
				{
					if (rx[k] <= i && ry[k] <= j) b[f[k]]++;
					else if (rx[k] <= i) r1[f[k]]++;
					else if (ry[k] <= j) r2[f[k]]++;
				}
				for (int k = 0; k <= b[0] + b[1]; k++)//两场都晋级的人中有k个从第一场晋级
				{
					int l1 = g - k, l2 = g - (b[0] + b[1] - k);
					if (l1 >= 0 && l2 >= 0) //两场剩余的晋级名额分别为l1, l2
					{
						int a1 = min(r1[1], l1);
						int a2 = min(r2[1], l2);
						if (a1 + a2 + b[1] > res)
							res = a1 + a2 + b[1];
					}
				}
			}
		}
		printf("Case %d: %d\n", t_case, res);
	}
	return 0;
}
