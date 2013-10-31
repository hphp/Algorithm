/*
 * Author: iSea
 * Created Time:  2010/7/17 16:20:03
 * File Name: life_gen.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;
const double eps = 1e-8;

int sgn(double x) {
    return (x > eps) - (x < -eps);
}

int range(int x) {
    return rand() * rand() % x + 1;
}

int range(int x, int y) {
    return x == y? x : range(y - x) + x - 1;
}

double double_rand(int x) {
    return (double)(x * 100 + range(0, 99)) / 100;
}

double nag(double x) {
    return range(3) == 1? -x : x;
}

int main() {
    freopen ("life.in", "w", stdout);
    //bound
    printf ("2\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 1.0\n0.0 1.0 1.0 1.0\n");
    printf ("2\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 1.0\n0.0 0.0 1.0 0.0\n");
    //parallel
    printf ("2\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 0.0\n0.0 1.0 1.0 1.0\n");
    printf ("2\n0.0 1.0\n");
    printf ("0.1 0.0 0.1 1.0\n0.9 0.0 0.9 1.0\n");
    //vertical
    printf ("4\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 0.0\n0.0 1.0 1.0 1.0\n");
    printf ("0.1 0.0 0.1 1.0\n0.9 0.0 0.9 1.0\n");
    printf ("4\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 1.0\n0.0 1.0 1.0 2.0\n");
    printf ("0.0 1.0 1.0 0.0\n0.0 2.0 1.0 1.0\n");
    //speical
    printf ("2\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 1.0\n0.0 0.0 1.0 2.0\n");
    printf ("2\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 2.0\n0.0 0.0 1.0 1.0\n");
    printf ("2\n0.0 1.0\n");
    printf ("0.0 0.5 1.0 1.5\n0.0 0.0 1.0 2.0\n");
    printf ("3\n0.0 1.0\n");
    printf ("0.0 0.0 1.0 1.0\n0.0 2.0 1.0 2.0\n0.0 2.5 2.5 0.0\n");
    //random
    int Case = 20;
    for (int i = 0, n; i < Case; ++i) {
        if (i < 10) n = 100;
        else if (i < 18) n = range(500, 2000);
        else if (i < 19) n = 10000;
        else n = 50000;
        set <double> s;
        printf ("%d\n", n);
        int l = range(0, 2000), r = range(l + 1, l + 2000);
        printf ("%.2lf %.2lf\n", double_rand(l), double_rand(r)); 
        for (int k = 0; k < 10; ++k) {
            double x = nag(double_rand(range(10000)));
            printf ("%.2lf %.2lf %.2lf %.2lf\n", x, 0.0, x, 1.0);
        }
        for (int k = 10; k < n; ++k) {
            double x1, y1, x2, y2;
            while (true) {
                x1 = nag(double_rand(range(8000)));
                y1 = nag(double_rand(range(8000)));
                x2 = nag(double_rand(range(8000)));
                y2 = nag(double_rand(range(8000)));
                if (sgn(x1 - x2) == 0) x2 += 1.0;
                double k = (y2 - y1) / (x2 - x1);
                if (s.find(k) == s.end()) {
                    s.insert(k);
                    printf ("%.2lf %.2lf %.2lf %.2lf\n", x1, y1, x2, y2);
                    break;
                }
            }
        }
    }
    
    return 0;
}

