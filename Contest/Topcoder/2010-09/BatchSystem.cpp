#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define N 110
using namespace std;
typedef long long Int;

struct Duty
{
	int cnt;
	string name;
	Int sum;	
}duty[N];

//bool cmp(const Duty &a , const Duty &b)
bool cmp(Duty a ,Duty b)
{
	if(a.sum < b.sum)
		return 1;
	if(a.sum > b.sum)
		return 0;
	if(a.cnt < b.cnt)
		return 1;
		return 0;
		
}

class BatchSystem
{
	public:
	vector <int> schedule(vector <int> duration, vector <string> user)
	{
		int sizeu = user.size();
		int cnt = 0;
		for(int i=0;i<sizeu;i++)
		{
			string cur = user[i];
			int j=0;
			for(;j<cnt;j++)
				if(cur == duty[j].name)
				{
					duty[j].sum += duration[i];
					break;
				}
			if(j == cnt)
			{
				duty[cnt].cnt = cnt;
				duty[cnt].name = cur;
				duty[cnt].sum = duration[i];
				cnt ++;
			}
		}
		std::sort(duty,duty+cnt,cmp);
		vector<int> ans;
		for(int i=0;i<cnt;i++)
		{
			for(int j=0;j<sizeu;j++)
				if(user[j]==duty[i].name)
				{
					ans.push_back(j);
				}
		}
		return ans;
	}
};

/*int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int> t;
		vector<string> user;
		int a;
		char s[1000];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			t.push_back(a);	
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			string cur = s;
			user.push_back(cur);
		}
		BatchSystem BS = BatchSystem();
		vector<int> ans = BS.schedule(t,user);
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
			printf("\n");
	}
	return 0;
}*/
/*
400 100 100 100
Danny_Messer Stella_Bonasera Stella_Bonasera Mac_Taylor

200 200 200
"Gil" "Sarah" "Warrick"

100 200 50
"Horatio Caine" "horatio caine" "YEAAAAAAH"
*/

