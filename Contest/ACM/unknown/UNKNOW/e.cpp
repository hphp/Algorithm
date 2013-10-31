#include <stdio.h>
#define N 22

int maxmax,n;
int sign[N][N];
int a[9]={1,2,3,4,5,6,7,13,21};

void dfs(int x,int y)
{
	if(y>=n)
	{
		dfs(x+1,0);
		return;
	}
	if(x>=n)
	{
		int cnt=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(sign[i][j])
					cnt++;
					if(maxmax<cnt)
						maxmax=cnt;
						return;
	}
	int flag=0;
	for(int i=0;i<x;i++)
	{
		if(sign[i][y])
		{
			for(int j=y-1;j>=0;j--)
			{
				if(sign[i][j])
				{
					if(sign[x][j])
					{
						flag=1;
						break;
					}
				}
			}
		}
	}
	if(flag==0)
	{
		sign[x][y]=1;
	}
	dfs(x,y+1);
	sign[x][y]=0;
	dfs(x,y+1);
}

int main()
{
	for(int i=0;i<9;i++)
	{
		n=a[i];
		maxmax =0;
		for(int j=0;j<i;j++)
			for(int ii=0;ii<n;ii++)
				sign[j][ii]=0;
		dfs(0,0);
		printf("%d,",maxmax);
	}
	return 0;
}
