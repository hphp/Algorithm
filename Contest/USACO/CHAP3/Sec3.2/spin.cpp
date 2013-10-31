/*
ID: hanjiatong1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define W 6
using namespace std;

struct Spin
{
	int v;
	int w;
	int st[W];
	int d[W];	
}spin[5];

int main() {
    ofstream fout ("spin.out");
    ifstream fin ("spin.in");
    for(int i=0;i<5;i++)
	{
		fin >> spin[i].v >> spin[i].w;
		for(int j=0;j<spin[i].w;j++)
		{
			fin >> spin[i].st[j] >> spin[i].d[j];
		}
	}
	int a;
	bool flag = 0;
	int tpr[360] = {0};
	for(int sec = 0;sec < 360 ; sec ++)
	{
		for(int k=0;k<360;k++)
			tpr[k] = 0;

		for(int i=0;i<5;i++)
		{
			int k = spin[i].v*sec%360;
			for(int j=0;j<spin[i].w;j++)
			{ 
				int st = (spin[i].st[j]+360+k)%360;
				int et = (st + spin[i].d[j]);
				for(int kk=st;kk<=et;kk++)
				{
					/*if(spin[i].d[j] < 100)
						fout << kk%360 << " ";*/
					tpr[kk%360] |= (1<<i);
					if(tpr[kk%360] == 31)
					{
					//	fout <<endl<< "hei " << kk%360 << endl;
						fout << sec << endl;
						flag =1;
						break;
					}
				}
				if(flag==1)break;
				
			//	fout << endl << st << " " << et  << " ;";
			}	
			if(flag==1)break;
			//fout << endl;
		}
		if(flag==1)break;
	}
	if(!flag)
		fout << "none" << endl;
	
    return 0;
}
/*
2010-15:12
这道题一点都不难。
首先没有想象的难。
第二就是最后的解法也不难
问题在于，根本没有读懂题意。
诶，这样的事情可能曾经也发生过
就是他说，改变的方向是读书增多的方向，先是1度，然后是2度。。。我靠。我以为他说的度数增多是轮子的度数。 
不过还好。吃一堑长一智，亏着我果断看解题报告了。
诶。多向各个方向考虑啊！ 
*/
