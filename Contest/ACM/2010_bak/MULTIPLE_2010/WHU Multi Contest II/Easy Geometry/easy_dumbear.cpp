#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-8;

int sgn(double d) {
    if (d > eps)
        return 1;
    if (d < -eps)
        return -1;
    return 0;
}

struct point {
    double x, y;
    int p;
    point(double _x = 0, double _y = 0): x(_x), y(_y) {
    }
    void input() {
        scanf("%lf%lf%d", &x, &y, &p);
    }
};

bool operator==(const point& p1, const point& p2) {
    return sgn(p1.x - p2.x) == 0 && sgn(p1.y - p2.y) == 0;
}

point operator+(const point& p1, const point& p2) {
    return point(p1.x + p2.x, p1.y + p2.y);
}

point operator-(const point& p1, const point& p2) {
    return point(p1.x - p2.x, p1.y - p2.y);
}

double operator^(const point& p1, const point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}

double operator*(const point& p1, const point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

const int max_n = 1000 + 10;

int n;
point p[max_n], p_buf[max_n], center;

bool solve();
double get_expectation();
double get_probability(const point&);
bool is_less(const point&, const point&);

int main() {
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d", &n) == EOF)
        return false;
    for (int i = 0; i < n; ++i)
        p[i].input();
    printf("%.2lf\n", get_expectation());
    return true;
}

double get_expectation() {
    copy(p, p + n, p_buf);
    double e = 0;
    for (int i = 0; i < n; ++i)
        e += get_probability(p_buf[i]);
    return e;
}

double get_probability(const point& c) {
    center = c;
    sort(p, p + n, is_less);
    double pro = 0, p0 = c.p / 100.0;// p1 = (100 - p[0].p) / 100.0;
    double p1 = log((100 - p[0].p) / 100.0);
    int pos = 1;
    for (int i = 0; i < n - 1; ++i) {
        p0 *= (100 - p[i].p) / 100.0;
        if (i == 0 || sgn((p[i - 1] - c) * (p[i] - c)) > 0){
//            p1 /= (100 - p[i].p) / 100.0;
            p1 -= log((100 - p[i].p) / 100.0);
        }
        if (pos == i)
            pos = (pos + 1) % (n - 1);
        while (sgn((p[i] - c) * (p[pos] - c)) > 0) {
//            p1 *= (100 - p[pos].p) / 100.0;
            p1 += log((100 - p[pos].p) / 100.0);
            pos = (pos + 1) % (n - 1);
        }
        pro += exp(p1) * (c.p / 100.0) * (p[i].p / 100.0);
    }
    pro += p0;
    return pro;
}

bool is_less(const point& p1, const point& p2) {
    if (p1 == p2)
        return false;
    if (p1 == center)
        return false;
    if (p2 == center)
        return true;
    return sgn(atan2(p1.y - center.y, p1.x - center.x) - atan2(p2.y - center.y, p2.x - center.x)) < 0;
}

