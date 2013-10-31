#include <stdio.h>
#include <string>
#include <vector>
#define N 110
using namespace std;
class RabbitVoting
{
	public:
		string getWinner(vector <string> names, vector <string> votes)
		{
			int cnt[N];
			int ss = names.size();
			int vs = votes.size();
			for(int i=0;i<ss;i++)
				cnt[i] = 0;
			int mx = 0;
			for(int j=0;j<vs;j++)
			for(int i=0;i<ss;i++)
			{
				if(i != j && votes[j] == names[i])
				{
					cnt[i]++;
					if(cnt[i] > mx)
						mx = cnt[i];
				}
			}
			int ans = 0 ;
			int r = -1;
			for(int i=0;i<ss;i++)
				if(cnt[i] == mx)
				{
					r = i;
					ans ++;
				}
			string aa;
			if(ans == 1)
				aa = names[r];
				return aa;
		}
};
