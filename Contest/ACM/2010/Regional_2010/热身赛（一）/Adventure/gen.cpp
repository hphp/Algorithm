#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;

const int N = 200;
const int H_MAX = 10000;
const int CASE_NO = 20;

int main()
{
	freopen("adv.in", "w", stdout);
	printf("%d\n", CASE_NO);
	printf("2 2\n1 2\n1 1\n");
	printf("4 1\n1\n2\n3\n4\n");
	srand(time(NULL));
	for(int i = 0; i < CASE_NO-2; i++) {
		int n = rand()%N+1, m = rand()%N+1;
		printf("%d %d\n", n, m);
		fprintf(stderr, "n=%d m=%d\n", n, m);
		for(int j = 0; j < n; j++, putchar('\n'))
			for(int k = 0; k < m; k++)
				printf("%d ", rand()%H_MAX+1);
	}
	return 0;
}
