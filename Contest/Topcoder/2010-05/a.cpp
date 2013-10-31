#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define N 10100
#define abss(a) ((a)>0?(a):(-(a)))

struct Node
{
	int x,y;	
}node[N];
bool cmp(Node a,Node b)
{
	if(a.x < b.x)
		return 1;
		return 0;
}

class LinearTravellingSalesman
{
	public:
		int findMinimumDistance(vector<int> x,vector<int>y);
};

int LinearTravellingSalesman::findMinimumDistance(vector<int> x,vector<int>y)
{
	for(int i =0 ;i < x.size(); i ++)
	{
		node[i].x = x[i];
		node[i].y = y[i];
	}
	std::sort(node,node+x.size(),cmp);
	int sum = 0;
	for(int i=1;i<x.size();i++)
	{
		sum += abss(node[i].x-node[i-1].x)+abss(node[i].y-node[i-1].y);
	}
	return sum;
}
