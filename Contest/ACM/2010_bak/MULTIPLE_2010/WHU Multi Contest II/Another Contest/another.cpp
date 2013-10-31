/*
 * Author: iSea
 * Created Time:  2010/8/15 10:17:15
 * File Name: another.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;

struct con {
    int id, sol, s;
    con(int _id = 0, int _sol = 0, int _s = 0):
        id(_id), sol(_sol), s(_s) {}
    bool operator<(const con& a) const {
        if (s == a.s)
            return sol == a.sol? id < a.id : sol > a.sol;
        return s > a.s;
    }
};

con c[maxn];
int n, s, p, t[maxn];

int main() {
    freopen ("another.out", "w", stdout);
    while (scanf ("%d%d%d", &n, &s, &p) != EOF) {
        for (int j = 0; j < s; ++j)
            c[j] = con(j + 1, 0, 0);
        for (int i = 0; i < n; ++i) {
            int num = 0;
            for (int j = 0; j < s; ++j) {
                scanf ("%d", &t[j]);
                num += t[j];
            }
            for (int j = 0; j < s; ++j) {
                if (t[j]) {
                    ++c[j].sol;
                    c[j].s += s - num;
                }
            }
        }
        sort (c, c + s);
        for (int j = 0; j < s; ++j) {
            if (c[j].id == p) {
                printf ("%d %d\n", c[j].s, j + 1);
                break;
            }
        }
    }
    
    return 0;
}

