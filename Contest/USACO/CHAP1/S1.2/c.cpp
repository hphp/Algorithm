/*
ID: hanjiatong1
PROG: transform
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 11


using namespace std;
string grid[N];
string stdg[N];
int n;

char get(int k,int kk,int i,int j)
{
	switch(k)
		{
			case 0 : return stdg[j][n-1-i];
			case 1 : return stdg[n-1-i][n-1-j];
			case 2 : return stdg[n-1-j][i];
			case 3 : return stdg[i][n-1-j];
			case 4 : 
				switch(kk)
				{
					case 0:return stdg[n-1-j][n-1-i];
					case 1: return stdg[n-1-i][j];
					case 2: return stdg[j][i];
				}
			case 5 : return stdg[i][j];
			
		}
}

int num[8] = {1,1,1,1,3,1,0};

int main() {
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
    while(fin >> n)
    {
	    for(int i=0;i<n;i++)
	    	fin >> grid[i];
	    for(int i=0;i<n;i++)
	    	fin >> stdg[i];
	    int k=0;
	    for(;k<6;k++)
	    {
			int kk=0;
		    for(;kk<num[k];kk++)
		    {
		   		int i =0;
			    for(;i<n;i++)
			    {
					int j =0;
			    	for(;j<n;j++)
			    	{
						char c = grid[i][j];
						if(c!= get(k,kk,i,j))
							break;
					}
					if(j != n)break;
				}
				if(i==n)break;
			}
			if(kk != num[k])break;
		}
	    fout << k+1 << endl;
	}	
    return 0;
}

