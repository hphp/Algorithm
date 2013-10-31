/*
 * Author: iSea
 * Created Time:  2010/8/17 14:53:38
 * File Name: divide_gen.cpp
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

void gen_word(int len, bool f) {
    char s[50012];
    for (int i = 0; i < len; ++i) {
        int t = range(26) - 1;
        if (f) t = range(3) - 1;
        s[i] = (char)('A' + t);
    }
    s[len] = '\0';
    puts(s);
}

int main() {
    freopen ("divide.in", "w", stdout);
    puts ("A\nB");
    puts ("AA\nBA\nZZ");
    puts ("ABA\nAAA\nABB");
    puts ("ABBA\nCDDC\nABAB\nABBB\nABABA");
    int Case = 40;
    for (int i = 0; i < Case; ++i) {
        if (i < 10) gen_word(3, true);
        else if (i < 25) gen_word(4, true);
        else if (i < 35) gen_word(range(100, 200), false);
        else if (i < 38) gen_word(range(200, 20000), false);
        else gen_word(50000, false);
    }
    return 0;
}

