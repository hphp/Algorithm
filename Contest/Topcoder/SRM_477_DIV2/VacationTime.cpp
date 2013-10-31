#include <vector>
using namespace std;

class VacationTime
{
	public:
		int bestSchedule(int N , int K , vector <int> w)
		{
			int  ans = N;
			for(int i=K;i<=N;i++)
			{
				int st = i-K+1;
				int ss = w.size();
				int cnt = 0;
				for(int j=0;j<ss;j++)
				{
					if(w[j]>=st&&w[j]<=i)
						cnt++;
				}
				ans = ans<cnt?ans:cnt;
			}
			return ans;
		}
};
