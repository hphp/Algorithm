/*
ID: hanjiatong1
PROG: ttwo
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ofstream fout ("ttwo.out");
ifstream fin ("ttwo.in");
char s[20][20];
bool vst[121][121][4][4];
#define avl(x,y) ((x>0&&x<11&&y>0&&y<11&&s[x][y]!='*')?1:0)

struct Pos
{
	int x,y,dir;	
}f,c;
int mvd[4] = {1,2,3,0};
int mv[4][2] = {
	{-1,0},{0,1},{1,0},{0,-1}
};

int main()
{
	for(int i=1;i<=10;i++)
		fin >> s[i]+1;
	for(int i=1;i<=10;i++)
	{
		for(int j=1;j<=10;j++)
		{
			if(s[i][j] == 'F')
			{
				f.x = i;
				f.y = j;
				f.dir = 0;
			}
			if(s[i][j] == 'C')
			{
				c.x = i;
				c.y = j;
				c.dir = 0;	
			}
		}
	}
	for(int i=0;i<=110;i++)
		for(int j=0;j<=110;j++)
			for(int k=0;k<4;k++)
				for(int d=0;d<4;d++)
					vst[i][j][k][d] = 0;
	bool flag = 0;
	int cnt = 0;
	while(1)
	{
		//fout << "hei " << f.x*11+f.y << " " << c.x*11+c.y << " " << f.dir << " " << c.dir << endl;
		//fout << "vst" << vst[f.x*11+f.y][c.x*11+c.y][f.dir][c.dir] << endl;
		if(vst[f.x*11+f.y][c.x*11+c.y][f.dir][c.dir] == 1)
			break;
		vst[f.x*11+f.y][c.x*11+c.y][f.dir][c.dir] = 1;
		//fout << "f:" << f.x << " " << f.y << " " << f.dir << endl;
		//fout << "c:" << c.x << " " << c.y << " " << c.dir << endl;
		if(avl(f.x+mv[f.dir][0],f.y+mv[f.dir][1]))
		{
			f.x = f.x + mv[f.dir][0];
			f.y = f.y + mv[f.dir][1];	
		}
		else
		{
			f.dir = mvd[f.dir];	
		}
		if(avl(c.x+mv[c.dir][0],c.y+mv[c.dir][1]))
		{
			c.x = c.x + mv[c.dir][0];
			c.y = c.y + mv[c.dir][1];
		}
		else
		{
			c.dir = mvd[c.dir];
		}
		cnt ++;
		if(f.x==c.x&&f.y==c.y)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
		fout << cnt;
	else fout << 0;
	fout << endl;
	return 0;
}
