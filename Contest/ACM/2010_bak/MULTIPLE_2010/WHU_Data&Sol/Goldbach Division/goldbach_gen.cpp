/*
 * Author: iSea
 * Created Time:  2010/7/17 9:50:28
 * File Name: goldbach_gen.cpp
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

const int maxn = 20000 + 10;
const int inf = (-1u) >> 1;

int range(int x) {
    return rand() * rand() % x + 1;
}

int range(int x, int y) {
    return x == y? x : range(y - x) + x - 1;
}

bool f[maxn];

int main() {
    int Case = 2000;
    freopen ("goldbach.in", "w", stdout);
    for (int i = 0; i < 500; ++i) {
        printf ("%d\n%d\n", i + 1, 20000 - i);
        f[i + 1] = f[20000 - i] = true;
    }
    for (int i = 0; i < Case - 1000; ++i) {
        int t = range(501, 19500);
        while (f[t])
            t = range(501, 19500);
        f[t] = true;
        printf ("%d\n", t);
    }
            
    return 0;
}

