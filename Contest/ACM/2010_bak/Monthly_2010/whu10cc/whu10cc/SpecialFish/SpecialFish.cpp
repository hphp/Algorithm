/*
 * Author: momodi
 * Created Time:  2010-4-11 15:08:20
 * File Name: SpecialFish.cpp
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

struct Graph {
    static const int maxn = 100;
    int w[maxn][maxn], lx[maxn], ly[maxn], matx[maxn], maty[maxn], n; 
    bool fx[maxn], fy[maxn]; 
    void clear() { 
        memset(w, 0, sizeof(w)); 
        n = 0; 
    } 
    void insert(int u, int v, int c) { 
        get_max(n, max(u + 1, v + 1)); 
        w[u][v] = c; 
    } 
    int match() { 
        memset(ly, 0, sizeof(ly)); 
        for (int i = 0; i < n; ++i) { 
            lx[i] = -maxint; 
            for (int j = 0; j < n; ++j) { 
                get_max(lx[i], w[i][j]); 
            } 
        } 
        memset(matx, -1, sizeof(matx)); 
        memset(maty, -1, sizeof(maty)); 
        for (int i = 0; i < n; ++i) { 
            memset(fx, false, sizeof(fx)); 
            memset(fy, false, sizeof(fy)); 
            if (!dfs(i)) { 
                --i; 
                int p = maxint; 
                for (int k = 0; k < n; ++k) { 
                    if (fx[k] == true) { 
                        for (int j = 0; j < n; ++j) { 
                            if ((fy[j] == false)) { 
                                get_min(p, lx[k] + ly[j] - w[k][j]); 
                            } 
                        } 
                    } 
                } 
                for (int j = 0; j < n; ++j) { 
                    ly[j] += fy[j] * p; 
                } 
                for (int k = 0; k < n; ++k) { 
                    lx[k] -= fx[k] * p; 
                } 
            } 
        } 
        int ans = 0; 
        for (int i = 0; i < n; ++i) { 
            ans += w[maty[i]][i]; 
        } 
        return ans; 
    } 
    bool dfs(int u) { 
        fx[u] = 1; 
        for (int v = 0; v < n; ++v) { 
            if (lx[u] + ly[v] == w[u][v] && fy[v] == false) { 
                fy[v] = true; 
                if (maty[v] == -1 || dfs(maty[v])) { 
                    matx[u] = v; 
                    maty[v] = u; 
                    return true; 
                } 
            } 
        } 
        return false; 
    } 
}; 

Graph g;
int main() {
    int n;
    while (scanf("%d", &n) == 1 && n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &V[i]);
        }
        vector<vector<bool> > adj(n, vector<bool>(n, 0));
        for (int i = 0; i < n; ++i) {
            char buf[n + 1];
            scanf("%s", buf);
            for (int j = 0; j < n; ++j) {
                if (buf[j] == '1') {
                    adj[i][j] = true;
                }
            }
        }
        g.clear();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (adj[i][j]) {
                    g.insert(i, j, V[i] ^ V[j]);
                }
            }
        }
        printf("%d\n", g.match());
    }
    return 0;
}

