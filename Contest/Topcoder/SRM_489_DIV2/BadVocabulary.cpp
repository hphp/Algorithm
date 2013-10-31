#include <vector>
#include <string>
using namespace std;
class BadVocabulary
{
	public:
		int count(string bP,string bS,string bs,vector <string> v)
		{
			int n = v.size();
			int ans = 0;
			for(int j=0;j<n;j++)
			{
			int ol = v[j].length();
				bool sign = 0;
				int len = bP.length();
				int i = 0;
				for(i = 0 ; i < len && i < ol; i ++)
					if(bP[i] != v[j][i])
						break;
				if(i == len)
					sign = 1;
				len = bS.length();
				int a = ol-1;
				for(i = len-1;i>=0&&a>=0;i--,a--)
				{
					if(v[j][a] != bS[i])
						break;
				}
				if(i < 0)
					sign = 1;
				bool flag = 0;
				len = bs.length();
				for(int k=1;k<ol-len;k++)
				{
					int p = 0;
					for(i = k ; i < ol && p < len;i++,p++)
					{
						if(bs[p] != v[j][i])
							break;
					}
					if(p == len)
					{
						flag = 1;break;	
					}
				}
				if(flag)
					sign = 1;
				if(sign)
					ans++;
			}
			return ans;
		}
};
