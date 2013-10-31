/*
 * Author: iSea
 * Created Time:  2010/7/18 16:55:33
 * File Name: integer_isea.cpp
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
const int mod = 100007;

int step[mod], cycle, left, dp[22];

void get_step(int m) {
    memset (step, -1, sizeof(step));
    step[0] = 0;
    int now = 0, cnt = 1;
    while (true) {
        now = (now * 10 + 2) % m;
        if (step[now] != -1) {
            cycle = cnt - step[now];
            left = step[now];
            break;
        }
        step[now] = cnt++;
    }
}

int cal(int x, int m) {
    if (x == 1) return 1;
    get_step(m);
    int now = cal(x - 1, cycle);
    int res = 0;
    while (now--) {
        res = res * 10 + 2;
        if (res >= mod) {
            int x = (res - mod) / m;
            res -= x * m;
        }
    }
    return res;
}

int n;

int main() {
    for (int i = 1; i < 10; ++i)
        dp[i] = (9 * cal(i, mod) + 1) % mod;
    freopen ("integer.in", "r", stdin);
    freopen ("integer_isea.in", "w", stdout);
    while (scanf ("%d", &n) != EOF) {
        if (n <= 10)
            printf ("%d\n", n == 1? 1 : dp[n - 1]);
        else if (n & 1)
            printf ("%d\n", dp[8]);
        else
            printf ("%d\n", dp[9]);
    }
        
    return 0;
}

