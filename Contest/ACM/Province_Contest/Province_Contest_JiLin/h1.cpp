#include <stdio.h>
#include <math.h>
#define N 1019
#define MAXX  1000000000000000.9

double wt[N],dis[N][N],x[N],y[N];
int st[N],n;

double smt(void)
{
	for(int i=0;i<=n+1;i++)
	{
		st[i]=0;
		wt[i]=MAXX;
	}
	int min=0;
	int cur=0;
	wt[0]=0;
	double sum=0;
	while(cur!=n+1)
	{
		st[cur]=1;
		sum+=wt[cur];
		min=cur;
		cur=n+1;
		for(int i=0;i<=n;i++)
		{
			if(st[i]!=1)
			{
				if(dis[i][min]<wt[i])
					wt[i]=dis[i][min];
				if(wt[i]<wt[cur])
					cur=i;
			}
		}
	}
/*	for(int i=0;i<=n;i++)
		printf("%lf ",wt[i]);
		printf("\n");*/
	return sum;
}

double distance(int i,int j)
{
	return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x[i],&y[i]);
			dis[0][i]=dis[i][0]=fabs(y[i]);
			for(int j=1;j<i;j++)
			{
				dis[i][j]=dis[j][i]=distance(i,j);
			}
		}
	/*	for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
				printf("%lf ",dis[i][j]);
				printf("\n");
		}*/
		double ans=smt();
		printf("%.2lf\n",ans);
	}
	return 0;
}
/*
3
0 1
5 2
100 100
3
 0 1  
3 7 
-100 -100
4
0 1
3 5
-110 100
100 1

*/
