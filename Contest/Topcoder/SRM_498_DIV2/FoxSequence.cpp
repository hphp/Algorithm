#include <string>
#include <vector>
using namespace std;
#define N 61
int avll[N][5][2];

class FoxSequence
{
	public:
		string isValid(vector<int> seq)
		{
			int n = seq.size();
			for(int i=0;i<n;i++)
				for(int j=0;j<5;j++)
					for(int k=0;k<2;k++)
						avll[i][j][k] = 0;
			avll[0][0][0] = 1;
			for(int i=0;i<n-1;i++)
				for(int j=0;j<5;j++)
					for(int k=0;k<2;k++)
						if(avll[i][j][k])
						{
			/*				if((j == 1))
							{
								if(k == 0)
									avl[i+1][3][0] = 1;
								else
								{
									if(seq[i+1] - seq[i] == seq[i]-seq[i-1])	
									{
										avl[i+1][3][0] = 1;
									}
								}
							}*/
							if(k == 0)
							{
								if(j == 2)
									avll[i][j][1] = 1;
								if((j == 0) || (j ==3))
								{
									if(seq[i+1]-seq[i] > 0)
										avll[i+1][j][1] = 1;
								}
								else if(j == 2)
								{
									if(seq[i+1]==seq[i])	
										avll[i+1][j][1] = 1;
								}
								else
								{
									if(seq[i+1]-seq[i] < 0)
										avll[i+1][j][1] = 1;
								}
							}
							else
							{
								avll[i][j+1][0] = 1;
								if(seq[i+1]-seq[i] == seq[i]-seq[i-1])
									avll[i+1][j][1] = 1;
							}
						}
			string ans = "";
			if(avll[n-1][4][0] || avll[n-1][4][1])
				ans = "YES";
			else ans = "NO";
			return ans;
		}
};

