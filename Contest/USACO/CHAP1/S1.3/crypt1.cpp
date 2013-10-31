/*
ID: hanjiatong1
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#define N 10
#define K 6

using namespace std;
bool exist[N];
int rec[K],v[N];
int n;

int vst[1000][100];
int sum;

int mul(char a[],char b[])
{
	int rr[2][5] = {0};
	int sa = strlen(a);
	int sb = strlen(b);
	int next = 0;
	int cc = 0;
	for(int i=sa-1;i>=0;i--)
	{
		int tmp = (a[i]-'0')*(b[0]-'0') + next;
		next = tmp/10;
		tmp = tmp%10;
		rr[0][cc] = tmp;
		cc ++;
		if(! exist[tmp])
			return 0;
	}
	if(next > 0)
		return 0;
	cc = 1;
	next = 0;
	for(int i=sa-1;i>=0;i--)
	{
		int tmp = (a[i]-'0')*(b[1]-'0') + next;
		next = tmp/10;
		tmp = tmp%10;
		rr[1][cc] = tmp;
		cc ++;
		if(! exist[tmp])
			return 0;	
	}
	if(next > 0)return 0;
	next =0 ;
	for(int i=0;i<4;i++)
	{
		int tmp = rr[0][i]+rr[1][i] + next;
		next = tmp/10;
		tmp %= 10;
		if(! exist[tmp])
			return 0;
	}
	if(next > 0)return 0;
	return 1;
}

void Multiple(int rec[],FILE * fout)
{
	char str[2][N];
	int a = 0 , b = 0;
	for(int i=0;i<3;i++)
	{
		a *= 10;
		a += rec[i];
		str[0][i] = rec[i]+'0';
	}
	str[0][3] = '\0';
	for(int i=3;i<5;i++)
	{
		b *= 10;
		b += rec[i];
		str[1][i-3] = rec[i]+'0';
	}
	if(vst[a][b])return;
	vst[a][b] = 1;
	str[1][2] = '\0';
	int tmp = mul(str[0],str[1]);
	sum += tmp;
//	if(tmp)
//		fprintf(fout , "%s %s\n",str[0],str[1]);
}

void dfs(int st,int curp,FILE * fout)
{
	if(curp == 5)
	{
		Multiple(rec,fout);
		return;
	}
	rec[curp] = v[st];
	for(int i=0;i<n;i++)
	{
		dfs(i,curp+1,fout);	
	}
}

int main() {
	
	FILE * fin = fopen("crypt1.in","r");
	FILE * fout = fopen("crypt1.out","w");
    
    fscanf(fin,"%d",&n);
    sum = 0;
    for(int i=0;i<1000;i++)
    	for(int j=0;j<100;j++)
    		vst[i][j] = 0;
    for(int i=0;i<N;i++)
    	exist[i] = 0;
    for(int i=0;i<n;i++)
    {
		int a;
		fscanf(fin,"%d",&a);
		v[i] = a;
		exist[a] = 1;
	}
	
	for(int i=0;i<n;i++)
		dfs(i,0,fout);
	
	fprintf(fout,"%d\n",sum);
    
    return 0;
}

