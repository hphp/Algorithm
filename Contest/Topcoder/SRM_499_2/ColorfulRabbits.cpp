#include <vector>
using namespace std;
#define N 1000100
int rec[N] = {0};
int rr[N] = {0};

class ColorfulRabbits
{
	public:
		int getMinimum(vector <int> r)
		{
			int n = r.size();
			for(int i=0;i<N;i++)
				rr[i] = rec[i] = 0;
			int sum = 0;
			for(int i=0;i<n;i++)
			{
				rr[r[i]] ++;
				if(!rec[r[i]])
				{
					sum+=r[i]+1;
					rec[r[i]] = 1;
				}
				if(rr[r[i]] == r[i]+1)
					rec[r[i]] = 0, rr[r[i]] = 0;
			}
			return sum;
		}
};
