/*
ID: hanjiatong1
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
#define MAX (1<<28)
#define Min(a,b) ((a)<(b)?(a):(b))

using namespace std;
int sign[1000] = {0};
int pow[6] = {0};
int bit[8000][10] = {0};
int bitn[8000];

void init()
{
	memset(sign,-1,sizeof(sign));
	pow[0] = 1;
	for(int i=1;i<6;i++)
	{
		pow[i] = pow[i-1]*6;	
	}
	for(int i=1;i<8000;i++)
	{
		int tmp = i;
		bitn[i] = 0;
		while(tmp)
		{
			bit[i][bitn[i]++] = tmp%6;
			tmp/=6;
		}
	}
}
#define S 100
struct SpcOffer
{
	int n;
	int k[5];
	int c[5];
	int p;
	int reduce;
}so[S];
int buy[5],price[5];
int stm[10000],cost[10000];
int mn[10000];

int main() {
	
    ofstream fout ("shopping.out");
    ifstream fin ("shopping.in");
    int s;
    init();
    fin >> s;
    int cnt = 0;
    
    for(int i=0;i<s;i++)
    {
		int n;
		fin >> n;
		so[i].n = n;
		for(int j=0;j<n;j++)
		{
			fin >> so[i].c[j] >> so[i].k[j];
		}
		fin >> so[i].reduce;
	}
	int b;
	fin >> b;
	int fstm = 0;
	for(int i=0;i<b;i++)
	{
		int c,k,p;
		fin >> c >> k >> p;
		if(sign[c] == -1)
			sign[c] = cnt++;
//		buy[i] = k;
		price[sign[c]] = p;
		stm[s+i] = pow[sign[c]];
		cost[s+i] = p;
		fstm += (pow[sign[c]]*k);
	}
	
	for(int i=0;i<s;i++)
	{
		stm[i] = 0;
		cost[i] = 0;
		bool flag = 0;
		for(int j=0;j<so[i].n;j++)	
		{
			int c = so[i].c[j];
			int k = so[i].k[j];
			if(sign[c]==-1)
			{
				flag = 1;
				break;
			}
			stm[i] += (pow[sign[c]]*k);
		//	cost[i] += k*price[sign[c]];
		}
		cost[i] = so[i].reduce;
		if(flag)
		{
			cost[i] = MAX;
		}
	}
/*	for(int i=0;i<s+b;i++)
	{
		for(int j=0;j<6;j++)
			fout << bit[stm[i]][j] << " ";
			fout << endl << cost[i] << endl;
	}
	fout << "fstm" << endl;
	for(int j =0;j<6;j++)
		fout << bit[fstm][j] <<  " " ;
		fout << endl; */
	
	for(int i=1;i<=fstm;i++)
		mn[i] = MAX;
	mn[0] = 0;
	for(int i=1;i<=fstm;i++)
	{
		for(int k=0;k<s+b;k++)
		{
			bool flag = 0;
			int left = 0;
			for(int j=0;j<cnt;j++)
				if(bit[i][j] >= bit[stm[k]][j])
					left += ((bit[i][j]-bit[stm[k]][j])*pow[j]);
				else flag = 1;
//			if((stm[k] & i) == stm[k])
			if(!flag)
			{
				mn[i] = Min(mn[left] + cost[k],mn[i]);
			}
		}
	}
	fout << mn[fstm] << endl;
    
    return 0;
}
/*
19:32-
很简单读懂题目
很简单开始敲代码，但是变量比较多
但是在敲的时候和n个人聊天。。额 主要是一个
其中还听了超哥的喝酒理论-- 让自己的波动非正常。。
后来样例没过 就到了22:00
发现了问题。原来是stm
到今天早上过来 改了一下 发现了自己想的和题目描述不符 所以改啊。。
后来再和自己的输入对照的时候发现的。。汗了。
07：20-07:50 
*/
