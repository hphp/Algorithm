#include <stdio.h>
#define N 1010
#define MAX (1<<28)
struct G
{
	int r,c;	
}g[N];

int main()
{
	int n;
	int tt = 1;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&g[i].r,&g[i].c);
		}
		if(tt>1)printf("\n");
		printf("Case %d:\n",tt++);
		for(int i=0;i<n;i++)
		{
			int mr = MAX,mc = MAX;
			for(int j=0;j<n;j++)
			{
				if(g[j].r <= g[i].r || g[j].c <= g[i].c)
					continue;
				if(g[j].r == mr)
				{
					if(g[j].c < mc)
					{
						mr = g[j].r;
						mc = g[j].c;
					}	
				}
				if(g[j].r < mr)
				{
					mr = g[j].r;
						mc = g[j].c;
				}
			}	
			if(mr == MAX && mc == MAX)
				mr = mc = -1;
			printf("%d %d\n",mr,mc);
		}
	}
}
