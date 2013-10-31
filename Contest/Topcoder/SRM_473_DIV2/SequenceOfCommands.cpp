#include <string>
#include <vector>
using namespace std;

int dir[4][2] = 
{
	{1,3},{2,0},{3,1},{0,2}
};
int mv[4][2] = 
{
	{0,1},{1,0},{0,-1},{-1,0}
};

class SequenceOfCommands
{
	public:
		string whatHappens(vector<string> c)
		{
			string ans = "";
			int n = c.size();
			int cd=0,x=0,y=0;
			for(int i=0;i<n;i++)
			{
				string aa = c[i];
				int len = aa.length();
				for(int j=0;j<len;j++)
				{
					if(c[i][j] == 'S')
					{
						x += mv[cd][0];
						y += mv[cd][1];
					}
					else
					{
						if(c[i][j] == 'R')	
							cd = dir[cd][0];
						else
							cd = dir[cd][1];
					}
				}
			}
			if((x == 0) && (y == 0))
			{
				ans = "bounded";
			}
			else
			{
				if(cd == 0)	
					ans = "unbounded";
				else ans = "bounded";
			}
			return ans;
		}
};
