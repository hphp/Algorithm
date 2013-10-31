#include <stdio.h>
#include <algorithm>
#define N 1100
#define Max(a,b) ((a)>(b)?(a):(b))

int mx[N];
struct Day
{
	int s,e;	
}day[N];

bool cmp(Day a,Day b)
{
	if(a.e < b.e)
		return 1;
		return 0;	
}

int n;

int main()
{
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&day[i].s,&day[i].e);	
		}
		std::sort(day+1,day+n+1,cmp);
		for(int i=0;i<=day[n].e;i++)
			mx[i] = 0;
		for(int i=1;i<=n;i++)
		{
			int jj = day[i].e;
			mx[jj] = Max(mx[jj],mx[day[i].s]+1);
			for(int j=day[i].e;j<=day[n].e;j++)
			{
				mx[j] = Max(mx[j],mx[jj]);
			}
		}
		printf("%d\n",mx[day[n].e]);
	}
	return 0;
}
