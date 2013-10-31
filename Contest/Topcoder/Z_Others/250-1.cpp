#include <string>
#include <vector>
using namespace std;
#define N 51
#define SS 30
int rec[N][SS];
int rn[N];
class AnagramFree
{
	public:
		int getMaximumSubset(vector <string> S)
		{
			int n = S.size();
			for(int i=0;i<N;i++)
				for(int j=0;j<SS;j++)
					rec[i][j] = 0;
			int cnt = 0;
			for(int i=0;i<n;i++)
			{
				int len = S[i].length();
				int recc[SS] = {0};
				for(int j=0;j<len;j++)
					recc[S[i][j]-'a']++;
				int j;
				for(j=0;j<cnt;j++)
				{
					int k=0;
					for(;k<26;k++)
					{
						if(recc[k]!=rec[j][k])
							break;
					}
					if(k == 26)
						break;
				}
				if(j == cnt)
				{
					for(int k=0;k<26;k++)
						rec[cnt][k] = recc[k];
					cnt ++;
				}
			}
			return cnt;
		}
};
/*
2004
2011
226
*/
