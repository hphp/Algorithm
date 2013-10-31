/*
ID: hanjiatong1
PROG: ariprog
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define M 251
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;
ofstream fout ("ariprog.out");
ifstream fin ("ariprog.in");
int n, m;
int LIM,Lim;
int avl[M*M*2] = {0},savl[M*M*2] = {0};
int mx[M*M*2];
int rec[M*M*2],cnt;

void booling()
{
	for(int i=1;i<M*M;i++)
		mx[i] = M;
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
		{
			avl[i*i+j*j] = 1;
			mx[i*i+j*j] = Min(mx[i*i+j*j],Max(i,j));
		}
	savl[0] = 1;
	for(int i=0;i<M*M;i++)
	{
		savl[i] = savl[Max(i-1,0)] + avl[i];
		if(avl[i])
		{
			rec[cnt++] = i;
	//		fout << i << ' ' ;
		}
	}
}

bool flag ;

void dfs(int st)
{
	int lim = LIM-1;
	int sign = 0;
	int i = 0;
//	for(;i<LIM;i++)
	for(int ii=0;ii<cnt && i <= LIM;ii++)
	{
		i = rec[ii];
		int cur = i,j=0;
		int ll = i+(n-1)*st;
		for(j=0;j<n;j++)
		{
			if(cur > LIM)
				sign = 1;
			if(cur > LIM || (avl[cur] == 0) || mx[cur] > m)
			{
				break;
			}
			cur += st;
		}
		if(j>=n)
		{
			flag = 1;
			fout << i << ' ' << st << endl;
		}
		if(sign == 1)break;
	}
	if(st < Lim)
		dfs(st+1);
}

int main() {
	
	booling();
    fin >> n >> m;
    flag = 0;
    LIM = m*m*2;
    Lim = LIM/(n-1);
    for(int st = 1; st <=Lim; st ++)
    {
		int sign = 0;
		int i = 0;
	//	for(;i<LIM;i++)
		for(int ii=0;ii<cnt && i <= LIM;ii++)
		{
			i = rec[ii];
			int cur = i,j=0;
			for(j=0;j<n;j++)
			{
				if(cur > LIM)
					sign = 1;
				if((avl[cur] == 0) || mx[cur] > m)
				{
					break;
				}
				cur += st;
			}
			if(j>=n)
			{
				flag = 1;
				fout << i << ' ' << st << endl;
			}
			if(sign == 1)break;
		}
	}
    if(flag == 0)
    	fout << "NONE" << endl;
    return 0;
}

/*
2010-06-01-17:53
*/
