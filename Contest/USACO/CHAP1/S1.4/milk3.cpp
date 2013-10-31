/*
ID: hanjiatong1
PROG: milk3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 21
#define Min(a,b) ((a)<(b)?(a):(b))
int vst[N][N][N];
int full[N];
using namespace std;

int lim[3];
    ofstream fout ("milk3.out");
    ifstream fin ("milk3.in");

void dfs(int c[3])
{
	if(vst[c[0]][c[1]][c[2]] == 1)
		return;
/*	for(int i=0;i<3;i++)
		fout << c[i] << ' ';
		fout << endl;*/
	vst[c[0]][c[1]][c[2]] = 1;
	
	if(c[0] == 0)	
	{
		full[c[2]] = 1;
	}
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(i != j && c[i] > 0)
			{
				int mj = lim[j]-c[j];
				int fill = Min(mj,c[i]);
				c[i] -= fill;
				c[j] += fill;
				dfs(c);
				c[i] += fill;
				c[j] -= fill;
			}
		}
	}
}


int main() {
    for(int i=0;i<N;i++)
    {
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				vst[i][j][k] = 0;
    	full[i] = 0;
	}
    for(int i=0;i<3;i++)
    	fin >> lim[i];
    int c[3];
    c[0] = c[1]= 0;
    c[2] = lim[2];
//    fin >> a >> b >> c;
    full[c[2]] = 1;
    dfs(c);
    int flag = 0;
    for(int i=0;i<N;i++)
    	if(full[i] == 1)
    	{
			if(flag)fout << ' ';
			fout << i;
			flag = 1;
		}
		fout << endl;
    return 0;
}

/*
2010-5-29:17:30--17:52
*/

