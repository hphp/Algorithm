#include <stdio.h>
#include <string.h>
#include <time.h>
#include <algorithm>
using namespace std;

int main(){
	freopen("D:\\in.txt", "w", stdout);
	srand((unsigned)time(NULL));
	int cases = 97;
	printf("%d\n\n", cases + 3);
	while(cases--){
		int n = rand() % 1000 + 1, m = rand() % 1000 + 1, k = rand() % n + 1;
		printf("%d %d %d\n", n, m, k);
		for(int i = 0; i < n; ++i){
			int u = rand() % 1000 + 1;
			printf("%d ", u);
		}
		printf("\n\n");
	}
	for(int t = 0; t < 3; ++t){
		int n = 1000, m = 1000, k;
		if(t == 0) k = 1;
		else if(t == 1) k = 1000;
		else k = 729;
		printf("%d %d %d\n", n, m, k);
		for(int i = 0; i < n; ++i){
			int u = rand() % 1000 + 1;
			printf("%d ", u);
		}
		printf("\n\n");
	}
	return 0;
}