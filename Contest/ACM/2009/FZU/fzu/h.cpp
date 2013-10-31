#include <stdio.h>
#define N 1010

int h[N][N];
char grid[N][N];
int n,m,maxmax;
int kind[N][N];
int tran[7][2]={{0,0},{1,1},{2,2},{0,1},{1,2},{0,2}};
int lower[N];

void init(void)
{
	for(int i=0;i<N;i++)
		h[i][0]=0;
}

void dp_init(int sign)
{
	for(int i=0;i<=n||i<=m;i++)
		h[i][0]=h[0][i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int curkind = kind[i][j];
			if(curkind==6||tran[curkind][0]==sign||tran[curkind][1]==sign)
			{
				h[i][j]=h[i-1][j]+1;
			}
			else h[i][j]=0;
		}
}

void dp(void)
{
	maxmax=0;
	for(int i=0;i<3;i++)
	{
		dp_init(i);
		for(int j=1;j<=n;j++)
		{
	//		lower[1]=0;
			for(int k=1;k<=m;k++)
			{
				int lowest=h[j][k];
				if(h[j][k]>h[j][k-1])
					lower[k]=k-1;
				else
				{
					int l = lower[k-1];
					while(l>0&&h[j][k]<=h[j][l])
					{
						l=lower[l];
					}
					lower[k]=l;
				}
			//	max[j][k]=h[j][k]*(k-lower[j][k]);
				int last = lower[k];
				while(last)
				{		
					int temp = lowest*(k-last);
					if(temp>maxmax)	
					{
						maxmax = temp;
					}
					lowest=h[j][last];
					last = lower[last];
				}
			}
		}
	}
}

int main()
{
	init();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%s",grid[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char ch = grid[i][j];
				if(ch>='a'&&ch<='c')
				{
					kind[i][j]=ch-'a';
				}
				else
				{
					kind[i][j]=ch-'w'+3;
				}
			}
		/*for(int i=1;i<=n;i++)
		{	for(int j=1;j<=m;j++)
				printf("%d ",kind[i][j]);
		}*/
		dp();
		printf("%d\n",maxmax);
	}
	return 0;
}
