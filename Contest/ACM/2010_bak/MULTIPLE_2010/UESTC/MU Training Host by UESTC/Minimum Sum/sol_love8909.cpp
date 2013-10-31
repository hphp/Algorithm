#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64;

const int MAX = 100005;
const int LOGMAX = 17;

int N, num[MAX], si[MAX], pos[MAX], sn[LOGMAX][MAX];
int to_left[LOGMAX][MAX];

bool cmp(int a, int b)
{
	return num[a] < num[b];
}

void build(int level, int L, int R)
{
	if (L == R) return;
	int cur = (level&1), nxt = (level&1^1);
	int M = (L + R) / 2;
	int l = L, r = M + 1;
	for (int i = L; i <= R; i++)
	{
		if (sn[cur][i] <= M)
			sn[nxt][l++] = sn[cur][i];
		else
			sn[nxt][r++] = sn[cur][i];
		to_left[level][i] = l - L;
	}
	build(level + 1, L, M);
	build(level + 1, M + 1, R);
}

int query(int level, int L, int R, int l, int r, int k)
{
	//printf("query (%d %d) for (%d %d) k = %d\n", L, R, l, r, k);
	if (L == R) return L;
	int ls = (L == l ? 0 : to_left[level][l - 1]);
	int rs = to_left[level][r];
	int tl = rs - ls, M = (L + R) / 2;
	if (k <= tl)
		return query(level + 1, L, M, L + ls, L + rs - 1, k);
	else
		return query(level + 1, M + 1, R, M + 1 + (l - L - ls), M + (r + 1 - L - rs), k - tl);
}

int64 SC[MAX], SS[MAX];

void clear(int N)
{
	memset(SC, 0, (N + 1) * sizeof(SC[0]));
	memset(SS, 0, (N + 1) * sizeof(SS[0]));
}

void addS(int64 S[], int idx, int val)
{
	for ( ; idx <= N; idx += idx & -idx)
	{
		S[idx] += val;
	}
}

int64 getS(int64 S[], int idx)
{
	int64 ret = 0;
	for ( ; idx > 0; idx -= idx & -idx)
	{
		ret += S[idx];
	}
	return ret;
}

struct Query
{
	int l, r, median;
} qq[MAX];

int64 result[MAX];
int sq[MAX];

bool cmpQ(int a, int b)
{
	return qq[a].median < qq[b].median;
}

int main()
{
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\hs.out", "w", stdout);

	int T, Q;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			pos[i] = i;
			scanf("%d", &num[i]);
		}
		sort(pos + 1, pos + 1 + N, cmp);
		for (int i = 1; i <= N; i++)
		{
			sn[0][pos[i]] = i;
			si[i] = num[pos[i]];
		}
		build(0, 1, N);
		scanf("%d", &Q);
		for (int i = 0; i < Q; i++)
		{
			sq[i] = i;
			scanf("%d %d", &qq[i].l, &qq[i].r);
			int k = (qq[i].r - qq[i].l + 1) / 2 + 1;
			qq[i].median = query(0, 1, N, ++qq[i].l, ++qq[i].r, k);
			//printf("***%d\n", si[qq[i].median]);
		}
		sort(sq, sq + Q, cmpQ);

		clear(N);
		memset(result, 0, (Q + 1) * sizeof(result[0]));
		int p = 1, q = 0;
		while (p <= N && q < Q)
		{
			while (p <= N && si[p] < si[qq[sq[q]].median])
			{
				addS(SC, pos[p], 1);
				addS(SS, pos[p], si[p]);
				p++;
			}
			int64 s1 = getS(SC, qq[sq[q]].r) - getS(SC, qq[sq[q]].l - 1);
			int64 s2 = getS(SS, qq[sq[q]].r) - getS(SS, qq[sq[q]].l - 1);
			result[sq[q]] += (int64)si[p] * s1 - s2;
			q++;
		}
		clear(N);
		p = N, q = Q - 1;
		while (p >= 1 && q >= 0)
		{
			while (p >= 1 && si[p] > si[qq[sq[q]].median])
			{
				addS(SC, pos[p], 1);
				addS(SS, pos[p], si[p]);
				p--;
			}
			int64 s1 = getS(SC, qq[sq[q]].r) - getS(SC, qq[sq[q]].l - 1);
			int64 s2 = getS(SS, qq[sq[q]].r) - getS(SS, qq[sq[q]].l - 1);
			result[sq[q]] += s2 - si[p] * s1;
			q--;
		}
		printf("Case #%d:\n", t_case);
		for (int i = 0; i < Q; i++)
			printf("%lld\n", result[i]);
		printf("\n");

	}
	return 0;
}
