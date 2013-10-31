/*
 * Author: iSea
 * Created Time:  2010/7/16 22:16:14
 * File Name: ancient.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 10000 + 10;
const int inf = (-1u) >> 1;

struct team {
    char s[64];
    bool operator<(const team& t) const {
        return strcmp(s, t.s) < 0;
    }
};

team t[maxn];
int n, len[maxn];

int main() {
    freopen ("ancient.out", "w", stdout);
    while (scanf ("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf ("%s", t[i].s);
        sort (t, t + n);
        for (int i = 0; i < n; ++i)
            len[i] = strlen(t[i].s);
        int ans = len[0] + 1, maxlen = len[0];
        for (int i = 1; i < n; ++i) {
            int comlen = min(len[i], len[i - 1]);
            for (int j = 0; j < len[i] && j < len[i - 1]; ++j) {
                if (t[i].s[j] != t[i - 1].s[j]) {
                    comlen = j;
                    break;
                }
            }
            ans += len[i] + len[i - 1] - 2 * comlen + 1;
            maxlen = max(maxlen, len[i]);
        }
        ans += len[n - 1] - maxlen;
        printf ("%d\n", ans);
    }
            
    return 0;
}

