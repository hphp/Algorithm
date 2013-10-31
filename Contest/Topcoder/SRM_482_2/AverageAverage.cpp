#include <vector>
using namespace std;

class AverageAverage
{
	public :
		double average(vector <int> numList)
		{
			int size = numList.size();
			int stm = 1<<size;
			double sum = 0.0 ;
			for(int i=1;i<stm;i++)
			{
				double ps = 0.0;
				int cnt = 0;
				for(int j=0;j<size;j++)
				{
					if(i & (1<<j))
					{
						ps += numList[j];
						cnt ++;
					}
				}
				sum += (ps/cnt);
			}
			sum /= (stm-1);
			return sum;
		}
};
