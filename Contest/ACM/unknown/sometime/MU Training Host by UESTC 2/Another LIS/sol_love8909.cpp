#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 100005, MAXLOG = 17;

int S[MAX], pos[MAX], N;

int kthNum(int k)
{
	int ret = 0;
	for (int i = MAXLOG; i >= 0; i--)
	{
		ret += (1 << i);
		if (ret > N || S[ret] >= k)
			ret -= (1 << i);
		else
			k -= S[ret];
	}
	return ret + 1;
}

void addS(int idx, int val)
{
	for (; idx <= N; idx += idx & -idx)
		S[idx] += val;
}

void addM(int idx, int val)
{
	for (; idx <= N; idx += idx & -idx)
		S[idx] = max(S[idx], val);
}

int getM(int idx)
{
	int ret = 0;
	for (; idx > 0; idx -= idx & -idx)
		ret = max(ret, S[idx]);
	return ret;
}

int main()
{
	int T, xk;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &pos[i]);
		
		memset(S, 0, (N + 1) * sizeof(S[0]));
		for (int i = 1; i <= N; i++)
			addS(i, 1);
		for (int i = N; i >= 1; i--)
		{
			pos[i] = kthNum(pos[i] + 1);
			addS(pos[i], -1);
		}
		
		printf("Case #%d:\n", t_case);

		memset(S, 0, (N + 1) * sizeof(S[0]));
		int res = 0;
		for (int i = 1; i <= N; i++)
		{
			int t = getM(pos[i]) + 1;
			if (t > res) res = t;
			addM(pos[i], t);
			printf("%d\n", res);
		}
		printf("\n");
	}
	return 0;
}
