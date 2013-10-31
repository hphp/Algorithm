/*
 * Author: momodi
 * Created Time:  2010-4-14 15:55:08
 * File Name: Precious.cpp
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

const double eps = 1e-9;
int sgn(double a) {
    return (a > eps) - (a < -eps);
}
#define SQR(v) ((v) * (v))
struct P {
    double x, y;
    P(double x, double y):x(x), y(y){}
    P():x(0), y(0){}
    double cross(P a, P b) const {
        return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
    }
    double dot(P a, P b) const {
        return (a.x - x) * (b.x - x) + (a.y - y) * (b.y - y);
    }
    double dist(P a) const {
        return sqrt(SQR(a.x - x) + SQR(a.y - y));
    }
};


const int maxn = 110;
int n, m;
P poly[maxn];
int type[maxn];

bool inter(P a, P b, P c, P d) {
    double s1 = a.cross(b, c);
    double s2 = a.cross(b, d);
    if (sgn(s1 - s2) == 0) {
        return false;
    }
    P t = P((c.x * s2 - d.x * s1) / (s2 - s1), (c.y * s2 - d.y * s1) / (s2 - s1));
    return sgn(t.dot(a, b)) < 0 && sgn(t.dot(c, d)) <= 0;
}
int inside(const P &p) {
    int ans = -1;
    for (P *it = poly + n - 1, *jt = poly; jt != poly + n; it = jt++) {
        double t = it->y < jt->y ? it->cross(*jt, p) : jt->cross(*it, p);
        if (sgn(t) == 0 && sgn(p.dot(*it, *jt)) <= 0) {
            return 0;   // point p is on the polygon.
        }
        if (sgn(t) < 0 && ((sgn(it->y - p.y) < 0) ^ (sgn(jt->y - p.y) < 0))) {
            ans *= -1;
        }
    } 
    return ans; //if ans == 1 point is in the polygon and if ans == -1 point is out the polygon.
}

bool conn(P S, P T) {
    if (inside(P((S.x + T.x) / 2, (S.y + T.y) / 2)) == -1) {
        return false;
    }
    for (int i = n - 1, j = 0; j < n; i = j++) {
        if (inter(S, T, poly[i], poly[j])) {
            return false;
        }
    }
    return true;
}

double adj[maxn][maxn];

double solve() {
    for (int i = 0; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (conn(poly[i], poly[j])) {
                adj[i][j] = adj[j][i] = poly[i].dist(poly[j]);
            } else {
                adj[i][j] = adj[j][i] = 1e100;
            }
        }
    }
    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                get_min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    double tot = 0, OK = 0;
    for (int i = 0; i < n; ++i) {
        if (type[i] != 0) {
            ++tot;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (type[i] == -1 && type[j] == 1 && sgn(adj[n][i] + adj[n][j] - m) <= 0) {
                ++OK;
            }
        }
    }
    //for (int i = 0; i < n; ++i) {
        //printf("%.2f ", adj[i][n]);
    //}
    //puts("");
    //printf("%.0f %.0f %.0f\n", I, O, tot);
    if (tot == 0) return 0;
    return OK / (tot * tot);
}

int main() {
    while (scanf("%d %d", &n, &m) == 2 && (n || m)) {
        for (int i = 0; i <= n; ++i) {
            scanf("%lf %lf", &poly[i].x, &poly[i].y);
            if (i < n) {
                scanf("%d", type + i);
            }
        }
        printf("%.9f\n", solve());
    }
    return 0;
}

