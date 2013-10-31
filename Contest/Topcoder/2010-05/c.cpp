#include <string>
#include <vector>
using namespace std;
typedef long long Int;
#define MAX 1010000100000LL
#define MAXX 101000000LL
#define N 53
#define avl(x,y) ((x)>=0 && (x) < n && (y)>=0 && (y) < m)
#define abss(x) ((x)>0?(x):(-(x)))

class ActivateGame
{
	private :
		Int mn[N][N];
		Int MTREE(int x,int y);
		int n,m;
		int g[N][N];
	public :
		int findMaxScore(vector <string> grid);	
};

int mv[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
Int ActivateGame::MTREE(int x, int y)
{
	for(int i = 0 ; i <= n ;i ++)
		for(int j = 0 ; j <= m ; j ++)
		{
			mn[i][j] = MAX;
		}
	mn[n][m] = MAX*2;
	int flag[N][N] = {0};
	mn[x][y] = 0;
	int cx = x;
	int cy = y;
	int mx = x;
	int my = y;
	Int sum = 0;
	int cnt = 0;
	while(cx != n && cy != m)
	{
	//	printf("%d %d %I64d\n",cx,cy,mn[cx][cy]);
		sum += mn[cx][cy];
		cnt ++;
	//	printf("sum : %I64d\n",sum);
		flag[cx][cy] = 1;
		mx = cx ; my = cy;
		cx = n ; cy = m;
		for(int i =0 ;i < 4; i ++)	
		{
			int xx = mx + mv[i][0];
			int yy = my + mv[i][1];	
			if(avl(xx,yy) && flag[xx][yy] == 0)
			{
				if(MAXX-abss(g[xx][yy]- g[mx][my]) < mn[xx][yy])
					mn[xx][yy] = MAXX-abss(g[xx][yy]- g[mx][my]);
	//			printf("%I64d %I64d\n",mn[xx][yy],mn[cx][cy]);
				/*if(mn[xx][yy] < mn[cx][cy])
				{
					cx = xx; cy = yy;	
				}*/
			}
		}
		for(int i =0 ;i < n; i ++)	
			for(int j=0;j<m;j++)
		{
			int xx = i;;
			int yy = j;	
			if(avl(xx,yy) && flag[xx][yy] == 0)
			{
				if(mn[xx][yy] < mn[cx][cy])
				{
					cx = xx; cy = yy;	
				}
			}
		}
	}
//	printf("cnt : %d\n",cnt);
	return sum;
}

int ActivateGame::findMaxScore(vector <string > grid)
{
	n = grid.size();
	m = grid[0].length();
	for(int i =0 ; i < n; i ++)
	{
		for(int j= 0 ; j < m; j ++)	
		{
			char c = grid[i][j];
			if(c >= 'a' && c <= 'z')
				g[i][j] = c - 'a' + 10;
			else if(c >= 'A'&& c <= 'Z')
				g[i][j] = c-'A' + 36;
			else g[i][j] = c-'0';
		}
	}
	Int ans = MTREE(0,0);
//	printf("%I64d\n",MAXX*(n*m-1) - ans);
	int aa = (int)(MAXX*(n*m-1) - ans);
	return aa;
}

/*int main()
{
	int n;
	char s[39];
	while(scanf("%d",&n)!=EOF)	
	{
		ActivateGame a = ActivateGame();
		vector<string> grid;
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			grid.push_back(s);
		}
		printf("%d\n",a.findMaxScore(grid));
	}
}*//*
3
John
Brus
Gogo
*/

