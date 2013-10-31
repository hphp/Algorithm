#include <vector>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAX (1<<28)
using namespace std;

class TheBoringGameDivTwo
{
	public:
		vector <int> find(int x1,int kJ,int x2,int kB,int y,int kF)
		{
			vector<int> ans;
			int x = x1+x2;
			if((y+kF-x) == (kJ+kB))
			{
				int mn = MAX;
				int mx = -MAX;
				for(int c = 0;c<=y;c++)
				{
					for(int e = 0;e<=y;e++)
					{
						int d =  y-c-2*e;
						if(d>=0)
						{
							int a =  x+c-d;
							if(a>=0)
							{
								int b = kF-a-d;
								if(b>=0)
								{
									mn = Min(c+e+kF,mn);
									mx = Max(c+e+kF,mn);
								}
							}
						}
					}
				}
				if(mn<MAX&&mx>=0)
				{
					ans.push_back(mn);
					ans.push_back(mx);
					return ans;
				}
				else return ans;
/*				int mn,mx;
				if((y-x)&1)
				{
					mn = (y-x+1)/2;
				}
				else mn = (y-x)/2;
				mx = (y-x+Min(x,kF))/2;
				ans.push_back(mn+kF);
				ans.push_back(mx+kF);
*/
			}
			else return ans;
		}
};
