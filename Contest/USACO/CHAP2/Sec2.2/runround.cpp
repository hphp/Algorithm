/*
ID: hanjiatong1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define LIM 10000000000LL
using namespace std;
int cc , rec[10];

ofstream fout ("runround.out");
ifstream fin ("runround.in");

bool unique(long long cur)
{
	cc = 0;
	bool use[10] = {0};
	while(cur)
	{
		int a = cur%10;
	//	fout << a << ' ';
	//	fout << use[a] << endl;
//		printf("%d ",a);
//		printf("%d ",use[a]);
		if(a == 0 || use[a])return 0;
		rec[cc ++] = a;
		use[a] = 1;
		cur /= 10;
	}
//	fout << endl;
	return 1;
}
int real[20];
bool runround()
{
	int use[10] = {0};
	for(int j=cc-1,i=0;j>=0,i<cc;i++,j--)
		real[i] = rec[j];
	int st = 0;
	int cur = real[0];
	int ccc = 0;
	use[real[0]] = 1;
	while(ccc < cc)
	{
	//	printf("%d %d\n",st,real[st]);
	//	fout << st << ' '<<real[st] << endl;
		st += real[st];
		st %= cc;
		if(st != 0 && use[real[st]])return 0;
		use[real[st]]++;
		ccc++;
	}
	if(st == 0)
	{
		for(int i=1;i<cc;i++)
		if(use[real[i]]!=1)
			return 0;
			return 1;
	}	
	else 
		return 0;
	//printf("\n");
}

int main() {
    int a;
    fin >> a;
    long long i=a+1;
    for(;i<LIM;i++)
    {
		if(unique(i) && runround())
			break;
	}
	fout << i << endl;
    return 0;
}

