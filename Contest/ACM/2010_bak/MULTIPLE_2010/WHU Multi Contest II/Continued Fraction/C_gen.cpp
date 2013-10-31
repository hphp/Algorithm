#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

const int max_len = 10000 + 10;

char buf[max_len];

void make_string(char*, int, int);

int main() {
    freopen("in.txt", "w", stdout);
    srand(time(NULL));
    puts("L");
    puts("R");
    for (int i = 0; i < 5; ++i) {
        make_string(buf, rand() % 10 + 10, 2);
        puts(buf);
    }
    for (int i = 0; i < 5; ++i) {
        make_string(buf, rand() % 50 + 50, 2);
        puts(buf);
    }
    for (int i = 0; i < 5; ++i) {
        make_string(buf, rand() % 500 + 500, 4);
        puts(buf);
    }
    for (int i = 0; i < 5; ++i) {
        make_string(buf, rand() % 5000 + 5000, 64);
        puts(buf);
    }
    return 0;
}

void make_string(char* str, int len, int mod) {
    str[0] = (rand() % 2 == 0 ? 'L' : 'R');
    for (int i = 1; i < len; ++i)
        str[i] = (rand() % mod != 0 ? str[i - 1] : (str[i - 1] == 'L' ? 'R' : 'L'));
    str[len] = '\0';
}
