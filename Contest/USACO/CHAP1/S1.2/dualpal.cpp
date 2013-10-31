/*
ID: hanjiatong1
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define LIM (1<<30)
#define S 301
#define N 301

using namespace std;

string Tran(int base10,int base)
{
	char str[S];
	char a[S];
	int cnt =0;
	while(base10)
	{
		int tmp = base10%base;
		
		a[cnt] = (tmp < 10) ? (tmp+'0'): (tmp -10 + 'A');
		
		base10 /= base;
		
		cnt++;
	}
	a[cnt] = '\0';
	for(int i=cnt-1;i>=0;i--)
	{
		str[cnt-1-i] = a[i];
	}
	str[cnt] = '\0';
	string ans = str;
	return ans;
}
int palsquare(string str)
{
	int a[S];
	int stack = -1;
	int s = str.length();
	if(s == 1)return 1;
	int i =0;
	int mid = s/2;
	while(i < mid)
	{
		int c= str[i] - '0';
		if(c<0||c>9)
			c = str[i] - 'A' + 10;
		a[++stack] = c;
		i++;
	}
	if(s%2==1)
		i ++;
	while(i<s)
	{
		int c= str[i] - '0';
		if(c<0||c>9)
			c = str[i] - 'A' + 10;
		if(a[stack] == c)
			stack --;
		else break;
		i++;
	}
	if(stack == -1 && i == s)
		return 1;
		return 0;
}


int main() {
	
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
    
    int n,s;
    fin >> n >> s;
    int cc =0;
    for(int i=s+1;i<LIM;i++)
    {
		int cnt =0;
		int k=2;
		for(;k<11;k++)
		{
			string str = Tran(i,k);
			if(palsquare(str))
				cnt++;
			if(cnt > 1)
				break;
		}
		if(k < 11)
		{
			fout << i <<endl;
			cc ++;
			if(cc == n)	
				break;
		}
	}
    return 0;
}

