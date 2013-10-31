#include <stdio.h>
#define N 30
#define E_1 0.36788
double kind[N][N],kind2[N][N],C[N][N];
double jc[N];
int n,m;

void init()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			kind[i][j] =kind2[i][j] = 0;
	kind[0][0] =kind2[0][0] = 1.0;
}
double cp[21] = {0,1,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
void init_init()
{
	
	jc[0] = 1;
	for(int i=1;i<N;i++)
	{
		jc[i] = i*jc[i-1];
		cp[i] = jc[i]*E_1;
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			C[i][j] = 0;
	C[0][0] = 1;
	for(int i=1;i<N;i++)
	{
		C[i][0] = 1;
		for(int j=1;j<=i;j++)
		{
			C[i][j] = C[i-1][j-1]+C[i-1][j];
			printf("%.0lf ",C[i][j]);
		}
		printf("\n");
	}
	for(int i=1;i<N;i++)
	{
		cp[i] = 0;
		int flag = 1;
		for(int j=0;j<=i;j++)
		{
			cp[i] += (flag*jc[i-j]*C[i][j]);
			flag = -flag;
		}
		printf("%.0lf ",cp[i]);
	}
		printf("\n");
	cp[1] = 1;
	
}

int main()
{
	init_init();
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=i;k++)
				{
					kind[i][j] += (kind[i-k][j-1]*C[n-i+k][k]*cp[k]);
				}
				printf("%.0lf ",kind[i][j]/jc[j]);
			}
			printf("\n");
		}
		printf("fain\n");
		for(int i=1;i<=n-1;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int k=1;k<=i;k++)
				{
					if(j-1==0&&kind[i-k][j-1]!=0)
					{
					//	printf("hei i-k %d %d %.0lf\n",i-k,j-1,kind[i-k][j-1]);	
					}
				//	printf("heillo %.0lf ",kind2[i][j]);
				//	printf("%d %d i-k , j - 1 ,%.0lf %.0lf %.0lf\n",i-k,j-1,kind2[i-k][j-1],C[n-1-i+k][k],cp[k]);
					kind2[i][j] += (kind2[i-k][j-1]*C[n-1-i+k][k]*cp[k]);
				}
				//printf("hie\n");
				printf("%.0lf ",kind2[i][j]/jc[j]);
			}
			printf("\n");
		}
			printf("\n");
		double sum = 0;
		for(int i=1;i<=m;i++)
		{
			sum += (kind[n][i]/jc[i]-(i>1?kind2[n-1][i-1]/jc[i-1]:0));
			printf("%.0lf %.0lf\n",kind[n][i]/jc[i],(i>1?kind2[n-1][i-1]/jc[i-1]:0));
		}
			//
		
		printf("%.4lf\n",sum/jc[n]);
	}
	return 0;
}
