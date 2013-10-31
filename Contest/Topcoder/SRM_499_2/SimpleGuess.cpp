#include <vector>
using namespace std;

class SimpleGuess
{
	public:
		int getMaximum(vector<int> h)
		{
			int n = h.size();
			int ans = 0;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
				{
					if(i!=j)
					{
						int a = (h[i]+h[j]);
						if(((a%2)==0 )&& (a > 0))
						{
							int b = a/2;
							int c = h[i]-b;
							if(c >0 && c < h[i])
							{
if(b!=c)
								if(ans < b*c)	
									ans = b*c;
							}
						}
					}
				}
			return ans;
		}
};
