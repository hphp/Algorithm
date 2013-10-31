#include <stdio.h>
#include <math.h>
#define N 310
#define P 10

typedef int Int;

Int rrmq[N][N][P];
Int rmq[N][N][N][P];
Int grid[N][N];
int n,m;

Int Max(Int a,Int b)
{
	return a>b?a:b;	
}

void ST_prepro(void)
{
	int limm=(int)(log(1.0*m)/log(2.0));
	int limn=(int)(log(1.0*n)/log(2.0));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			rrmq[i][j][0]=grid[i][j];
		for(int k=1;k<=limm;k++)
		{
			for(int j=0;j<m;j++)
			{
				if(j+(1<<k)>m)
					break;
				int temp=j+(1<<(k-1));
				rrmq[i][j][k]=Max(rrmq[i][j][k-1],rrmq[i][temp][k-1]);
			}	
		}
		/*int num;
		scanf("%d",&num);
		for(int kk=0;kk<num;kk++)
		{
			int y1,y2;
			scanf("%d%d",&y1,&y2);
			int cc=(int)(log(y2-y1+1)/log(2.0));
			Int d=Max(rrmq[i][y1][cc],rrmq[i][y2-(1<<cc)+1][cc]);
			printf("%u\n",d);
		}*/
	}
	for(int i=0;i<n;i++)
	{
		for(int j)	
	}
/*	for(int i=0;i<n;i++)
	for(int k=0;k<=limm;k++)
	for(int j=0;j<m;j++)
	{
		if(j+(1<<k)>m)break;
		rmq[i][0][j][k]=rrmq[i][j][k];
	}
	;;;;
	for(int k=0;k<=limm;k++)
		for(int j=0;j<m;j++)
	{
		if(j+(1<<k)>m)break;
		for(int ki=1;ki<=limn;ki++)
		{
			for(int i=0;i<n;i++)
			{
				if(i+(1<<ki)>n)	
					break;
				int temp=i+(1<<(ki-1));
						rmq[i][ki][j][k]=Max(rmq[i][ki-1][j][k],rmq[temp][ki-1][j][k]);
			}	
		}
	}*/
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				scanf("%d",&grid[i][j]);
		ST_prepro();
		int num;
		scanf("%d",&num);
		for(int i=0;i<num;i++)
		{
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x1--;x2--;y1--;y2--;
		//	printf("x2-x1%d\n",x2-x1);
			int k1=(int)(log(1.0*(x2-x1+1))/log(2.0));
			int k2=(int)(log(1.0*(y2-y1+1))/log(2.0));
			//printf("k1 %d k2:%d\n",k1,k2);
			Int c=Max(rmq[x1][k1][y1][k2],rmq[x1][k1][y2-(1<<k2)+1][k2]);
		//	printf("c%u\n",c);
			Int d=Max(rmq[x2-(1<<k1)+1][k1][y1][k2],rmq[x2-(1<<k1)+1][k1][y2-(1<<k2)+1][k2]);
			//printf("d%u\n",d);
			Int ans = Max(c,d);
			printf("%d ",ans);
			if((grid[x1][y1]==ans)||(grid[x2][y1]==ans)||(grid[x2][y1]==ans)||(grid[x2][y2]==ans))
				printf("yes\n");
				else printf("no\n");
		}
	}	
	return 0;
}
