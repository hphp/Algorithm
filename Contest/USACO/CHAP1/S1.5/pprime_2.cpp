/*
ID: hanjiatong1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 10100
#define NN 100000
using namespace std;

bool flag[NN];
int cnt,rec[N];

ofstream fout ("pprime.out");
ifstream fin ("pprime.in");
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
	for(int i=2;i<NN;i++)
		if(flag[i] == 0)
		{
			rec[cnt++] = i;
		}
}

int num( int cur)
{
	int cc = 0 , tmp = cur;
	while(tmp)
	{
		cc++;
		tmp /= 10;
	}
	return cc;
}
int a,b;

int convert(int,int);
int ifprime(int);

void dfs(int st,int n,int nn,int cur)
{
	if(st == n+1)
	{
		cur = convert(cur,nn);
		if(cur > b)return;
		if(cur >= a)
		{
			if(ifprime(cur))
				fout << cur << endl;
		}
		return;
	}

	int ss = (st==1)?1:0;
	for(int i=ss;i<10;i++)
	{
		dfs(st+1,n,nn,cur*10+i);
	}
}

int convert(int cur,int n)
{
//	printf("hi %d\n",cur);
	if(n == 1)
	return cur;
	if(n%2==0)
	{
		int tmp = cur;
		int cc = 0;
		while(cc<n/2)
		{
			int ccc = cur%10;
			tmp = tmp*10 + ccc;
			cur/=10;
			cc++;
		}
		return tmp;
	}
	else
	{
		int tmp = cur;
		cur /=10;
		int cc = 0;
		while(cc < n/2)
		{
			int ccc = cur%10;
			tmp = tmp*10 + ccc;
			cur/=10;
			cc++;
		}
		return tmp;
	}
}

int ifprime(int cur)
{
	for(int i=0;i<cnt&&rec[i] <= cur/2;i++)
	{
		if(cur%rec[i]==0)
			return 0;
	}
	return 1;
}

int main() {
  	booling();
    fin >> a >> b;
    
    int n1 = num(a);
    int n2 = num(b);
//    printf("%d %d\n",n1,n2);

    for(int i=n1;i<=n2;i++)
    {
		dfs(1,i/2+((i%2==0)?0:1),i,0);
	}
    return 0;
}
/*
2010-06-09
13:10---14:42
*/
