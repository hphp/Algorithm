/*
ID: hanjiatong1
PROG: packrec
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#include <algorithm>
using namespace std;

    ofstream fout ("packrec.out");
    ifstream fin ("packrec.in");
struct Rec
{
	int e[2];
}rcd[60*17*60],rec[5];
int cnt;

void dfs0(int st,int a[],int r[])
{
	if(st == 4)
	{
		int sum = 0 , h = 0;
		for(int i=0;i<4;i++)
		{
			int cur = a[i];
			sum += rec[cur].e[r[i]];
			h = Max(h,rec[cur].e[1-r[i]]);
		}
		rcd[cnt].e[0] = Min(sum,h);
		rcd[cnt++].e[1] = Max(sum,h);
		return ;
	}
	r[st] = 0;
	dfs0(st+1,a,r);
	r[st] = 1;
	dfs0(st+1,a,r);
}

void dfs1(int st,int a[],int r[])
{
	if(st == 4)
	{
		int sum = 0 , h = 0;
		for(int i=0;i<3;i++)
		{
			int cur = a[i];
			sum += rec[cur].e[r[i]];
			h = Max(h,rec[cur].e[1-r[i]]);
		}
		sum = Max(sum,rec[a[3]].e[r[3]]);
		h += rec[a[3]].e[1-r[3]];
		rcd[cnt].e[0] = Min(sum,h);
		rcd[cnt++].e[1] = Max(sum,h);
		return ;
	}
	r[st] = 0;
	dfs1(st+1,a,r);
	r[st] = 1;
	dfs1(st+1,a,r);
}
void dfs2(int st,int a[],int r[])
{
	if(st == 4)
	{
		int sum = 0 , h = 0;
		for(int i=0;i<2;i++)
		{
			int cur = a[i];
			sum += rec[cur].e[r[i]];
			h = Max(h,rec[cur].e[1-r[i]]);
		}
		sum = Max(sum,rec[a[2]].e[r[2]]);
		h += rec[a[2]].e[1-r[2]];
		sum += rec[a[3]].e[r[3]];
		h = Max(h,rec[a[3]].e[1-r[3]]);
		rcd[cnt].e[0] = Min(sum,h);
		rcd[cnt++].e[1] = Max(sum,h);
		return ;
	}
	r[st] = 0;
	dfs2(st+1,a,r);
	r[st] = 1;
	dfs2(st+1,a,r);
}
void dfs3(int st,int a[],int r[])
{
	if(st == 4)
	{
		int sum = 0 , h = 0;
		for(int i=0;i<2;i++)
		{
			int cur = a[i];
			sum += rec[cur].e[r[i]];
			h = Max(h,rec[cur].e[1-r[i]]);
		}
		sum += Max(rec[a[2]].e[r[2]],rec[a[3]].e[r[3]]);
		h = Max(rec[a[2]].e[1-r[2]]+rec[a[3]].e[1-r[3]],h);
	/*	if(a[0] == 0 && a[1] == 3 && a[2] == 2)
		{
			fout << sum <<  ' '	 << h << endl;
		}*/
		rcd[cnt].e[0] = Min(sum,h);
		rcd[cnt++].e[1] = Max(sum,h);
		return ;
	}
	r[st] = 0;
	dfs3(st+1,a,r);
	r[st] = 1;
	dfs3(st+1,a,r);
}
void dfs4(int st,int a[],int r[])
{
	if(st == 4)
	{
/*
		if(rec[a[0]].e[r[0]] > rec[a[1]].e[r[1]])
			return;
		if(rec[a[3]].e[1-r[3]] < rec[a[1]].e[1-r[1]])
			return ;
*/
		int sum = 0 , h = 0;
		if(rec[a[0]].e[r[0]] > rec[a[1]].e[r[1]])
		{
			int aa = rec[a[0]].e[r[0]]+rec[a[2]].e[r[2]];
			int bb = rec[a[0]].e[r[0]] + rec[a[3]].e[r[3]];
			sum = Max(aa,bb);
			aa = rec[a[0]].e[1-r[0]]+rec[a[1]].e[1-r[1]];
			bb = rec[a[2]].e[1-r[2]] + rec[a[3]].e[1-r[3]];
			h = Max(aa,bb);
		}
		else if(rec[a[3]].e[1-r[3]] < rec[a[1]].e[1-r[1]])
		{
			int aa = rec[a[1]].e[r[1]]+rec[a[2]].e[r[2]];
			int bb = rec[a[1]].e[r[1]] + rec[a[3]].e[r[3]];
			sum = Max(aa,bb);
			aa = rec[a[0]].e[1-r[0]]+rec[a[1]].e[1-r[1]];
			bb = rec[a[2]].e[1-r[2]] + rec[a[3]].e[1-r[3]];
			h = Max(aa,bb);	
		}
		else
		{
			int aa = rec[a[0]].e[r[0]]+rec[a[2]].e[r[2]];
			int bb = rec[a[1]].e[r[1]] + rec[a[3]].e[r[3]];
			sum = Max(aa,bb);
			aa = rec[a[0]].e[1-r[0]]+rec[a[1]].e[1-r[1]];
			bb = rec[a[2]].e[1-r[2]] + rec[a[3]].e[1-r[3]];
			h = Max(aa,bb);
		}
		rcd[cnt].e[0] = Min(sum,h);
		rcd[cnt++].e[1] = Max(sum,h);
		return ;
	}
	r[st] = 0;
	dfs4(st+1,a,r);
	r[st] = 1;
	dfs4(st+1,a,r);
}

