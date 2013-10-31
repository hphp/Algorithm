/*
 * Author: iSea
 * Created Time:  2010/7/15 21:28:56
 * File Name: proud.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 500 + 10;
const int maxm = 5000 + 10;
const int inf = (-1u) >> 1;

struct good {
    int p, q, v;
    void input() {
        scanf ("%d%d%d", &p, &q, &v);
    }
    bool operator<(const good& g) const {
        return q - p > g.q - g.p;
    }
};

good g[maxn];
int n, m, dp[maxm];

int main() {
    freopen ("proud.out", "w", stdout);
    while (scanf ("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            g[i].input();
        sort (g, g + n);
        memset (dp, -1, sizeof(dp));
        dp[m] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = g[i].q; j <= m; ++j)
                if (dp[j] != -1)
                    dp[j - g[i].p] = max(dp[j - g[i].p], dp[j] + g[i].v);
        int ans = 0;
        for (int i = 0; i <= m; ++i)
            ans = max(ans, dp[i]);
        printf ("%d\n", ans);
    }
    return 0;
}

