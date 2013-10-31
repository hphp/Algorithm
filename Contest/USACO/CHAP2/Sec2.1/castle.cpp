/*
ID: hanjiatong1
PROG: castle 
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 53 
#define avl(x,y) ((x) >= 1 && (x) <= n && (y) >= 1 && (y)<=m ? 1 :0)
using namespace std;
int area[N*N],cnt;
int blg[N][N];
int n,m;
int st[N][N];

int mv[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};
void dfs(int x,int y)
{
	area[cnt] ++;
	blg[x][y] =cnt;
	for(int i=0;i<4;i++)
	{
		int xx = x + mv[i][0];
		int yy = y + mv[i][1];
		if(avl (xx,yy) &&( ! (st[x][y] & (1<<i))) && (blg[xx][yy] == -1))
		{
			dfs(xx,yy);
		}
	}
}

int fst[4] = {1,2,1,0};
char to[4] = {"NE"};

int main() {
    ofstream fout ("castle.out");
    ifstream fin ("castle.in");
    fin >> m >> n;
    for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			blg[i][j] = -1;
			fin >> st[i][j];
		}
	cnt = 0;
	int mx = 0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(blg[i][j] == -1)
			{
				dfs(i,j);
				if(area[cnt] > mx)
					mx = area[cnt];
				cnt ++;
			}
	//	for(int i=0;i<cnt;i++)
	//		fout << area[i] << ' ';
	int mxmx = 0;
	int ansx = -1,ansy = -1;
	char anss;
	for(int j=1;j<=m;j++)
	{
		for(int k=0;k<2;k++)
		for(int i=n;i>0;i--)
		{
			{
				int tire = fst[k];
				int xx = i + mv[tire][0];
				int yy = j + mv[tire][1];
				if( avl(xx,yy) && ( st[i][j] & (1<<tire)) && (blg[i][j]!=blg[xx][yy]))
				{
					int mx = area[blg[i][j]] + area[blg[xx][yy]];
					if(mx > mxmx)
					{
						mxmx = mx;
						ansx = i;
						ansy = j;
						anss = to[k];
					}
				//	if(i == 4 && j == 1)
			//			fout << mx << endl;
				}
			}
		}
	}
	fout << cnt << endl;
	fout << mx << endl;
	fout << mxmx << endl;
	fout << ansx << ' ' << ansy << ' ' << anss  << endl;
    return 0;
}

/*
     1   2   3   4   5   6   7
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#   
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #   
   #---#########---#####---#---#
 4 # ->#   |   |   |   |   #   #   
   ############################# 

*/
/*2010-06-10:
	20:39--21:50
	*/
