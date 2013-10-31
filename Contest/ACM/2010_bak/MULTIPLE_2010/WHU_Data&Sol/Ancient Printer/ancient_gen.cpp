/*
 * Author: iSea
 * Created Time:  2010/7/16 22:40:17
 * File Name: ancient_gen.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;

int range(int x) {
    return rand() * rand() % x + 1;
}

int range(int x, int y) {
    return x == y? x : range(y - x) + x - 1;
}

void gen_word(int len) {
    char s[64];
    for (int i = 0; i < len; ++i) {
        int t = range(26) - 1;
        s[i] = (char)('a' + t);
    }
    s[len] = '\0';
    puts(s);
}

int main() {
    int Case = 10;
    freopen ("ancient.in", "w", stdout);
    for (int i = 0, n; i < Case; ++i) {
        if (i < 5) n = 10;
        else if (i < 9) n = range(1000);
        else n = 10000;
        printf ("%d\n", n);
        for (int j = 0; j < n; ++j)
            gen_word(range(50));
    }
    
    return 0;
}

