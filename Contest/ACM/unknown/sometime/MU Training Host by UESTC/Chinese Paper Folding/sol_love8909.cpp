#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64;

const int MAX = 1000005;

int coverX[MAX], coverY[MAX];

void init(int cover[], int L)
{
	cover[0] = cover[L] = 0;
	for (int i = 1; i < L; i++) cover[i] = 1;
}

bool isRevX, isRevY;

int fold(int cover[], int &L, int &R, int v, bool &isRev)
{
	bool gt = false;
	v += L;
	if (abs(v - L) > abs(v - R)) isRev = !isRev, gt = true;
	int ret = cover[v];
	for (int xl = v, xr = v; xl != L && xr != R; xl--, xr++)
	{
		if (!gt)
		{
			cover[xr] += cover[xl];
			cover[xl] = 0;
		}
		else
		{
			cover[xl] += cover[xr];
			cover[xr] = 0;
		}
	}
	if (!gt) L = v;
	else R = v;
	return ret;
}

int main()
{
	char com[4];
	int T, Len, Wid, K;
	scanf("%d", &T);
	for (int t_case = 1; t_case <= T; t_case++)
	{
		scanf("%d %d %d", &Len, &Wid, &K);
		init(coverX, Len);
		init(coverY, Wid);
		int totalX = 0, totalY = 0, L = 0, R = Len, U = 0, D = Wid, v;
		isRevX = isRevY = false;
		while (K--)
		{
			scanf("%s %d", com, &v);
			if (com[0] == 'L' || com[0] == 'R')
			{
				if (isRevX) v = R - L - v;
				if (!isRevX && com[0] == 'R') isRevX = !isRevX;
				if (isRevX && com[0] == 'L') isRevX = !isRevX;
				totalX += fold(coverX, L, R, v, isRevX);
			}
			else
			{
				if (isRevY) v = D - U - v;
				if (!isRevY && com[0] == 'U') isRevY = !isRevY;
				if (isRevY && com[0] == 'D') isRevY = !isRevY;
				totalY += fold(coverY, U, D, v, isRevY);
			}
		}
		printf("Case %d: %lld\n", t_case, (int64)totalX * Wid + (int64)totalY * Len);
	}
	return 0;
}
