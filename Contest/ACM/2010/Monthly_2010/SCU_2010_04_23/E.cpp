#include <stdio.h>
#include <algorithm>
#define N 12

int exist[N][3];
//s 0 b 1 c 2
char ch[4] = {"sbc"};
struct Rec
{
	int id,kind;	
}rec[16];

int num[N][3];
int flag = 0;
int pair,three;
int cnt;

void dfs(int cur)
{
	if(flag == 1)
	return;
	if(cur == cnt)
	{
		if(pair == 1 && three == 4)
		{
			flag = 1;
		}
		return ;
	}
	int id = rec[cur].id;
	int kind = rec[cur].kind;
	if(num[id][kind]==0)
	{
		dfs(cur+1);
		return;
	}
	if(pair == 0 && num[id][kind]>1)
	{
		num[id][kind] -= 2;
		pair ++;
		dfs(cur);
		if(flag == 1)
			return; 
		pair--;
		num[id][kind] += 2;
	}
	if(num[id][kind]>2)
	{
		num[id][kind]-=3;
		three ++;
		dfs(cur);
		if(flag == 1)return;
		three--;
		num[id][kind]+=3;
	}
	if(id < 7)
	if(num[id][kind]>0 && num[id+1][kind]>0 && num[id+2][kind]>0)
	{
		for(int j=0;j<3;j++)
		{
			num[id+j][kind] --;
		}
		three ++;
		dfs(cur);
		three--;
		for(int j=0;j<3;j++)
		{
			num[id+j][kind] ++;
		}
	}
}

bool cmp(Rec a,Rec b)
{
	if(a.kind < b.kind)
		return 1;
	if(a.kind > b.kind)
		return 0;
	if(a.id < b.id)
		return 1;
		return 0;		
}

int main()
{
	char s[3];
	int test;
	scanf("%d",&test);
	for(int tt = 1; tt <= test ; tt ++)
	{
		for(int i=0;i<10;i++)
			for(int j=0;j<3;j++)
				exist[i][j] = 0;
		for(int i=0;i<13;i++)
		{
			scanf("%s",s);
			switch(s[1])
			{
				case 's' : 
					{
						exist[s[0]-'1'][0] ++;
						break;
					}	
				case 'b':
					{
						exist[s[0]-'1'][1]++;
						break;
					}
				case 'c':
					{
						exist[s[0]-'1'][2]++;
						break;
					}
			}
		}
	/*	for(int i=0;i<cnt;i++)
			printf("%d %d\n",rec[i].id,rec[i].kind);*/
		printf("Case %d:",tt);
		int sign = 0;
		for(int j=0;j<3;j++)
		for(int i=0;i<10;i++)
		{
				if(exist[i][j]>3)
					continue;
				flag = 0;
				pair = 0;
				three = 0;
				for(int ii=0;ii<10;ii++)
					for(int jj=0;jj<3;jj++)
						num[ii][jj] = exist[ii][jj];
				
				num[i][j] ++;
				cnt = 0;
				for(int jj=0;jj<3;jj++)
				for(int ij=0;ij<10;ij++)
				if(num[ij][jj]>0)
				{
					rec[cnt].id = ij;
					rec[cnt].kind = jj;
					cnt ++;	
				}
				dfs(0);
				if(flag == 1)
				{
					sign = 1;
					printf(" %d%c",i+1,ch[j]);
				}
		}
		if(sign == 0)
			printf(" None");
		printf("\n");
	}
	return 0;
}
/*
1b 1b 2b 2b 3b 3b 5s 6s 7s 1c 1c 2c 2c

*/
