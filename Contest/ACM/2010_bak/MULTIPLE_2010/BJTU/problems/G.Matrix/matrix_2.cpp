#include <iostream>

using namespace std;

const int N = 100;

int A[N][N], B[N][N];
int n, m;

struct longlonglonglong {
long long a, b;

longlonglonglong () {a=b=0;}
longlonglonglong (int x) {a=x;b=0;}
};

longlonglonglong operator << (longlonglonglong a, int b) {
a.a <<= b;
a.b += a.a >> 60;
a.a &= (1LL<<60LL)-1;

return a;
}

longlonglonglong operator + (longlonglonglong a, int b) {
a.a += b;
a.b += a.a >> 60;
a.a &= (1LL<<60LL)-1;

return a;
}

bool operator < (longlonglonglong a, longlonglonglong b) {
return a.b<b.b || a.b==b.b && a.a<b.a;
}

bool operator != (longlonglonglong a, longlonglonglong b) {
return a.a!=b.a || a.b!=b.b;
}

longlonglonglong tmp;
longlonglonglong As[N - 1], Bs[N - 1];

int main () {
int i, j, k;
freopen("matrix.in" , "r" , stdin);
while (cin >> n >> m && n > 0) {
for (i = 0; i < n; i ++)
for (j = 0; j < m; j ++)
cin >> A[i][j];
for (i = 0; i < n; i ++)
for (j = 0; j < m; j ++)
cin >> B[i][j];
for (i = 0; i < m; i ++) {
for (j = 0; j < m; j ++) {
if (j != 0) {
tmp = 0;
for (k = 0; k < n; k ++)
tmp = (tmp << 1) + A[k][j];
As[j - 1] = tmp;
}

if (j != i) {
tmp = 0;
for (int k = 0; k < n; k ++)
tmp = (tmp << 1) + (B[k][j] ^ A[k][0] ^ B[k][i]);
Bs[j < i? j : j - 1] = tmp;
}
}

sort(As, As + m - 1);
sort(Bs, Bs + m - 1);
for (j = 0; j < m - 1; j ++)
if (As[j] != Bs[j])
break;
if (j == m - 1) {
cout<< "Yes" << endl;
break;
}
}
if (i == m)
cout << "No" << endl;
}

return 0;
}


