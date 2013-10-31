#include <vector>
#include <string>
using namespace std;
#define Min(a,b) ((a)<(b)?(a):(b))

class MatrixShiftings
{
	public:
		int minimumShifts(vector <string> matrix , int value)
		{
			int n = matrix.size();
			int m = matrix[0].length();
			int MAX = (1<<28);
			int ans = MAX;
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
				{
					if((matrix[i][j]-'0') == value)
					{
						int tmp = Min(j,m-j) + Min(i,n-i);
						ans = Min(ans,tmp);
					}
				}
			if(ans >= MAX)
				ans = -1;
			return ans;
		}
};
