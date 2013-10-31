

/*
|-------|    |-------|    |-------|    
|       |    |       |    |   |   |    
|---O   |    |---O   |    |   O   |          
|       |    |       |    |       |           
|-------|    |-------|    |-------|    
    A            B            C

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O   |    |   O   |
|   |   |    |   |   |    |   |   |
|-------|    |-------|    |-------|
    D            E            F

|-------|    |-------|    |-------|
|       |    |       |    |       |
|   O   |    |   O---|    |   O   |
|   |   |    |       |    |   |   |
|-------|    |-------|    |-------|
    G            H            I
    
9 9 12       9 12 12       9 12 12        12 12 12      12 12 12 
6 6 6  5 ->  9  9  9  8->  9  9  9  4 ->  12  9  9  9-> 12 12 12 
6 3 6        6  6  6       9  9  9        12  9  9      12 12 12 

*/
/*
time : -- 2010-6-1:16:53--17:30

*/
/*
ID: hanjiatong1
PROG: clocks
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int next[13];
int before[13];
int afct[10][10] = {// move : -- > clock
	{0},
	{0,1,1,0,1,1,0},
	{0,1,1,1,0},
	{0,0,1,1,0,1,1,0},
	{0,1,0,0,1,0,0,1,0},
	{0,0,1,0,1,1,1,0,1},
	{0,0,0,1,0,0,1,0,0,1},
	{0,0,0,0,1,1,0,1,1,0},
	{0,0,0,0,0,0,0,1,1,1},
	{0,0,0,0,0,1,1,0,1,1}
	};
	
int g[4][4];
int rec[10*4];
int cnt;
int flag = 0;
    ofstream fout ("clocks.out");
    ifstream fin ("clocks.in");

int acnt,arec[10*4];

void dfs(int g[][4],int use[10],int st)
{
	if(cnt > acnt)
		return ;
	for(int i=1;i<10;i++)
		if(use[i] > 3)
			return ;
/*	for(int i=0;i<cnt;i++)
	{
		printf("%d ",rec[i]);	
	}
	printf("\n");
	for(int i=1;i<10;i++)
		if(use[i])
			printf("%d %d\n",i,use[i]);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
			printf("%d ",g[i][j]);
			printf("\n");
	}
	system("pause");*/
	int sign = 0;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(g[i][j]!=12)
			{
				sign = 1;
				break;
			}
		}
	if(sign == 0)
	{
		if(acnt == cnt)
		{
			int ss = 0;
			for(int i=0;i<cnt;i++)
				if(rec[i] < arec[i])
				{
					ss = 1;
					break;
				}
				else 
				{
					ss = -1;
					break;	
				}
			if(ss == 1)
			{
				for(int i=0;i<cnt;i++)
					arec[i]	 = rec[i];
			}
		}
		else
		{
			acnt = cnt;
			for(int i=0;i<cnt;i++)
				arec[i]	 = rec[i];
		}
/*		printf("%d",rec[0]);
		for(int i=1;i<cnt;i++)
			printf(" %d",rec[i]);
			printf("\n");*/
			flag = 1;
			return ;
	}
	for(int i=st;i<=9;i++)
	{
		rec[cnt++] = i;
		use[i]++;
		for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
			{
				int cur = j*3+k+1;
				if(afct[i][cur])
				{
					g[j][k] = next[g[j][k]];
				}
			}
	/*	if(cnt == 1 && i== 9)
		{
				
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				fout << g[j][k] << ' ';
			}
			fout << endl;
		}
		}*/
		dfs(g,use,i);for(int j=0;j<3;j++)
			for(int k=0;k<3;k++)
			{
				int cur = j*3+k+1;
				if(afct[i][cur])
				{
					g[j][k] = before[g[j][k]];
				}
			}
//		if(flag == 1)return;
		cnt--;
		use[i]--;
	}
}

int main() {
    next[3] = 6;next[6] = 9;
    next[9] = 12;next[12] = 3;
    before[6] = 3;before[9] = 6;
    before[12] = 9; before[3] = 12;
    for(int i=0;i<3;i++)
    	for(int j=0;j<3;j++)
    	{
			fin >> g[i][j];
		}
	int a,b;
/*	while(scanf("%d%d",&a,&b)&&a&&b)
		printf("%d\n",afct[a][b]);*/
	cnt = 0;
	int use[10];
	flag = 0;
	for(int i=0;i<10;i++)
		use[i] = 0;
	acnt = 10*3;
	dfs(g,use,1);
	if(flag == 0)
	{
		fout << "impossible" << endl;
		return 0;
	}
		for(int i=0;i<acnt-1;i++)
			fout << arec[i] << ' ';
			fout << arec[acnt -1] << endl;
    return 0;
}
/*

*/
