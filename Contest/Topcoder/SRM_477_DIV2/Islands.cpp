#include <string>
#include <vector>
#define avl(i,j) ((((i)>=0)&&((i)<n)&&((j)>=0)&&((j)<m))?1:0)

using namespace std;

int mv[2][3][2] = 
{
	{
		{-1,0},{-1,1},
		{0,-1}
	},
	{
		{-1,-1},{-1,0},
		{0,-1}
	}
};

class Islands
{
	public:
		int beachLength(vector <string> ks)
		{
			int n = ks.size();
			int m = ks[0].length();
			bool flag = 0;
			int cnt = 0;
			for(int i=0;i<n;i++)
			{
				flag = 1^flag;
				for(int j=0;j<m;j++)
				{
					for(int k=0;k<3;k++)
					{
						int ii = i + mv[flag][k][0];
						int jj = j + mv[flag][k][1];
						if(avl(ii,jj))
						{
							if(ks[ii][jj] != ks[i][j])
								cnt++;
						}
					}
				}
			}
			return cnt;
		}
};
