#include <algorithm>
#include <vector>
#include <string>
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
#define NN 18
#define STM (1<<16)
struct P
{
	int x,y,e;
}p[NN];

struct R
{
	int stm;
	double v;
}rr[STM];
int cnt[STM],mn[STM];

bool cmp(R a, R b)
{
	if(a.v < b.v)
		return 1;
	else if(a.v > b.v)
		return 0;
	if(a.stm < b.stm)
		return 1;
		return 0;
}

class SquaresCovering
{
	public :
		int minCost(vector <int> x, vector <int> y, vector <int> cost, vector <int> sides)
		{
			int size = x.size();
			int sn = cost.size();
			for(int i=0;i<size;i++)
			{
				p[i].x = x[i];
				p[i].y = y[i];
				p[i].e = 0;
			}
			int stm = 1<<size;
			for(int i=1;i<stm;i++)
			{
				int xmx = 0 ,ymx = 0,xmn = MAX,ymn = MAX;
				mn[i] = MAX;
				cnt[i] = 0;
				rr[i].stm = i;
				for(int j=0;j<size;j++)
				{
					if(i & (1<<j))
					{
						if(xmx < x[j])
						{
							xmx = x[j];
						}
						if(xmn > x[j])
						{
							xmn = x[j];
						}
						if(ymx < y[j])
						{
							ymx = y[j];
						}
						if(ymn > y[j])
						{
							ymn = y[j];
						}
						cnt[i]++;
					}
				}
				int xx = Max(xmx - xmn + 1 ,ymx-ymn+1);
				for(int j=0;j<sn;j++)
					if(sides[j]>=xx)
						if(cost[j] < mn[i])
							mn[i] = cost[j];
			}
			for(int i=0;i<stm;i++)
				rr[i].v = mn[i]*1.0/cnt[i];
			sort(rr,rr+stm,cmp);
			//for(int i=0;i<stm;i++)
		//		printf("%lf ",rr[i].v);
			int already =0;
			mn[0] = 0;
			for(int k=0;k<200;k++)
			{
				already = 0;
			for(int i=1;i<stm;i++)
			{
				if((already & i) < i)
				{
					if(mn[i] + mn[already] <= mn[already|i])
					{
						mn[already|i] = mn[i]+mn[already];
						already = already | i;
					}
				}
			}
			}
			return mn[stm-1];
		}
};
/*
int main()
{
	SquaresCovering sc SquaresCovering();
	while(scanf)	
}
*/
