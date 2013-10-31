#include <vector>
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;

class KiwiJuiceEasy
{
	public:
		vector <int> thePouring(vector <int> capacities, vector <int> bottles, vector <int> fromId, vector <int> toId)
		{
			int ans[100];
			int n = capacities.size();
			for(int i=0;i<n;i++)
				ans[i] = bottles[i];
			int size = fromId.size();
			for(int i=0;i<size;i++)
			{
				int f = fromId[i];
				int t = toId[i];
				int amount = Min(capacities[t]-ans[t],ans[f]);
				ans[f] -= amount;
				ans[t] += amount;
			}
			vector<int> aa;
			for(int i=0;i<n;i++)
				aa.push_back(ans[i]);
			return aa;
		}
};
