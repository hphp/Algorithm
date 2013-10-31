#include <stdio.h>

#define N 210

int n, m;
int v[N][N];

int main()
{
	freopen("KArray.in","r",stdin);
    freopen("testTLE.out","w",stdout);
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i= 1; i <= n; i++)
		{
			v[i][0] = 0;
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &v[i][j]);
				v[i][j] += v[i][j-1];
			}
		}
		
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int p = i; p <= n; p++)
					for (int q = j; q <= n; q++)
					{
						int tol = 0;
						for (int w = i; w <= p; w++)
							tol += (v[w][q] - v[w][j-1]);
						if (tol == m)
							goto yes;
					}
		goto no;
		yes:
			printf("yes\n");
			continue;
		no:
			printf("no\n");
	}
}
