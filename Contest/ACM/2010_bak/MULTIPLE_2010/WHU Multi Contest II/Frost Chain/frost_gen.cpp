/*
 * Author: iSea
 * Created Time:  2010/8/18 18:13:47
 * File Name: frost_gen.cpp
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

int nag(int x) {
    return range(3) == 1? -x : x;
}

int main() {
    freopen ("frost.in", "w", stdout);
    printf ("3 1\n0 1 0 2 0 3 0 4 0 5\n1 1 1 1 1\n");
    printf ("3 2\n0 1 0 2 0 3 0 4 0 5\n1 1 1 1 1\n");
    printf ("3 3\n0 1 0 2 0 3 0 4 0 5\n1 1 1 1 1\n");
    printf ("3 4\n0 1 0 2 0 3 0 4 0 5\n1 1 1 1 1\n");
    printf ("3 5\n0 1 0 2 0 3 0 4 0 5\n1 1 1 1 1\n");
    printf ("3 5\n0 1 0 2 0 3 0 4 0 5\n2 1 1 1 1\n");
    printf ("4 5\n0 1 0 2 0 3 0 4 0 5\n2 1 1 1 1\n");
    printf ("5 5\n0 1 0 2 0 3 0 4 0 5\n2 1 1 1 1\n");
    printf ("25 1\n0 1 0 2 0 3 0 4 0 5\n5 5 5 5 5\n");
    printf ("25 1\n0 1 0 2 0 3 0 4 0 5\n1 2 3 4 5\n");
    printf ("25 2\n0 1 0 2 0 3 0 4 0 5\n1 2 3 4 5\n");
    printf ("15 100\n0 1 0 2 0 3 0 4 0 5\n5 5 5 5 5\n");
    printf ("20 100\n0 1 0 2 0 3 0 4 0 5\n5 5 5 5 5\n");
    printf ("20 100\n0 1 0 12 0 23 0 34 0 45\n5 5 5 5 5\n");
    printf ("25 100\n0 1 0 12 0 23 0 34 0 45\n5 5 5 5 5\n");
    int Case = 85;
    for (int i = 0; i < Case; ++i) {
        int n = range(10, 25), d = range(10000);
        printf ("%d %d\n", n, d);
        for (int k = 0; k < 10; ++k)
            printf ("%d%c", nag(range(800)), k == 9? '\n' : ' ');
        for (int k = 0; k < 5; ++k)
            printf ("%d%c", range(5), k == 4? '\n' : ' ');
    }
    return 0;
}

