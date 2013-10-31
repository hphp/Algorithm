#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int MAXS = 362880;
const int oo = 0x3f3f3f3f;
const int det[] = { 3, -1, 1, -3 };
const char sym[] = { "dlru" };

int factorial[9];

int encode(char s[])
{
	int h = 0;
	for (int i = 0; i < 9; i++)
	{
		int rev = 0;
		for (int j = 0; j < i; j++)
			rev += (s[j] > s[i]);
		h += rev * factorial[i];
	}
	return h;
}

void decode(int h, char s[])
{
	int used[9];
	memset(used, 0, sizeof(used));
	for (int i = 8; i >= 0; i--)
	{
		int rev = h / factorial[i];
		for (int j = 8; j >= 0; j--)
		{
			if (used[j]) continue;
			if (rev == 0)
			{
				used[j] = true; s[i] = j;
				break;
			}
			else rev--;
		}
		h %= factorial[i];
	}
}

int input_state()
{
	char s[16];
	scanf("%s", s);
	for (int i = 0; i < 9; i++)
	{
		if (s[i] != 'X') s[i] -= '1';
		else s[i] = 8;
	}
	return encode(s);
}


struct BS
{
	int Q[MAXS], head, tail;
	int dist[MAXS], prev[MAXS];
	int meet[64], n;
	char turn[MAXS];

	BS *other;
	void clear()
	{
		head = tail = 0;
		memset(dist, 0x3f, sizeof(dist));
		memset(prev, 0xff, sizeof(prev));
	}
	void step()
	{
		n = 0;
		int MAXD = dist[Q[head]] + 1;
		while (head < tail)
		{
			int u = Q[head], p = -1;
			if (dist[u] == MAXD) break;
			char cur[9], nxt[9];
			decode(u, cur);
			for (int i = 0; i < 9 && p < 0; i++)
				if (cur[i] == 8) p = i;
			for (int i = 0; i < 4; i++)
			{
				if (p % 3 == 0 && i == 1) continue;
				if (p % 3 == 2 && i == 2) continue;
				int q = p + det[i];
				if (q < 0 || q > 8) continue;
				memcpy(nxt, cur, sizeof(cur));
				swap(nxt[p], nxt[q]);
				int h = encode(nxt);
				if (dist[h] == +oo)
				{
					prev[h] = u; turn[h] = sym[i];
					dist[h] = dist[u] + 1;
					Q[tail++] = h;
				}
				if (other->dist[h] < +oo)
				{
					meet[n++] = h;
				}
			}
			head++;
		}
	}
} bs[2];

char bestAns[64];

void update(int h)
{
	BS &F = bs[0], &B = bs[1];
	char s[64];
	int n = 0, t = h;
	while (F.prev[t] != -1)
	{
		s[n++] = F.turn[t];
		t = F.prev[t];
	}
	reverse(s, s + n);
	t = h;
	while (B.dist[t] > 0)
	{
		int p = -1;
		char cur[9], nxt[9];
		decode(t, cur);
		for (int i = 0; i < 9 && p < 0; i++)
			if (cur[i] == 8) p = i;
		for (int i = 0; i < 4; i++)
		{
			if (p % 3 == 0 && i == 1) continue;
			if (p % 3 == 2 && i == 2) continue;
			int q = p + det[i];
			if (q < 0 || q > 8) continue;
			memcpy(nxt, cur, sizeof(cur));
			swap(nxt[p], nxt[q]);
			int nh = encode(nxt);
			if (B.dist[nh] == B.dist[t] - 1)
			{
				t = nh;
				s[n++] = sym[i];
				break;
			}
		}
	}
	s[n] = 0;
	if (bestAns[0] == 0 || strcmp(s, bestAns) < 0)
		strcpy(bestAns, s);
}

void solve(int s, int t)
{
	bs[0].clear(); bs[1].clear();
	BS &F = bs[0], &B = bs[1];
	F.other = &B; B.other = &F;
	if (s == t)
	{
		printf("0\n\n");
		return;
	}
	F.Q[F.tail++] = s; F.dist[s] = 0;
	B.Q[B.tail++] = t; B.dist[t] = 0;
	for (int f = 0; ; f = 1 - f)
	{
		bs[f].step();
		if (bs[f].n)
		{
			printf("%d\n", F.dist[bs[f].meet[0]] + B.dist[bs[f].meet[0]]);
			bestAns[0] = 0;
			for (int i = 0; i < bs[f].n; i++)
			{
				update(bs[f].meet[i]);
			}
			printf("%s\n", bestAns);
			break;
		}
	}
}

int main()
{
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\1.txt", "w", stdout);
	factorial[0] = 1;
	for (int i = 1; i < 9; i++)
		factorial[i] = factorial[i - 1] * i;

	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		int s = input_state();
		int t = input_state();
		printf("Case %d: ", t_case);
		solve(s, t);
	}
    return 0;
}
