#include <stdio.h>
#include <algorithm>
#define Min(a,b) ((a)<(b)?(a):(b))
#define N 100001
#define M 101
#define MAX 101001010100001LL

typedef __int64 Int;
Int smn[2][M];
int rec[2][M],rr[N][M];
int n,m;
int flag[N];

struct Node
{
	int i;
	int v;
	int del;
}node[N];

bool cmp1(Node a , Node b)
{
	if(a.i < b.i)
		return 1;
	return 0;
}
bool cmp(Node a , Node b)
{
	if(a.v < b.v)
		return 1;
	return 0;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&m);
		if(m > n)m = n;
		for(int i=1;i<=n;i++)
		{
			node[i].i = i;
			scanf("%d",&node[i].v);
		}
		std::sort(node+1,node+n+1,cmp);

/*		for(int i=1;i<=n;i++)
		{
			mn[i] = node[i].v - node[1].v;
		}*/
/*		for(int i=1;i<=n;i++)
			printf("%d ",node[i].v);
		printf("\n");*/
		for(int j=0;j<=m;j++)
		{
			smn[0][j] = -node[1].v;
			rec[0][j] = 1;
		}
/*		for(int j=0;j<=m;j++)
			printf("%d ",smn[0][j]);
		printf("\n");*/
		Int cur = -MAX;
		for(int i=1;i<=n;i++)
		{
//				printf("%d %d\n",node[i].i,node[i].v);

			for(int j=1;j<=m;j++)
			{
				cur = smn[0][j-1] + node[i].v;
				rr[i][j] = rec[0][j-1];
		/*		if(rec[i-1][j-1] == 0)
					printf("strange %d %d\n",i,j);*/
			//mn[i] = Min(smn[i-1] + v[i],mn[i]);
				smn[1][j] = Min(smn[0][j],cur-node[i+1].v);
				if(smn[0][j] < cur-node[i+1].v)
				{
			//		rec[i][j] = rec[i-1][j];
				}
				else
				{
					rec[1][j] = i+1;
				}
		/*		if(i == 1 && j == 1)
				{
					printf("%I64d\n",smn[0][1]);
					printf("smi-1j-1: %I64d i-1j: %I64d cur-nodei+1: %I64d cur: %I64d smnij: %I64d\n",smn[i-1][j-1],smn[i-1][j],cur-node[i+1].v,cur,smn[i][j]);
					printf("%d %d\n",i,j);
				}*/
			}
			for(int j=1;j<=m;j++)
			{
				rec[0][j] = rec[1][j];
				smn[0][j] = smn[1][j];
			}
		}
		int  ccur = n, team = m;
		int cnt = 0;
		for(int i=0;i<=n;i++)
			flag[i] = -1;
		while(ccur)
		{
		//	printf("hello cc %d team %d\n",ccur,team);
			ccur = rr[ccur][team];
			team --;
			flag[ccur] = team;
			ccur --;
		}
/*		for(int i=0;i<=n;i++)
			printf("%d ",flag[i]);
		printf("\n");*/
		int tmp = 0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i] == -1)
				node[i].del = tmp;
			else
			{
				tmp = flag[i];
				node[i].del = tmp;
			}
		}
	/*	for(int i=1;i<=n;i++)
			printf("%d ",node[i].del);*/
		std::sort(node+1,node+1+n,cmp1);
		printf("%d\n",n);
		printf("%d",node[1].del);
		for(int i=2;i<=n;i++)
			printf(" %d",node[i].del);
		printf("\n");
	/*	int a,b;
		while(scanf("%d %d",&a,&b)&&a&&b)
			printf("%I64d %I64d\n",mn[a][b],smn[a][b]);*/
//		printf("%I64d\n",cur);
	}
	return 0;
}
