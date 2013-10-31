/*
 * Author: iSea
 * Created Time:  2010/7/15 21:38:04
 * File Name: proud_gen.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

const int maxn = 500 + 10;
const int maxm = 5000 + 10;
const int inf = (-1u) >> 1;

int range(int x) {
    return rand() * rand() % x + 1;
}

int range(int x, int y) {
    return x == y? x : range(y - x) + x - 1;
}

struct good {
    int p, q, v;
    void output() {
        printf ("%d %d %d\n", p, q, v);
    }
    bool operator<(const good& g) const {
        return q - p > g.q - g.p;
    }
};

good g[maxn];

void Case_One() {
    int n = range(100), m = range(1000, 5000);
    printf ("%d %d\n", n, m);
    int pre = 100;
    for (int i = 0; i < n; ++i) {
        g[i].v = range(1000);
        if (pre > 0) {
            g[i].q = pre;
            g[i].p = range(min(10, pre));
            pre -= g[i].p;
        }
        else {
            g[i].q = range(100);
            g[i].p = range(g[i].q);
        }
    }
    random_shuffle(g, g + n);
    for (int i = 0; i < n; ++i)
        g[i].output();
}

void Case_Two() {
    int n = range(200), m = range(1000, 5000);
    printf ("%d %d\n", n, m);
    int a[maxn], b[maxn];
    for (int i = 0; i < n; ++i) {
        a[i] = range(50, 100);
        b[i] = range(49);
    }
    sort (a, a + n);
    sort (b, b + n);
    for (int i = 0; i < n; ++i) {
        g[i].v = range(1000);
        g[i].q = a[n - 1 - i];
        g[i].p = g[i].q - b[i];
    }   
    random_shuffle(g, g + n);
    for (int i = 0; i < n; ++i)
        g[i].output();
}

void Case_Three() {
    int n = range(500), m = range(5000);
    printf ("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
        g[i].v = range(1000);
        g[i].q = range(100);
        g[i].p = range(g[i].q);
        g[i].output();
    }
}
    
int main() {
    freopen ("proud.in", "w", stdout);
    int Case = 50;
    for (int i = 0; i < Case; ++i) {
        if (i < 10) Case_One();
        else if (i < 20) Case_Two();
        else Case_Three();
    }
    
    return 0;
}

