#include <set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#define N 1010
#define MAX (1<<28)

using namespace std;
struct G
{
	int r,c;
}g[N];
set<G> sett;
set<G>::iterator it,it2,itm;

bool operator  < (const G a,const G b)
{
	if(a.r < b.r)
		return 1;
	if(a.r > b.r)
		return 0;
	if(a.c < b.c)
		return 1;
		return 0;
}
/*
bool operator  < (const iterator it,const iterator it2)
{
	G a = (*it);
	G b = (*it2);
	if(a.r < b.r)
		return 1;
	if(a.r > b.r)
		return 0;
	if(a.c < b.c)
		return 1;
		return 0;
}
*/
G binary_search(G cur)
{
	int r = cur.r;
	int c = cur.c;
	it = sett.begin();
	it2 = sett.end();
	while((it) != (it2))
	{
		itm = (it + it2)/2;
		if((*itm).r==cur.r && (*itm).c == cur.c)
			return *itm;
		if((*itm).r < cur.r)
			it = ++itm;
		else if((*itm).r > cur.r)
			it2 = --itm;
	}
	G g = {-1,-1};
	return g;
/*
	int r = cur.r;
	int c= cur.c;
	it = sett.begin();
	it2 = sett.end();
	if((*it).r >= r)
	{
		G g = {-1,-1};
		return g;
	}
	if(it2.r <= r)
	{
		G g = {-1,-1};
		return g;
	}
	while(it+1 < it2)
	{
		itm = (it+it2)/2;
		if(())
	}
*/
}




int main()
{
	int n;
	int tt = 1;
	int r,c;
	char s[199];
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
		sett.clear();
		if(tt > 1)printf("\n");
		printf("Case %d:\n",tt++);
		for(int i=0;i<n;i++)
		{
			scanf("%s",s);
			if(s[0] == 'a')
			{
				scanf("%d%d",&r,&c);
				G g = {r,c};
				sett.insert(g);
			}
			else if(s[0] == 'r')
			{
				scanf("%d%d",&r,&c);
				G g = {r,c};
				sett.erase(sett.find(g));
			}
			else if(s[0] == 'f')
			{
				scanf("%d%d",&r,&c);
				G cur = {r,c};
				G g = binary_search(cur);
				if(g.r < 0)
				{
					printf("-1\n");
				}
				else
				{
					printf("%d %d\n",g.r,g.c);
				}
/*				it = sett.find(g);
				it++;
				if(it != sett.end())
				{
					printf("%d %d\n",(*it).r,(*it).c);
				}
				else printf("-1\n");*/
			}

		}
	}
}

