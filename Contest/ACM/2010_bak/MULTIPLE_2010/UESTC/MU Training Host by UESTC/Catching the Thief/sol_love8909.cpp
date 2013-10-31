#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\1.out", "w", stdout);
	int T, N;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%d", &N);
		printf("Case %d: ", t_case);
		if (N <= 2) printf("%d\n", N);
		else printf("%d\n", 2 * N - 4);
	}
	return 0;
}
