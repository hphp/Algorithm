#include <vector>
#include <string>
#define MAX (1<<28)
using namespace std;

class FoxProgression
{
	public:
		int theCount(vector<int>seq)
		{
			int n = seq.size();
			int ans = 0;
			if(n < 2)
				ans = -1;
			else
			{
				int test = MAX;
				if(n == 2)
				{
					if(seq[0]&&seq[1])
					{
						if(((seq[1]*seq[1]%seq[0]) == 0) && ((seq[1]%seq[0])==0))
						{
							test = seq[1]*seq[1]/seq[0];
							ans++;	
						}
					}
					if(seq[1]+seq[1]-seq[0]!=test)
					ans++;
				}
				else
				{
					int flag = 0;
					for(int i=1;i<n-1;i++)
					{
						if(seq[i-1]&&seq[i]);
						else {flag = 1;break;}
						if((seq[i]*seq[i]) == (seq[i-1]*seq[i+1]) && ((seq[i]%seq[i-1])==0));
						else 
						{
							flag = 1;break;
						}
					}
					if(!flag)
					{
						if((seq[n-1]*seq[n-1]%seq[n-2]) == 0)
							ans++,test = seq[n-1]*seq[n-1]/seq[n-2];	
					}
					flag = 0;
					for(int i=1;i<n-1;i++)
					{
						if((seq[i]+seq[i]) == (seq[i-1]+seq[i+1]));
						else 
						{
							flag = 1;break;
						}
					}
					if(!flag)
						if(seq[n-1]+seq[n-1]-seq[n-2]!=test)
							ans++;
				}
			}
			return ans;
		}
};
