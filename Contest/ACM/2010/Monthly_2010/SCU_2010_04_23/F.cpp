#include <stdio.h>
#include <algorithm>
#define N 11000
#define M 110
#define MAX (1<<20)
#define Min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)>0 ? (a):(-(a)))

double h[2][N];
int n,m;
double mn[N][M];

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		int flag = 0;
		if(n < m)
		{
			flag = 1;
		}
		for(int i=1;i<=n;i++)
			scanf("%lf",&h[flag][i]);
		for(int j=1;j<=m;j++)
			scanf("%lf",&h[1-flag][j]);
		if(n < m)
		{
			int t = n;
			n = m;
			m = t;
		}
		std::sort(h[0]+1,h[0]+n+1);
		std::sort(h[1]+1,h[1]+m+1);
	/*	for(int j=0;j<2;j++)
		{
		for(int i=1;i<=n;i++)
			printf("%lf ",h[j][i]);
			printf("\n");
		}*/
		double ans = MAX;
		int dif = n-m+1;
		for(int i=0;i<=m;i++)
			for(int j=0;j<=dif;j++)
				mn[i][j] = MAX;
		for(int i=1;i<=dif;i++)
		mn[0][i] = 0.0;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=dif;j++)
			{
				double tmp = mn[i-1][j];
				if(tmp < MAX)
					tmp += abs(h[1][i]-h[0][i+j-1]);
				mn[i][j] = Min(mn[i][j-1],tmp);
			}
		}
		for(int j=1;j<=dif;j++)
			if(mn[m][j] < ans)
				ans = mn[m][j];
		printf("%.6lf\n",ans);
	}
	return 0;
}
/*
2 3
1.5 2.0
1.5 1.7 2.0
2 3
1.5 2.0
1.5 1.7 1.9

3 4
1.5 1.67 1.68 
1.7 1.5 1.6 1.64
3 10
1.5 1.67 1.68 
1.5 1.67 1.68 1.5 1.67 1.68 1.5 1.67 1.68 1.2
*/
