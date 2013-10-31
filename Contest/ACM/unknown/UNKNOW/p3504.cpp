//11:38
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 1010
#define S 110
#define M 10100
#define MAX 100000000

char ori[N];
int from[N],cnt[N],here[N];
int wlt[M][30];
struct Dic
{
	int size;
	char s[S];	
}dic[M];
int start[M],end[M];
int n,m;
int least,most;

bool cmp(Dic a,Dic b)
{
	if(a.size<b.size)
		return 1;
	else if(a.size==b.size)	
	{
		if(strcmp(a.s,b.s)<0)	
			return 1;
			return 0;
	}
	return 0;
}

void dp_init(void)
{
	for(int i=0;i<=n;i++)
	{
		cnt[i]=-1;
		from[i]=-1;
	}
	from[0]=0;
	cnt[0]=1;
	here[0]=-1;
}

void dp(void)
{
	dp_init();
	for(int i=1;i<=n;i++)
	{
		for(int j=least;j<=most;j++)
		{
			int ff=i-j+1;
		//	printf("ff %d %d\n",ff,i);
			if(ff>0)
			{
				if(from[ff-1]>=0);
				else continue;
				int l[26]={0};
				for(int d=ff;d<=i;d++)
					l[ori[d]-'a']++;
				for(int c=start[j],d=ff;c<=end[j];c++,d++)
				{
				//	printf("s %s\n",dic[c].s);
					if(ori[ff]<dic[c].s[0])
						break;
					if(ori[ff]==dic[c].s[0]&&ori[i]==dic[c].s[dic[c].size-1])
					{
						int dd=0;
						for(;dd<26;dd++)
						{
							if(l[dd]!=wlt[c][dd])
								break;
						}
						if(dd==26)
						{
							if(from[i]>=0)
								cnt[i]=2;
							else if(cnt[ff-1]>1)
								cnt[i]=2;
							else
							{
								from[i]=ff-1;
								here[i]=c;
								cnt[i]=1;
							}
						}
					}
				}
			}
			else break;
		}	
	}	
/*	for(int i=0;i<=n;i++)
		printf("%d %d\n",from[i],here[i]);*/
}

void print(int cur,int num)
{
	if(cur==0)
		return;
	if(num==-1)
	{
		printf("impossible\n");
		return ;
	}	
	else if(num>1)
	{
		printf("ambiguous\n");
		return ;
	}
	else
	{
		print(from[cur],cnt[cur]);
	}
	if(here[cur]!=-1)
	{
		if(from[cur])
			printf(" ");
		printf("%s",dic[here[cur]].s);
	}
}

void init(void)
{
	for(int i=0;i<m;i++)
		for(int j=0;j<26;j++)
			wlt[i][j]=0;
	least=MAX;
	most=0;	
}

int main()
{
	int test;
	scanf("%d",&test);
	int rec[N];
	while(test--)
	{
		scanf("%s",ori+1);
		n=strlen(ori+1);
		init();
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%s",dic[i].s);
			dic[i].size=strlen(dic[i].s);
			if(dic[i].size>most)
				most=dic[i].size;
			if(dic[i].size<least)
				least=dic[i].size;
		/*	for(int j=0;j<dic[i].size;j++)
				rec[j]=dic[i].s[j]-'a';
			sort(rec,rec+dic[i].size,cmp1);
			for(int j=0;j<dic[i].size;j++)
				dic[i].s[j]=rec[j]+'a';*/
		}
		sort(dic,dic+m,cmp);
		for(int i=0;i<m;i++)
			for(int j=0;j<dic[i].size;j++)
				wlt[i][dic[i].s[j]-'a']++;
		start[dic[0].size]=0;
		for(int i=1;i<m;i++)
			if(dic[i].size!=dic[i-1].size)
			{
				start[dic[i].size]=i;
				end[dic[i-1].size]=i-1;
			}
		end[dic[m-1].size]=m-1;
	/*	for(int i=0;i<m;i++)
			printf("%s\n",dic[i].s);
		for(int i=least;i<=most;i++)
			printf("%d %d\n",start[i],end[i]);*/
		dp();
		print(n,cnt[n]);
		printf("\n");
	}
	return 0;
}
