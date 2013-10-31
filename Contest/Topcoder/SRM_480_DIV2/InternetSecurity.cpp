#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define N 101

vector<string> key[N];
char rec[N];
class InternetSecurity
{
	public:
		vector <string> determineWebsite(vector <string> address, vector <string> keyword, vector <string> dangerous, int threshold)
		{
			int size = keyword.size();
			for(int i = 0;i < size; i ++)
			{
				key[i].clear();
				int len = keyword[i].length();
				int j = 0;
				int cnt = 0;
				while(j <= len)
				{
					if(keyword[i][j] == ' ' || keyword[i][j] == '\0')
					{
						rec[cnt] = '\0';
						string temp = rec;
						key[i].push_back(temp);
						cnt = 0;
					}
					else {
						rec[cnt++] = keyword[i][j];
					}
					j++;
				}
			}
			map<string,int> ifD;
			for(int i=0;i<dangerous.size();i++)
				ifD[dangerous[i]] = 1;
			int ans[N],acnt=0;
			int flag = 1;
			bool isans[N] = {0};
			while(flag)
			{
				flag = 0;
				for(int i=0;i<size;i++)
				{
					if(isans[i])continue;
					int cnt = 0;
					for(int j=0;j<key[i].size();j++)
					{
						if(ifD[key[i][j]])
							cnt ++;
					}
					if(cnt >= threshold)
					{
						for(int j=0;j<key[i].size();j++)
						{
							ifD[key[i][j]] = 1;
						}
						flag = 1;	
						isans[i] = 1;
						ans[acnt++] = i;
					}
				}
			}
			vector<string> rans;
			sort(ans,ans+acnt);
			for(int i=0;i<acnt;i++)
				rans.push_back(address[ans[i]]);
			return rans;
		}
};
