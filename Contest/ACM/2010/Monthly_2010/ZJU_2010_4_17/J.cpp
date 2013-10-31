#include <stdio.h>
#define N 110
#define T 11000
#define MAX (1<<29)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int mn[N][T][2];
int n;
int time[N][2];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		int sumt = 0,sumtt = 0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<2;j++)
			{
				scanf("%d",&time[i][j]);
			}
			sumt += time[i][0];
			sumtt += time[i][1];
		}
		sumt = Min(sumt,sumtt);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=sumt;j++)
				for(int k=0;k<2;k++)
					mn[i][j][k] = MAX;
		mn[0][0][0] = 0;
		mn[0][0][1] = 0;
		int ttt = 0;
		for(int i=0;i<n;i++)
		{
			int xx = 0;
			for(int j=0;j<=ttt;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(mn[i][j][k] < MAX || mn[i][j][k] > sumt)
					{
						if(j+time[i+1][k] <= sumt)
						mn[i+1][j+time[i+1][k]][k] = Min(mn[i][j][k],mn[i+1][j+time[i+1][k]][k]);
						if(mn[i][j][k] + time[i+1][1-k] <= sumt)
						mn[i+1][mn[i][j][k] + time[i+1][1-k]][1-k] = 
						Min(j,mn[i+1][mn[i][j][k] + time[i+1][1-k]][1-k]);
						if(xx < mn[i][j][k] + time[i+1][1-k])
							xx = mn[i][j][k] + time[i+1][1-k];
					}
				}
			}
			ttt += Max(time[i+1][0],time[i+1][1]);
			ttt = Max(ttt,xx);
			ttt = Min(ttt,sumt);
		}
		int mnmn = MAX;
		for(int i=0;i<=sumt;i++)
			for(int k=0;k<2;k++)
			{
				int f = Max(mn[n][i][k],i);
				if(f < mnmn)	
					mnmn = f;
			}
		printf("%d\n",mnmn);
	}
	return 0;
}
