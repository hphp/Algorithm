#include <stdio.h>
#define B 51
#define M 1010
#define MAX (1<<28)
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

int mn[B][M];
int b,m;
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a;
		scanf("%d",&a);
		scanf("%d%d",&b,&m);
		for(int i=0;i<=b;i++)
			for(int j=0;j<=m;j++)
				mn[i][j] = MAX;
		for(int i=1;i<=m;i++)
			mn[1][i] = i;
		for(int i=0;i<=b;i++)
			mn[i][0] = 0;
		for(int i=2;i<=b;i++)
			for(int j=1;j<=m;j++)
				for(int k=1;k<=j;k++)
				{
					int add = 0;
					if(i == 1 && j == m)
						add = 1;
					mn[i][j] = Min(mn[i][j], Max(mn[i-1][k-1],mn[i][j-k])+1);
				}
		printf("%d %d\n",a,mn[b][m]);
	}
	return 0;
}