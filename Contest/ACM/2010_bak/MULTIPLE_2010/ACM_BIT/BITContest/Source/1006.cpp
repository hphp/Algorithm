#define UNI 9997
#include <cstdio>
#include <cstring>

using namespace std;

int m[3][3] = {
    {5, 1, 0},
    {-7, 0, 1},
    {4, 0, 0}
};

void cpy(int a[][3], int b[][3]) {
    int i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void mat_multi(int a[][3], int b[][3], int c[][3], int r) {
    int i, j, k;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % r + r) %r;
            }
        }
    }
}

void mat_pow(int a[][3], int res[][3], int n, int r) {
    int tmp[3][3], ts[3][3];

    while (n) {
        if (n & 1) {
            memset(ts, 0, sizeof(ts));
            mat_multi(res, a, ts, r);
            cpy(res, ts);
        }
        memset(tmp, 0, sizeof(tmp));
        mat_multi(a, a, tmp, r);
        cpy(a, tmp);
        n >>= 1;
    }
}

int main() {
    int ans[3] = {19, 6, 2};
    int res[3][3], a[3][3], n;
    int abc[] = {0, 1, 2, 6, 19};
    int s;

    //freopen("architect.in", "r", stdin);
    //freopen("architect.out", "w", stdout);

    while (scanf("%d", &n) && n) {
        if (n <= 4) {
            printf("%d\n", abc[n]);
            continue;
        }

        cpy(a, m);
        memset(res, 0, sizeof(res));
        res[0][0] = res[1][1] = res[2][2] = 1;
        mat_pow(a, res, n - 4, UNI);
        s = ((ans[0] * res[0][0]) % UNI + (ans[1] * res[1][0]) % UNI + (ans[2] * res[2][0]) % UNI) % UNI;
        printf("%d\n", s);
    }

    return 0;
}
