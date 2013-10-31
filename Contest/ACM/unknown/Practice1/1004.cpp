#include <stdio.h>
#include <string.h>
#define N 420
//'Y' (you), 'T' (target), 'S' (steel wall), 'B' (brick wall), 'R' (river) and 'E' (empty space). 

/*
3 4
YBEB
EERE
SSTE
3 4
YBEB
BBRE
SBTE


*/

char grid[N][N];
int step[N][N],n,m,s,f,sx,sy,flag[N][N];
int sp[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

struct PRI_QUEUE
{
	int x;
	int y;	
	int step;
}queue[N*N];

void b_init(void)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			step[i][j]=-1;	
			flag[i][j]=0;
		}	
	}
	step[sx][sy]=0;
	queue[0].x=sx;
	queue[0].y=sy;
	queue[0].step=0;
	s=0;
	f=1;
}

int pos(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m)
		return 1;
	else return 0;	
}

void exchange(PRI_QUEUE queue[],int a1,int a2)
{
	PRI_QUEUE temp=queue[a1];
	queue[a1]=queue[a2];
	queue[a2]=temp;	
}

void insert(int x,int y,int steps)
{
	queue[f].x=x;
	queue[f].y=y;
	queue[f].step=steps;
	int son=f;
	int mother=(f-1)/2;
	if(mother>=0)
		while(queue[mother].step>queue[son].step)
		{
			exchange(queue,mother,son);
			son=mother;
			mother=(son-1)/2;
			if(mother<0)break;
		}
	f++;
}

int smll(int a1,int a2,int end)
{
	if(a1>=end)
		return a1;
	else if(a2>=end)return a1;
	else
	{
		if(queue[a1].step<queue[a2].step)
			return a1;
		else return a2;	
	}	
}

void deleting(int end)
{
	queue[0]=queue[end];
	int mother=0;
	int son1=mother*2+1;
	int son2=mother*2+2;
	int cur_deal=smll(son1,son2,end);
	while(queue[cur_deal].step<queue[mother].step)
	{
		exchange(queue,cur_deal,mother);
		mother=cur_deal;
		son1=mother*2+1;
		son2=mother*2+2;
		cur_deal=smll(son1,son2,end);
		if(cur_deal>end)break;
	}
}

int bfs(void)
{
	b_init();
	while(f>0)
	{	
		int x=queue[0].x;
		int y=queue[0].y;
//		printf("%d %d\n",x,y);
		for(int i=0;i<4;i++)	
		{
			int xx=x+sp[i][0];
			int yy=y+sp[i][1];	
			if(pos(xx,yy)==1)
			{
				if(step[xx][yy]==-1)
				{
					if(grid[xx][yy]=='E')
					{
						step[xx][yy]=step[x][y]+1;
						insert(xx,yy,step[xx][yy]);
					}	
					else if(grid[xx][yy]=='T')
					{
						step[xx][yy]=step[x][y]+1;
						return step[xx][yy];	
					}
					else if(grid[xx][yy]=='B')
					{
						step[xx][yy]=step[x][y]+2;
						insert(xx,yy,step[xx][yy]); 
					}
				}
			}
		}
		deleting(f-1);
		f--;
	//	printf("f %d\n",f);
	}	
	return -1;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for()
		printf("%d\n",ans);
	}	
	return 0;
}
