#include <stdio.h>
#define N 1010

char grid[N][N];
int sign[N][N];
int max[N][N];
int n;
int ans;

void init(void)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			sign[i][j]=0;
}

void dp(void)
{
	ans=1;
	for(int i=0;i<n;i++)
		max[i][0]=max[0][i]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<n;j++)
		{
			int cur = max[i-1][j-1];
			int limit = i-cur;
			int ii=i;
			int jj=j;
			int cc=0;
			for(;ii>=limit;ii--,jj--,cc++)
			{
				if(grid[i][jj]!=grid[ii][j])
					break;
			}
			max[i][j]=cc;
			if(ans<max[i][j])
			ans= max[i][j];
		}
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
	//	init();
		for(int i=n-1;i>=0;i--)	
			scanf("%s",grid[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(grid[i][j]==grid[j][i])
				{
					sign[i][j]	= sign[j][i]=1;
				}
				else sign[i][j]=sign[j][i]=0;
			}
	/*	for(int i=1;i<n;i++)
			for(int j=0;j<n;j++)
				column_row[i][j]=column_row[i-1][j]+sign[i][j];*/
		dp();
		printf("%d\n",ans);
	}
	return 0;
}
