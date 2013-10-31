/*
ID: hanjiatong1
PROG: frac1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define E 0.000000
#define N 161
using namespace std;
struct Frac
{
	int n;
	int d;
}f[N*N];

bool cmp(Frac a , Frac b)
{
	double aa = a.n*1.0/a.d;
	double bb = b.n*1.0/b.d;	
	if(aa < bb+E)
		return 1;
		return 0;
}

int gcd(int a,int b)
{
	if(b == 0)	
		return a;
	return gcd(b,a%b);
}

int main() {
    std::ofstream fout ("frac1.out");
    std::ifstream fin ("frac1.in");
    int n;
    fin >> n;
    int cnt = 0;
    f[cnt].n = 0;
    f[cnt++].d = 1;
    f[cnt].n = 1;
    f[cnt++].d = 1;
    for(int i=2;i<=n;i++)
    	for(int j=1;j<i;j++)
    	{
			if(gcd(j,i)!=1)continue;
			f[cnt].n = j;
			f[cnt++].d = i;
		}
	sort(f,f+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		fout << f[i].n << '/' << f[i].d << endl;
	}
    return 0;
}

/*
  Name: 
  Copyright: 
  Author: 
  Date: 16-06-10 21:06
  Description: 
*/
