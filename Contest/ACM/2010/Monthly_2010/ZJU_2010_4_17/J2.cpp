#include <stdio.h>
#define N 110
#define T 11000
#define MAX (1<<29)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int mn[N][N][2];
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
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=100;j++)
				for(int k=0;k<2;k++)
					mn[i][j][k] = MAX;
		mn[0][0][0] = 0;
		mn[0][0][1] = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=100;j++)
			{
				for(int k=0;k<2;k++)
				{
					if(mn[i][j][k] < MAX)
					{
						if(time[i+1][1-k] - j >=0)
						{
							mn[i+1][time[i+1][1-k]-j][1-k] = 
								Min(mn[i][j][k]+j,mn[i+1][time[i+1][1-k]-j][1-k]);
						}
						if(time[i+1][1-k]-j <= 0)
						{
							mn[i+1][j-time[i+1][1-k]][k] =
								Min(mn[i][j][k]+time[i+1][1-k],mn[i+1][j-time[i+1][1-k]][k]);
						}
						{
							mn[i+1][time[i+1][k]][k] = 
								Min(mn[i][j][k]+j,mn[i+1][time[i+1][k]][k]);
						}
					}
				}
			}
		}
		int mnmn = MAX;
		for(int i=0;i<=100;i++)
			for(int k=0;k<2;k++)
			{
				int f = mn[n][i][k]+i;
				if(f < mnmn)	
					mnmn = f;
			}
		printf("%d\n",mnmn);
	}
	return 0;
}
