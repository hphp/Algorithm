/*
ID: hanjiatong1
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define N 510
#define F 1410
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;
#define TsfPP(a,e) ((edgew[e]==(a))?edgev[e]:edgew[e])
struct E
{
	int e;
	int p;
}e[N][F];
int ecnt[N],edgew[F],edgev[F],ec;
int grid[N][N];
int tmp[F][2];
int vst[N] = {0};
int rec[N],cnt;
int f;
int odd[2];
int find(int cur)
{
	int s = 0;
	int e = cnt-1;
	while(s<=e)
	{
		int mid = (s+e)/2;
		if(rec[mid] < cur)
			s = mid+1;	
		if(rec[mid] > cur)
			e = mid-1;	
		if(rec[mid] == cur)
			return mid;
	}	
}

void init()
{
	ec = 1;
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<cnt;j++)
		{
			grid[i][j] = 0;
		}
		ecnt[i] = 0;
	}
}
bool flag;
int evst[F];
int frec[F];
int Fsign;
int signcnt;

void dfs(int to,int eid,int cnt)
{
	if(flag == 1)
		return;
	frec[cnt] = to;
	if(cnt == f)
	{
		flag = 1;
		return;
	}
	evst[eid] = Fsign;
	for(int j=0;j<ecnt[to];j++)
	{
		int tto = e[to][j].p;
		int cure = e[to][j].e;
		if(evst[cure]==Fsign)continue;
		dfs(tto,cure,cnt+1);
	}
	if(odd[1] == to)
		evst[eid] = 0;
}

bool cmp(E a , E b)
{
	if(a.p < b.p)
		return 1;
		return 0;	
}

int main() {
	
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
    fin >> f;
    cnt = 0;
    for(int i=0;i<f;i++)
    {
		for(int j=0;j<2;j++)
		{
			fin >> tmp[i][j];
			if(!vst[tmp[i][j]])
			{
				rec[cnt++] = tmp[i][j];
				vst[tmp[i][j]] = 1;
			}
		}
	}
	sort(rec,rec+cnt);
	init();
	for(int i=0;i<f;i++)
	{
		int a = find(tmp[i][0]);
		int b = find(tmp[i][1]);
	//	fout << a << " " << b << endl;
		edgev[ec] = a;
		edgew[ec] = b;
		e[a][ecnt[a]].e = ec;
		e[b][ecnt[b]].e = ec;
		e[a][ecnt[a]++].p = b;
		e[b][ecnt[b]++].p = a;
		ec++;
	}
	signcnt = 0;
	for(int i=0;i<cnt;i++)
	{
		sort(e[i],e[i]+ecnt[i],cmp);
/*		for(int j=0;j<ecnt[i];j++)
			fout << e[i][j] << " ";*/
		if(ecnt[i]%2==1)
		{
			odd[signcnt]=i;
			signcnt++;
		}
//		fout << endl;
	}

	flag= 0;
	Fsign = f+10000;
	for(int i=0;i<cnt;i++)
	{
		if(signcnt == 2 && ecnt[i]%2==0)continue;
		for(int j=0;j<ecnt[i];j++)
		{
			int to = e[i][j].p;
			int cure = e[i][j].e;
			frec[0] = i;
			dfs(to,cure,1);
			if(flag)break;
			Fsign ++;
		}	
			if(flag)break;
	}
	if(flag)
	for(int i=0;i<=f;i++)
		fout << rec[frec[i]] << endl;
    
    return 0;
}
/*
09:11-
09:20-09:38ÖÐÍ¾´ó±ã
--
10:32
*/
