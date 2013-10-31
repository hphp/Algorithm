/*
ID: hanjiatong1
PROG: hamming
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;

int dis(int a,int b)
{
	int aaa[20] = {0},bbb[20] = {0};
	int aa = a,bb = b;
	int cnt =0;
	while(aa)
	{
		aaa[cnt] = aa%2;
		aa/=2;
		cnt ++;
	}
	int bc = 0;
	while(bb)
	{
		bbb[bc] = bb%2;
		bb/=2;
		bc ++;
	}
	int cc =0;
	for(int i=0;i<Max(bc,cnt);i++)
		if(aaa[i]!=bbb[i])
			cc ++;
			return cc;
}

int main() {
    ofstream fout ("hamming.out");
    ifstream fin ("hamming.in");
    int n,b,d;
    fin >> n >> b >> d;
    int stm = 1<<9;
    int cnt =0;
    int rec[70];
    for(int i =0 ;i < stm;i++)
	{
		int k=0;
		for(;k<cnt;k++)
			if(dis(i,rec[k]) < d)
				break;
		if(k >= cnt)
		{
			rec[cnt++] = i;	
			if(cnt ==n)
				break;
		}
	}
	fout << rec[0];
	for(int i=1;i<cnt;i++)
	{
		if(i%10==0)
		{
			fout << endl << rec[i];
			continue;
		}
		fout << ' ' << rec[i];
	}
	fout << endl;
    return 0;
}
/*
21-06-10 08:34
21-06-10 09:03
*/
