#include <vector>
using namespace std;

class CarrotBoxesEasy
{
	public:
		
		int theIndex(vector <int> c, int K)
		{
			int n = c.size();
			for(int i = 1; i < K ; i ++)
			{
				int r = 0;
				for(int j=0;j<n;j++)
					if(c[r] < c[j])
						r = j;
				c[r]--;
			}
				int r = 0;
				for(int j=0;j<n;j++)
					if(c[r] < c[j])
						r = j;
			return r;
		}
};
