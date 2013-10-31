#include <vector>
#include <algorithm>
#define abss(a) ((a)<0?(-(a)):(a))
using namespace std;
struct A
{
	int x,y;
}a[2000];

bool cmp(A a,A b)
{
	if(a.x < b.x)
		return 1;
	if(a.x == a.x)
	{
		if(a.y < b.y)
			return 1;
	}
	return 0;
}

class LinearTravellingSalesman
{
	public:
		int findMinimumDistance(vector<int> x,vector<int> y)
		{
			int n = x.size();
			for(int i=0;i<n;i++)
				a[i].x = x[i],a[i].y = y[i];
			std::sort(a,a+n,cmp);
			int ans = 0;
			for(int k=1;k<n;k++)
			{
				ans += abss(a[k].x-a[k-1].x)+abss(a[k].y-a[k-1].y);
			}
			return ans;
		}
};
