/*
ID: hanjiatong1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
using namespace std;
#define N 101000
#define MAX (1<<28)
map<string,int> exist;
int v[10];
char rans[N];
bool flag = 0;
ofstream fout ("msquare.out");
ifstream fin ("msquare.in");
int packv[10];

void changeA(int cur[])
{
	for(int i=0;i<8;i++)
	{
		packv[i] = cur[7-i];
	}
	for(int i=0;i<8;i++)
		cur[i] = packv[i];
}
void changeB(int cur[])
{
	for(int i=0;i<8;i++)
		packv[i] = cur[i];
	int curv = packv[3];
	for(int i=3;i>0;i--)
		packv[i] = packv[i-1];
	packv[0] = curv;
	curv = packv[4];
	for(int i=4;i<7;i++)
		packv[i] = packv[i+1];
	packv[7] = curv;
	for(int i=0;i<8;i++)
		cur[i] = packv[i];
}
void changeC(int cur[])
{
	for(int i=0;i<8;i++)
		packv[i] = cur[i];
	int curv = packv[1];
	packv[1] = packv[6];
	packv[6] = packv[5];
	packv[5] = packv[2];
	packv[2] = curv;
	for(int i=0;i<8;i++)
		cur[i] = packv[i];
}

int mnmn = MAX;
    
void dfs(char ans[],int cv[],int cnt)
{
	if(cnt >= mnmn)return;
	int i=0;
	for(;i<8;i++)
		if(cv[i]!=v[i])
		{
			break;
		}
	if(i == 8)
	{
		ans[cnt] = '\0';
		strcpy(rans,ans);
		mnmn = cnt;
		return;
	}
	char s[9] = "";
	for(int i=0;i<8;i++)
		s[i] = cv[i]+'0';
	s[8] = '\0';
	string a = s;
	if(exist[a]!=0)
	{
		if(exist[a] > cnt)
			return;
	}
	exist[a] = cnt;
	int packv1[10];
	for(int i=0;i<8;i++)
	{
		packv1[i] = cv[7-i];
	}
	ans[cnt] = 'A';
	ans[cnt+1] = '\0';
	dfs(ans,packv1,cnt+1);
	int packv2[10];
	for(int i=0;i<8;i++)
		packv2[i] = cv[i];
	changeB(packv2);
	ans[cnt] = 'B';
	ans[cnt+1] = '\0';
	dfs(ans,packv2,cnt+1);
	int packv3[10];
	for(int i=0;i<8;i++)
		packv3[i] = cv[i];
	changeC(packv3);
	ans[cnt] = 'C';
	ans[cnt+1] = '\0';
	dfs(ans,packv3,cnt+1);
}

char s[N];
int main() {
    
    for(int i=0;i<8;i++)
    	fin >> v[i];
    int cur[9] = {1,2,3,4,5,6,7,8};
    dfs(s,cur,0);
    fout << strlen(rans) <<rans << endl;
}
/*
2010-09-09
10:06-10:15

*/
