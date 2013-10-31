#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define NN 110

int cc[NN],rec[NN],real[NN];
int clear[NN];
int rr[NN][NN];

class RouteIntersection
{
	public:	
		string isValid(int N, vector <int> coords, string moves)
		{
			int size = coords.size();
			for(int i=0;i<size;i++)
			{
				rec[i] = coords[i];
			}
			sort(rec,rec+size);
			int cnt =0 ;
			for(int i=0;i<size;i++)
				if(i ==0 || rec[i]!=rec[i-1])
				{
					real[cnt ++] = rec[i];
				}
			for(int i=0;i<size;i++)
			{
				int j=0;
				for(;j<cnt;j++)
					if(coords[i] == real[j])
					{
						cc[i] = j;
						break;
					}
			}
			int c = 0;
			for(int i=0;i<cnt;i++)
			{
				clear[i] = 0;
				rr[c][i] = 0;
			}
			c ++;
			int len = moves.length();
			int flag = 1;
			for(int i=0;i<len;i++)
			{
				if(moves[i] == '+')
					clear[cc[i]] ++;
				else clear[cc[i]]--;
				for(int j=0;j<c;j++)
				{int k=0;
					for(;k<cnt;k++)
						if(clear[k] != rr[j][k])
							break;
					if(k == cnt)
					{
						flag = 0;
						break;
					}
				}
				for(int k=0;k<cnt;k++)
					rr[c][k] = clear[k];
				c ++;
			}
			string ans = "VALID";
			if(flag == 0)
				ans = "NOT VALID";
		/*	for(int i=0;i<cnt;i++)
				if(clear[i] != 0)
				{
					ans = "NOT VALID";
				}*/
			return ans;
		}
};
