#include <stdio.h>
#define N 110
#define STM (512)

struct Rec
{
	int x,y,stm;
};

int mn[N][N][STM];

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d",&n,&m);
		int cnt = 0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=m;j++)
				need[i][j] = 0;
		for(int i=1;i<=n;i++)
			{
				scanf("%s",grid[i]+1);
				for(int j=1;j<=m;j++)
					if(grid[i][j] == 'E')
					{
						master_hand[cnt].x = i;
						master_hand[cnt].y = j;
						cnt++;	
					}
			}
		for(int i=0;i<cnt;i++)
		{
			int x = master_hand[i].x;
			int y = master_hand[i].y;
			scanf("%d",&a);
			int stm = 0;
			for(int j=0;j<a;j++)
			{
				scanf("%d",&b);
				stm += (1<<(b-1));
			}
			need[x][y] = stm;
		}
	}
	return 0;
}
