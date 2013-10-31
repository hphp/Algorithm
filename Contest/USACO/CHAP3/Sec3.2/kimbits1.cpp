/*
ID: hanjiatong1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
#include <string>
#define NN 40
using namespace std;
typedef long long Int;
Int size[NN][NN];

ofstream fout ("kimbits.out");
ifstream fin ("kimbits.in");

void dfs(int n,int m,Int l)
{
	if(n ==1 && l == 1)
	{
		fout << "0";
		return;	
	}
	if(n <= 0)return;
	if(m == 0 && size[n][m]>=l)
	{
		fout << "0";
		dfs(n-1,m,l);
		return;
	}
	if(size[n-1][m] >= l)
	{
		fout << "0";
		dfs(n-1,m,l);
	}
	else
	{
		fout << "1";
		dfs(n-1,m-1,l-size[n-1][m]);
	}
}

int main() {
	int N,L;
	Int I;
	while(fin >> N >> L >> I)
	{
	    memset(size,0,sizeof(size));
	    size[1][0] = 1;
	    size[1][1] = 2;
	    for(int j=2;j<=L;j++)
	    	size[1][j] = 2;
//		fout << "shit" << endl;
	    for(int i=2;i<=N;i++)
	    {
			size[i][0] = 1;
	    	for(int j=1;j<=L;j++)
	    		size[i][j] = size[i-1][j-1] + size[i-1][j];
		}
//		fout << "shit" << endl;
//		fout << size[N][L] << endl;
		dfs(N,L,I);
		fout << endl;
	}
    return 0;
}
/*
3 1 2
3 1 3
3 1 4
3 1 5
3 2 1
3 2 2
3 2 3
3 2 4 
3 2 5
3 2 6
3 2 7

这道题首先看错了题意。 
以为满足属于集合的二进制数是连续1的个数小于等于L的。
2了，也不知道是怎么想的。昨天睡眠比较足，所以今天的思路比较清晰吧。
看了解题报告，才知道是那么回事。
然后基本上是自己想的。效果还不错，但是在边界处理上还是有些慢。
是因为我的大脑思考的不够快
但是比以前快多了 ohYeah~! 

错了一组数据 是因为没有想到整数范围不够。

自己测了很多组数据，这样还是卓有成效的。一次ac给人的感觉很爽

*/
