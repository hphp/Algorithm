#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#define N 110
using namespace std;
class RabbitStepping
{
	private:
		int C(int n,int m)
		{
			int t = 1;
			int ans = 1;
			while(t < m)
			{
				ans *= n;
				ans /= t;
			}
			return ans;
		}
	public:
		double getExpected(string field, int r)
		{
			int s = field.length();
			int sum =0;
			for(int i=2;i<s;i++)
			{
				if(field[i]=='W')
					sum ++;
			}
			return sum*1.0/C(s,r);
		}
};

int main()
{
	RabbitStepping a = RabbitStepping();
	string s;
	int r;
	while(cin >> s >> r)	
	{
		printf("%lf\n",a.getExpected);
	}
}
