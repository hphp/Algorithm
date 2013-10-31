#include <stdio.h>
#define N 1010

char grid[N][N];
int sign[N][N];
int max[N];
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
	max[0]=1;
	ans=1;
	for(int i=1;i<n;i++)
	{
		int cur = max[i-1]	;
		int limit = i-cur;
		int j;
		int cc=0;
		for(j=i;j>=limit;j--,cc++)
		{
			if(!sign[i][j])	
				break;
		}
		max[i]=cc;
		if(ans<max[i])
			ans= max[i];
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
