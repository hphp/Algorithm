#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const	int		limitSize	= 100 + 10;

int			n , m;
int			src	[limitSize][limitSize];
int			dst	[limitSize][limitSize];

void	init()
{
	int	i , j;
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			scanf("%d" , & src[i][j]);
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			scanf("%d" , & dst[i][j]);
}

int			row	[limitSize];
long long		st	[limitSize];
long long		ed	[limitSize];
long long		M = 67126311511LL;

void	solve()
{
	int	i , p , x , y;
	for (i = 0; i < m; i ++)
	{
		for (p = 0; p < n; p ++)
		{
			if (dst[p][0] == src[p][i]) row[p] = 0;
			else row[p] = 1;
		}
		for (y = 0; y < m; y ++)
		{
			st[y] = ed[y] = 0;
			for (x = 0; x < n; x ++)
			{
				st[y] = (st[y] * 2 + src[x][y]) % M;
				ed[y] = (ed[y] * 2 + (dst[x][y] + row[x]) % 2) % M;
			}
		}
		sort(st , st + m);
		sort(ed , ed + m);

		for (x = 0; x < m; x ++)
			if (st[x] != ed[x]) break;
		if (x == m)
		{
			puts("Yes"); return;
		}
	}

	puts("No");
}

int	main()
{
	freopen("matrix.in" , "r" , stdin);
	freopen("matrix.out" , "w" , stdout);

	while (scanf("%d%d" , &n , &m) , n > 0)
	{
		init();
		solve();
	}

	return 0;
}
