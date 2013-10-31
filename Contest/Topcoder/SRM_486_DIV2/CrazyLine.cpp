#include <vector>
#include <algorithm>
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
int a[1000];
class CrazyLine
{
	public:
		int maxCrazyness(vector<int>heights)
		{
			int size = heights.size();
			std::sort(heights.begin(),heights.end());
			for(int i=0;i<size;i++)
				a[i] = heights[i];
			for(int i=size-1,j=0;i>=0;i--,j++)
				heights[j] = a[i];
			if(size % 2 == 0)
			{
				int s1=0;
				int s2 = size/2;
				int ans1 = heights[s2-1];
				for(int i=0;i<s2-1;i++)
					ans1+=(2*heights[i]);
				for(int i=s2+1;i<size;i++)
					ans1-=(2*heights[i]);
				ans1-=heights[s2];
				return ans1;
			}
			else
			{
				if(size == 1)
					return 0;
				else
				{
					int s1=0;
					int s2 = size/2;
					int ans1 = 0;
					for(int i=0;i<s2;i++)
						ans1+=(2*heights[i]);
					for(int i=s2+2;i<size;i++)
						ans1-=(2*heights[i]);
					ans1-=(heights[s2]+heights[s2+1]);
					s1 = 0;
					s2 = (size+1)/2;
					int ans2 = heights[s2-1] + heights[s2-2];
					for(int i=0;i<s2-2;i++)
						ans2+=(2*heights[i]);
					for(int i=s2;i<size;i++)
						ans2-=(2*heights[i]);
					return Max(ans1,ans2);
				}
			}
		}
};
