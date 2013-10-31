#include <vector>
#include <string>
using namespace std;
#define N 50 
#define M 2000
#define MOD 1000000007
int kd[N][M][N][2];

class FoxAverageSequence
{
	public:
		int theCount(vector<int>s)
		{
			int n = s.size();
			if(n == 1)			
			{
				if(s[0] == -1)
					return 41;
				return 1;
			}
			for(int i=0;i<n;i++)
				for(int j=0;j<M;j++)
					for(int jj=0;jj<N;jj++)
						for(int k=0;k<2;k++)
						kd[i][j][jj][k] = 0;
			kd[0][0][0][0] = 1;
			if(s[0] == -1)
			{
				int ss = s[1],ee = s[1];
				if(s[1] == -1)
					ss = 0 , ee = 40;
				for(int i=0;i<=40;i++)
				for(int j=ss;j<=ee;j++)
				{
					if(i < j)continue;
					kd[2][i+j][j][(i > j)?1:0]++;
					printf("2 : i%d j%d %d\n",i,j,kd[2][i+j][j][(i > j)?1:0]);
				}
			}
			else
			{
				int ss = s[1],ee = s[1];
				if(s[1] == -1)
					ss = 0,ee=40;
				for(int i=ss;i<=ee;i++)
					if(s[0] >= i)
					{
						kd[2][s[0]+i][i][s[0]>i?1:0]++;// fuck 这里写错了。
					}
			}

			for(int i=3;i<=n;i++)
			{
				for(int j=0;j<i*40;j++)
				{
					int jjs = s[i-2] , jje = s[i-2];
					if(s[i-2] == -1)
						jjs = 0 , jje  = 40;
					for(int jj = jjs ; jj <= jje ; jj ++)
					{
						int ss = s[i-1],ee=s[i-1];
						if(s[i-1] == -1)
							ss = 0 , ee = 40;
						for(int k=ss;k<=ee;k++)
						{
							if((j/(i-1))<k)break;
							if(k >= jj)
							{
								for(int kk=0;kk<2;kk++)
								{
									kd[i][j+k][k][0] += kd[i-1][j][jj][kk];
									kd[i][j+k][k][0]%=MOD;
								}
							}
							else
							{
								kd[i][j+k][k][1] += kd[i-1][j][jj][0];
								kd[i][j+k][k][1]%=MOD;
							}
						}
					}
				}
			}
				
			int ans = 0 ;
			for(int i=0;i<M;i++)
				for(int ii=0;ii<N;ii++)
					for(int j=0;j<2;j++)
						ans += kd[n][i][ii][j] , ans %= MOD;
			return ans;
		}
};
