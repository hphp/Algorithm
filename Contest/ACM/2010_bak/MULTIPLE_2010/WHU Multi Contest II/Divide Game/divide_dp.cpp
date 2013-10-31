/*
 * Author: iSea
 * Created Time:  2010/8/17 14:35:27
 * File Name: divide_dp.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 100 + 10;
const int inf = (-1u) >> 1;

char s[50010];
bool dp[maxn][maxn][2];
int ct[maxn][26];

int main() {
    freopen ("divide.in", "r", stdin);
    freopen ("divide_dp.out", "w", stdout);
    while (scanf ("%s", s) != EOF) {
        int n = strlen(s);
        if (n > 100) {
            puts ("Yes");
            continue;
        }
        memset (dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            dp[0][i][1] = true;
            for (int h = 0; h < 26; ++h)
                ct[i][h] = ct[i - 1][h] + (s[i - 1] - 'A' == h);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                for (int s = 0; s < 2; ++s) {
                    if (!dp[i][j][s]) continue;
                    for (int k = j + 1; k <= n; ++k) {
                        int cnt = 0;
                        bool flag = true;
                        for (int h = 0; h < 26; ++h) {
                            if (ct[k][h] - ct[j][h] != 0 &&
                                ct[k][h] - ct[j][h] == ct[j][h] - ct[i][h]) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) {
                            dp[j][k][!s] = true;
                        }
                    }
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; ++i)
            flag |= dp[i][n][0];
        printf ("%s\n", flag? "Yes" : "No");
    }
    return 0;
}

