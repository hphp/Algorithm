#include <string>
#define MAX (1<<28)
using namespace std;
typedef long long Int;
char signs[1008],ts[1009];
int mn;
int flag;

void dfs(Int cur , int cnt,int t)
{
	if(cur > t)
		return;
	if(cnt >= mn)
		return;
	if(cur == t)
	{
		ts[cnt]= '\0';
		strcpy(signs,ts);
		mn = cnt;
		flag = 1;
		return;
	}
	else
	{
		if(cur > 1)
{
		ts[cnt] = '*';
		dfs(cur*cur,cnt+1,t);
}
		ts[cnt] = '+';
		dfs(cur+cur,cnt+1,t);
	}
}

class OneRegister
{
	public:
		string getProgram(int s,int t)
		{
			string ans;
			signs[0] = '\0';
			if(s == t)
			{
				ans = "";
			}
			else if(s == 0)
			{
				ans = ":-(";
			}
			else if(t == 0)
			{
				ans = "-";
			}
			else if(t == 1)
			{
				ans = "/";
			}
			else
			{
				ts[0] = '\0';
				mn = MAX;
				signs[0] = '\0';
				dfs((Int)s,0,t);


				ts[0] = '/';
				ts[1] = '\0';
				dfs(1LL,1,t);
//				int tmp = mn;
				if(flag)
					ans = signs;
				else ans = ":-(";
				
			}
			return ans;
		}
};
