/*
 * Author: momodi
 * Created Time:  2010-4-15 14:32:25
 * File Name: Railway.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int maxn = 10000;
const int maxm = 100000;
int n, m;
vector<int> adj[maxn];
int pre[maxn], low[maxn];
int ans[3];
int tim;
void dfs(int f, int v, int &anstype, int &anscnt) {
    anstype = anscnt = 0;
    int newtype = 0, newcnt = 0;
    low[v] = pre[v] = tim++;
    for (vector<int>::const_iterator it = adj[v].begin(); it != adj[v].end(); ++it) {
        if (*it != f) {
            if (pre[*it] == -1) {
                dfs(v, *it, newtype, newcnt);
                ++newcnt;
                if (low[*it] >= pre[v]) {
                    ans[min(2, newtype)] += newcnt;
                } else {
                    get_min(low[v], low[*it]);
                    anstype += newtype;
                    anscnt += newcnt;
                }
            } else {
                get_min(low[v], pre[*it]);
                if (pre[*it] < pre[v]) {
                    ++anstype;
                    ++anscnt;
                }
            }
        }
    }
}

int main() {
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        tim = 0;
        fill(pre, pre + n, -1);
        fill(ans, ans + 3, 0);
        int type, cnt;
        for (int i = 0; i < n; ++i) {
            if (pre[i] == -1) {
                dfs(i, i, type, cnt);
            }
        }
        //fprintf(stderr, "%d %d %d\n", ans[0], ans[1], ans[2]);
        assert(ans[0] + ans[1] + ans[2] == m);
        printf("%d %d\n", ans[0], ans[2]);
        
    }
    return 0;
}

