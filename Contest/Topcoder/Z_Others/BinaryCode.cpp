#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define N 10100
using namespace std;


class BinaryCode
{
	private:
		int getP(int p[],string s)
		{
			int l = s.length();
			for(int i=0;i<l;i++)
			{
				int cur = s[i]-'0';
				int add = 0;
				if(i)
					add = p[i-1];
				p[i+1] = cur-p[i]-add;
				if(p[i+1]!=0 && p[i+1]!=1)
					return 0;
				if(i == l-1)
				{
					if(p[i+1]!=0)
						return 0;
				}
			}
			return 1;
		}
	public:
		vector <string> decode(string message)
		{
			int l = message.length();
			int p[N];
			p[0] = 0;
			int ans = getP(p,message);
			string aa;
			vector<string> anss;
			char ss[N] = "";
			if(ans > 0)
				{
					for(int i=0;i<l;i++)
						ss[i] = p[i] + '0';
						ss[l] = '\0';
					aa = ss;
				}
			else aa = "NONE";
			anss.push_back(aa);
			p[0] = 1;
			ans = getP(p,message);
			if(ans > 0)
				{
					for(int i=0;i<l;i++)
						ss[i] = p[i] + '0';
						ss[l] = '\0';
			aa = ss;
				}
			else aa = "NONE";
			anss.push_back(aa);
			return anss;
				
		}
};
