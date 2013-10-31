#include <string>
#include <vector>
using namespace std;
#define N 51

long long A[N][N] = {0};

class MovieSeating
{
	public :
		MovieSeating()
		{
			for(int i=1;i<=N;i++)
			{
				A[i][0] = 1;
				for(int j=1;j<=i&&j<=8;j++)
					A[i][j] = A[i][j-1]*(i-j+1);
			}
		}
		long long getSeatings(int numFriends, vector <string> hall)
		{
			int size = hall.size();
			long long ans = 0;
			int len = 0;
			for(int i=0;i<size;i++)
			{
				len = hall[i].length();
				long long sum =0 ;
				for(int j=0;j<len;j++)
					if(hall[i][j] == '.')
						sum ++;
				ans += (A[sum][numFriends]);
			}
			if(numFriends == 1)
				return ans;

			for(int i=0;i<len;i++)
			{
				int sum = 0;
				for(int j=0;j<size;j++)
				{
					if(hall[j][i] == '.')
						sum ++;
				}
				ans += (A[sum][numFriends]);
			}
			return ans;
		}
};
