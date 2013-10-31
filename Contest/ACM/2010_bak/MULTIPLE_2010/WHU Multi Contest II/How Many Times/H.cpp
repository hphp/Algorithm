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
    point(double _x = 0, double _y = 0): x(_x), y(_y) {
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    double len() const {
        return sqrt(x * x + y * y);
    }
    point trunc(double l) const {
        double r = l / len();
        return point(x * r, y * r);
    }
    point rotate_left() const {
        return point(-y, x);
    }
    point rotate_right() const {
        return point(y, -x);
    }
};

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

struct circle {
    point c;
    double r;
    circle() {
    }
    circle(const point& _c, double _r): c(_c), r(_r) {
    }
    void input() {
        c.input();
        scanf("%lf", &r);
    }
};

const int max_n = 100 + 10;

int n;
circle cir[max_n];

bool solve();
int get_max_layer();
bool get_intersection(const circle&, const circle&, point&, point&);
int get_layer(const point&);

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d", &n) == EOF)
        return false;
    for (int i = 0; i < n; ++i)
        cir[i].input();
    printf("%d\n", get_max_layer());
    return true;
}

int get_max_layer() {
    int layer = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            point c1, c2;
            if (get_intersection(cir[i], cir[j], c1, c2)) {
                layer = max(layer, get_layer(c1));
                layer = max(layer, get_layer(c2));
            }
        }
    }
    for (int i = 0; i < n; ++i)
        layer = max(layer, get_layer(point(cir[i].c.x + cir[i].r, cir[i].c.y)));
    return layer;
}

bool get_intersection(const circle& cir1, const circle& cir2, point& c1, point& c2) {
    double d = (cir1.c - cir2.c).len();
    if (sgn(d - (cir1.r + cir2.r)) > 0 || sgn(d - abs(cir1.r - cir2.r)) < 0)
        return false;
    double p = (d + cir1.r + cir2.r) / 2.0;
    double h = sqrt(abs(p * (p - d) * (p - cir1.r) * (p - cir2.r))) * 2.0 / d;
    point pp = cir1.c + (cir2.c - cir1.c).trunc(sqrt(abs(cir1.r * cir1.r - h * h)));
    c1 = pp + (cir2.c - cir1.c).rotate_right().trunc(h);
    c2 = pp - (cir2.c - cir1.c).rotate_right().trunc(h);
    return true;
}

int get_layer(const point& p) {
    int layer = 0;
    for (int i = 0; i < n; ++i)
        if (sgn((p - cir[i].c).len() - cir[i].r) <= 0)
            ++layer;
    return layer;
}
