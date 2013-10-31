#include <vector>
#include <string>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;

class Filtering
{
	public:
		vector <int> designFilter(vector <int> s, string o)
		{
			int n = o.size();
			int mn,mx;
			int i=0;
			for(;i<n;i++)
			{
				if(o[i] == 'A')
				{
					mn = s[i];
					mx = s[i];
					break;
				}
			}
			for(;i<n;i++)
			{
				if(o[i] == 'A')
				{
					mn = Min(s[i],mn);
					mx = Max(s[i],mx);
				}
			}
			bool flag = 0;
			for(int i=0;i<n;i++)
			{
				if(o[i] == 'R')
				{
					if((s[i] >= mn) && (s[i]<=mx))
					{
						flag = 1;
					}
				}
			}
			vector <int> ans;
			if(!flag)
			{
			ans.push_back(mn);
			ans.push_back(mx);
			}
			return ans;
		}	
};
/*
2011-02-11
-10:08
-10:13
216.38
*/
