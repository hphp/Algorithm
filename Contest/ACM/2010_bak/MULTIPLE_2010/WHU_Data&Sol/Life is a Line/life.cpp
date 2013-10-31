/*
 * Author: iSea
 * Created Time:  2010/7/17 16:13:17
 * File Name: life.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 50000 + 10;
const int inf = (-1u) >> 1;
const double eps = 1e-8;

#define lowbit(x) ((x) & (-(x)))

int sgn(double x) {
    return (x > eps) - (x < -eps);
}

struct point {
    double x, y;
    point (double _x = 0, double _y = 0): x(_x), y(_y) {
    }
    point operator+(const point& p) const {
        return point(x + p.x, y + p.y);
    }
    point operator-(const point& p) const {
        return point(x - p.x, y - p.y);
    }
    double operator*(const point& p) const {
        return x * p.y - y * p.x;
    }
    double operator^(const point& p) const {
        return x * p.x + y * p.y;
    }
    double len() const {
        return sqrt(x * x + y * y);
    }
    void input() {
        scanf ("%lf%lf", &x, &y);
    }
    point trunc(double l) const {
        double r = l / len();
        return point(x * r, y * r);
    }
};

struct line {
    point a, b;
    line() {
    }
    void input() {
        a.input(), b.input();
    }
};

struct bit {
    int a[maxn];
    void clear() {
        memset(a, 0, sizeof(a));
    }
    void update(int x, int y) {
        for (; x < maxn; x += lowbit(x))
            a[x] += y;
    }
    int getsum(int x) {
        int res = 0;
        for (; x > 0; x -= lowbit(x))
            res += a[x];
        return res;
    }
};

bit t;
double l, r, pl[maxn], pr[maxn], hr[maxn];
int n, id[maxn];

bool comp(int x, int y) {
    return make_pair(pl[x], pr[x]) > make_pair(pl[y], pr[y]);
    return sgn(pl[x] - pl[y]) == 0? 
        sgn(pr[x] - pr[y]) > 0 : sgn(pl[x] - pl[y]) > 0;
}

double cal(const line& l, double x) {
    point c = l.b - l.a;
    double len = c.len();
    double x1 = l.b.x - l.a.x, x2 = x - l.a.x;
    c = c.trunc(len * x2 / x1);
    return (l.a + c).y;
}

int main() {
    freopen ("life.out", "w", stdout);
    while (scanf ("%d", &n) != EOF) {
        scanf ("%lf%lf", &l, &r);
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; ++i) {
            line li;
            li.input();
            if (sgn(li.a.x - li.b.x) == 0) {
                if (sgn(li.a.x - l) > 0 && sgn(li.a.x - r) < 0)
                    ++cnt2;
            }
            else {
                pl[cnt1] = cal(li, l);
                pr[cnt1] = cal(li, r);
                hr[cnt1] = pr[cnt1];
                id[cnt1] = cnt1;
                ++cnt1;
            }
        }
        sort (id, id + cnt1, comp);
        sort (hr, hr + cnt1);
        int ans = 0;
        n = unique(hr, hr + cnt1) - hr;
        t.clear();
        for (int i = 0; i < cnt1; ++i) {
            int pid = lower_bound(hr, hr + n, pr[id[i]]) - hr + 1;
            ans += t.getsum(pid);
            t.update(pid + 1, 1);
        }
        ans += cnt1 * cnt2;
        printf ("%d\n", ans);
    }
    
    return 0;
}

