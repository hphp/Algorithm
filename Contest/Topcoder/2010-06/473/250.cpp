#include <iostream>
#include <vector>
using namespace std;

class OnTheFarmDivTwo
{
	public:
	vector <int> animals(int heads, int legs)
	{
		int tmp = 4*heads - legs;
		if(tmp%2 == 0)
		{
			vector <int> aa;
			aa.push_back(tmp/2);
			aa.push_back(heads-tmp/2);
			return aa;
		}
		else
		{
		
			vector <int> aa;
			return aa;		
		}
	}
};
