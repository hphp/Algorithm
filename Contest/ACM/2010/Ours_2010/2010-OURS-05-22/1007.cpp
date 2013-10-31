#include <stdio.h>
#include <algorithm>
#define N 1010000

struct Node
{
	double s;
	int id;
}node[N];
double score[N];
bool cmp(Node a , Node b)
{
	if(a.s > b.s)
		return 1;
	if(a.s < b.s)
		return 0;
	if(a.id < b.id)
		return 1;
		return 0;
}

int rec[N];
int n,m,k;

int main()
{
	double a;
	while(scanf("%d %d %d",&m,&n,&k)!=EOF)
	{
		for(int i=0;i<=n;i++)
			score[i] = 0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				scanf("%lf",&a);
				score[j] += a;
			}
		}
		for(int i=1;i<=n;i++)
		{
			node[i].s = score[i];
			node[i].id = i;
		}
		std::sort(node+1,node+n+1,cmp);
		int cnt = 0;
		for(int i=1;i<=k;i++)
			rec[cnt++] = node[i].id;
		std::sort(rec,rec+cnt);
		for(int i=cnt-1;i>=0;i--)
		{
			printf("%d",rec[i]);
			if(i)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
