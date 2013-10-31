#include <string>
#include <vector>
#define MAX (1<<28)
#define Min(a,b) ((a) < (b)?(a):(b))
using namespace std;
#define N 51
#define M 3000
int grid[N][N];
int self[N];
int avl[M][N];
int mn[M][N];

class Thirteen
{
	public:
		int calcTime(vector<string> s)
		{
			int n = s.size();	
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(s[i][j] == '#')
						grid[i][j] = -1;
					else if(s[i][j] < 'a')
						grid[i][j] = s[i][j]-'A'+1;
					else grid[i][j] = s[i][j]-'a'+27;
				}
			for(int i=0;i<M;i++)
				for(int j=0;j<n;j++)
					avl[i][j] = 0;
			avl[0][0] = 1;
			for(int i=1;i<M;i++)
			{
				if(i%13 ==0)continue;
				for(int j=0;j<n;j++)
				{
					for(int k=0;k<n;k++)
					{
						if((grid[k][j] >=0))
						{
							if(i - grid[k][j] >=0)
								if(avl[i-grid[k][j]][k])
								{
									avl[i][j] = 1;
									break;
								}
						}
					}
				}
			}
			int ans = MAX;
			for(int i=0;i<M;i++)
				if(avl[i][n-1])
				{
					ans = i;break;
				}
/*			if(ans == MAX)
			{
				for(int i=0;i<n;i++)
				{
					self[i] = -1;
					for(int j=1;j<M;j++)
						if(avl[j][i])
						{
							self[i] = j;
							break;
						}
				}
				for(int i=1;i<M;i++)
				{
					if(i%13 ==0)continue;
					for(int j=0;j<n;j++)
					{
						if(avl[i][j])
						{
							mn[i][j] = MAX;
							for(int k=0;k<n;k++)
							{
								if(grid[k][j] >=0 && (grid[k][j] %13 !=0))
								{
									if(i - grid[k][j] >=0)	
										if(avl[i-grid[k][j]][k])
										{
											mn[i][j] = Min(mn[i-grid[k][j]][k],mn[i][j]);
											if(self[j] > 0)
												mn[i][j] = Min(mn[i][j],self[j]);
										}
								}
							}
						}
					}
				}
				int i = 1;
				while(i*13<M)
				{
					if(avl[i*13][n-1])
					{
						ans = Min(ans,i*13+mn[i*13][n-1]);
					}
					i++;
				}
			}*/
			if(ans == MAX)
				ans = -1;
			return ans;
		}
};
