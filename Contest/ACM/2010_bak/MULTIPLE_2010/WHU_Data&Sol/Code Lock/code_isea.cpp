/*
 * Author: iSea
 * Created Time:  2010/7/18 15:29:25
 * File Name: code_isea.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 2000 + 10;
const int inf = (-1u) >> 1;
const int mod = 1000000007;

struct disjoint_set {
    int p[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i)
            p[i] = i;
    }
    int find(int x) {
        return (x == p[x])? x : p[x] = find(p[x]);
    }
    void Union(int x, int y) {
        p[find(y)] = find(x);
    }
};

int mon(int a, int p, int m) {
    int res = 1;
    while (p) {
        if (p & 1) res = (long long)res * a % m;
        a = (long long)a * a % mod;
        p >>= 1;
    }
    return res;
}

disjoint_set ds;
int n, m;
map <int, int> mp;

int main() {
    freopen ("code.in", "r", stdin);
    freopen ("code_isea.in", "w", stdout);
    while (scanf ("%d%d", &n, &m) != EOF) {
        ds.init();
        mp.clear();
        int cnt = 0, num = 1;
        for (int i = 0, a, b; i < m; ++i) {
            scanf ("%d%d", &a, &b);
            if (mp.find(a) == mp.end()) mp[a] = num++;
            if (mp.find(++b) == mp.end()) mp[b] = num++;
            if (ds.find(mp[a]) != ds.find(mp[b])) {
                ++cnt;
                ds.Union(mp[a], mp[b]);
            }
        }
        printf ("%d\n", mon(26, n - cnt, mod));
    }
    
    return 0;
}

