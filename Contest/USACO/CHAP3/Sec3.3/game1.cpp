/*
ID: hanjiatong1
PROG: game1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 110
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;
int sum[N];
int best[N][N];

int main() {
    ofstream fout ("game1.out");
    ifstream fin ("game1.in");
    int n;
    int v[N];
    fin >> n;
    sum[0] = 0;
    for(int i=1;i<=n;i++)
	{
    	fin >> v[i];
    	sum[i] = sum[i-1] + v[i];
	}
	for(int i=1;i<=n;i++)
		best[i][i] = v[i];
	for(int k=1;k<n;k++)
	{
		for(int i=1;i+k<=n;i++)
		{
			int j = i+k;
			best[i][j] = Max(v[i] + (sum[j]-sum[i] - best[i+1][j]),v[j] + (sum[j-1]-sum[i-1]-best[i][j-1]));
		}	
	}
	
	fout << best[1][n] <<" " << sum[n]-best[1][n] << endl;
    
    return 0;
}
/*

2010-09-17-09:11
2010-09-17-09:00
很快读懂题，很快ac并且整个程序并没有逻辑错误上的改动 oh Yeah！ 
*/
