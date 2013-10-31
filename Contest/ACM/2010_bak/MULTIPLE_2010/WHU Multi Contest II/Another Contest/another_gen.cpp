/*
 * Author: iSea
 * Created Time:  2010/8/15 10:28:48
 * File Name: another_gen.cpp
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

void Case_Small() {
    int n = range(20), s = range(20);
    int p = range(s);
    printf ("%d %d %d\n", n, s, p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s; ++j) {
            printf ("%d%c", range(0, 2), j == s - 1? '\n' : ' ');
        }
    }
}

void Case_Large(bool biggest) {
    int n = range(1000), s = range(1000);
    if (biggest) n = 1000, s = 1000;
    int p = range(s);
    printf ("%d %d %d\n", n, s, p);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < s; ++j) {
            printf ("%d%c", range(0, 2), j == s - 1? '\n' : ' ');
        }
    }
}

int main() {
    freopen ("another.in", "w", stdout);
    printf ("3 3 1\n1 0 1\n1 1 1\n1 0 0\n");
    printf ("3 3 2\n1 0 1\n1 1 1\n1 0 0\n");
    printf ("3 3 3\n1 0 1\n1 1 1\n1 0 0\n");
    printf ("3 3 1\n1 1 1\n1 1 1\n1 1 1\n");
    printf ("3 3 2\n0 0 0\n0 0 0\n0 0 0\n");
    printf ("3 3 3\n0 0 0\n0 0 0\n1 1 1\n");
    printf ("3 3 2\n1 0 0\n0 1 1\n0 1 1\n");
    printf ("3 3 2\n0 0 1\n1 1 0\n1 1 0\n");
    printf ("3 3 1\n0 0 1\n1 1 0\n1 1 0\n");
    printf ("1 1 1\n0\n");
    printf ("1 1 1\n1\n");
    printf ("1 2 1\n0 1\n");
    int Case = 40;
    for (int i = 0; i < Case; ++i) {
        if (i < 33) Case_Small();
        else Case_Large(i > 37);
    }
    return 0;
}

