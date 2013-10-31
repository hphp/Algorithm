/*
ID: hanjiatong1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAX (1<<20)
using namespace std;
#define N 1010

int mx[N][N],v[N][N];

int main() {
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    
    int n;
    fin >> n;
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=i;j++)
	    	fin >> v[i][j];
	
	mx[1][1] = v[1][1];
	int mxmx = v[1][1];
	
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int aa = mx[i-1][j];
			int bb = j>1?mx[i-1][j-1]:-MAX;
			mx[i][j] = Max(aa,bb) + v[i][j];
			mxmx = Max(mx[i][j],mxmx);
		}
	}
	
	fout << mxmx << endl;
    
    return 0;
}
/*
2010-06-09:
	12:49--13:10 中间打水。 
*/

