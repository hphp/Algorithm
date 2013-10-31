#include <vector>
#include <string>
#include <stdlib.h>
#define N 100
int v[N];
using namespace std;

class RabbitVoting
{
	public:
		string getWinner(vector <string> names,vector<string> votes)
		{
			int n = names.size();
			for(int i=0;i<n;i++)
				v[i] = 0;
			int ans = 0;
			string sans;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)	
				{
					if(i == j)continue;
					if(votes[i] == names[j])
						v[j]++;
				}
			}
			char vv[40] = "";
			for(int j=0;j<n;j++)
			{
				if(v[j] == ans)
				{
					vv[0] = '\0';
					sans = vv;
				}
				else if(v[j] > ans)
				{
					ans = v[j];
					sans = names[j];
				}
			}
			return sans;
		}
};
