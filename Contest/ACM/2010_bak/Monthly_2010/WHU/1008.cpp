#include <stdio.h>
#define N 10
#define avl(x,y) (((x)>=1&&(x)<=8&&(y)>=1&&(y)<=8)?1:0)

char grid[N][N];
int mv[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

int main()
{
	int test;
	scanf("%d",&test);
	for(int tt=1;tt<=test;tt++)
	{
		for(int i=1;i<=8;i++)
			{
				scanf("%s",grid[i]+1);
			//	printf("%s\n",grid[i]+1);
			}
		int ans = 0;
		for(int i=1;i<=8;i++)
			for(int j=1;j<=8;j++)
			{
				int count = 0;
				if(grid[i][j] == '*')
				for(int k=0;k<8;k++)
				{
					int xx = i+mv[k][0];
					int yy = j+mv[k][1];
					int cnt = 0;
					int flag = 0;
					while(avl(xx,yy))
					{
						if(grid[xx][yy]=='D')
						{
							flag = 1;
							break;
						}
						if(grid[xx][yy]=='*')
							break;
						xx += mv[k][0];
						yy += mv[k][1];
						cnt++;
					}
					if(flag == 1)
					{
						count += cnt;
					}
				}	
				if(count > ans)
					ans = count;
			}
		printf("Case %d: %d\n",tt,ans);
	}	
	return 0;
}
/*
********
********
********
***LD***
***DL***
********
********
********

********
******D*
**DLLL**
**DLLLLL
**DLD***
********
********
********

********
********
*DD*****
*DLLD***
****L***
**DDD***
********
********
 

*/
