/*
ID: hanjiatong1
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define N 5010

struct Node
{
	int p;
	int a;	
}node[N];

using namespace std;

bool cmp(Node a,Node b)
{
	if(a.p < b.p)
		return 1;
		return 0;	
}

int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");
    int n,m;
    fin >> n >> m;
    for(int i=0;i<m;i++)
    {
		fin >> node[i].p >> node[i].a;	
	}
	sort(node,node+m,cmp);
	int total = 0, sum =0;
	for(int i=0;i<m;i++)
	{
		if(sum + node[i].a > n)
		{
			total += (n-sum)*node[i].p;
			break;
		}
		sum += node[i].a;
		total += node[i].a*node[i].p;
	}
	fout << total << endl;
    return 0;
}

