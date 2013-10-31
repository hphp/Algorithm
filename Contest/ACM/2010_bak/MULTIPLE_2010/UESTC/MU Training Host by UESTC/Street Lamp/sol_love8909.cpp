#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define two(x) (1<<(x))

const int MAXN = 128, MAXM = 16;
const int oo = 0x3f3f3f3f;
const int dx[] = {-1, -1, -1,  0,  0};
const int dy[] = {-1,  0,  1, -1, -1};

int N, M, Mask[5][MAXN], MaskLight[MAXN];

void init()
{
	char m[MAXN * 2 + 5][MAXM * 2 + 5];
	scanf("%d %d", &N, &M);
	gets(m[0]);
	for (int i = 0; i < 2 * N - 1; i++)
		gets(m[i]);
	
	//precalc mask
	for (int d = 0; d < 5; d++)
	{
		for (int x = 0; x < 2 * N - 1; x += 2)
		{
			Mask[d][x >> 1] = 0;
			for (int y = 0; y < 2 * M - 1; y += 2)
			{
				if (d == 0 && x - 1 >= 0 && y - 1 >= 0 &&
					(m[x - 1][y - 1] == '\\' || m[x - 1][y - 1] == 'X'))
					Mask[d][x >> 1] |= two(y >> 1);

				if (d == 1 && x - 1 >= 0 &&
					(m[x - 1][y] == '|'))
					Mask[d][x >> 1] |= two(y >> 1);

				if (d == 2 && x - 1 >= 0 && y + 1 < 2 * M - 1 &&
					(m[x - 1][y + 1] == '/' || m[x - 1][y + 1] == 'X'))
					Mask[d][x >> 1] |= two(y >> 1);

				if (d == 3 && y - 1 >= 0 &&
					(m[x][y - 1] == '-'))
					Mask[d][x >> 1] |= two(y >> 1);

				if (d == 4 && y + 1 < 2 * M - 1 &&
					(m[x][y + 1] == '-'))
					Mask[d][x >> 1] |= two(y >> 1);
			}
		}
	}

	//precalc light
	for (int x = 0; x < 2 * N - 1; x += 2)
	{
		MaskLight[x >> 1] = 0;
		for (int y = 0; y < 2 * M - 1; y += 2)
		{
			if (m[x][y] == 'o')
				MaskLight[x >> 1] |= two(y >> 1);
		}
	}
}

const int MAXSTATE = 150000, MOD = 1024;

struct Edge
{
	int s, v;
	Edge *next;
} e[2][MAXSTATE], *head[2][MOD];

int cnt[2], pp, cc;

int maxmax;

int get_id(int s)
{
	int h = (s >> M); s &= (two(M) - 1);
	for (Edge *p = head[cc][h]; p; p = p->next)
		if (p->s == s) return (p - e[cc]);
	int &p = cnt[cc];
	e[cc][p].s = s; e[cc][p].v = +oo; 
	e[cc][p].next = head[cc][h]; head[cc][h] = &e[cc][p];
	return p++;
}

int bits[1024];

void clear()
{
	cnt[cc] = 0;
	memset(head[cc], 0, sizeof(head[cc]));
}

int solve()
{
	pp = 0; cc = 1;

	clear(); e[cc][get_id(0)].v = 0;
	for (int i = 0; i < N; i++)
	{
		swap(pp, cc); clear();
		for (int curSwitch = 0; curSwitch < two(M); curSwitch++)
		{
			int preLamp = 0;
			preLamp ^= ((curSwitch & Mask[0][i]) >> 1);
			preLamp ^= (curSwitch & Mask[1][i]);
			preLamp ^= ((curSwitch & Mask[2][i]) << 1);
			
			for (Edge *p = head[pp][preLamp]; p; p = p->next)
			{
				int preV = p->v;
				int preSwitch = p->s;

				int curLamp = (MaskLight[i] ^ curSwitch);
				curLamp ^= ((curSwitch & Mask[3][i]) >> 1);
				curLamp ^= ((curSwitch & Mask[4][i]) << 1);

				curLamp ^= ((preSwitch) & Mask[1][i]);
				curLamp ^= ((preSwitch>>1) & Mask[2][i]);
				curLamp ^= ((preSwitch<<1) & Mask[0][i]);

				int id = get_id((curLamp << M) | curSwitch);
				int v = bits[curSwitch];
				if (preV + v < e[cc][id].v) e[cc][id].v = preV + v;
			}
		}
	}

	int ret = +oo;
	for (Edge *p = head[cc][0]; p; p = p->next)
	{
		int t = p->v;
		if (t < ret) ret = t;
	}
	if (ret >= +oo)
		return -1;
	else
		return ret;
}

int main()
{
	bits[0] = 0;
	for (int v = 1; v < 1024; v++)
	{
		bits[v] = bits[v - (v & -v)] + 1;
	}
	int T;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		init();
		printf("Case %d: %d\n", t_case, solve());
	}

	return 0;
}