bool cmp(Rec a , Rec b)
{
	if(a.e[0] < b.e[0])
		return 1;
	if(a.e[0] > b.e[0])
		return 0;
	if(a.e[1] < b.e[1])
		return 1;
		return 0;
	
}

int main() {
    for(int i=0;i<4;i++)
    {
    	fin >> rec[i].e[0] >> rec[i].e[1];
	}
	
	int a[10] = {0},r[10];
	for(int i=0;i<4;i++)
		a[i] = i;
	dfs0(0,a,r);
	
//	for(int i=0;i<cnt;i++)
//		fout << rcd[i].e[0] << ' ' << rcd[i].e[1] << endl;
	
	for(int i=0;i<4;i++)
	{
		int cnt = 0;
		for(int j=0;j<4;j++)
			if(j!=i)
				a[cnt++] = j;
		a[cnt++] = i;
		dfs1(0,a,r);
	}
	for(int i=0;i<4;i++)
	{
		for(int k=0;k<4;k++)
		{
			if(i == k)continue;
			int cnt = 0;
			for(int j=0;j<4;j++)
				if(j!=i && j != k)
				{
					a[cnt++] = j;
				}
			a[cnt++] = i;
			a[cnt++] = k;
			dfs2(0,a,r);
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int k=0;k<4;k++)
		{
			if(i == k)continue;
			int cnt = 0;
			for(int j=0;j<4;j++)
				if(j!=i && j != k)
					a[cnt++] = j;
			a[cnt++] = i;
			a[cnt++] = k;
	/*		for(int k=0;k<cnt;k++)
				fout << a[k] << ' ' ;
				fout << endl;*/
			dfs3(0,a,r);
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int k=0;k<4;k++)
		{
			if(i == k)continue;
			int cnt = 0;
			for(int j=0;j<4;j++)
				if(j!=i && j != k)
					a[cnt++] = j;
			a[cnt++] = i;
			a[cnt++] = k;
			dfs4(0,a,r);
		}
	}
	
	int area = rcd[0].e[0]*rcd[0].e[1];
	for(int i=1;i<cnt;i++)
	{
		int tmp = rcd[i].e[0]*rcd[i].e[1];
		
		if(tmp < area)
		{
			area = tmp;
		}
	}
	
	std::sort(rcd,rcd+cnt,cmp);
	int ee = 0;
	fout << area << endl;
	for(int i=0;i<cnt;i++)
	{
		int tmp = rcd[i].e[0]*rcd[i].e[1];
		
		if((tmp == area)&& ((i==0)||rcd[i].e[0]!=ee))
		{
			fout << rcd[i].e[0] << ' ' << rcd[i].e[1] << endl;
			ee = rcd[i].e[0];
		}
	}
	
	
    return 0;
}

/*
2010-06-08--8:24--11:00

*/
