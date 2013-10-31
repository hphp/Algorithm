#include <vector>
#include <string>
using namespace std;

class PermutationSignature
{
	public:
		vector <int> reconstruct(string s)
		{
			int n = s.length();
			int i = -1;
			int ans[100] = {0};
			int cnt = 0;
			int base = 0;
			bool flag = 0;
			while(i+1 < n)
			{
				int count = 0;
				if((i+1 < n) && (s[i+1] == 'I'))
				{
					while((s[i+1]=='I') && (i+1<n))
					{
						count ++;
						i++;
					}
					if(flag)
						count--;
					flag = 1;
					for(int ii=0;ii<count;ii++)
						ans[cnt++] = ++base;
				}
				if((i+1 < n) && (s[i+1] == 'D'))
				{
					flag =1;
					count =0;
					while((s[i+1]=='D') && (i+1<n))
					{
						i++;
						count++;
					}
					for(int ii=0;ii<=count;ii++)
						ans[cnt+count-ii] = ++base;
					cnt = cnt + count + 1;
				}
			}
			if(s[n-1] == 'I')
			{
				ans[cnt++] = ++base;
			}
			vector<int> rans;
			for(int i=0;i<cnt;i++)
			{
				rans.push_back(ans[i]);
			}
			return rans;
		}
};

/*
2011-02-11
10:13 - 10:59 想到思路
-11:28 敲完认为无误 
 352 测试了些数据 
*/
