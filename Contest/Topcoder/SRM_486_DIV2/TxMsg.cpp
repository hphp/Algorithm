#include <string>

using namespace std;

char vow[6] = {"aeiou"};

bool ifVow(char c)
{
	for(int j=0;j<5;j++)
		if(c == vow[j])
			return 1;
	return 0;
}

class TxMsg
{
	public:
		string getMessage(string original)
		{
			int len =original.length();
			char temp[100] = "";
			int cnt = 0;
			int st = 0,ed=0;
			for(int i=0;i<=len;i++)
			{
				if(original[i] == ' '||original[i] == '\0')
				{
					ed = i;
					bool flag = 0;
					for(int j=st;j<ed;j++)
						if(!ifVow(original[j]))
							flag = 1;
					if(flag)
					{
						int sign = 0;
						for(int j=st;j<ed;j++)
						{
							if(!ifVow(original[j]))
							{
								if(sign==0)	
									temp[cnt++] = original[j];
								sign = 1;
							}
							else 
								sign = 0;
						}
					}
					else
					{
						for(int j=st;j<ed;j++)
							temp[cnt++] = original[j];
					}
					temp[cnt++] = original[i];
					st = i+1;
				}
			}
			string ans = temp;
			return ans;
		}
		};
