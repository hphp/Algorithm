/*
ID: hanjiatong1
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 301
#define S 301

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
	
    ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
    int base;
    string str,a;
    fin >> base;
    for(int i=1;i<N;i++)
    {
		int sqrt = i*i;
		str = Tran(sqrt,base);
		if(palsquare(str))
		{
			a = Tran(i,base);
			fout << a << ' ' << str << endl;
		}
	}
    return 0;
}

