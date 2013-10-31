#include<vector>

using namespace std;

class TheAirTripDivTwo
{
	public:
		int find(vector <int> flights, int fuel)
		{
			int size = flights.size();
			int cnt = 0;
			while(fuel>=0 && cnt < size)
			{
				fuel-=flights[cnt];
				cnt ++;
			}
			if(fuel>=0)
				return size;
			else return cnt-1;
		}
};
