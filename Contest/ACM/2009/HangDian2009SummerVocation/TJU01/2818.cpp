//09-10-31-09-12---
#include <stdio.h>
#include <string.h>
#define N 30100

struct Set
{
	int f;
	int dis_f;
	int own;
	int ans;
}set[N];
int n;

void init()
{
	for(int i=0;i<=n;i++)
	{
		set[i].f = i;
		set[i].dis_f = 0;
		set[i].own = 1;
		set[i].ans = -1;
	}
}

int under(int cur)
{
//	printf("%d %d\n",cur,set[cur].dis_f);
	int sum =0;
	while(cur!=set[cur].f)
	{
		sum += set[cur].dis_f;
		cur = set[cur].f;
	}
	return sum;
/*	if(set[cur].f==cur)
		return set[cur].dis_f;
	return set[cur].dis_f+under(set[cur].f);*/
}

int find(int cur)
{
	while(cur!=set[cur].f)
	{
		cur = set[cur].f;
	}
	return cur;
}

void merge(int from,int to)
{
	int ff = find(from);
	set[from].dis_f = under(from);
	set[from].f = ff;
	int tt = find(to);
	set[to].dis_f = under(to);
	set[to].f = tt;
	if(ff!=tt)
	{
		set[ff].f = tt;
		set[ff].dis_f = set[tt].own;
		set[tt].own = set[tt].own+set[ff].own;
	}
}

int main()
{
	int p,a,b;
	char s[3];
	n = N-1;
	while(scanf("%d",&p)!=EOF)
	{
//	scanf("%d",&p);
		init();
		for(int i=0;i<p;i++)	
		{
			scanf("%s",s);
	/*		for(int j=1;j<=n;j++)
				if(set[j].dis_f)
					printf("%d %d\n",j,set[j].dis_f);*/
			if(s[0]=='M')
			{
				scanf("%d %d",&a,&b);
				merge(a,b);
			}
			else
			{	
				scanf("%d",&a);
				printf("%d\n",under(a));
			}
		}
	}
	return 0;
}
