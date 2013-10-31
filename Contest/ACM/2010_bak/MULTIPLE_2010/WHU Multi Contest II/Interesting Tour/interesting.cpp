/*
 * Author: iSea
 * Created Time:  2010/8/17 16:54:19
 * File Name: interesting.cpp
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

int dp[maxn][maxn], n, a, b;
vector <pair<int, int> > g;

int main() {
    freopen ("interesting.out", "w", stdout);
    while (scanf ("%d", &n) != EOF) {
        memset (dp, -1, sizeof(dp));
        dp[0][1] = dp[0][2] = dp[1][2] = 0;
        dp[1][0] = dp[2][0] = dp[2][1] = 0;
        g.clear();
        for (int i = 0; i < n - 3; ++i) {
            scanf ("%d%d", &a, &b);
            --a, --b;
            dp[a][i + 3] = dp[i + 3][a] = 0;
            dp[b][i + 3] = dp[i + 3][b] = 0;
            g.push_back(make_pair(a, b));
        }
        int res = 0;
        for (int i = n - 4; i >= 0; --i) {
            a = g[i].first, b = g[i].second;
            res = max(res, dp[a][i + 3] + dp[i + 3][b] + dp[b][a] + 3);
            dp[a][b] = dp[b][a] = max(dp[a][b], dp[a][i + 3] + 1 + dp[i + 3][b]);
        }
        res = max(res, dp[0][1] + dp[1][2] + dp[2][0] + 3);
        printf ("%d\n", res);
    }
    return 0;
}

