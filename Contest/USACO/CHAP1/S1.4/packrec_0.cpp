/*
ID: hanjiatong1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;

struct Rec
{
	int e[2];
}rcd[60*17],rec[4];
int cnt;
int mxh[20],mxl[20];
int suml,sumh;

int main() {
    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
    suml = 0;
    sumh = 0;
    int a,b;
    for(int i=1;i<5;i++)
    {
    	fin >> a >> b;
    	l[i] = Max(a,b);
    	h[i] = Min(a,b);
    	suml += l[i];
    	sumh += h[i];
	}
	for(int i=1;i<16;i++)
	{
		mxh[i] = 0;
		mxl[i] = 0;
		sth[i] = stl[i] = 0;
		for(int j=0;j<4;j++)
			if(i & (1<<j))
			{
				mxh[i] = Max(h[j+1],mxh[i]);
				mxl[i] = Max(l[j+1],mxl[i]);
				sth[i] += h[j+1];
				stl[i] += l[j+1];
				fout << 1 ;;// << ' ' ;//<< endl;
			}
			else fout << 0 ;//<<
		fout << mxh[i] << ' ' << mxl[i] << endl;
	}
	rec[cnt].h = sumh;
	rec[cnt++].l = mxl[15];
    for(int i=1;i<5;i++)
    {
		int ll = Max(sumh-h[i],l[i]);
		int hh = mxl[15-(1<<(i-1))] + h[i];
		rec[cnt].h = Min(hh,ll);
		rec[cnt++].l = Max(hh,ll);
		for(int j=i+1;j<5;j++)
		{
			int cst = 15-(1<<(i-1))-(1<<(j-1));
			int pl = mxl[cst] + h[i];
			int ph = Max(sth[cst],l[i]);
			ll = Max(l[j],pl);
			hh = h[j] + ph;
			rec[cnt].h = hh;
			rec[cnt++].l = ll;
		}
//		int h = 
	}
    return 0;
}

/*
2010-06-08--8:24

*/
