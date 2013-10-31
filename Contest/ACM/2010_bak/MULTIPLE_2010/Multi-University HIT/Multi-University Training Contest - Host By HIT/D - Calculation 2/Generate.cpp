#include <cstdio>
#include <cstdlib>
#include <ctime>
const int MOD = 1000000000;

int main()
{
    freopen("Calculation 2.in", "w", stdout);
    srand(time(0));
    for(int i = 1;i <= 500;++i)
        printf("%d\n", i);
    for(int i = 0;i < 100;++i)
        printf("%d\n", rand());
    for(int i = 0;i < 1000;++i)
        printf("%d\n", rand() * rand() % MOD);
    puts("1000000007");
    puts("999999999");
    puts("1000000000");
}
