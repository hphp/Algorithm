#include<stdio.h>

#define MAX_NUM 60000
#define N 10
#define MAX 1<<28

int cnt[N+1];
int list[N+1][MAX_NUM];
int p[N+1];

void init()
{
	p[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		cnt[i] = 0;
		p[i] = p[i-1] * 3;
	}
	
	for (int i = 1; i <= MAX_NUM; i++)
	{
		int temp = 0;
		int now = i;
		while (now)
		{
			if (now%3 != 0)
				temp++;
			now /= 3;
		}
		
		list[temp][cnt[temp]++] = i;
	}
}

int n,m;
int con[N][N];
int max;
int min[MAX_NUM][N];
int best;

void dp()
{
	best = MAX;
	
	max = 1;
	for (int i = 0; i < n; i++)
		max *= 3;
	
	for (int i = 0; i < max; i++)
		for (int j = 0; j < n; j++)
			min[i][j] = MAX;
	
	for (int i = 0; i<cnt[1] && list[1][i]<max; i++)
	{
		int id = 0;
		int now = list[1][i];
		while (now)
		{
			if (now%3 != 0)
				break;
			now /= 3;
			id++;
		}
		min[list[1][i]][id] = 0;

	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j<cnt[i] && list[i][j]<max; j++)
		{

			int now = list[i][j];
			int now_id = 0;
			while (now)
			{
				if (now%3 != 0)
				{
					int cur = list[i][j] - p[now_id];
					int cur_id = 0;
					while (cur)
					{
						if (cur%3 != 0)
						{
							if (con[cur_id][now_id] != -1)
							{
								int temp = min[list[i][j]-p[now_id]][cur_id] + con[cur_id][now_id];
								if (temp < min[list[i][j]][now_id])
								{
									min[list[i][j]][now_id] = temp;
									
									if (i == n)
									{
										if (temp < best)
											best = temp;
									}
								}
							}
						}
						cur /= 3;
						cur_id++;
					}
				}
				now /= 3;
				now_id++;
			}
		}
	}
	
	if (best == MAX)
		printf("-1\n");
	else
		printf("%d\n", best);
}

int main()
{
	freopen("rin.in", "r", stdin);
	freopen("rin.out", "w", stdout);
	
	init();
	
	while (scanf("%d %d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
				con[i][j] = con[j][i] = -1;
			
			con[i][i] = 0;
		}
			
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			a--;
			b--;
			if (con[a][b] == -1)
				con[a][b] = con[b][a] = c;
			else if (con[a][b] > c)
				con[a][b] = con[b][a] = c;
		}
		
		dp();
	}
}
