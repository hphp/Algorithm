/*
ID: hanjiatong1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int n;
char ch[4] = "+- ";
ofstream fout ("zerosum.out");
ifstream fin ("zerosum.in");

void dfs(int res,int cur,int sign[])
{
	if(cur == n)
	{
		if(res == 0)
		{
			fout << "1";
			for(int i=1;i<cur;i++)
			{
				fout << ch[sign[i]] << i+1;
			}
			fout << endl;
		}
		return;
	}
	if(sign[cur-1]!=2)
	{
		int ress = res - cur + cur*10+cur+1;
		if(sign[cur-1]==1)
			ress = res + cur - (cur*10+cur+1);
		sign[cur] = 2;
		dfs(ress,cur+1,sign);
	}
	sign[cur] = 0;
	dfs(res+cur+1,cur+1,sign);
	sign[cur] = 1;
	dfs(res-cur-1,cur+1,sign);
}

int main() {
    fin >> n;
    int cnt[9] = {0};
	//2 : ' '
    // 0 :' + ' 
	//1 : '-' 
    dfs(1,1,cnt);
    return 0;
}
/*
ºÚµ•Ã‚

*/

