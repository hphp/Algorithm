#include <stdio.h>
#include <queue>
using namespace std;
#define N 1100
#define MAX (1<<30)

#define avl(x,y) (((x)>0 && (x)<=n && (y)>0 &(y) <= m)?1:0) 

struct Queue
{
	int x,y;
	int step;
	bool operator <(const Queue & a)const
	{
		return step > a.step;
	}
};

char grid[N][N];
int belong[N][N];
int minn[N][N];
int sx,sy,ex,ey;
int n,m;
int mv[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int bfs()
{
	priority_queue<Queue> queue;
	Queue tmp = {sx,sy,0};
	minn[sx][sy] = 0;
	queue.push(tmp);
	while(!queue.empty())
	{
		Queue tmp = queue.top();
		queue.pop();
		int x = tmp.x;
		int y = tmp.y;
		int step = tmp.step;
	//	printf("%d %d %d\n",x,y,step);
		if(x == ex && y == ey)
			return step;
		for(int i=0;i<4;i++)
		{
			int xx = x+mv[i][0];
			int yy = y+mv[i][1];	
			int add = 1;
			if(avl(xx,yy))
			{
				if(grid[xx][yy] == 'X')
					add = 0;
				if(minn[xx][yy] > minn[x][y]+add)
				{
					minn[xx][yy] = minn[x][y] + add;
					Queue ttmp;
					ttmp.x = xx;
					ttmp.y = yy;
					ttmp.step = minn[xx][yy];
					queue.push(ttmp);
				}
			}
		}
	}
	return -1;
}

int main()
{
	while(scanf("%d %d",&n,&m) != EOF)
	{
		if(!(n||m))break;
		for(int i=1;i<=n;i++)
			scanf("%s",grid[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
			//	belong[i][j] = -1;
				minn[i][j] = MAX;
			}
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		int ans = bfs();
		printf("%d\n\n",ans);
	}
	return 0;	
}
