#include <string>
using namespace std;

class ColorfulTilesEasy
{
	public:
		int theMin(string r)
		{
			int len = r.length();
			char c = r[0];
			int ans = 0;
			int i = 0;
			while(i < len)
			{
				c = r[i];
				int cnt = 0;
				while((i < len) && (r[i] == c))
				{
					i++;
					cnt++;
				}
				printf("%d\n",cnt);
				ans += (cnt/2);
			}
			return ans;
		}
};
