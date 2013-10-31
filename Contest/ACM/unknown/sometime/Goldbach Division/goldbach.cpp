/*
 * Author: iSea
 * Created Time:  2010/7/17 9:42:42
 * File Name: goldbach.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 20000 + 10;
const int inf = (-1u) >> 1;

bool f[maxn];
int g[maxn], prime[2270], cnt = 0, n;

void create() {
    f[0] = f[1] = true;
    for (int i = 2; i < maxn; ++i) {
        if (!f[i])
            prime[cnt++] = i;
        for (int j = 0; (long long)prime[j] * i < maxn; ++j) {
            f[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void make() {
	for (int i = 1; i < cnt; ++i) 
		for (int j = i + 1; j < cnt && prime[i] + prime[j] < maxn; ++j)
            ++g[prime[i] + prime[j]];
    for (int i = 2; i < maxn; i += 2) 
        for (int j = 1; j < cnt && prime[j] + i < maxn; ++j) {
            g[prime[j] + i] += g[i];
            if (i > prime[j] && i - prime[j] != prime[j] && !f[i - prime[j]])
                --g[prime[j] + i];
        }
    for (int i = 1; i < maxn; i += 2)
        g[i] /= 3;
}

int main() {
    freopen ("goldbach.out", "w", stdout);
    create();
    make();
    while (scanf ("%d", &n) != EOF)
        printf ("%d\n", g[n]);
    return 0;
}

