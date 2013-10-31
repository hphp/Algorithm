/*
 * Author: xay
 * Created Time:  2010-4-9 15:10:52
 * File Name: Mahjong.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int maxint = -1u>>1;

bool melds(int n, int *a) {
    if (n == 0) return true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 9; ++j) {
            int k = i * 9 + j;
            if (a[k] >= 3) {
                a[k] -= 3;
                if (melds(n - 3, a)) return true;
                a[k] += 3;
            }
            if (j < 7 && a[k] > 0 && a[k + 1] > 0 && a[k + 2] > 0) {
                --a[k];
                --a[k + 1];
                --a[k + 2];
                if (melds(n - 3, a)) return true;
                ++a[k + 2];
                ++a[k + 1];
                ++a[k];
            }
        }
    }
    return false;
}
bool check(int n, int *a) {
    int tile[30];
    memcpy(tile, a, sizeof(tile));
    for (int i = 0; i < 27; ++i) {
        if (tile[i] >= 2) {
            tile[i] -= 2;
            if (melds(n - 2, tile)) return true;
            tile[i] += 2;
        }
    }
    return false;
}
int main() {
    int t, ca = 0, n = 13;
    int a[30];
    char s[5];
    scanf("%d", &t);
    while (t--) {
        memset(a, 0, sizeof(a));
        printf("Case %d:", ++ca);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            int x = 0;
            if (s[1] == 'b') x = 1;
            else if (s[1] == 'c') x = 2;
            x = x * 9 + s[0] - '1';
            ++a[x];
        }
        bool flag = false;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 9; ++j) {
                int k = i * 9 + j;
                if (a[k] >= 4) continue;
                ++a[k];
                if (check(n + 1, a)) {
                    printf(" %d", j + 1);
                    if (i == 0) printf("s");
                    else if (i == 1) printf("b");
                    else printf("c");
                    flag = true;
                }
                --a[k];
            }
        }
        if (!flag) printf(" None");
        printf("\n");
    }
    return 0;
}

