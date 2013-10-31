/*
ID: hanjiatong1
PROG: sort3
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define N 1100
using namespace std;
int a[N],sd[N];
int main() {
    ofstream fout ("sort3.out");
    ifstream fin ("sort3.in");
    int n;
    int cnt[4];
    int ocp[4][4];
    for(int i =0;i<n;i++)
    {
	    fin >> a[i];
	    cnt[a[i]]++;
	}
	int cc = 0,ccc=0,aa=1;
	while(cc < n)
	{
		sd[cc]=aa;
		ccc++;
		if(ccc == cnt[aa])
		{
			aa ++;
			ccc=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		ocp[a[i]][sd[i]]++;
	}
	int ans =0 , t = 0;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(i!=j)
			{
				ans += Min(ocp[i][j],ocp[j][i]);
				t += Max(ocp[i][j],ocp[j][i])-Min(ocp[i][j],ocp[j][i]);
			}
		}
	}
	fout << ans + 2*t << endl;
    return 0;
}

/*
  Name: 
  Copyright: 
  Author: 
  Date: 16-06-10 21:02
  16-06-10 21:31

  Description: 
*/