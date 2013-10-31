#include <stdio.h>
#include <queue>
using namespace std;
#define N 1010

struct Node
{
	int x;
	int y;	
	int step;
	const bool operator <(Node a)const
	{
		if(a.step<step)
			return 1;
			return 0;	
	}
}node[N*N];

char grid[N][N];
int minstep[N][N];
int n,m;
int sx,sy,ex,ey;
int kind[4][2]={{1,0},{-1,0},{0,-1},{0,1}};

int avl(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
		return 1;
		return 0;	
}

void init(void)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			minstep[i][j]=n*m+1;	
}

int bfs(void)
{
	priority_queue <Node> p_q;
	Node a={sx,sy,0};
	p_q.push(a);
	minstep[sx][sy]=0;
	while(!p_q.empty())
	{
		Node a=p_q.top();
		int x=a.x;
		int y=a.y;
		int stp=a.step;
		if(minstep[x][y]>stp)
			continue;
		if(x==ex&&y==ey)
			return stp;
//		printf("%d %d %d\n",x,y,stp);
		p_q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+kind[i][0];
			int yy=y+kind[i][1];
			if(avl(xx,yy))
			{
				int step=stp;
				if(grid[xx][yy]=='.')
					step++;
					if(step<minstep[xx][yy])
					{
						minstep[xx][yy]=step;
						Node a={xx,yy,step};
						p_q.push(a);	
					}	
			}
		}	
	}
	return minstep[ex][ey];
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		init();
		for(int i=0;i<n;i++)
			scanf("%s",grid[i]);
			scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
			sx--;sy--;ex--;ey--;
		int ans=bfs();
		printf("%d\n",ans);
	}	
	return 0;
}
