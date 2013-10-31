//09-11-01--08:46
#include <stdio.h>
#include <math.h>
#define N 301
#define LOG 10
#define Max(a,b) ((a)>(b)?(a):(b))

int rmq[N][LOG][N][LOG];
int n,m;
int i,j,ki,kj,tmpi,tmpj;

void dp()
{
	int limi = (int)(log(n*1.0)/log(2.0))+1;
	int limj = (int)(log(m*1.0)/log(2.0))+1;
	for( i=1;i<=n;i++)
	for( kj = 1;kj<=limj;kj++)
	{
		for( j=1;j<=m;j++)
		{
//			if(j+(1<<kj)>m)break;
			 tmpj = j+(1<<(kj-1));
			if(tmpj>m)break;
			rmq[i][0][j][kj] = Max(rmq[i][0][j][kj-1],rmq[i][0][tmpj][kj-1]);
		}
	}
	for( j=1;j<=m;j++)
	for( ki = 1;ki<=limi;ki++)
	{
		for( i=1;i<=n;i++)
		{
//			if(i+(1<<ki)>n)break;
			 tmpi = i+(1<<(ki-1));
			if(tmpi>n)break;
			rmq[i][ki][j][0] = Max(rmq[i][ki-1][j][0],rmq[tmpi][ki-1][j][0]);
		}
	}
//	printf("%d %d\n",limi,limj);
	for( ki=1;ki<=limi;ki++)
	{
		for( kj=1;kj<=limj;kj++)	
		{
			for( i=1;i<=n;i++)	
			{
				for( j=1;j<=m;j++)
				{
			//		if(i+(1<<ki)>n)break;
			//		if(j+(1<<kj)>m)break;
					 tmpi = i+(1<<(ki-1));
					 tmpj = j+(1<<(kj-1));
					if(tmpi>n)break;
					if(tmpj>m)break;
					rmq[i][ki][j][kj] = Max(rmq[i][ki-1][j][kj],rmq[tmpi][ki-1][j][kj]);
				}
			}
		}
	}
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for( i=1;i<=n;i++)	
		{
			for( j=1;j<=m;j++)
			{
				scanf("%d",&rmq[i][0][j][0]);
			}
		}
		dp();
		int p,r1,r2,c1,c2;
		int cl,rw,mc,mr,m;
		scanf("%d",&p);
		for( i=0;i<p;i++)
		{
			scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
			 cl = (int)(log((c2-c1+1)*1.0)/log(2.0));
			 rw = (int)(log((r2-r1+1)*1.0)/log(2.0));
			 mc = Max(rmq[r1][rw][c1][cl],rmq[r1][rw][c2-(1<<cl)+1][cl]);
			 mr = Max(rmq[r2-(1<<rw)+1][rw][c1][cl],rmq[r2-(1<<rw)+1][rw][c2-(1<<cl)+1][cl]);
			 m = Max(mc,mr);
			if(rmq[r1][0][c1][0]==m||rmq[r1][0][c2][0]==m||rmq[r2][0][c1][0]==m||rmq[r2][0][c2][0]==m)
			{
				printf("%d yes\n",m);
			}
			else printf("%d no\n",m);
		}
	}
	return 0;
}
