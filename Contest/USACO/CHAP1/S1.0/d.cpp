/*
ID: hanjiatong1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define M 13

int mday[2][M] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};

using namespace std;

int first = 3;
int cnt[13] ;

int leap(int year)
{
	if((year % 100 != 0 && year % 4 == 0) || (year % 400 == 0))
		return 1;
		return 0;
}

int getWeekday(int yf,int m,int cur)
{
	int tmp = (mday[yf][m] + first)%7;
	return tmp == 0 ? 7 : tmp;
}

int main() {
	
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");
    
    int n;
    
    fin >> n;
    
    int st = 1;
    
    for(int i=0;i<n;i++)
    {
		int ly = 0;
		if(leap(1900+i))
			ly = 1;
		first = getWeekday(ly,12,first);
		cnt[first] ++;
//		fout << "hei " << first <<  endl;
		st = 1;
		while( st < 12)
		{
			first = getWeekday(ly,st,first);
			cnt[first]++;
			st ++ ;
		}
	}
	
	fout  <<  cnt[6] << ' ' << cnt[7];
	for(int i=1;i<6;i++)
		fout  <<  ' ' <<  cnt[i];
		fout <<  endl;
//	while(fin >> a)
	
    return 0;
}

