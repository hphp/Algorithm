/*
ID: hanjiatong1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
typedef long long Int;
using namespace std;

int main() {
    ofstream fout ("subset.out");
    ifstream fin ("subset.in");
    int n;
    fin >> n;
    int sum = (n+1)*n/2;
    Int avl[800] = {0};
    if(sum %2 ==0)
    {
		avl[0] = 1;
		for(int i=1;i<=n;i++)
			for(int j=sum-i;j>=0;j--)
				if(avl[j])
					avl[j+i] += avl[j];
		fout << avl[sum/2]/2 << endl;
	}
	else fout << 0 << endl;
    return 0;
}

/*

21-06-10 09:11
21-06-10 09:21

*/
