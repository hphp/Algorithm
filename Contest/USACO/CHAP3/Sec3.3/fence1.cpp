/*
ID: hanjiatong1
PROG: fence
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define N 1010
#define F 2410
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
int dfscnt;
int vstn[F];

void dfs(int curn,int eno)
{
//	vstn[curn] ++;
	evst[eno] = Fsign;
	if(flag == 1)
		return;
	frec[dfscnt] = curn;
	if(dfscnt == f)
	{
		flag = 1;
		return;
	}
/*	if(vstn[curn] % 2 == 0)
	{
		return;	
	}*/
	for(int j=0;j<ecnt[curn];j++)
	{
		int tto = e[curn][j].p;
		int cure = e[curn][j].e;
		if(evst[cure]==Fsign)continue;
		dfscnt++;
		dfs(tto,cure);
		dfscnt--;
	}
//	vstn[curn]--;
	evst[eno] = 0;
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
			vst[tmp[i][j]] 
	/*
	 		if(!vst[tmp[i][j]])
			{
				rec[cnt++] = tmp[i][j];
				vst[tmp[i][j]] = 1;
			}
			*/
		}
	}
	sort(rec,rec+cnt);
	init();
	for(int i=0;i<f;i++)
	{
		int a = find(tmp[i][0]);
		int b = find(tmp[i][1]);
	//	fout << a << " " << b << endl;
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
	int stackp[F+F];
	int stacke[F+F];
	int scnt = 0;
	for(int i=0;i<cnt;i++)
	{
		if(signcnt == 2 && ecnt[i]%2==0)continue;
		for(int jj=0;jj<ecnt[i];jj++)
		{
			dfscnt = 0;
			scnt = 0;
			int curp = e[i][jj].p;
			int cure = e[i][jj].e;
			stackp[scnt] = i;
			scnt ++;
			stackp[scnt] = curp;
			stacke[scnt] = cure;
			int rs = -1;
			while(1)
			{
				if(scnt == f)
				{
					flag =1 ;break;
				}
				if(rs == scnt)
				{
				/*	if(scnt>0)
						evst[stacke[scnt]] = 0;
				*/
					scnt--;
					if(scnt < 0)break;
				}
				rs = scnt;
				curp = stackp[scnt];
				if(scnt > 0)
				{
					cure = stacke[scnt];
					evst[cure] = Fsign;
				}

				for(int k=0;k<ecnt[curp];k++)
				{
					int np = e[curp][k].p;
					int ne = e[curp][k].e;
					if(evst[ne] == Fsign)continue;
					scnt ++;
					stackp[scnt] = np;
					stacke[scnt] = ne;
					break;
				}
			}
			if(flag)
				break;
			Fsign--;
		}
		if(flag)break;
	}
	if(flag)
		for(int i=0;i<=scnt;i++)
			fout << rec[stackp[i]] << endl;

	return 0;
}
/*
 * 2010-08-23
 *
 */
