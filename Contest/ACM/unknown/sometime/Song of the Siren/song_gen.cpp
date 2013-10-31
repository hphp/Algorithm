/*
 * Author: iSea
 * Created Time:  2010/7/18 9:51:05
 * File Name: song_gen.cpp
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
    freopen ("song.in", "w", stdout);
    printf ("1000\n0 0 1 0 -1 0 2 0 -2 0\n");
    printf ("1\n-4 0 -2 0 0 0 2 0 4 0\n");
    printf ("1000\n1 0 -1 0 0 1 0 -1 0 0\n");
    printf ("5\n3 4 4 3 -3 4 -4 3 -3 -4\n");
    printf ("10\n3 4 4 3 -3 4 -4 3 -3 -4\n");
    printf ("1\n0 0 0 1 0 2 0 3 0 4\n");
    printf ("2\n0 0 0 1 0 2 0 3 0 4\n");
    printf ("3\n0 0 0 1 0 2 0 3 0 4\n");
    printf ("4\n0 0 0 1 0 2 0 3 0 4\n");
    printf ("5\n0 0 0 1 0 2 0 3 0 4\n");
    printf ("1\n0 0 2 0 1 1 1 -1 1 0\n");
    printf ("2\n0 0 2 0 1 1 1 -1 1 0\n");
    printf ("3\n0 0 2 0 1 1 1 -1 1 0\n");
    printf ("100\n0 0 2 0 1 1 1 -1 1 0\n");
    printf ("100\n0 0 200 0 100 100 100 -100 100 0\n");
    printf ("500\n0 0 200 0 100 100 100 -100 100 0\n");
    printf ("500\n0 0 2000 0 1000 1000 1000 -1000 1000 0\n");
    int Case = 8;
    for (int i = 0; i < Case; ++i) {
        printf ("%d\n", range(500, 1000));
        for (int k = 0; k < 10; ++k)
            printf ("%d%c", nag(range(800)), k == 9? '\n' : ' ');
    }
    return 0;
}

