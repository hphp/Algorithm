/*
 * Author: momodi
 * Created Time:  2010-4-11 15:24:02
 * File Name: Pie.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 10000;
double dtn[maxn], dtm[maxn];
int n, m;
double f[2][maxn + 1];
double solve() {
    memset(f, 0, sizeof(f));
    f[0][0] = f[1][0] = 0;
    for (int i = 1; i <= n; ++i) {
        double *now = f[1 ^ (i & 1)], *pre = f[i & 1];
        now[i - 1] = 1e100;
        for (int j = i; j + (n - i) <= m; ++j) {
            now[j] = min(now[j - 1], pre[j - 1] + abs(dtn[i - 1] - dtm[j - 1]));
        }
    }
    return f[1 ^ (n & 1)][m];
}

int main() {
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf", dtn + i);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%lf", dtm + i);
        }
        sort(dtn, dtn + n);
        sort(dtm, dtm + m);
        if (n > m) {
            for (int i = 0; i < n; ++i) {
                swap(dtn[i], dtm[i]);
            }
            swap(n, m);
        }
        printf("%.6f\n", solve());
    }
    return 0;
}

