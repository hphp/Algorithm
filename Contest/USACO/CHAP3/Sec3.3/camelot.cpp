/*
ID: hanjiatong1
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define H 33
#define W 30
#define MAX (1<<20)
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define avl(a,b) (((a)>=0&&(a)<h&&(b)>=0&&(b)<w)?1:0)
using namespace std;

int kh,kw,knh[H*W],knw[H*W];
int h,w;
int ft[H*W][H*W];
int cnt;

void finit()
{
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			for(int ii=0;ii<h;ii++)
				for(int jj=0;jj<w;jj++)
					ft[i*w+j][ii*w+jj] = MAX;
}
	ofstream fout ("camelot.out");
    ifstream fin ("camelot.in");

void scanin()
{
	char s[4];
	char c;
    fin >> h >> w;
    fin >> c >> kh;
	kw = c-'A';
	kh --;

	cnt = 0;

	int h;
	while(fin >> s >> h)
	{
		knw[cnt] = s[0]-'A';
		knh[cnt] = h-1;
		cnt ++;
	}
}

struct Node
{
	int h,w;
	int stp;
}queue[W*H];

int mv[8][2] = 
{
	{-2,1},{-1,2},{1,2},{2,1},
	{2,-1},{1,-2},{-1,-2},{-2,-1}
};
int step[H][W];
void bfs_init()
{
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			step[i][j] = MAX;
}

void bfs(int sth,int stw)
{
	bfs_init();
	int s = 0;
	int e = 0;
	queue[e].h = sth;
	queue[e].w = stw;
	queue[e].stp= 0;
	step[sth][stw] = 0;
	e ++;
	while(s <= e)
	{
		int ch = queue[s].h;
		int cw = queue[s].w;
		int stp = queue[s].stp;
		if(step[ch][cw] > stp)
		{
			s ++;
			continue;
		}

		for(int j=0;j<8;j++)
		{
			int nh = ch + mv[j][0];
			int nw = cw + mv[j][1];
			if(avl(nh,nw))
			{
				if(step[nh][nw] > stp + 1)		
				{
					step[nh][nw] = stp + 1;
					queue[e].h = nh;
					queue[e].w = nw;
					queue[e].stp = stp + 1;
					e ++;
				}
			}
		}
		s ++;
	}
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			 ft[sth*w+stw][i*w+j]= Min(ft[sth*w+stw][i*w+j],step[i][j]);
}
int kt[H][W];
int mvK[8][2] = 
{
	{-1,0},{-1,1},{0,1},{1,1},
	{1,0},{1,-1},{0,-1},{-1,-1}
};
int fe;

void bfsKing(int sth,int stw)
{
	bfs_init();
	int s = 0;
	int e = 0;
	queue[e].h = sth;
	queue[e].w = stw;
	queue[e].stp = 0;
	step[sth][stw] = 0;
	e ++;
	while(s < e)
	{
		int ch = queue[s].h;
		int cw = queue[s].w;
		int stp = queue[s].stp;
		if(step[ch][cw] > stp)
		{
			s ++;
			continue;
		}

		for(int j=0;j<8;j++)
		{
			int nh = ch + mvK[j][0];
			int nw = cw + mvK[j][1];
			if(avl(nh,nw))
			{
				if(step[nh][nw] > stp + 1)		
				{
					step[nh][nw] = stp + 1;
					queue[e].h = nh;
					queue[e].w = nw;
					queue[e].stp = stp + 1;
					e ++;
				}
			}
		}
		s ++;
	}
	fe = e;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			kt[i][j] = step[i][j];
}

int main() {

	scanin();
	finit();

	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			bfs(i,j);
		}
	bfsKing(kh,kw);

	int fking = kh*w+kw;
	int ans = MAX;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
			int dis = kt[i][j];
			int mn = 0;
			int sum = 0;
			for(int k=0;k<cnt;k++)	
			{
				int cknh = knh[k];
				int cknw = knw[k];
				int curd = ft[cknh*w+cknw][i*w+j];
				sum += curd;
				for(int kk=0;kk<50&&kk<fe;kk++)
				{
					int nh = queue[kk].h;
					int nw = queue[kk].w;
					int stp = queue[kk].stp;
					int tmp = ft[cknh*w+cknw][nh*w+nw] + ft[nh*w+nw][i*w+j] + stp - dis-curd;
					if(tmp  < mn)
					{
						mn  = 	tmp;
					}
				}
			}
			if(sum + dis + mn < ans)
			{
				ans = sum + dis +mn;
			}
		}
	fout << ans << endl;
    
    return 0;
}

/*
 *2010-09-20-8:14
2010-09-20-11:05
开始时候，木有将最初加入的点sth,stw 的标记位赋值.
另外，因为不想枚举所有的点A，使得knight和king是经过点A会合后一起出发的。
但是数据木有过，抱着试试看的心情，枚举了最多从点king出发的50个点，作为汇合点，
竟然所有数据都通过了。
中间错了一次，原因在于有的时候点king周围根本没有50个点。
总体来说，挺慢的。。。
但是基本上没有太大改动。自己的想法也很不错，赞一个！
 * */

