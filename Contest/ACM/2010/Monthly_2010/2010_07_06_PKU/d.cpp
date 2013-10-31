#include <stdio.h>
#include <stdlib.h>
#define N 110000
#define K 6
#define STM 81

int kd[N][STM];
int n;
int b[STM][K];
int p[5];
void booling()
{
	p[0] = 1;
	for(int i=1;i<=4;i++)
		p[i] = p[i-1]*3;
	for(int i=0;i<STM;i++)
	{
		int t = i;
		int c =0;
		while(t)
		{
			b[i][c++] = t%3;
			t/=3;
		}
	}
	/*for(int i=0;i<5;i++)
		printf("%d ",p[i]);
		printf("\n");
		for(int i=0;i<41;i++)
		{
			for(int j=0;j<4;j++)
				printf("%d ",b[i][j]);
				printf("\n");
		}*/
}

void dfs(int r,int st,int stm,int add)
{
//	printf("%d %d %d %d\n",r,st,stm,add);
	system("pause");
	if(st == 4)
	{
		int sum =0;
		for(int i=0;i<4;i++)
		{
			sum = sum + (b[stm][i]-1)*p[i];
			printf("%d ",b[stm][i]);
		}
		printf("\n%d %d\n",r+1,add);
		for(int i=0;i<4;i++)
			printf("%d ",b[sum][i]);
			printf("\n");
		kd[r+1][sum] += add;
		return;
	}
//	for(int i=st;i<4;i++)
	int i = st;
	{
		if(b[stm][i] == 0)
		{
			dfs(r,i+1,stm + 2*p[i],add);
		}
		if(i<3 && b[stm][i] == 0 && b[stm][i+1] == 0)
		{
			dfs(r,i+2,stm+p[i]+p[i+1],add);
		}
		if(b[stm][i] > 0)
			dfs(r,i+1,stm,add);
	}
}

int main()
{
	int tc;
	booling();
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<STM;j++)
				kd[i][j] = 0;
		kd[1][40] = 1;
		for(int i=1;i<=n+1;i++)
		{
			for(int j=0;j<STM;j++)
			{
				if(kd[i][j])
				{
					printf("hello start %d %d %d\n",i,j,kd[i][j]);
					dfs(i,0,j,kd[i][j]);
				}
			}
		}
		printf("%d\n",kd[n+1][40]);
	}
	return 0;
}
