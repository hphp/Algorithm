#include <stdio.h>
#include <algorithm>
#define N 20
#define S 100

struct P
{
	char s[S];
	int a,b;
	int sn;
}p[N];
int n;

bool cmp(P a , P b)
{
	if(a.a > b.a)
		return 1;
	else if(a.a < b.a)
		return 0;
	else
	{
		if(a.b < b.b)	
			return 1;
		if(a.b > b.b)
			return 0;
		if(strcmp(a.s,b.s)<0)
			return 1;
		return 0;
	}
}

bool cmp1(P a , P b)
{
	if(a.sn < b.sn)
		return 1;
	else if(a.sn > b.sn)
		return 0;
	if(strcmp(a.s,b.s)<0)
		return 1;
	return 0;
}

bool cmps(P a , P b)
{
	if(strcmp(a.s,b.s)<0)
		return 1;
	return 0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int tt = 1 ; tt <= tc; tt ++)
	{
		int sum =0;
		for(int i=0;i<10;i++)	
		{
			scanf("%s%d%d",p[i].s,&p[i].a,&p[i].b);
			sum += p[i].a;
		}
		std::sort(p,p+10,cmp);
//		for(int i=0;i<10;i++)
//			printf("%s\n",p[i].s);
/*		for(int i=0;i<=10;i++)
			for(int j=0;j<=sum;j++)
				mx[i][j] = -1;
		mx[0][0] = 0;
		for(int i=1;i<=10;i++)
		{
				
		}*/
		for(int i=0;i<5;i++)
			p[i].sn = 0;
		for(int i=5;i<10;i++)
			p[i].sn = 1;
		std::sort(p,p+10,cmp1);
		printf("Case %d:\n",tt);
			printf("(%s",p[0].s);
		for(int i=1;i<5;i++)
			printf(", %s",p[i].s);
		printf(")\n");
		printf("(%s",p[5].s);
		for(int i=6;i<10;i++)
			printf(", %s",p[i].s);
		printf(")\n");
	}
}


