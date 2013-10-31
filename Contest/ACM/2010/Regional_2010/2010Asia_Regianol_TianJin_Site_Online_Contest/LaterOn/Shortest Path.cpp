#include <stdio.h>
#define N 310
#define MAX (1<<28)
#define Min(a,b) ((a)<(b)?(a):(b))

int dis[N][N];
int vst[N];
int n,m,q;

void init()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)	
			dis[i][j] = MAX;
	for(int i=0;i<n;i++)
		vst[i] = 0;
}

int main()
{
	int tt = 1;
	while(scanf("%d%d%d",&n,&m,&q)!=EOF)
	{
		if(!(n||m||q))break;
		init();
		int a,b,c;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			dis[a][b] = Min(dis[a][b],c);
		}
		if(tt > 1)
			printf("\n");
		printf("Case %d:\n",tt++);
		int sign;
		for(int i=0;i<n;i++)
			dis[i][i] = 0;
		for(int i=0;i<q;i++)
		{
			scanf("%d",&sign);
			if(sign == 0)
			{
				scanf("%d",&a);
				if(vst[a])
				{
					printf("ERROR! At point %d\n",a);	
				}
				else
				{
					for(int j=0;j<n;j++)
						for(int k=0;k<n;k++)
							if(dis[j][a] < MAX && dis[a][k] < MAX)
							if(dis[j][a] + dis[a][k] < dis[j][k])
							{
								dis[j][k] = dis[j][a] + dis[a][k];
							}
					vst[a] = 1;
				}
			}
			else if(sign == 1)
			{
				scanf("%d%d",&a,&b);
				if((!vst[a])||(!vst[b]))
				{
					printf("ERROR! At path %d to %d\n",a,b);
				}
				else
				{
					if(dis[a][b] < MAX)
						printf("%d\n",dis[a][b]);
					else
					{
						printf("No such path\n");
					}
				}
			}
		}
	}
	return 0;
}
/*
2010-09-15
12:13-12:30
14:42-15:13
total: 47min 
一次AC
这道题的关键在于看，当一个点available的时候，那么对于通过他链接的所有点之间的距离都可以相应的改变。
同时他到别的点的距离以及其他点到他的距离也会相应的改变。
当询问两个点的时候，题目简化了，事实上如果不判断两个点是否被访问过，那么很可能dis已经更新了，但是是非法的。 
5 10 100
1 2 6335
0 4 5725
3 3 6963
4 0 8146
1 2 9962
1 0 1943
2 1 2392
4 2 154
2 2 7422
1 3 9896
0 1
0 2 

1 1 2
1 1 3
1 1 4
1 1 0
0 3 
0 4
*/
