/*
ID: hanjiatong1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 1000010

using namespace std;
int st[N],end[N];

int main() {
	
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    
    int n; 
    fin >> n ;
    for(int i=0;i<N;i++)
    	st[i] = end[i] = 0;
    int a,b;
    for(int i=1;i<=n;i++)
    {
		fin >> a >> b;
		st[a] ++;
		st[b] --;
	}
	
	int alo = 0 , amn = 0;
	int flag = 0;
	int str[2] ;
	str[0] = 0;
	str[1] = -1;
	
	for(int i=0;i<N;i++)
	{
		if(flag == 0 && st[i] > 0)
		{
			if(str[1]!=-1) 
				if(i - str[1] > amn)
					amn = i - str[1];
			str[0] = i;//开始有了 
		}
		flag += st[i];
		if(flag == 0 && st[i] < 0)
		{
			if(i - str[0] > alo)
				alo = i - str[0];
			str[1] = i;//没有的开始 
		}
	}
    fout << alo << ' ' << amn << endl;
    return 0;
}

