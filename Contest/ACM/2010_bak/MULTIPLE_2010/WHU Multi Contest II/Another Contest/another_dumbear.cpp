/*
 * Author: Dumbear
 * Created Time:  2010/8/18 16:40:09
 * File Name: another.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int max_n = 1000 + 10, max_s = 1000 + 10;

int n, s, p, g[max_n][max_s], score[max_s], num[max_s], rank;

bool solve();
void compute_rank();

int main() {
    freopen ("another.in", "r", stdin);
    freopen ("another_dumbear.out", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d%d%d", &n, &s, &p) == EOF)
        return false;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < s; ++j)
            scanf("%d", &g[i][j]);
    compute_rank();
    printf("%d %d\n", score[p], rank);
    return true;
}

void compute_rank() {
    memset(score, 0, sizeof(score));
    memset(num, 0, sizeof(num));
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < s; ++j)
            if (g[i][j] == 0)
                ++cnt;
        for (int j = 0; j < s; ++j) {
            if (g[i][j] == 1) {
                score[j] += cnt;
                ++num[j];
            }
        }
    }
    --p;
    rank = 1;
    for (int j = 0; j < s; ++j)
        if (score[j] > score[p] || (score[j] == score[p] && num[j] > num[p]) || (score[j] == score[p] && num[j] == num[p] && j < p))
            ++rank;
}
