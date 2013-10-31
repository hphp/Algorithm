#include <vector>
#include <algorithm>
#define LMAX 4611686018427387904LL
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;
typedef long long Int;
class SignalIntelligence
{
	Int get_size(int last, vector <int> const & numbers)
	{
		int shift = 0;
		int size = numbers.size();
		for(size_t i=0;i<size;i++)	
		{
			if(i != last)
			{
				if(shift >= 61)
				{
					return LLONG_MAX;
				}
				else
				{
					for(int sh=shift+1;sh<62;sh++)	
					{
						if((((1LL)<<shift) + numbers[i]) < (1LL<<sh))
						{
							shift = sh;
							break;	
						}
					}
				}
			}
		}
		return (1LL<<shift) + numbers[last]-1;
	}

	public:
		long long encrypt(vector <int> numbers)
		{
			int size = numbers.size();
			sort(numbers.begin(),numbers.end());
			long long mnmn = LLONG_MAX;
			for(size_t i=0;i<size;i++)
			{
				mnmn = min(mnmn,get_size(i,numbers));
			}
			return mnmn;
		}
};
