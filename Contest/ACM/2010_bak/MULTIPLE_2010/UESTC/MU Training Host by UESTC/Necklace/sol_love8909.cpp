#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAX = 1000005;

char s[MAX * 2];
bool canCollect[2][MAX];
int Q[MAX * 2], det[MAX * 2];

void solve(int N, int W, int flag)
{
	det[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		det[i] = det[i - 1] + (s[i] == 'C' ? +1 : -1);
	}
	int head = 0, tail = 0;
	for (int i = 0; i <= N; i++)
	{
		while (head < tail && det[Q[tail - 1]] > det[i]) tail--;
		Q[tail++] = i;
		if (i >= W)
		{
			while (i - Q[head] >= W) head++;
			canCollect[flag][i - W] = (det[i - W] <= det[Q[head]]);
		}
	}
}

int main()
{
	freopen("f:\\necklace.in", "r", stdin);
	freopen("f:\\necklace.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%s", s + 1);
		int N = strlen(s + 1);
		for (int i = 1; i <= N; i++)
			s[N + i] = s[i];
		s[2 * N + 1] = 0;
		solve(2 * N, N, 0);
		reverse(s + 1, s + 1 + 2 * N);
		solve(2 * N, N, 1);
		int res = 0;
		for (int i = 1; i <= N; i++)
		{
			if (canCollect[0][i] || canCollect[1][N - i])
			{
				res++;
			}
		}
		printf("Case %d: %d\n", t_case, res);
	}

	fclose(stdin);
	fclose(stdout);
    return 0;
}


