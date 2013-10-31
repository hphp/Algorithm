#include <stdio.h>
#include <string.h>
#define S 22
#include <algorithm>
#define N 10010

using namespace std;

struct W
{
	int id;
	char s[S];
}w[N],word[N];
int n;

bool cmp(W a , W b)
{
	if(strcmp(a.s,b.s)<0)
		return 1;
		return 0;	
}
int cnt;
int find(char s[])
{
	if(strcmp(s,w[0].s) <= 0)
		return 0;
	if(strcmp(s,w[cnt-1].s) >= 0)
		return cnt-1;
	int st = 0;
	int ed = cnt-1;
	while(st + 1 < ed)
	{
		int mid = (st+ed)/2;
		if(strcmp(s,w[mid].s) <= 0)
			ed = mid;
		else st = mid;
	}
	return ed;
}

int Pre(char s[],char des[])
{
	int size = strlen(s);
	int sd = strlen(des);
	if(size > sd)
		return 0;
	int i = 0;
	for(;i<size;i++)
		if(s[i] != des[i])
			return 0;
	if(i == size)
		return 1;
}

struct Rec
{
	int id;	
}rec[10];

bool cmp1(Rec a , Rec b)
{
	if(a.id < b.id)
		return 1;
		return 0;	
}

int main()
{
	while(scanf("%d",&n)!=EOF)	
//	scanf("%d",&n);
	{
		for(int i=0;i<n;i++)
		{
			w[i].id = i;
			scanf("%s",w[i].s);
			strcpy(word[i].s,w[i].s);
		}
		std::sort(word,word+n,cmp);
		cnt = 0;
		for(int i=0;i<n;i++)
		{
			if(i==0 || strcmp(word[i].s,word[i-1].s) != 0)
			{
				strcpy(w[cnt].s,word[i].s);
				cnt ++;	
			}
		}
		int a;
		char s[N];
		scanf("%d",&a);
		for(int i=0;i<a;i++)
		{
			scanf("%s",s);
			int tmp = find(s);
			int flag = 0;
			for(int j=tmp;j<cnt;j++)
			{
				if(Pre(s,w[j].s))
				{
					if(flag)printf(" ");
					printf("%s",w[j].s);
//					rec[flag].id = w[j].id;
					flag ++;
					if(flag == 8)
						break;
				}
			}
/*			std::sort(rec,rec+flag,cmp1);
			for(int j=0;j<flag;j++)
			{
				if(j)printf(" ");
				printf("%s",word[rec[j].id].s);
			}*/
			if(flag == 0)
				printf("%s",s);
			printf("\n");
		}
	}
//	while(1);
	return 0;
}
/*
15
a
ab
hello
that
those
dict
youdao
world
your
zy
za
zx
z
zz
8
bob
d
dict
dicti
yo
z
z
*/
