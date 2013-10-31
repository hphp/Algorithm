#include <string>
#include <vector>
#define MOD 1000000007
#define N 51
#define KK 1010
using namespace std;
int kind[N][KK];
int grid[N][N];

class EllysPlaylists
{
	int n;
	void grid_init()
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				grid[i][j] = 0;
	}
	public:
		int countPlaylists(vector<string> s,int K)
		{
			n = s.size();
			grid_init();
			for(int i=0;i<n;i++)
			{
				int li = s[i].length();
				for(int j=0;j<n;j++)
				{
					int sti = li-3;
					int	stj = 0;
					while(stj < 3)
					{
						if(s[i][sti] != s[j][stj])break;
						sti++,stj++;
					}
					if(stj == 3)
						grid[i][j] = 1;
				}
			}
			for(int i=0;i<n;i++)
				for(int j=0;j<=K;j++)
					kind[i][j] = 0;
			for(int i=0;i<n;i++)
				kind[i][1] = 1;
			for(int i=2;i<=K;i++)
			{
				for(int j=0;j<n;j++)
				{
					for(int k=0;k<n;k++)
					{
						if(grid[k][i])
						{
							kind[j][i] += kind[k][i-1];
							kind[j][i] %= MOD;
						}
					}
				}
			}
			int ans = 0;
			for(int i=0;i<n;i++)
				ans += kind[i][K],ans%=MOD;
			return ans;
		}
};
