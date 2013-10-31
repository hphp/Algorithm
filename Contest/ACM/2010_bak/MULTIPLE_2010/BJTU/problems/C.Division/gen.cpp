#include <iostream>

using namespace std;

void	make(int N, int M)
{
	printf("%d %d\n", N, M);
	for (int i = 0; i < N; ++i) printf("%d ", rand() % 10000); printf("\n");
}

int	main()
{
	freopen("in.txt", "w", stdout);
	printf("1\n");
	make(5, 2);
	make(5000, 20);
	make(5000, 100);
	make(10000, 1000);
	make(10000, 5000);
	return 0;
}
