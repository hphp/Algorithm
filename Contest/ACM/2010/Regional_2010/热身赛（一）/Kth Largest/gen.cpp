#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;

const int N = 10000;
const int MAX_VALUE = 10000;
const int CASE_NO = 5;

int main()
{
	int a, b;
	
	freopen("klarge.in", "w", stdout);
	printf("%d\n", CASE_NO);
	printf("2 1\n3 4\n5 6\n");
	printf("2 3\n2 1\n4 8\n");
	for(int i = 0; i < CASE_NO-2; i++) {
		int no = rand()%N+1, k = rand()%(no*no)+1;
		printf("%d %d\n", no, k);
		for(int i = 0; i < no; i++) printf("%d ", rand()%MAX_VALUE+1);
		printf("\n");
		for(int i = 0; i < no; i++) printf("%d ", rand()%MAX_VALUE+1);
		printf("\n");
	}
	
	return 0;
}
