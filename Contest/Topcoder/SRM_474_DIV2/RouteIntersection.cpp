#include <vector>
#include <string>
#include <map>
using namespace std;
int sign[51][51];

class RouteIntersection
{
	public:
		string isValid(int n,vector <int> cd, string mv)
		{
			int nn = cd.size();
			map<int,int> mp;
			int cnt = 1;
			mp[0] = 1;
			cnt ++;
			for(int i=0;i<nn;i++)
				if(!mp[cd[i]])
					mp[cd[i]] = cnt++;
			for(int j=0;j<=nn;j++)
			for(int i=0;i<cnt;i++)
				sign[j][i] = 0;
			int ans = 0;
			for(int i=0;i<nn;i++)
			{
				for(int k=1;k<cnt;k++)
					sign[i+1][k] = sign[i][k];
				if(mv[i] == '+')
					sign[i+1][mp[cd[i]]] ++;
				else sign[i+1][mp[cd[i]]]--;
				for(int j=0;j<=i;j++)
				{
					int k =0;
					for(k=1;k<cnt;k++)
						if(sign[j][k] != sign[i+1][k])
							break;
					if(k == cnt)
						ans = 1;
				}
			}
			string sans = "VALID";
			if(ans)
				sans = "NOT VALID";
			return sans;
		}
};

