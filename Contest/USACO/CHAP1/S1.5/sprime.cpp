/*
ID: hanjiatong1
PROG: sprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 101000
#define NN 1010090

using namespace std;
bool flag[NN];
int cnt,rec[N];

ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

int n;

void booling()
{
	for(int i=2;i<NN;i++)
	{
		if(flag[i]==0)
		for(int j=2;i*j<NN;j++)
		{
			flag[i*j] = 1;
		}
	}
	cnt = 0;
	flag[1] = 1;
	for(int i=2;i<NN;i++)
		if(flag[i] == 0)
		{
			rec[cnt++] = i;
		}
}

int ifprime(int cur)
{
	if(cur < NN)
	{
		if(flag[cur] == 1)
		return 0;
		return 1;
	}
	for(int i=0;i<cnt&&rec[i] <= cur/2;i++)
	{
		if(cur%rec[i]==0)
			return 0;
	}
	return 1;
}

void dfs(int st,int n,int cur)
{
	if(st > n)
	{
		fout << cur << endl;
		return;
	}
	int ss = st==1?1:0;
	for(int i=ss;i<10;i++)
	{
		if(ifprime(cur*10+i))
			dfs(st+1,n,cur*10+i);
	}
}

int main()
{
	booling();
	
    fin >> n;
    
    dfs(1,n,0);
    
    return 0;
}
/*
2010-06-09:
	14:52--15:12
*/
