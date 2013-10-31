#include <stdio.h>
#include <stdlib.h>

struct Point
{
	char c;
	int t, v, x, y;
	int max;
};

int n, m, cnt, hp;
struct Point p[110];
int sign[2][110][110];
int q;
int step[5][2] = {
		{1, 0},
		{-1, 0},
		{0, 1},
		{0, -1},
		{0, 0}};

void init_sign(int q, int v)
{
	for (int i = 0; i <= n; i++)	
		for (int j = 0; j <= m; j++)
			sign[q][i][j] = v;
}

void move(int time)
{
	init_sign(1-q, 1);

	for (int i = 0; i < cnt; i++) 
	{
		sign[1-q][p[i].x][p[i].y] = 0;
		int mod = time%p[i].t;
		int bei = 0;
		int out = 0;
		while (1)
		{
			int x, y;
			switch (p[i].c)
			{
				case 'N':
					x = p[i].x - (mod + p[i].t*bei) * p[i].v;
					y = p[i].y;
					if (x <= p[i].max)
						out = 1;
					break;
				case 'S':
					x = p[i].x + (mod + p[i].t*bei) * p[i].v;
					y = p[i].y;
					if (x >= p[i].max)
						out = 1;
					break;
				case 'W':
					x = p[i].x;
					y = p[i].y - (mod + p[i].t*bei) * p[i].v;
					if (y <= p[i].max)
						out = 1;
					break;
				case 'E':
					x = p[i].x;
					y = p[i].y + (mod + p[i].t*bei) * p[i].v;
					if (y >= p[i].max)
						out = 1;
					break;
			}
			
			if (out || mod+p[i].t*bei>time)
				break;
			sign[1-q][x][y] = 0;
			bei++;
		}
	}

	/*
	printf("time=%d-----------------\n", time);
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			printf("%d", sign[1-q][i][j]);
		}
		printf("\n");
	}
	*/
}

int dp()
{
	q = 0;
	init_sign(0, 0);
	sign[0][0][0] = 2;

	int time = 0;
	while (++time <= hp)
	{
		move(time);

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				if (sign[q][i][j] == 2)
				{
					for (int k = 0; k < 5; k++)
					{
						int x = i + step[k][0];
						int y = j + step[k][1];
						if (x>=0 && x<=n && y>=0 && y<=m && sign[1-q][x][y]==1)
							sign[1-q][x][y] = 2;
					}
				}

		q = 1 - q;
		
		if (sign[q][n][m] == 2)
			return time;
	}

	return -1;
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	while (scanf("%d %d %d %d", &n, &m, &cnt, &hp) != EOF)
	{
		for (int i = 0; i < cnt; i++)
		{
			getchar();
			scanf("%c %d %d %d %d", &p[i].c, &p[i].t, &p[i].v, &p[i].x, &p[i].y);
		}

		for (int i = 0; i < cnt; i++)
		{
			switch (p[i].c)
			{
				case 'N':
					p[i].max = -1;
					for (int j = 0; j < cnt; j++)
						if (i!=j &&
							p[j].y==p[i].y &&
							p[j].x>p[i].max &&
							p[j].x<p[i].x)
							p[i].max = p[j].x;
					break;
				case 'S':
					p[i].max = n+1;
					for (int j = 0; j < cnt; j++)
						if (i!=j &&
							p[j].y==p[i].y &&
							p[j].x<p[i].max &&
							p[j].x > p[i].x)
							p[i].max = p[j].x;
					break;
				case 'W':
					p[i].max = -1;
					for (int j = 0; j < cnt; j++)
						if (i!=j &&
							p[j].x==p[i].x &&
							p[j].y>p[i].max &&
							p[j].y<p[i].y)
							p[i].max = p[j].y;
					break;
				case 'E':
					p[i].max = m+1;
					for (int j = 0; j < cnt; j++)
						if (i!=j &&
							p[j].x==p[i].x &&
							p[j].y<p[i].max &&
							p[j].y>p[i].y)
							p[i].max = p[j].y;
					break;
			}
		}

		int result = dp();	
		if (result == -1)
			printf("Bad luck!\n");
		else
			printf("%d\n", result);
	}

	return 0;
}
