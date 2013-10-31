#include <vector>
using namespace std;
class OnTheFarmDivTwo
{
public:
	vector<int> animals(int head,int legs)
	{
		int a = head,b = legs;
		vector<int> ans;
		if(((b-2*a) >= 0) && ((b-2*a)%2==0))
		{
			int y = (b-2*a)/2;
			int x = a-y;
			int x2 = x*2,y4=y*4;
			if(x>=0&&x<=a && y>=0 && y<=a && x2>=0 && x2<=b)
			{
				ans.push_back(x);
				ans.push_back(y);
			}
		}
		return ans;
	}
};
