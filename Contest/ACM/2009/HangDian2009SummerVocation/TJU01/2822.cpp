//09-10-31---15:54--
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define N 1010
#define MAX (1<<30)
#define avl(x,y) (((x)>=0&&((x)<n)&&(y)>=0&&(y)<m)?1:0)

int n,m;
int sx,sy,ex,ey;
char grid[N][N];
struct Grid
{
	int x,y;
	int l;
	bool operator < (const Grid & a)const
	{
		if(l<a.l)	
			return 0;
			return 1;
	}
};
int least[N][N];
int v[4][2] ={{1,0},{-1,0},{0,-1},{0,1}};

int bfs()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			least[i][j] = MAX;
	std::priority_queue <Grid> p_q;
	Grid t = {sx,sy,0};
	least[sx][sy] = 0;
	p_q.push(t);
	while(!p_q.empty())
	{
		Grid t = p_q.top();
		p_q.pop();
		int x = t.x;
		int y = t.y;
		int l = t.l;
//		printf("%d %d %d\n",x,y,l);
		if(x==ex&&y==ey)return l;
		for(int i=0;i<4;i++)
		{
			int xx = x+v[i][0];
			int yy = y+v[i][1];
			if(avl(xx,yy))
			{
				int tt = l;
		//		printf("helo %d %d %d\n",xx,yy,tt);
				if(grid[xx][yy]=='.')tt++;
				if(least[xx][yy]>tt)
				{
				least[xx][yy] = tt;
				Grid tmp = {xx,yy,tt};
				p_q.push(tmp);
				}
			}
		}
	}
	return -1;
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		for(int i=0;i<n;i++)	
			scanf("%s",grid[i]);
		scanf("%d %d %d %d",&sx,&sy,&ex,&ey);
		sx--;sy--;ex--;ey--;
		int ans = bfs();
		printf("%d\n",ans);
	}
	return 0;
}
