#include <vector>
using namespace std;
#define N 50

int taken[N][N];

class TheMoviesLevelOneDivTwo
{
	public:
		int find(int n,int m,vector<int> row , vector<int> seat)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					taken[i][j] = 0;
			for(int i=0;i<n;i++)
				taken[row[i]][seat[i]]= 1;
			int ans = 0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<m;j++)
				{
					if(!taken[i][j])
						if(!taken[i][j+1])
							ans++;
				}
			}
			return ans;
		}
};
