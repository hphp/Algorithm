/*
 * Author: iSea
 * Created Time:  2010/8/18 10:04:38
 * File Name: frost_bf.cpp
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

bool g[8][8];
int x[8], y[8], h[8], n, d;
double p[8];

bool can(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) +
        (y[i] - y[j]) * (y[i] - y[j]) <= d * d;
}

void cal(int hp[], int cur, int t, double pro) {
    if (t == 0)
        return ;
    int tot = 0;
    for (int i = 0; i < 5; ++i)
        if (g[cur][i] && hp[i] > 0)
            ++tot;
    if (tot == 0)
        return ;
    for (int i = 0; i < 5; ++i) {
        if (g[cur][i] && hp[i] > 0) {
            if (hp[i] == 1) {
                //printf ("update i %d p %lf\n",
                        //i, pro / tot);
                p[i] += pro / tot;
            }
            --hp[i];
            cal(hp, i, t - 1, pro / tot);
            ++hp[i];
        }
    }
}

int main() {
    freopen ("frost.in", "r", stdin);
    while (scanf ("%d%d", &n, &d) != EOF) {
        for (int i = 0; i < 5; ++i)
            scanf ("%d%d", &x[i], &y[i]);
        for (int i = 0; i < 5; ++i)
            scanf ("%d", &h[i]);
        for (int i = 0; i < 5; ++i) {
            p[i] = 0.0;
            g[i][i] = false;
            g[i][5] = g[5][i] = true;
            for (int j = 0; j < i; ++j) {
                g[i][j] = g[j][i] = can(i, j);
            }
        }
        cal(h, 5, n + 1, 1.0);
        for (int i = 0; i < 5; ++i)
            printf ("%.3lf%c", p[i], i == 4? '\n' : ' ');
    }
    return 0;
}

