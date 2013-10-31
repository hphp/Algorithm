#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void output(int);

int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    output(1);
    puts("3");
    puts("0 0 1");
    puts("0 0 1");
    puts("0 0 1");
    puts("4");
    puts("0 0 1");
    puts("0 0 2");
    puts("0 0 3");
    puts("0 0 1");
    puts("4");
    puts("0 0 1");
    puts("2 0 1");
    puts("1 1 1");
    puts("1 -1 1");
    output(rand() % 5 + 5);
    output(rand() % 10 + 10);
    output(rand() % 10 + 20);
    output(rand() % 10 + 30);
    output(rand() % 10 + 40);
    output(rand() % 10 + 50);
    output(rand() % 10 + 60);
    output(rand() % 10 + 70);
    output(rand() % 10 + 80);
    output(rand() % 10 + 90);
    output(rand() % 10 + 90);
    output(rand() % 10 + 90);
    return 0;
}

void output(int n) {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
        printf("%d %d %d\n", rand() % 20000 - 10000, rand() % 20000 - 10000, rand() % 5000 + 1);
}
