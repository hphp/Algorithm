/*
 * Author: iSea
 * Created Time:  2010/7/17 9:54:16
 * File Name: goldbach_TLE.cpp
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
int g[maxn], prime[maxn], cnt = 0, n;

void create() {
	for (int i = 2; i < maxn; ++i) {
		if (!f[i])
			prime[cnt++] = i;
		for (int j = 0; prime[j] * i < maxn; ++j) {
			f[prime[j] * i] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}

void make() {
	for (int i = 1; i < cnt; ++i) {
		for (int j = i + 1; j < cnt && prime[i] + prime[j] < maxn; ++j) {
			++g[prime[i] + prime[j]];
			for (int k = j + 1; k < cnt && prime[i] + prime[j] + prime[k] < maxn; ++k)
				++g[prime[i] + prime[j] + prime[k]];
		}
	}
}

int main() {
    freopen ("goldbach.in", "r", stdin);
    freopen ("goldbach_TLE.out", "w", stdout);
	create();
	make();
	while (scanf ("%d", &n) != EOF)
		printf ("%d\n", g[n]);
    return 0;
}

