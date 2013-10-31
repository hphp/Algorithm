#include <stdio.h>
#include <vector>
#define N 510
#define MAX (1<<28)
//#define avl(i,j) ((i)>0&&(i)<=n&&(j)>0&&(j)<=m&&s[i][j] == ' ' ? 1 : 0)
//
int n,m;
char s[N][N];
bool avl(int i,int j)
{
	if(i>0&&i<=n&&j>0&&j<=m)
	{
		if(s[i][j] == ' '||s[i][j] == 'E')
			return 1;
		return 0;
	}
	return 0;
}

int st,end;
int mv[4][2][2] = 
{
	{{0,-1},{0,1}},
	{{-1,0},{1,0}},
	{{0,1},{0,-1}},
	{{1,0},{-1,0}}
};
int rl[4][N*N];
int rr[4][N*N];

void change()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i == 8 && j == 1)
				printf("%c: %d %d %d\n",s[i][j],rr[2][(i-1)*m+j-1],rl[0][(i-1)*(m)+j-1]);
			if(s[i][j] == ' ')
			{
				int li = i;
				int lj = j-1;
				if(avl(li,lj))
				{
					rr[2][(i-1)*(m)+j-1] = rl[0][(i-1)*(m)+j-1] = rl[0][(li-1)*(m)+lj-1];
				}
				else rr[2][(i-1)*(m)+j-1] = rl[0][(i-1)*(m)+j-1] = (i-1)*(m)+j-1;
				//con[i*m+j].push_back(rl[i][j]);
			}
			else if(s[i][j] == 'E')
			{
				end = (i-1)*(m)+j-1;	
			}
			else if(s[i][j] == '|')
			{
				st = (i-1)*(m)+j-1;
			}
			else rr[2][(i-1)*(m)+j-1] = rl[0][(i-1)*(m)+j-1] = -1;
		}
	for(int i=n;i>0;i--)
		for(int j=m;j>0;j--)
		{
			if(s[i][j] == ' ')
			{
				int ri = i;
				int rj = j+1;
				if(avl(ri,rj))
				{
					rl[2][(i-1)*(m)+j-1] = rr[0][(i-1)*(m)+j-1] = rr[0][(ri-1)*(m)+rj-1];
				}
				else rl[2][(i-1)*(m)+j-1] = rr[0][(i-1)*(m)+j-1] = (i-1)*(m)+j-1;
				//con[i*m+j].push_back(rr[i][j]);
			}
			else if(s[i][j] == '#')
				rl[2][(i-1)*(m)+j-1] = rr[0][(i-1)*(m)+j-1] = -1;
		}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j] == ' ')
			{
				int li = i-1;
				int lj = j;
				if(avl(li,lj))
				{
					rr[4][(i-1)*(m)+j-1] =rl[1][(i-1)*(m)+j-1] = rl[1][(li-1)*(m)+lj-1];
				}
				else rr[4][(i-1)*(m)+j-1] =rl[1][(i-1)*(m)+j-1] = (i-1)*(m)+j-1;
				//con[i*m+j].push_back(rl[i][j]);
			}
			else if(s[i][j] == 'E')
			{
				end = (i-1)*(m)+j-1;	
			}
			else if(s[i][j] == '|')
			{
				st = (i-1)*(m)+j-1;
			}
			else rr[4][(i-1)*(m)+j-1] = rl[1][(i-1)*(m)+j-1] = -1;
		}
	for(int i=n;i>0;i--)
		for(int j=m;j>0;j--)
		{
			if(s[i][j] == ' ')
			{
				int ri = i+1;
				int rj = j;
				if(avl(ri,rj))
				{
					rl[4][(i-1)*(m)+j-1] = rr[1][(i-1)*(m)+j-1] = rr[1][(ri-1)*(m)+rj-1];
				}
				else rl[4][(i-1)*(m)+j-1] = rr[1][(i-1)*(m)+j-1] = (i-1)*(m)+j-1;
				//con[i*m+j].push_back(rr[i][j]);
			}
			else if(s[i][j] == '#')
				rl[4][(i-1)*(m)+j-1] = rr[1][(i-1)*(m)+j-1] = -1;
		}

}

struct Info
{
	int p,stm,stp;
}queue[N*N*4];
int step[N*N][4];

void bfsinit()
{
	for(int i=0;i<=n*m+m;i++)
		for(int j=0;j<4;j++)
			step[i][j] = MAX;
}

int bfs(int start)
{
	bfsinit();
	int s = 0;
	int e =0;
	queue[e].p = start;
	queue[e].stm = 0;
	queue[e].stp= 0;
	step[start][0] = 0;
	e ++;
	while(s < e)
	{
		int bstm = queue[s].stm;
		int p = queue[s].p;
		int stp = queue[s].stp;
		if(p == end)return stp;
		int h = p/(m)+1;
		int w = p%(m)+1;
	//	printf("%d %d %d\n",h,w,stp);
		if(step[p][bstm] > stp )
		{
			s ++;
			continue;
		}
		for(int i=0;i<2;i++)
		{
			int nh = h + mv[bstm][i][0];
			int nw = w + mv[bstm][i][1];
			int np = (nh-1)*(m)+nw-1;
			if((!avl(nh,nw))||(step[np][bstm] < stp+1))continue;
			step[np][bstm] = stp+1;
			queue[e].p = np;
			queue[e].stm = bstm;
			queue[e].stp = stp+1;
			e ++;
		}
		int np = rl[bstm][p];
		int nh = np/(m)+1;
		int nw = np%(m)+1;
		int nstm = (bstm+1)%4;
		if((avl(nh,nw))&&step[np][nstm] > stp+1)
		{
			step[np][nstm] = stp+1;
			queue[e].p = np;
			queue[e].stm = nstm;
			queue[e].stp = stp+1;
			e ++;
		}
		np = rr[bstm][p];
		nh = np/(m)+1;
		nw = np%(m)+1;
		nstm = (bstm+3)%4;

		if((avl(nh,nw))&&step[np][nstm] > stp+1)
		{
			step[np][nstm] = stp+1;
			queue[e].p = np;
			queue[e].stm = nstm;
			queue[e].stp = stp+1;
			e ++;
		}
		s++;
	}
	return -1;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		getchar();
		for(int i=1;i<=n;i++)
		{
			gets(s[i]+1);
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%c",s[i][j]);
			printf("\n");
		}
		change();
		int a,b;
		while(scanf("%d%d",&a,&b)&&a!=0)
		{
			for(int i=0;i<4;i++)	
				printf("%d %d\n",rl[i][(a-1)*(m)+b-1],rr[i][(a-1)*(m)+b-1]);
		}
		int ans = bfs(st);
		if(ans >= 0)
			printf("%d\n",ans);
		else printf("Can not escape!\n");
	}
	return 0;
}
