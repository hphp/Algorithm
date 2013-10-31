#include <string>
#include <vector>
using namespace std;
#define avl(x,y) ((((x)>=0&&(x)<n)&&((y)>=0&&(y)<m))?1:0)
#define N 53

int bl[N][N][2];// 0 : B v  1  R h 
int mv[2][2][2] = 
{
	{{-1,0},{1,0}},
	{{0,-1},{0,1}}
};

char stdd[4] = "BRG";

class ColoredStrokes
{
	public:
		int getLeast(vector <string> p)
		{
			int n = p.size();
			int m = p[0].length();
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					for(int k=0;k<2;k++)
						bl[i][j][k] = -1;
			int ans = 0;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
				{
					if(p[i][j] == 'G')
					{
						for(int ss=0;ss<2;ss++)
						{
							if(bl[i][j][ss] == -1)
							{
								ans ++;
								for(int kk=0;kk<2;kk++)
								{
									int xx = i;
									int yy = j;
									while(avl(xx,yy) && ((p[xx][yy] ==  stdd[ss])||((p[xx][yy] ==  stdd[2]))))
									{
										bl[xx][yy][ss] = 0;
										xx += mv[ss][kk][0];
										yy += mv[ss][kk][1];
									}
								}
							}
						}
					}
				}
				
			for(int ss =0;ss<2;ss++)
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
				{
					if(p[i][j] == stdd[ss])
					{
						if(bl[i][j][ss] == -1)
						{
							ans ++;
							for(int kk=0;kk<2;kk++)
							{
								int xx = i;
								int yy = j;
								while(avl(xx,yy) && ((p[xx][yy] ==  stdd[ss])||((p[xx][yy] ==  stdd[2]))))
								{
									bl[xx][yy][ss] = 0;
									xx += mv[ss][kk][0];
									yy += mv[ss][kk][1];
								}
							}
						}
					}
				}
			return ans;
		}
};


/*
2020 - 2040

289
*/
