/*
 * Author: iSea
 * Created Time:  2010/7/16 11:20:16
 * File Name: treasure_gen.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 100 + 10;
const int inf = (-1u) >> 1;

int range(int x) {
    return rand() * rand() % x + 1;
}

int range(int x, int y) {
    return x == y? x : range(y - x) + x - 1;
}

char s[maxn][maxn];
bool v[maxn][maxn];

char get_ch(int x) {
    if (x < 26) return (char)('A' + x);
    else return (char)('a' + x - 26);
}

void Case_Small() {
    int n = range(4, 10), m = range(4, 10);
    int rally_num = 10;
    if (n * m <= 30) rally_num = 5;
    printf ("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp = range(5);
            if (tmp <= 3) s[i][j] = '.';
            else if (tmp <= 4) s[i][j] = '*';
            else s[i][j] = '#';
        }
        s[i][m] = '\0';
    }
    memset (v, false, sizeof(v));
    for (int i = 0; i < rally_num; ++i) {
        int px = range(n) - 1, py = range(m) - 1;
        while (v[px][py])
            px = range(n) - 1, py = range(m) - 1;
        v[px][py] = true;
        s[px][py] = get_ch(i);
    }
    for (int i = 0; i < n; ++i) 
        puts(s[i]);
}

void Case_Large(bool f) {
    int n = range(20, 100), m = range(20, 100);
    if (f) n = 100, m = 100;
    int rally_num = range(40, 52);
    printf ("%d %d\n", n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int tmp = range(5);
            if (tmp <= 3) s[i][j] = '.';
            else if (tmp <= 4) s[i][j] = '*';
            else s[i][j] = '#';
        }
        s[i][m] = '\0';
    }
    memset (v, false, sizeof(v));
    for (int i = 0; i < rally_num; ++i) {
        int px = range(n) - 1, py = range(m) - 1;
        while (v[px][py])
            px = range(n) - 1, py = range(m) - 1;
        v[px][py] = true;
        s[px][py] = get_ch(i);
    }
    for (int i = 0; i < n; ++i) 
        puts(s[i]);
}
        
int main() {
    int Case = 50;
    freopen ("treasure.in", "w", stdout);
    for (int i = 0; i < Case; ++i) {
        if (i < 30) Case_Small();
        else Case_Large(i > 47);
    }
    return 0;
}

