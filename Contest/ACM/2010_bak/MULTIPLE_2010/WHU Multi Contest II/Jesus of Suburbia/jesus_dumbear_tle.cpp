/*
 * Author: Dumbear
 * Created Time:  2010/8/18 20:23:08
 * File Name: jesus.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int max_n = 10 + 2;
const int mod = 14121413;

struct object {
    int n, v1[max_n], v2[max_n];
    void input(int size) {
        n = size;
        for (int i = 0; i < n; ++i)
            scanf("%d", &v1[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &v2[i]);
        for (int i = 0; i < n; ++i)
            if (v1[i] > v2[i])
                swap(v1[i], v2[i]);
    }
    long long get_jesus() const {
        long long jesus = 1;
        for (int i = 0; i < n; ++i)
            jesus = (jesus * (v2[i] - v1[i])) % mod;
        return jesus;
    }
};

const int max_m = 100 + 10;

int m, n;
object ob[max_m], cur_ob;

bool solve();
long long get_jesus();
long long get_jesus(int, int);

int main() {
    freopen("jesus.in", "r", stdin);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d%d", &m, &n) == EOF)
        return false;
    for (int i = 0; i < m; ++i)
        ob[i].input(n);
    printf("%I64d\n", get_jesus());
    return true;
}

long long get_jesus() {
    long long jesus = 0;
    for (int i = 0; i < m; ++i) {
        cur_ob = ob[i];
        jesus = (jesus + get_jesus(i + 1, 0)) % mod;
    }
    return jesus;
}

long long get_jesus(int id, int p) {
    if (id == m)
        return cur_ob.get_jesus();
    long long jesus = 0;
    if (ob[id].v1[p] > cur_ob.v1[p]) {
        int tmp = cur_ob.v2[p];
        cur_ob.v2[p] = min(cur_ob.v2[p], ob[id].v1[p]);
        jesus = (jesus + get_jesus(id + 1, 0)) % mod;
        cur_ob.v2[p] = tmp;
    }
    if (ob[id].v2[p] < cur_ob.v2[p]) {
        int tmp = cur_ob.v1[p];
        cur_ob.v1[p] = max(cur_ob.v1[p], ob[id].v2[p]);
        jesus = (jesus + get_jesus(id + 1, 0)) % mod;
        cur_ob.v1[p] = tmp;
    }
    if (p != n - 1 && ob[id].v2[p] > cur_ob.v1[p] && ob[id].v1[p] < cur_ob.v2[p]) {
        int tmp1 = cur_ob.v1[p], tmp2 = cur_ob.v2[p];
        cur_ob.v1[p] = max(cur_ob.v1[p], ob[id].v1[p]);
        cur_ob.v2[p] = min(cur_ob.v2[p], ob[id].v2[p]);
        jesus = (jesus + get_jesus(id, p + 1)) % mod;
        cur_ob.v1[p] = tmp1;
        cur_ob.v2[p] = tmp2;
    }
    return jesus;
}
