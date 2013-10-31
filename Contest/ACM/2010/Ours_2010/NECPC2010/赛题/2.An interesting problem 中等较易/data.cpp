#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
    freopen("in.in", "w", stdout);
    for(int i = 1; i <= 9; ++i)
        for(int j = 1; j <= 100; ++j)
            printf("%d %d\n", i, j);
}
