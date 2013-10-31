#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;

typedef unsigned long long int64;

char L[32], H[32];
int len;
int64 A, B;

int dp[21][2][2][10][7];

int dfs(int pos, int D, int U, int last, int state)
{
	if (pos >= len) 
	{
		if (state == 5) return 0;
		else return -19890902;
	}
	int &ret = dp[pos][D][U][last][state];
	if (ret != -1) return ret;

	ret = -19890902;

	for (int d = (D ? 0 : L[pos]); d <= (U ? 9 : H[pos]); d++)
	{
		if (state == 6)
		{
			if (d == 0)
			{
				int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, 6);
				if (t > ret) ret = t;
			}
			else
			{
				int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, 0);
				if (t > ret) ret = t;
			}
		}
		if ((state == 0 || state == 3) && d > last)
		{
			int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, state + 1);
			if (t > ret) ret = t;
		}
		if (state % 3 == 1)
		{
			if (d > last)
			{
				int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, state);
				if (t > ret) ret = t;
			}
			else if (d < last)
			{
				int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, state + 1);
				if (t > ret) ret = t;
			}
		}
		if (state % 3 == 2)
		{
			if (d < last)
			{
				int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, state);
				if (t > ret) ret = t;
			}
			if (state == 2 && d > 0)
			{
				int t = d + dfs(pos+1, D||d>L[pos], U||d<H[pos], d, 3);
				if (t > ret) ret = t;
			}
		}
	}

	return ret;
}

int solve(int64 A, int64 B)
{
	sprintf(L, "%I64u", A);
	sprintf(H, "%I64u", B);
	len = max(strlen(L), strlen(H));

	sprintf(L, "%0*I64u", len, A);
	sprintf(H, "%0*I64u", len, B);
	for (int i = 0; i < len; i++)
		L[i] -= '0', H[i] -= '0';

	memset(dp, 0xff, sizeof(dp));
	
	return dfs(0, 0, 0, 0, 6);
}

int main()
{
	//freopen("f:\\bipeak.in", "r", stdin);
	//freopen("f:\\bipeak.ans", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%I64u %I64u", &A, &B);
		int res = solve(A, B);
		if (res < 0) res = 0;
		printf("Case %d: %d\n", t_case, res);
	}
	return 0;
}
