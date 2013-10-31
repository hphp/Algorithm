/*
 * Author: iSea
 * Created Time:  2010/4/20 16:29:42
 * File Name: date.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl

const int maxn = 29 * 29 * 4 * 2 + 10;
const int inf = (-1u) >> 1;

struct pnode {
    int v, d;
    pnode(int _v = 0, int _d = 0): v(_v), d(_d) {
    }
    bool operator<(const pnode& a) const {
        return d > a.d;
    }
};

bool v[maxn];
int t[32][32], n, m, hh, mm, tot, dis[maxn];

void init() {
    --n, --m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) 
            scanf ("%d", &t[i][j]);
    scanf ("%d:%d", &hh, &mm);
}

priority_queue <pnode> pq;
    
int getid(int x, int y, int d, int choose = 0) {
    return x * 4 * m + y * 4 + d + choose * tot;
}

int getds(int tds, int tm, int type) {
    if (type)
        return tds >= tm && tds < 2 * tm? 0 : tm - tds;
    return tds < tm? 0 : 2 * tm - tds;
}

void update(int id, int ds) {
    if (!v[id] && dis[id] > ds) {
        dis[id] = ds;
        pq.push(pnode(id, ds));
    }
}

void getnext(int id, int ds) {
    int choose = id >= tot? 1 : 0;
    if (id >= tot) id -= tot;
    int d = id % 4; id /= 4;
    int r = id % m, c = id / m, tm = t[c][r];
    int tds = ds % (2 * tm);
    if (d == 0) {
        update(getid(c, r, 1, choose), ds + 1 + getds(tds, tm, 0));
        update(getid(c, r, 2, choose), ds + 1 + getds(tds, tm, 1));
        if (r > 0)
            update(getid(c, r - 1, 1, choose), ds + 2);
        if (c > 0)
            update(getid(c - 1, r, 2, choose), ds + 1);
        if (!choose) {
            update(getid(c, r, 0, 1), ds);
            update(getid(c, r, 1, 1), ds + 1);
            update(getid(c, r, 2, 1), ds + 1);
        }
    }
    else if (d == 1) {
        update(getid(c, r, 0, choose), ds + 1 + getds(tds, tm, 0));
        update(getid(c, r, 3, choose), ds + 1 + getds(tds, tm, 1));
        if (r < m - 1)
            update(getid(c, r + 1, 0, choose), ds + 2);
        if (c > 0)
            update(getid(c - 1, r, 3, choose), ds + 1);
        if (!choose) {
            update(getid(c, r, 1, 1), ds);
            update(getid(c, r, 0, 1), ds + 1);
            update(getid(c, r, 3, 1), ds + 1);
        }
    }
    else if (d == 2) {
        update(getid(c, r, 0, choose), ds + 1 + getds(tds, tm, 1));
        update(getid(c, r, 3, choose), ds + 1 + getds(tds, tm, 0));
        if (r > 0)
            update(getid(c, r - 1, 3, choose), ds + 2);
        if (c < n - 1)
            update(getid(c + 1, r, 0, choose), ds + 1);
        if (!choose) {
            update(getid(c, r, 2, 1), ds);
            update(getid(c, r, 0, 1), ds + 1);
            update(getid(c, r, 3, 1), ds + 1);
        }
    }
    else if (d == 3) {
        update(getid(c, r, 1, choose), ds + 1 + getds(tds, tm, 1));
        update(getid(c, r, 2, choose), ds + 1 + getds(tds, tm, 0));
        if (r < m - 1) 
            update(getid(c, r + 1, 2, choose), ds + 2);
        if (c < n - 1)
            update(getid(c + 1, r, 1, choose), ds + 1);
        if (!choose) {
            update(getid(c, r, 3, 1), ds);
            update(getid(c, r, 1, 1), ds + 1);
            update(getid(c, r, 2, 1), ds + 1);
        }
    }
}

void dijkstra() {
    while (!pq.empty())
        pq.pop();
    tot = n * m * 4;
    for (int i = 0; i < tot * 2; ++i) {
        v[i] = false;
        dis[i] = inf;
    }
    dis[0] = hh * 60 + mm;
    pq.push(pnode(0, dis[0]));
    for (int i = 0, k; i < tot * 2; ++i) {
        do {
            k = pq.top().v;
            pq.pop();
        }while (v[k]);
        v[k] = true;
        getnext(k, dis[k]);
    }
}

void solve() {
    dijkstra();
    int ans = dis[getid(n - 1, m - 1, 3, 1)];
    printf ("%02d:%02d\n", ans / 60, ans % 60);
}

int main() {
    freopen ("date.out", "w", stdout);
    while (scanf ("%d%d", &n, &m) != EOF) {
        init();
        solve();
    }
    
    return 0;
}

