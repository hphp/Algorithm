#include <vector>
#include <string>
using namespace std;
#define N 61
int dmx[N][N],rmx[N][N];

class AmoebaDivTwo
{
	public:
		int count(vector <string> table, int K)		
		{
			int n = table.size();
			int m = table[0].length();
			for(int i=n-1;i>=0;i--)
			{
				for(int j = m-1;j>=0;j--)
				{
					if(table[i][j] == 'M')
						dmx[i][j] = rmx[i][j] = 0;
					else
					{
						if(j == m-1)
							rmx[i][j] = 1;
						else rmx[i][j] = rmx[i][j+1]+1;
						if(i == n-1)
							dmx[i][j] = 1;
						else dmx[i][j] = dmx[i+1][j]+1;
					}
				}
			}
			int cnt = 0;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(dmx[i][j] >= K)
						cnt++;
					if(K > 1)
					if(rmx[i][j] >= K)
						cnt++;
				}
			}
			return cnt;
		}
};

/*
2011-01-24
14:50
15:03 - 15:10 AC
174.xx
*/
