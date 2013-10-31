/*
ID: hanjiatong1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <string.h>

using namespace std;
#define K 101000

struct Node
{
	int last;
	char kind;
	string s;
	int step;
}queue[K];
string f;
map<string,bool> vst;

int bfs(string st)
{
	vst.clear();
	int s = 0;
	int e = 0;
	queue[e].last = -1;
	queue[e].kind = 'n';
	queue[e].step = 0;
	queue[e].s = st;
	e ++;
	while(s <= e)
	{
		string cur = queue[s].s;
		if(cur == f)
		{
			return s;
		}
		int step = queue[s].step;
		char next[9];
		for(int j=0;j<8;j++)
			next[j] = cur[7-j];
		next[8] = '\0';
		string tmp = next;
		if(vst[tmp]==0)
		{
			queue[e].last = s;
			queue[e].kind = 'A';
			queue[e].step = step+1;
			queue[e].s = tmp;
			e ++;
			vst[tmp] = 1;
		}
		next[0] = cur[3];
		for(int j=1;j<4;j++)
			next[j] = cur[j-1];
		for(int j=4;j<7;j++)
			next[j] = cur[j+1];
		next[7]= cur[4];
		next[8] = '\0';
		tmp = next;
		if(vst[tmp]==0)
		{
			queue[e].last = s;
			queue[e].kind = 'B';
			queue[e].step = step+1;
			queue[e].s = tmp;
			e ++;
			vst[tmp] = 1;
		}
		for(int j=0;j<8;j++)
			next[j] = cur[j];
		next[1] = cur[6];
		next[6] = cur[5];
		next[5] = cur[2];
		next[2] = cur[1];
		next[8] = '\0';
		tmp = next;
		if(vst[tmp]==0)
		{
			queue[e].last = s;
			queue[e].kind = 'C';
			queue[e].step = step+1;
			queue[e].s = tmp;
			e ++;
			vst[tmp] = 1;
		}
		s++;
	}
	return -1;
}
char rec[K];

int main() {
    ofstream fout ("msquare.out"); 
    ifstream fin ("msquare.in");
	int v[9];
	char ff[9];
    for(int i=0;i<8;i++)
    {
    	fin >> v[i];
    	ff[i] = v[i]+'0';
	}
	ff[8] = '\0'; 
	f = ff;
//	fout << f << endl;
    string st = "12345678";
    int last = bfs(st);
    int cnt = 0;
    while(queue[last].last != -1)
    {
//		fout << last << " ";
		rec[cnt++] = queue[last].kind;
		last = queue[last].last;
	}
    rec[cnt] = '\0';
    fout << strlen(rec) << endl ;
	for(int j=cnt-1;j>=0;j--)
		fout << rec[j] ;
		fout << endl;
    return 0;
}

