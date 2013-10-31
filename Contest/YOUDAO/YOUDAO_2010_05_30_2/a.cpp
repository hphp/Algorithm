#include <stdio.h>
#include <algorithm>
#define N 210
#define MAX (1<<28)
#define E 0.000001

struct Node
{
	double a;
	int b;	
}node[N];

bool cmp(Node a , Node b)
{
	if(a.a/a.b > b.a/b.b)
		return 1;
		return 0;
}

double mx[N*5][N];

int main()
{
	int test;
	scanf("%d",&test);
	int n,m;
	double a;
	int b;
	while(test--)
	{
		scanf("%d%d",&n,&m);
		double A = 0;
		int B = 0;
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%lf%d",&a,&b);
			sum += b;
			A += a*b;
			B += b;
		}
		for(int j=0;j<m;j++)
		{
			scanf("%lf%d",&a,&b);
			sum += b;
			node[j].a = a;	
			node[j].b = b;
		}
		double tmp = A/B;
		if(tmp > 90.0-E)
			printf("%d\n",0);
		else
		{
			for(int i=B;i<=sum;i++)
				for(int j=0;j<=m;j++)
					mx[i][j] = -MAX;
			mx[B][0] = A;
			int flag = 0;
			for(int j=0;j<m;j++)
			{
				for(int k=sum-node[j].b;k>=B;k--)
				{
					for(int jj=j;jj>=0;jj--)
					{
						if(mx[k][jj] < 0)continue;
						if(mx[k][jj] + node[j].a*node[j].b > mx[k+node[j].b][jj+1])
						{
							mx[k+node[j].b][jj+1] = mx[k][jj] + node[j].a*node[j].b;
		/*
							if(mx[k+node[j].b][jj+1] > (k+node[j].b)*(90.0-E))
							{
								flag = 1;
								printf("%d\n",jj+1);
							}
			*/
						}
					}
//					if(flag == 1)
//						break;
				}
		/*		for(int jj=0;jj<=j;jj++)
					for(int k=sum;k>=B;k--)
						if(mx[k][jj] > (90.0-E)*k)
						{
							printf("%d\n",jj);
							flag = 1;
							break;
						}
				if(flag == 1)
				{
					break;	
				}*/
			}
		//	if(flag == 1)continue;
/*			std::sort(node,node+m,cmp);
			int i=0;
			for(;i<m;i++)
			{
				A += node[i].a*node[i].b;
				B += node[i].b;
				if(A/B > 90 - E)
					break;
			}*/
			int ans = m+1;
				for(int j=0;j<=m;j++)
				{
					int i=B;
					for(;i<=sum;i++)
					{
						if(i)
							if(mx[i][j] >= (90.0-E)*i)
								break;
					}
					if(i <= sum)
					{
						ans = j;
						break;
					}
				}
			if(ans <= m)
				printf("%d\n",ans);
			else 
			printf("Impossible\n");
		}
	}	
}

/*
0 2
89 1
90 1
2 2
100 5
50 1
0 1
0 1

2 2
100 1
50 5
100 5
100 5

3 4
80.00 1
40.00 2
20.00 2
90.00 3
88.00 2
92.00 2
100.00 1
3 4
62.00 1
70.00 1
80.00 1
99.00 2
100.00 2
100.00 2
100.00 2

*/
