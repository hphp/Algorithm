#include <stdio.h>
#define N 110
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int ocp[N][N];
struct Wall
{
	int row;
	int cs,ce;	
}wall[N];

int grid[N][N];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				grid[i][j] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			wall[i].row = y1;
			wall[i].cs = Min(x1,x2);
			wall[i].ce = Max(x1,x2);
			for(int ii=wall[i].cs;ii<=wall[i].ce;ii++)
				grid[y1][ii] = i;
		}
	}
	return 0;
}
