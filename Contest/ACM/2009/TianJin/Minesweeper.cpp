#include <stdio.h>
#define N 110
#define avl(x,y) ((x)>=0&&(x)<n&&(y)>=0&&(y)<m?1:0)
char s[N][N];
int n,m;
int mv[8][2] = 
{
	{-1,-1},{-1,0},{-1,1},
	{0,-1},{0,1},
	{1,-1},{1,0},{1,1}
};



int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		for(int i=0;i<n;i++)
			scanf("%s",s[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(s[i][j] == '.')
				{
					int sum =0;
					for(int k=0;k<8;k++)
					{
						int ii = i + mv[k][0];
						int jj = j + mv[k][1];
						if(avl(ii,jj))
						{
							sum += ((s[ii][jj] == '*')?1:0);
						}
					}
					s[i][j] = '0' + sum;
				}
			}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%c",s[i][j]);
				printf("\n");
		}
	}
	return 0;
}
/*
13:50
13:59

*/
