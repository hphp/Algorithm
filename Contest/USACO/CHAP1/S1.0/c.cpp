/*
ID: hanjiatong1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 12

using namespace std;
int v[N],add[N];
struct P
{
	int id;
	string name;	
}p[N];
int n;


int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int a;
    fin >> n;
    string s;
    for(int i=0;i<n;i++)
    {
		fin >> p[i].name;	
		add[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		fin >> s;
		for(int j=0;j<n;j++)
			if(s == p[j].name)
			{
				fin >> v[j] >> a;
				add[j] += v[j];
			//	fout << "who wiil give " << j << endl;
				if(a)
				{
					int give = v[j]/a;
					for(int k=0;k<a;k++)
					{
						fin >> s;
						int m = 0;
						for(; m < n ; m ++)
							if(s == p[m].name)
								break;
				//		fout << "give who : " << m << ' ';
						add[m] += give;
						add[j] -= give;
					}
				}
			//	fout << endl;
				break;
			}
	}
	for(int i=0;i<n;i++)
	{
    	fout << p[i].name << ' ' << add[i]-v[i] << endl;
	}
    return 0;
}

