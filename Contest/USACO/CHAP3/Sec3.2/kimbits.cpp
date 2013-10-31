/*
ID: hanjiatong1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    int N , L , I;
    fin >> N >> L >> I;
    
    int base = (1<<(L+1))-1;
    int k = -2; 
    int kk = -2;
    int Base = 0;
    int cur = I-1;
	k = 0;
	while(Base + (base << (k))+(1<<k)-1 < cur + (1<<k))
	{
		cur += (1<<k);
		fout << "hei:";
		fout << Base + (base << (k))+(1<<k)-1  << " " << cur << endl;
		k ++;
	}
	k--;
	fout << k << " " << kk << endl;
	Base = Base + (base << (k))+(1<<k);
	base = 1;
	
	while(k>0)
	{
		k = 0;
		while(Base + (1<<k)-1 < cur + (1<<k))
		{
			cur += (1<<k);
			k ++;
		}
		k--;
		if(k < 0)break;
		fout << k << " " << kk << endl;
		Base = Base + (1<<k);
	}
    
    fout << cur << endl;
    
    return 0;
    
}

