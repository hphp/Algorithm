#include<stdio.h>
#include<stdlib.h>

#define N 110
#define STATE 512
#define MAX 1<<28

int n, m;
char grid[N][N];
int min[N][N][STATE];
int p[N*N];
int sx, sy;
int begin, last;
int queue[N*N*STATE][2];
int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void bfs()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m;j++)
			{
				if (grid[i][j] == '#')
					continue;
				for (int k = 0; k < STATE; k++)
					min[i][j][k] = MAX;
			}
	
	begin = 0;
	last = 1;
	queue[0][0] = sx*m + sy;
	queue[0][1] = 0;
	min[sx][sy][0] = 0;
	int ans = MAX;
	while (begin < last)
	{
		if (ans != MAX)
			break;
		
		int x = queue[begin][0]/m;
		int y = queue[begin][0]%m;
		int state = queue[begin++][1];
		for (int i = 0; i < 4; i++)
		{
			int xx = x + step[i][0];
			int yy = y + step[i][1];
			if (xx>=n || xx < 0 || yy>=m || yy<0)
				continue;
			if (grid[xx][yy] == '#')
				continue;
			if (grid[xx][yy] == 'E')
			{
				if (min[xx][yy][state]==MAX && (state&p[xx*m+yy]) == p[xx*m+yy])
				{
					queue[last][0] = xx*m + yy;
					queue[last++][1] = state;
					min[xx][yy][state] = min[x][y][state] + 1;
				}
			}
			else if (grid[xx][yy] == '.')
			{
				if (min[xx][yy][state]==MAX)
				{
					queue[last][0] = xx*m + yy;
					queue[last++][1] = state;
					min[xx][yy][state] = min[x][y][state] + 1;
				}
			}
			else if (grid[xx][yy] == 'T')
			{
				ans = min[x][y][state] + 1;
				break;
			}
			else if (grid[xx][yy] != '#')
			{
				int id = grid[xx][yy] - '1';
				int cur = state | (1<<id);
				if (min[xx][yy][cur]==MAX)
				{
					queue[last][0] = xx*m + yy;
					queue[last++][1] = cur;
					min[xx][yy][cur] = min[x][y][state] + 1;
				}
			}
		}
	}
	
	if (ans == MAX)
		printf("impossible!\n");
	else
		printf("%d\n", ans);
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int c = 0; c < test; c++)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", grid[i]);
			
		for (int i = 0; i < n; i++)	
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == 'S')
				{
					sx = i;
					sy = j;
				}
				else if (grid[i][j] == 'E')
				{
					int cnt;
					scanf("%d", &cnt);
					int state = 0;
					for (int k = 0; k < cnt; k++)
					{
						int a;
						scanf("%d", &a);
						a--;
						state = state | (1<<a);
					}
					p[i*m + j] = state;
				}
			}
		bfs();
	}
}
