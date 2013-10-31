#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64;

const int MAX = 64;
const int64 MOD = 1234567894987654321LL;
const int64 RG = 100000000000000000LL;

inline int64 abs64(int64 x)
{
	return x < 0 ? -x : x;
}

inline int64 mul(int64 a, int64 b)
{
	int64 ret = 0;
	if (a < 0) a += MOD;
	if (b < 0) b += MOD;
	while (b)
	{
		if (b & 1)
		{
			ret = ret + a; if (ret >= MOD) ret -= MOD;
		}
		b >>= 1;
		a = a + a; if (a >= MOD) a -= MOD;
	}
	if (ret < 0) ret += MOD;
	return ret;
}

int64 inv(int64 x)
{
	int64 ret = 1, b = MOD - 2;
	while (b)
	{
		if (b & 1) ret = mul(ret, x);
		x = mul(x, x);
		b >>= 1;
	}
	return ret;
}

int N;
int64 b[MAX], x, E[MAX][MAX], X[MAX], INVN2 = inv(MOD - 2);

inline void add(int r1, int r2, int64 k) //r1 += r2 * k
{
	for (int c = 1; c <= N + 1; c++)
	{
		E[r1][c] += mul(E[r2][c], k);
		E[r1][c] %= MOD;
	}
}

void triangle(int x)
{
	int i;
	if (x > N) return;
	int64 INVX = inv(E[x][x]);
	while (true)
	{
		if (E[x][x] == 0)
		{
			for (i = x + 1; i <= N && !E[i][x]; i++);
			add(x, i, -1);
			add(i, x, +1);
		}
		for (i = x + 1; i <= N && !E[i][x]; i++);
		if (i == N + 1) break;
		add(i, x, mul(-E[i][x], INVX));
	}
	triangle(x + 1);
}

void solve()
{
	triangle(1);	
	for (int i = N; i >= 1; i--)
	{
		X[i] = E[i][N + 1];
		for (int j = N; j > i; j--)
		{
			X[i] = (X[i] - mul(E[i][j], X[j])) % MOD;
		}
		X[i] = mul(X[i], inv(E[i][i]));
	}
}

int main()
{
	//freopen("f:\\sphere.in", "r", stdin);
	//freopen("f:\\sphere.ans", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%d", &N);
		for (int i = 0; i <= N; i++)
		{
			int64 s = 0;
			for (int j = 1; j <= N; j++)
			{
				if (i == 0)
					scanf("%I64d", &b[j]);
				else
				{
					scanf("%I64d", &x);
					E[i][j] = (x - b[j]) % MOD;
					int64 t = (mul(b[j], b[j]) - mul(x, x)) % MOD;
					s = (s + t) % MOD;
				}
			}
			E[i][N + 1] = mul(s, INVN2);
		}
		solve();
		printf("Case %d:\n", t_case);
		for (int i = 1; i <= N; i++)
		{
			if (X[i] < 0) X[i] += MOD;
			if (X[i] > RG) X[i] -= MOD;
			printf("%I64d", X[i]);
			if (i < N) printf(" ");
			else printf("\n");
		}
	}
	return 0;
}

