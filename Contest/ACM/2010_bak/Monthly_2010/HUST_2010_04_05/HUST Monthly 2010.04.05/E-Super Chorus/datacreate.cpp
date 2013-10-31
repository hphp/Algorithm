#include <time.h>
#include <cstdio>
#include <cstdlib>

int outputCase(int n) {
    printf("%d\n", n);
    for(int i = 0; i < n; i ++) {
        printf("%d %d\n", rand() % 250 + 1650, rand() % 2);
    }
}

int main()
{
    freopen("input.in", "w", stdout);
    srand(time(NULL));
    puts("2\n173 1\n173 1");
    puts("3\n165 0\n170 1\n165 0");
    puts("3\n175 0\n167 1\n175 1");
    for(int test = 0; test < 44; test ++) {
        outputCase(rand() % 3000 + 1);
    }
    outputCase(3000);
    outputCase(3000);
    outputCase(3000);
    return 0;
}
