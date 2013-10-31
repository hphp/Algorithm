/*
ID: hanjiatong1
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define Min(a,b) ((a)<(b)?(a):(b))
#define MAX (1<<28)
#define N 51
#define SS 310
using namespace std;

struct Barn
{
	int u;
}barn[SS];

bool cmp(Barn a, Barn b)
{
	if(a.u < b.u)
		return 1;
		return 0;
}

int mn[SS][N],best[SS][N];

int main() {
    ofstream fout ("barn1.out");
    ifstream fin ("barn1.in");
    
    int m,S,C;
    fin >> m >> S >> C;
    
    for(int i=1;i<=C;i++)
    {
		fin >> barn[i].u;	
	}
	sort(barn+1,barn+C+1,cmp);
	if(m > C)
		m = C;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=C;j++)
			mn[i][j] = MAX;
	best[0][0] = -barn[1].u;
	
	for(int i=1;i<=C;i++)
	{
		best[i][0] = best[i-1][0];
		for(int j=1;j<=m;j++)
		{
			mn[i][j] = best[i-1][j-1] + barn[i].u + 1;
			best[i][j] = Min(best[i-1][j] , mn[i][j] - barn[i+1].u);
		}
	}
	
	fout << mn[C][m] << endl;
	
    return 0;
}

