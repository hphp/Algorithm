#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(double d) {
    if (d > eps)
        return 1;
    if (d < -eps)
        return -1;
    return 0;
}

void to_normal(double& d, double l = 1.0) {
    if (d > l || d < -l)
        d = l * sgn(d);
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

const int n = 5;

double radius;
point cir[n], center, vic;
vector<point> vec[n];

bool solve();
double get_area();
bool is_less(const point&, const point&);
void get_intersection(const point&, const point&, double, point&, point&);
bool is_valid(const point&);
bool is_valid(const point&, const point&, const point&);
double get_area(const point&, const point&, const point&);
double get_triangle_area(double, double, double);

int main() {
    freopen ("song.in", "r", stdin);
    freopen ("song.out", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%lf", &radius) == EOF)
        return false;
    for (int i = 0; i < n; ++i)
        cir[i].input();
    double area = get_area();
    if (sgn(area) < 0)
        printf("Poor iSea, maybe 2012 is coming!\n");
    else if (sgn(area) == 0)
        printf("Only the point (%.2lf, %.2lf) is for victory.\n", vic.x, vic.y);
    else
        printf("The total possible area is %.2lf.\n", area);
    return true;
}

double get_area() {
    for (int i = 0; i < n; ++i)
        vec[i].clear();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = (cir[i] - cir[j]).len();
            if (sgn(d - radius * 2.0) > 0)
                return -1.0;
            point c1, c2;
            get_intersection(cir[i], cir[j], radius, c1, c2);
            vec[i].push_back(c1);
            vec[i].push_back(c2);
            vec[j].push_back(c1);
            vec[j].push_back(c2);
        }
    }
    double area = 0;
    for (int i = 0; i < n; ++i) {
        center = cir[i];
        sort(vec[i].begin(), vec[i].end(), is_less);
        vec[i].resize(unique(vec[i].begin(), vec[i].end()) - vec[i].begin());
        if (vec[i].size() > 1 && vec[i].back() == vec[i].front())
            vec[i].pop_back();
        if (vec[i].size() == 1) {
            if (is_valid(vec[i].front()))
                vic = vec[i].front();
            continue;
        }
        for (int j = 0; j < vec[i].size(); ++j) {
            if (is_valid(vec[i][j]))
                vic = vec[i][j];
            if (is_valid(cir[i], vec[i][j], vec[i][(j + 1) % vec[i].size()]))
                area += get_area(cir[i], vec[i][j], vec[i][(j + 1) % vec[i].size()]);
        }
    }
    return abs(area);
}

bool is_less(const point& p1, const point& p2) {
    return atan2(p1.y - center.y, p1.x - center.x) < atan2(p2.y - center.y, p2.x - center.x);
}

void get_intersection(const point& p1, const point& p2, double r, point& c1, point& c2) {
    double d = (p1 - p2).len(), p = (d + r * 2.0) / 2.0;
    double h = sqrt(abs(p * (p - d) * (p - r) * (p - r))) * 2.0 / d;
    point pp = p1 + (p2 - p1).trunc(sqrt(abs(r * r - h * h)));
    c1 = pp + (p2 - p1).rotate_right().trunc(h);
    c2 = pp - (p2 - p1).rotate_right().trunc(h);
}

bool is_valid(const point& p) {
    for (int i = 0; i < n; ++i)
        if (sgn((p - cir[i]).len() - radius) > 0)
            return false;
    return true;
}

bool is_valid(const point& c, const point& p1, const point& p2) {
    point p((p1.x + p2.x) / 2.0, (p1.y + p2.y) / 2.0);
    if (p == c) {
        p = c + (p1 - c).rotate_left();
    } else {
        if (sgn((p1 - c) * (p2 - c)) < 0)
            p = c + (c - p).trunc(radius);
        else
            p = c + (p - c).trunc(radius);
    }
    return is_valid(p);
}

double get_area(const point& c, const point& p1, const point& p2) {
    point v1 = p1 - c, v2 = p2 - c;
    double tmp = (v1 ^ v2) / (v1.len() * v2.len());
    to_normal(tmp);
    double ang = acos(tmp), r = radius;
    double area1 = ang * r * r / 2.0, area2 = get_triangle_area(r, r, (p1 - p2).len());
    if (sgn((p1 - c) * (p2 - c)) < 0)
        return pi * r * r - area1 + area2 + p1 * p2 / 2.0;
    return area1 - area2 + p1 * p2 / 2.0;
}

double get_triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    return sqrt(abs(p * (p - a) * (p - b) * (p - c)));
}
