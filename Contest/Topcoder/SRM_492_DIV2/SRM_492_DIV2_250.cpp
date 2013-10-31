#include <stdio.h>
#include <vector>
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;

class TimeTravellingCellar
{
	public:
		int determineProfit(vector <int> profit, vector <int> decay)
		{
			int n = profit.size();
			int ans = -(1<<28);
			for(int i=0;i<n;i++)
			{
				int pp = -(1<<28);
				for(int j=0;j<n;j++)
				{
					if(i == j)continue;
					pp = Max(pp,profit[i]-decay[j]);
				}
				ans = Max(pp,ans);
			}
			return ans;
		}
};
/*
2011-02-01
10:04 - 10:14
*/
