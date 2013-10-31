#include <iostream>

using namespace std;
const int MOD = 100000007;
typedef long long int64;
int64 power(int64 a, int64 b, int64 c) {
    if (b == 0) return 1;
    int64 tmp = power(a, b >> 1, c);
    if (b & 1)
        return tmp * tmp % c * a % c;
    return tmp * tmp % c;
}

int64 inv(int64 a, int64 p) {
    return power(a, p - 2, p);
}

int64 solve(int64 m, int64 n, int64 p) {
    int64 A = m * n + 1;
    int64 res = 1;
    for (int i = 1; i <= n; ++ i)
        res = res * (A - n + i) % p * inv(i, p) % p;
    res = res * inv(A, p) % p;
    return res;
}

int main() {
    freopen("problem.in", "r", stdin);
    freopen("problem.out", "w", stdout);
    int m, n;
    while(scanf("%d%d", &n, &m) == 2)
        printf("%lld\n", solve(m, n, MOD));
    return 0;
}
