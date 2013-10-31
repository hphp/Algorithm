#include <stdio.h>
#define K 11
#define N 110
#define M  10010
#define MAX 10000000

struct Brand
{
	int id;
	int cost;
	int value;
}stuff[N];
int mearn[K][M][N];
int n,sumvalue;
int maxmax;
int cnt[K],number[K][N];

void dp_init(void)
{
	for(int i=0;i<=sumvalue;i++)
		mearn[0][i][0]=0;
		maxmax=-MAX;
}

void dp(void)
{
	dp_init();
	int max[M]={0};
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=sumvalue;j++)
		{
			for(int k=1;k<=cnt[i];k++)
				mearn[i][j][k]=-MAX;
			mearn[i][j][0]=max[j];
			max[j]=-MAX;
		}
		for(int k=0;k<cnt[i];k++)	
		{
			for(int j=sumvalue;j>=0;j--)	
			{
				for(int nn=cnt[i];nn>0;nn--)
				{
				int id=number[i][k];
				int cost=stuff[id].cost;
				int value=stuff[id].value;
				if(j-cost<0)
					continue;
				int temp;
				if(mearn[i][j-cost][nn-1]>=0)
					temp=mearn[i][j-cost][nn-1]+value;
				else temp=-MAX;
				if(mearn[i][j][nn]<temp)
				{
					if(temp>max[j])
						max[j]=temp;
					mearn[i][j][nn]=temp;
				//	if(j<200)
				//	printf("%d %d %d %d\n",i,j,nn,temp);
				}
				}
			}
		}
	}
	for(int j=0;j<=sumvalue;j++)
	for(int i=1;i<=cnt[n];i++)
		if(maxmax<mearn[n][j][i])
			maxmax=mearn[n][j][i];
}

void init(void)
{
	for(int i=0;i<=n;i++)
		cnt[i]=0;
}

int main()
{
	int m;
	while(scanf("%d%d%d",&m,&sumvalue,&n)!=EOF)
	{
		init();
		for(int i=0;i<m;i++)	
		{
			scanf("%d%d%d",&stuff[i].id,&stuff[i].cost,&stuff[i].value);
			number[stuff[i].id][cnt[stuff[i].id]++]=i;
		}
		/*for(int i=1;i<=n;i++)
			printf("%d ",cnt[i]);*/
/*		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<cnt[i];j++)	
				printf("%d ",number[i][j]);
				printf("\n");
		}*/
		dp();
		if(maxmax==-MAX)
			printf("Impossible\n");
		else 
		printf("%d\n",maxmax);
	}
	return 0;
}
