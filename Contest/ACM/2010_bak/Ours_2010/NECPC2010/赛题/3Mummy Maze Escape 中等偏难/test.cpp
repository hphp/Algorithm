#include <stdio.h>

#define N 10

struct Node
{
	int mx, my;
	int yx, yy;
};

int n, m;
int ex, ey, mx, my, yx, yy;
int min[N][N][N][N], door[N][N][N][N];
struct Node queue[N*N*N*N];
int head, tail;
int step[5][2] = {
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1},
		{0, 0}
		};

int bfs()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int ii = 0; ii < n; ii++)
				for (int jj = 0; jj < m; jj++)
					min[i][j][ii][jj] = -1;

	head = 0;
	tail = 1;
	queue[0].mx = mx;
	queue[0].my = my;
	queue[0].yx = yx;
	queue[0].yy = yy;
	min[mx][my][yx][yy] = 0;
	while (head < tail)
	{
		int x1 = queue[head].mx;
		int y1 = queue[head].my;
		int x2 = queue[head].yx;
		int y2 = queue[head].yy;
		//printf("%d,%d --> %d,%d\n", x1, y1, x2, y2);
		head++;
		if (x1==ex && y1==ey)
			return min[x1][y1][x2][y2];

		for (int i = 0; i < 5; i++)
		{
			int xx1 = x1 + step[i][0];
			int yy1 = y1 + step[i][1];

			if (!(xx1>=0 && xx1<n && yy1>=0 && yy1<m))
				continue;
			if (door[x1][y1][xx1][yy1])
				continue;

			int xx2 = x2;
			int yy2 = y2;

			int time = 0;
			while (time < 2)
			{
				time++;
				if (yy1 != yy2)
				{
					if (yy2 > yy1)	
					{
						if (door[xx2][yy2][xx2][yy2-1])
						{
							if (xx2 > xx1)	
							{
								if (door[xx2][yy2][xx2-1][yy2])
									break;
								xx2--;
							}
							else if(xx2 < xx1)
							{
								if (door[xx2][yy2][xx2+1][yy2])
									break;
								xx2++;
							}
						}
						else
							yy2--;
					}
					else if(yy2 < yy1)
					{
						if (door[xx2][yy2][xx2][yy2+1])
						{
							if (xx2 > xx1)	
							{
								if (door[xx2][yy2][xx2-1][yy2])
									break;
								xx2--;
							}
							else if(xx2 < xx1)
							{
								if (door[xx2][yy2][xx2+1][yy2])
									break;
								xx2++;
							}
						}
						else
							yy2++;
					}
				}
				else
				{
					if (xx2 > xx1)	
					{
						if (door[xx2][yy2][xx2-1][yy2])
							break;
						xx2--;
					}
					else if(xx2 < xx1)
					{
						if (door[xx2][yy2][xx2+1][yy2])
							break;
						xx2++;
					}
				}
			}

			//printf("\t%d %d %d %d\n", xx1, yy1, xx2, yy2);

			if (min[xx1][yy1][xx2][yy2] == -1)
			{
				min[xx1][yy1][xx2][yy2] = min[x1][y1][x2][y2] + 1;
				if (!(xx1==xx2 && yy1==yy2))
				{
					queue[tail].mx = xx1;
					queue[tail].my = yy1;
					queue[tail].yx = xx2;
					queue[tail].yy = yy2;
					tail++;
				}
			}
		}
	}

	return -1;
}

int main()
{
	freopen("maze1.in","r",stdin);
	freopen("test.out","w",stdout);
	while (scanf("%d %d", &n, &m) != EOF)
	{
		scanf("%d %d", &ex, &ey);
		scanf("%d %d", &mx, &my);
		scanf("%d %d", &yx, &yy);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int ii = 0; ii < n; ii++)
					for (int jj = 0; jj < m; jj++)
						door[i][j][ii][jj] = 0;

		int cnt;
		scanf("%d", &cnt);
		for (int i = 0; i < cnt; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			door[x1][y1][x2][y2] = 1;
			door[x2][y2][x1][y1] = 1;
		}

		int result = bfs();
		if (result == -1)
			printf("impossible\n");
		else
			printf("%d\n", result);
	}
}
