/*
ID: hanjiatong1
PROG: range
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 260
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;

char s[N][N];
int to_left[N][N],to_up[N][N];
int mx[N][N];
int cnt[N];

int main() {
    ofstream fout ("range.out");
    ifstream fin ("range.in");
    int n;
    fin >> n;
	for(int i=1;i<=n;i++)
		fin >> s[i]+1; 
	for(int i=0;i<=n;i++)
		to_up[0][i] = to_left[i][0] = 0;
    for(int i=1;i<=n;i++)
    {
		for(int j=1;j<=n;j++)
		{
			if(s[i][j] == '0')
			{
				to_up[i][j] = 0;
				to_left[i][j] = 0;
			}
			else
			{
				to_up[i][j] = to_up[i-1][j]+1;
				to_left[i][j] = to_left[i][j-1]+1;
			}
//			fout << to_up[i][j] << "," << to_left[i][j]  << " ";
		}
//		fout << endl;
	}
	for(int i=0;i<=n;i++)
	{
		mx[i][0] = mx[0][i] = 0;
		cnt[i] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mx[i][j] = Min(Min(to_up[i][j],mx[i-1][j-1]+1),to_left[i][j]);
			for(int k=2;k<=mx[i][j];k++)
				cnt[k]++;
	//		fout << mx[i][j] << " "; 
		}
	//	fout << endl;
	}
	for(int i=2;i<=n;i++)
		if(cnt[i])
			fout << i << " " << cnt[i] << endl;
    return 0;
}
/*
读题比较慢，但是完全是自己读懂的。 
虽然比较慢但是很开心啊! 
很快有思路 
很快敲完。构造还不错!
2010-09-17-08:00
2010-09-17-08:48-第一次提交。。错了 
08:58- ac

				to_up[i][j] = to_up[i-1][j]+1;
				to_left[i][j] = to_left[i][j-1]+1; 
这个地方写成了

				to_up[i][j] = to_up[i-1][j]+1;
				to_left[i][j] = to_up[i][j-1]+1; 
复制粘贴的时候没有搞清楚 汗啊。。
保证自己写的每一步都是对的是真重要。。 
*/
