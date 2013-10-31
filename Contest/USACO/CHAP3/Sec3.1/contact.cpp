/*
ID: hanjiatong1
PROG: contact
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm> 
#include <string>
#include <string.h>
#define S 201000
#define STM 4096

struct Stm
{
	int len;
	int stm;
	int cnt;	
}stm[STM*13];

int vst[STM][13];

using namespace std;

char s[S];

bool cmp(Stm a , Stm b)
{
	if(a.cnt > b.cnt)
		return 1;
	if(a.cnt < b.cnt)
		return 0;
	if(a.len < b.len)
		return 1;
	if(a.len > b.len)
		return 0;
	if(a.stm < b.stm)
		return 1;
		return 0;
}

void init()
{
	for(int i=0;i<STM;i++)
	{
		for(int j=1;j<13;j++)
			vst[i][j] = -1;
	}
}

int main() {
    ofstream fout ("contact.out");
    ifstream fin ("contact.in");
    int a,b,n;
    fin >> a >> b >> n;
    int cc = 0;
    while(fin >> s+cc+1)
	{
		cc = strlen(s+1);
//		fout << cc << " ";
	}
	init();
//	fout << cc << endl;
//	fout << s+1 << endl;
	int ccc = 0;
	for(int i=1;i<=cc;i++)
	{
		int cstm = 0;
		for(int k=i;k>i-b&&k>0;k--)
		{
			cstm += (s[k]-'0')<<(i-k);
			if(i-k+1<a)continue; 
			if(vst[cstm][i-k+1]!=-1)
			{
//			fout << "hei " << cstm << " " << i-k+1 << endl;
				stm[vst[cstm][i-k+1]].cnt ++;
			}
			else
			{
				vst[cstm][i-k+1] = ccc;
				stm[ccc].cnt = 1;
				stm[ccc].stm = cstm;
				stm[ccc].len = i-k+1;
				ccc++;	
			}
		}
	}
	sort(stm,stm+STM*13,cmp);
	int flag = 0;
	int start =0;
	int kcnt = 0;
    for(int i=0;kcnt<n&&i<STM*13;i++)
    {
//		fout << stm[i].stm << " "<< stm[i].len << " "<< stm[i].cnt << endl;
		if(!stm[i].cnt)break;
		if(!i || stm[i].cnt!=stm[i-1].cnt)
		{
			flag = 0;
			if(start)
			{
				kcnt++;
				if(kcnt == n)
					break;
				fout << endl;
			}
			start ++;
			fout << stm[i].cnt << endl;
		}
		else 
		{
			flag ++;
		}
		if(flag > 0 && flag == 6)
		{
			flag = 0;
			fout << endl;
		}
		else if(flag)
			fout << " ";
		int cstm = stm[i].stm;
		int cc = 0;
		int rr[13];
		while(cc<stm[i].len)
		{
			rr[cc] = cstm%2;
			cstm/=2;
			cc++;
		}
		for(int k=cc-1;k>=0;k--)
			fout << rr[k];
	}
		fout << endl;
    return 0;
}
/*
2010-09-08
8:10-9:06
做的时间挺长的。。思路想的比较快。 
-9:38
把所有case全部过掉
在输出的时候出了些问题
首先是没有看清楚题意
题意说输出的时候 每6个占一行 
然后是没有想好就乱改
对于这样的输出的问题还是先想好为妙
韩笨笨
 
*/
