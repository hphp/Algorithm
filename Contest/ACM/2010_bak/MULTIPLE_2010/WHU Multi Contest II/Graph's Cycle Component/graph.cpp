/*
 * Author: momodi
 * Created Time:  2010-7-19 14:48:03
 * File Name: CycleGraph.cpp
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
const int maxn = 100000;
int f[maxn];
const int maxm = 300000;
int U[maxm], V[maxm];
bool flag[maxn];
int deg[maxn];

int find(int v) {
    int fa = f[v];
    while (fa != f[fa]) {
        fa = f[fa];
    }
    while (v != fa) {
        int tmp = f[v];
        f[v] = fa;
        v = tmp;
    }
    return fa;
}
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        for (int i = 0; i < n; ++i) {
            f[i] = i;
            deg[i] = 0;
            flag[i] = true;
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d", U + i, V + i);
            int u = find(U[i]);
            int v = find(V[i]);
            f[u] = v;
            ++deg[U[i]];
            ++deg[V[i]];
        }
        for (int i = 0; i < n; ++i) {
            if (deg[i] != 2) {
                flag[find(i)] = false;
            }
        }
        int ansa = 0, ansb = 0;
        for (int i = 0; i < n; ++i) {
            if (i == find(i)) {
                ++ansa;
                if (flag[i]) {
                    ++ansb;
                }
            }
        }
        printf("%d %d\n", ansa, ansb);
    }
    return 0;
}

