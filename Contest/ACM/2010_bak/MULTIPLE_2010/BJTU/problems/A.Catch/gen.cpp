#include <iostream>

using namespace std;

void	make(int N, int M, bool sign, bool connect)
{
	printf("%d %d %d\n", N, M, rand() % N);
	if (connect)
	{
		M -= N - 1;
		for (int i = 0; i < N - 1; ++i) printf("%d %d\n", i, i + 1);
	}
	for (int i = 0; i < M; ++i)
	{
		while (1)
		{
			int u = rand() % N, v = rand() % N;
			if (u == v) continue;
			if (sign && ((u + v) % 2 == 0)) continue;
			printf("%d %d\n", u, v);
			break;
		}
	}
}

int	main()
{
	freopen("in.txt", "w", stdout);
	printf("%d\n", 10);
	make(5, 10, 1, 1);
	make(10, 100, 1, 1);
	make(100, 1000, 0, 1);
	make(1000, 999, 1, 0);
	make(5000, 100000, 0, 1);
	make(10000, 100000, 1, 1);
	make(10000, 100000, 0, 1);
	make(10000, 100000, 1, 1);
	make(10000, 100000, 0, 0);
	return 0;
}
