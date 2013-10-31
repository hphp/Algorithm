#include <vector>
#include <algorithm>
#define N 53
using namespace std;
/*
struct B
{
	int sum;
}b[N];*/
int b[N];

class Badgers
{
	public:
		int feedMost(vector <int> h, vector <int> g , int tF)
		{
			int n = h.size();
			for(int i=n;i>0;i--)
			{
				for(int j=0;j<n;j++)
				{
					b[j] = h[j] + (i-1)*g[j];
				}
				sort(b,b+n);
				int sum = 0;
				for(int j=0;j<i;j++)
					sum += b[j];
				if(sum <= tF)
					return i;
			}
			return 0;
		}
};
