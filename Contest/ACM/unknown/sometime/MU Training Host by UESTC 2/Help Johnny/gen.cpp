#include <stdio.h>
#include <stdlib.h>

int main(){
	int T,N,i,j;
	freopen("help.in","w",stdout);
	T = 10;
	printf("%d\n",T);
	for (i = 0;i < T;i++){
		N = 100000;
		printf("%d\n",N);
		for (j = 0;j < N;j++){
			if (j) putchar(' ');
			printf("%d %d",rand() % 99999+1,rand() % 99999+1);
		}
		putchar('\n');
	}
	fclose(stdout);
}
