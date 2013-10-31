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
����Ƚ�����������ȫ���Լ������ġ� 
��Ȼ�Ƚ������Ǻܿ��İ�! 
�ܿ���˼· 
�ܿ����ꡣ���컹����!
2010-09-17-08:00
2010-09-17-08:48-��һ���ύ�������� 
08:58- ac

				to_up[i][j] = to_up[i-1][j]+1;
				to_left[i][j] = to_left[i][j-1]+1; 
����ط�д����

				to_up[i][j] = to_up[i-1][j]+1;
				to_left[i][j] = to_up[i][j-1]+1; 
����ճ����ʱ��û�и���� ��������
��֤�Լ�д��ÿһ�����ǶԵ�������Ҫ���� 
*/
