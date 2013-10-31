#include <stdio.h>
#include <math.h>
#define N 310
#define M 10
//#define Min(c,a,b) grid[][][][]

int grid[N][N];
int rmq[2][N][N][M];//0 row 1 column
int n,m;

void dp_init(int flag,int cur)
{
	if(flag==0)
	{
		for(int i =0;i<m;i++)	
			rmq[0][cur][i][0]=i;
	}
	else
		for(int i=0;i<n;i++)
			rmq[1][cur][i][0]=i;
}

void Rmq(int flag,int cur)
{
	if(flag==0)
	{
		int lim=(int)(log(2*m)/log(2));
		//printf("lim:%d\n",lim);
		for(int i=1;i<=lim+1;i++)	
		{
			for(int j=0;j<m;j++)	
			{
				int temp = j+(1<<(i-1));
				int a=rmq[flag][cur][temp][i-1];
				int b=rmq[flag][cur][j][i-1];
				int c=b;
				if(grid[cur][a]>grid[cur][b])
					c=a;
				rmq[flag][cur][j][i]=c;
//				printf("return cur%d j%d i%d c%d\n",cur,j,i,c);
			}
		}
	}
	else
	{
		int lim=(int)(log(2*n)/log(2));
		for(int i=1;i<=lim+1;i++)	
		{
			for(int j=0;j<n;j++)	
			{
				int temp = j+(1<<(i-1));
				int a=rmq[flag][cur][temp][i-1];
				int b=rmq[flag][cur][j][i-1];
				int c=b;
				if(grid[a][cur]>grid[b][cur])
					c=a;
				rmq[flag][cur][j][i]=c;
			}
		}
	}

}

void dp(void)
{
	for(int i=0;i<n;i++)
	{
		dp_init(0,i);
		Rmq(0,i);
	}
	for(int i=0;i<m;i++)
	{
		dp_init(1,i);
		Rmq(1,i);
	}
}

void init(void)
{
	for(int i=0;i<2;i++)	
		for(int j=0;j<N;j++)
			for(int k=0;k<N;k++)
				for(int c=0;c<M;c++)
					rmq[i][j][k][c]=N-1;
}

int lca(int flag,int cur,int s,int t)
{
	int k =(int)(log(t-s+ 1)/log(2));
//	printf("k:%d\n",k);
	//printf("m+2*k-1:%d n-2*k+1:%d\n",s+(1<<k)-1,t-(1<<k)+1);
//	printf("rmq:%d %d %d %d\n",flag,cur,s,k);
//printf("rmq:%d %d %d %d\n",flag,cur,t-(1<<k)+1,k);
		int a=rmq[flag][cur][s][k];
	int b=rmq[flag][cur][t-(1<<k)+1][k];
//	printf("a:%d b:%d\n",a,b);
	int c=a;
	if(flag==0)
	{
		if(grid[cur][a]<grid[cur][b])
			c=b;
	}
	else
	{
		if(grid[a][cur]<grid[b][cur])
			c=b;
	}
//	printf("c:%d\n",c);
	return c;
}

int main()
{
	init();
	int r1,c1,r2,c2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&grid[i][j]);
		dp();
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++)
		{
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			r1--;r2--;c1--;c2--;
		//	printf("1:%d\n",rmq[0][r1][c1][c2]);
			int maxmax=0;
			int flag=0;
			if(r2-r1<c2-c1)
			{
				for(int i=r1;i<=r2;i++)
				{
					int cur=lca(0,i,c1,c2);
					if(grid[i][cur]>maxmax)
					{
						maxmax=grid[i][cur];
						
						/*if(flag==0)
						break;*/
					}
				}
			}
			else
			{
				for(int i=c1;i<=c2;i++)
				{
					int cur=lca(1,i,r1,r2);
					if(grid[cur][i]>maxmax)
					{
						maxmax=grid[cur][i];
					/*	if(grid[r1][c1]>=maxmax||grid[r1][c2]>=maxmax||grid[r2][c1]>=maxmax||grid[r2][c2]>=maxmax)
						flag=1;
						else flag=0;
						if(flag==0)
						break;*/
					}
				}
			}
			printf("%d ",maxmax);
			if(grid[r1][c1]>=maxmax||grid[r1][c2]>=maxmax||grid[r2][c1]>=maxmax||grid[r2][c2]>=maxmax)
						flag=1;
			//else flag=0;
			if(flag==0)
				printf("no\n");
				else printf("yes\n");
		}
	}
	return 0;
}
