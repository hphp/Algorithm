/*
ID: hanjiatong1
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define N 15
#define K 30
#define STM (1<<N)

using namespace std;
int vv[N][K];
int a[K];
vector<int> ones[N+1];
void booling()
{
	for(int i=0;i<STM;i++)
	{
		int cnt =0;
		for(int j=0;j<N;j++)
			if(i & (1<<j))
				cnt ++;
		ones[cnt].push_back(i);
	}
}

int main() {
	booling();
    ofstream fout ("holstein.out");
    ifstream fin ("holstein.in");
    int v;
    fin >> v;
    for(int i=0;i<v;i++)
    {
		fin >> a[i];
	}
	int g;
	fin >> g;
	for(int i=0;i<g;i++)
		for(int j=0;j<v;j++)
			fin >> vv[i][j];
	int stm = 1<<g;
	int flag =0;
	for(int ii=1;ii<=g;ii++)
	{
		int ss = ones[ii].size();
		for(int kk=0;kk<ss;kk++)
	{
		int i = ones[ii][kk];
		int sum[K] = {0};
		int cnt = 0;
		for(int j=0;j<N;j++)
		{
			if(i & (1<<j))
			{
				for(int k=0;k<v;k++)
					sum[k] += vv[j][k];
				cnt ++;
			}
		}
		int k=0;
		for(;k<v;k++)
		{
			if(sum[k] < a[k])
				break;
		}
		if(k == v)
		{
			fout << cnt ;
			for(int j=0;j<N;j++)
				if(i & (1<<j))
					fout <<  ' ' << (j+1);
			fout << endl;
			flag = 1;
			break;
		}
	}
	if(flag == 1)break;
	}
    return 0;
}

