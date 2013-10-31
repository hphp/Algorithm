#include <stdio.h>
#define N 16
#define M 300
#define STM 65536
int ones[STM];

int grid[N][M];
int stm[N][M];
int num[N][N][M];
int n,m;

void booling(void)
{
	for(int i=0;i<STM;i++)
	{
		int cnt=0;
		for(int j=0;j<N;j++)
			if(i&(1<<j))
				cnt++;
		ones[i]=cnt;
	}
}

int main()
{
	booling();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int j=0;j<m;j++)
			stm[0][j]=0;
		for(int i =1;i<=n;i++)	
		{
			for(int j=0;j<m;j++)	
			{
				scanf("%d",&grid[i][j])	;
				stm[i][j]=(grid[i][j]<<(i-1))+stm[i-1][j];
			//	printf("(%d %d) ",grid[i][j],stm[i][j]);
			}
		//	printf("\n");
		}
		int flag=0;
		for(int i=1;i<=n;i++)
		{
			int j;
			for(j=0;j<i;j++)	
			{
				int k=0;
				for(;k<m;k++)
				{
					int a=ones[stm[i][k]-stm[j][k]];
					num[i][j][k]=a;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i;j++)	
			{
				for(int k=1;k<j;k++)	
				{
					for(int e=0;e<k;e++)	
					{
						for(int cc=0;cc<m;cc++)
						{
							int a=num[i][j][cc]+num[k][e][cc];
							if(a!=1)
							{
								flag=1;
								break;
							}
						}
						if(flag==1)
							break;
					}
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			printf("Yes, I found it\n");
		else printf("It is impossible\n");
	}
	return 0;
}
