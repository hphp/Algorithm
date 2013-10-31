//09-10-19--20:42--
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 100
#define MAX (1<<30)
#define Min(a,b) ((a)<(b)?(a):(b))

struct Edge
{
	int a,b;
	int belong;
}edge[N*N];
int rec[N],map[N],n,ea,eb,ia,ib,da,db;
int grid[N][N][2];
int a,b,tt=1;

int main()
{
	while(scanf("%d %d %d",&n,&ea,&eb)!=EOF)
	{
		if(!(n||ea||eb))break;
		scanf("%d %d %d %d",&ia,&ib,&da,&db);
		int cnt =0,part=0;
		for(int i=0;i<n;i++)
		{
			rec[i] = i;
			for(int j=0;j<n;j++)
				for(int k=0;k<2;k++)
					grid[i][j][k] =0;
		}
		for(int i=0;i<ea;i++)
		{
			scanf("%d %d",&a,&b);
			edge[cnt].a=a;
			edge[cnt].b=b;
			grid[a][b][0] =  1;
			grid[b][a][0] =  1;
			edge[cnt].belong=1;cnt++;
		}
		part=cnt;
		for(int j=0;j<eb;j++)
		{
			scanf("%d %d",&a,&b);
			edge[cnt].a = a;
			edge[cnt].b = b;
			grid[a][b][1] = 1;
			grid[b][a][1] = 1;
			edge[cnt].belong=2;cnt++;
		}
		int mnmn = MAX;
		do
		{
			for(int i=0;i<n;i++)
				map[rec[i]] = i;
		/*	for(int i=0;i<n;i++)
				printf("%d ",rec[i]);
				printf("\n");
			for(int i=0;i<n;i++)
				printf("%d ",map[i]);
				printf("\n");*/
			int sum =0;
			for(int i=0;i<part;i++)
			{
				int a = edge[i].a;
				int b = edge[i].b;
				if(grid[rec[a]][rec[b]][1]==0)
				{
					sum += Min(ib,da);
				}
			}
			for(int i=part;i<cnt;i++)
			{
				int a = edge[i].a;
				int b = edge[i].b;
				if(grid[map[a]][map[b]][0]==0)
				{
					sum+=Min(ia,db);
				}
			}
		//	printf("%d %d\n",sum,mnmn);
			if(sum <mnmn)
				mnmn = sum;
		}while(next_permutation(rec,rec+n));
		printf("Case #%d: %d\n",tt++,mnmn);
	}
	return 0;
}
