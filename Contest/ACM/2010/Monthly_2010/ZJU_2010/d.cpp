#include <stdio.h>
#include <vector>
#define N 371
#define abss(a) ((a)>0?(a):(-(a)))
std::<vector>edge[N];
int sign[N];
struct P
{
	int x,y;	
}p[N];

int dis(int i,int j)
{
	return (abss(p[i].x-p[j].x)+abss(p[i].y-p[j].y));
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d",&p[i].x,&p[i].y);
			for(int j=1;j<i;j++)
			{
				if(dis(i,j)<=L)
				{
					
				}
			}
		}
	}
	return 0;
}
