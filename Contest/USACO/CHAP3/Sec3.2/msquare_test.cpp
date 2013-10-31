/*
ID: hanjiatong1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;
#define N 101000
map<string,bool> exist;
int v[10];
char rans[N];
bool flag = 0;
    ofstream fout ("msquare.out");
    ifstream fin ("msquare.in");
void dfs(char ans[],int cv[],int cnt)
{
	fout << "dfs" << endl;
	for(int i=0;i<8;i++)
		fout << cv[i] << " ";
		fout << endl;
	if(flag == 1)
	{
		fout << "flag = 1" << endl;
		return;
	}
	int i=0;
	for(;i<8;i++)
		if(cv[i]!=v[i])
			break;
	if(i == 8)
	{
		flag = 1;
		ans[cnt] = '\0';
		strcpy(rans,ans);
		fout << "cool" << rans << endl;
		return;
	}
	char s[9] = "";
	for(int i=0;i<8;i++)
		s[i] = cv[i]+'0';
	s[8] = '\0';
	string a = s;
	if(exist[a])
	{
		fout << "exist[a] hrere "  << endl;
		return;
	}
	exist[a] = 1;
	int packv[10];
	for(int i=0;i<8;i++)
	{
		packv[i] = cv[7-i];
	}
	ans[cnt] = 'A';
	fout << "1hei" << endl;
	for(int i=0;i<8;i++)
		fout << packv[i] << " ";
		fout << endl;
	dfs(ans,packv,cnt+1);
	for(int i=0;i<8;i++)
		packv[i] = cv[i];
	int curv = packv[3];
	for(int i=3;i>0;i--)
		packv[i] = packv[i-1];
	packv[0] = curv;
	curv = packv[4];
	for(int i=4;i<7;i++)
		packv[i] = packv[i+1];
	packv[7] = curv;
	fout << "2hei" << endl;
	for(int i=0;i<8;i++)
		fout << packv[i] << " ";
		fout << endl;
	ans[cnt] = 'B';
	dfs(ans,packv,cnt+1);
	for(int i=0;i<8;i++)
		packv[i] = cv[i];
	curv = packv[1];
	packv[1] = packv[5];
	packv[5] = packv[6];
	packv[6] = packv[2];
	packv[2] = curv;
	fout << "3hei" << endl;
	for(int i=0;i<8;i++)
		fout << packv[i] << " ";
		fout << endl;
	ans[cnt] = 'C';
	dfs(ans,packv,cnt+1);
}

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

char s[N];
int main() {
    scanf("%s",s);
    for(int i=0;i<7;i++)
    	scanf("%d",&v[i]);
    int cur[10] = {1,2,3,4,5,6,7,8};
    for(int i=0;i<strlen(s);i++)
    {
		if(s[i] == 'A')
		{
			changeA(cur);
		}
		if(s[i] == 'B')
		{
			changeB(cur);
		}
		if(s[i] == 'C')
		{
			changeC(cur);
		}
		for(int j=0;j<8;j++)
			printf(" %d ",cur[j]);
			printf("\n");
	}
	while(1);
}
/*
2010-09-09
10:06-10:15
BCABCCB
2 6 8 4 5 7 3 1 

*/
