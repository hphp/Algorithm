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

void init()
{
	ec = 1;
	for(int i=0;i<cnt;i++)
	{
		for(int j=0;j<cnt;j++)
		{
			grid[i][j] = 0;
		}
		vst[i] = 0;
		ecnt[i] = 0;
	}
}
bool flag;
int signcnt;

bool cmp(E a , E b)
{
	if(a.p < b.p)
		return 1;
		return 0;	
}

int stackp[F+F];
int main() {
	
    ofstream fout ("fence.out");
    ifstream fin ("fence.in");
    fin >> f;
    cnt = 510;
	init();
    for(int i=0;i<f;i++)
    {
		for(int j=0;j<2;j++)
		{
			fin >> tmp[i][j];
			vst[tmp[i][j]] = 1;
		}
		grid[tmp[i][0]][tmp[i][1]] ++;
		grid[tmp[i][1]][tmp[i][0]] ++;
	}

	flag= 0;
	int scnt = 0;
	for(int i=0;i<cnt;i++)
	{
		if(vst[i] == 0)continue;
		if(signcnt == 2 && ecnt[i]%2==0)
			continue;
		scnt = 0;
		int curp = i;
		stackp[scnt] = i;
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

			for(int np  = 0 ; np < cnt; np ++)
			{
				if(vst[np] == 0)continue;
				if(grid[curp][np])
				{
					grid[curp][np]--;
					grid[np][curp]--;
					scnt ++;
					stackp[scnt] = np;
					break;
				}
			}
		}
		if(flag)
			break;
	}
	if(flag)
		for(int i=0;i<=scnt;i++)
			fout << stackp[i] << endl;

	return 0;
}
/*
 * 2010-08-23
 *
 */
