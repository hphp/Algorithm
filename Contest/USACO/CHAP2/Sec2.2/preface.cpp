/*
ID: hanjiatong1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
#define N 3510
#define K 20
int vst[N];
int v[K] = {1,5,10,50,100,500,1000};
int s[K] = {3,0,3,0,3};

int n;
int need[N][K];
struct Rec
{
	int v;
	int flag;
	int need[7];
	int present;
}rec[K];
int fcnt;
ofstream fout ("preface.out");
ifstream fin ("preface.in");
char hello[K] = "IVXLCDM";
int cntr[K] = {0};

void dfs(int cur,int s,int cnt[7],int cc)
{
	if(vst[cur] ==0)
	{
		for(int i=0;i<7;i++)
			cntr[i] += cnt[i];
	}
	vst[cur]++;
	int ss = s-1;
	if(rec[s].flag)
	{
		ss ++;
	}
	for(int i = ss;i>=0;i--)
	{
		if(cur + rec[i].v <= n)
		{
			for(int j=0;j<7;j++)
				cnt[j] += rec[i].need[j];
			if(i == s)
			{
				if(cc < 3)
					dfs(cur+rec[i].v,i,cnt,cc+1);
			}
			else dfs(cur+rec[i].v,i,cnt,1);
			for(int j=0;j<7;j++)
				cnt[j] -= rec[i].need[j];
		}
	}
}

bool cmp(Rec a , Rec b)
{
	if(a.v < b.v)	
		return 1;
		return 0;
}

int main() {
    fin >> n;
    fcnt = 7;
    for(int i=0;i<7;i++)
    	need[i][i] = 1;
    for(int i = 1; i<=n;i++)
    	vst[i] = 0;
	for(int i=0;i<7;i+=2){
		for(int j=i+1;j<i+s[i];j++)
		{
			v[fcnt] = v[j]-v[i];
			need[fcnt][i] ++;
			need[fcnt][j] ++;
			fcnt ++;
		}
	}
	for(int i=0;i<fcnt;i++)
	{
		rec[i].v = v[i];
		rec[i].flag = 0;
		for(int j=0;j<7;j++)
			rec[i].need[j] = need[i][j];
	}
	for(int i=0;i<7;i++)
		rec[i].present = i;
	for(int i=7;i<fcnt;i++)
		rec[i].present = -1;
	for(int i = 0; i < 7 ; i += 2)
	{
		rec[i].flag = 1;
	}
	std::sort(rec,rec+fcnt,cmp);
	for(int i=0;i<7;i++)
		cntr[i] = 0;
	for(int i = fcnt-1; i >= 0;i--)
		if(rec[i].v <= n)
		{
			int cnt[7] = {0};
			for(int j=0;j<7;j++)
				cnt[j] += rec[i].need[j];
			dfs(rec[i].v,i,cnt,1);
		}
	for(int i=0;i<7;i++)
		if(cntr[i])
			fout << hello[i] << " " << cntr[i] << endl;
			
    return 0;
}
/*
很多信息都没有抓住
As many as three of the same marks that represent 10n may be placed consecutively to form other numbers
Marks that have the value 5x10n are never used consecutively. 
as many as : 最多可以有几个连续 ， 
Sometimes, a mark that represents 10^n is placed before a mark of one of the two next higher values (I before V or X; X before L or C; etc.). In this case, the value of the smaller mark is SUBTRACTED from the mark it precedes: 
样例：  higher values (I before V or X; X before L or C; etc.)


calculate and print the number of I's, V's, etc. (in order from lowest to highest) required to typeset all the page numbers (in Roman numerals) from 1 through N. Do not print letters that do not appear in the page numbers specified. 
输出要求，竟然没有看懂
usaco基本无废话，要仔细的看~
2010-08-31
 
*/

