#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\1.out", "w", stdout);
	int T, n, p;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		double ua, u0, u1, t1, s;
		scanf("%lf %lf %lf %lf %d", &ua, &u0, &u1, &t1, &n);
		double k = -log((u1-ua) / (u0-ua)) / t1;
		printf("Case %d:\n", t_case);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %lf", &p, &s);
			if (fabs(ua - u0) < 1e-8)
			{
				if (p == 0)
					printf("%.2f\n", 0);
				else
					printf("%.2f\n", ua);
			}
			else
			{
				if (p == 0)
					printf("%.2f\n", -log((s-ua) / (u0-ua)) / k);
				else
					printf("%.2f\n", (u0-ua)*exp(-k * s) + ua);
			}
		}
		printf("\n");
	}
	return 0;
}

