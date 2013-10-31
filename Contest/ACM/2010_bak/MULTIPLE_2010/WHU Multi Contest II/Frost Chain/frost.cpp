/*
 * Author: iSea
 * Created Time:  2010/8/18 10:39:00
 * File Name: frost.cpp
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

#define REP(i,n) for(i=0; i<=n; ++i)

bool g[8][8];
int x[8], y[8], h[8], s[8], n, d, sum;
double p[8], dp[6][6][6][6][6][6];

bool can(int i, int j) {
    return (x[i] - x[j]) * (x[i] - x[j]) +
        (y[i] - y[j]) * (y[i] - y[j]) <= d * d;
}

double cal(int t[], int cur) {
    double &res = dp[t[0]][t[1]][t[2]][t[3]][t[4]][cur];
    if (res != -1.0)
        return res;
    res = 0.0;
    int nsum = 0;
    for (int i = 0; i < 5; ++i)
        nsum += t[i];
    if (sum - nsum > n + 1)
        return res;
    if (t[cur] + 1 > h[cur])
        return res;
    for (int i = 0; i < 5; ++i) {
        if (g[i][cur]) {
            int ct[8], cnt = 0;
            for (int j = 0; j < 5; ++j) {
                ct[j] = t[j];
                if (j == cur) ++ct[j];
                if (g[i][j] && ct[j] > 0)
                    ++cnt;
            }
            double tmp = cal(ct, i);
            res += tmp / cnt;
        }
    }
    return res;
}

int main() {
    freopen ("frost.out", "w", stdout);
    while (scanf ("%d%d", &n, &d) != EOF) {
        for (int i = 0; i < 5; ++i)
            scanf ("%d%d", &x[i], &y[i]);
        sum = 0;
        for (int i = 0; i < 5; ++i) {
            scanf ("%d", &h[i]);
            sum += h[i];
        } 
        for (int i = 0; i < 5; ++i) {
            p[i] = 0.0;
            g[i][i] = false;
            g[i][5] = g[5][i] = true;
            for (int j = 0; j < i; ++j) {
                g[i][j] = g[j][i] = can(i, j);
            }
        }
        REP(s[0], h[0]) REP(s[1], h[1]) REP(s[2], h[2]) 
        REP(s[3], h[3]) REP(s[4], h[4])  
        for (int i = 0; i < 5; ++i) 
        dp[s[0]][s[1]][s[2]][s[3]][s[4]][i] = -1.0;
        dp[h[0]-1][h[1]][h[2]][h[3]][h[4]][0] = 
        dp[h[0]][h[1]-1][h[2]][h[3]][h[4]][1] = 
        dp[h[0]][h[1]][h[2]-1][h[3]][h[4]][2] = 
        dp[h[0]][h[1]][h[2]][h[3]-1][h[4]][3] = 
        dp[h[0]][h[1]][h[2]][h[3]][h[4]-1][4] = 0.2;
        REP(s[0], h[0]) REP(s[1], h[1]) REP(s[2], h[2]) 
        REP(s[3], h[3]) REP(s[4], h[4])  
        for (int i = 0; i < 5; ++i) {
            double tp = cal(s, i);
            if (s[i] == 0) p[i] += tp;
        }
        for (int i = 0; i < 5; ++i)
            printf ("%.3lf%c", p[i], i == 4? '\n' : ' ');
    }
    return 0;
}

