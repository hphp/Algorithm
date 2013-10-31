#include <vector>
#include <string>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define N 58
#define MAX 1000000000000000000000000090000000000000000000000000000000000000000000000000000000000.0
using namespace std;
double mx[N][N];
double mn[N][N];

class FoxPlayingGame
{
	public:
		double theMax(int nA,int nB,int pA,int pB)
		{
			double add = pA/1000.0;
			double mul = pB/1000.0;
			for(int i=0;i<=nA;i++)
				for(int j=0;j<=nB;j++)
					mx[i][j] = -MAX,mn[i][j] = MAX;
			mx[0][0] = 0;
			mn[0][0] = 0;
			for(int i=0;i<=nA;i++)
				for(int j=0;j<=nB;j++)
				{
					if(i)
					{
						mx[i][j] = Max(mx[i][j],mx[i-1][j] + add);
						mn[i][j] = Min(mn[i][j],mn[i-1][j] + add);
					}
					if(j)
					{
						mx[i][j] = Max(mx[i][j],mx[i][j-1]*mul);
						mx[i][j] = Max(mx[i][j],mn[i][j-1]*mul);
						mn[i][j] = Min(mn[i][j],mx[i][j-1]*mul);
						mn[i][j] = Min(mn[i][j],mn[i][j-1]*mul);
					}
				}
			return mx[nA][nB];
		}
};
