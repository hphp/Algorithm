#include <stdio.h>
#include <vector>

#define N 1010

int n, m;
std::vector<int> p[N];

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 1; i <= n; i++)
			p[i].clear();
		for (int i = 1; i <= m; i++)
		{
			int c;
			scanf("%d", &c);
			for (int j = 0; j < c; j++)
			{
				int id;
				scanf("%d", &id);
				p[id].push_back(i);
			}
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < p[i].size(); j++)
			{
				if (j != 0)
					printf(" ");
				printf("%d", p[i][j]);
			}

			printf("\n");
		}
	}
}
