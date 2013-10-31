#include <string>
using namespace std;

class PotatoGame
{
	public:
		string theWinner(int n)
		{
			int cnt = 0;
			while(n)	
			{
				cnt += n%4;
				n/=4;	
			}
			string ans = "";
			if(cnt%2)
				ans = "Hanako";
			else ans = "Taro";
			return ans;
		}
};
