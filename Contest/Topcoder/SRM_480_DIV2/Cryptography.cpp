#include <stdio.h>
#include <vector>

using namespace std;

class Cryptography
{
	public:
		long long encrypt(vector <int> numbers)
		{
			long long ans = 0;
			int size = numbers.size();
			for(int i=0;i<size;i++)	
			{
				long long sum = 1;
				for(int j=0;j<size;j++)
				{
					sum *= (numbers[j]+(i==j?1:0));
				}
				ans = ans>sum?ans:sum;
			}
			return ans;
		}
};

