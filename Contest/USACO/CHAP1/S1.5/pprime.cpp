/*
ID: hanjiatong1
PROG: pprime
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 1010000
#define NN 10000001
using namespace std;

bool flag[NN];
int cnt,rec[N];

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
	for(int i=5;i<NN;i++)
		if(flag[i] == 0)
		{
			rec[cnt++] = i;
		}
	printf("%d\n",cnt);
}

int find(int cur)
{
	int st = 0;
	int ed = cnt-1;
	if(rec[st] > cur)
		return st;
	if(rec[ed] < cur)
		return ed;
		
	while(st +1 < ed)
	{
		int mid = (st+ed)/2;
		if(rec[mid] < cur)
			st = mid;
		if(rec[mid] >= cur)
			ed = mid;
	}
	return ed;
	
}

void booling2()
{
	for(int i=0;i<cnt;i++)
	{
		int cur = rec[i];
		for(int j=1;cur*j<NN*10;j++)
		{
				
		}
	}
}

int main() {
//    ofstream fout ("pprime.out");
  //  ifstream fin ("pprime.in");
    booling();
    
    boolinga();
    int a, b;
    cin >> a >> b;
    
    int st = find(a);
  //  printf("%d %d\n",st,rec[st]);
    int r[20];
    for(int i=st;i<cnt&&rec[i] <= b;i++)
    {
		int cur = rec[i];
		int cc = 0 , tmp = cur;
		while(tmp)
		{
			r[cc++] = tmp%10;
			tmp /= 10;
		}
		int mid = cc/2;
		int ss = mid -1 , ee = mid+1;
		if(cc %2 == 0)
			ss = mid-1,ee = mid;
		while(ss >= 0 && ee < cc && r[ss] == r[ee])
		{
			ss--;
			ee++;	
		}
		
		if(ss < 0 || ee >= cc)
			printf("%d\n",cur);
			
	}
	
	for(int i = rec[cnt-1] ; i<= b; i ++)
	{
		for(int j=0;j<cnt;j++)
			if()
	}
    
    return 0;
}

