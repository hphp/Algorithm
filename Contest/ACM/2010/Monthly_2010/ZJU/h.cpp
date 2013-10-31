#include <stdio.h>
#define N 100000

char grid[10][N];
int n;

int main()
{
	int test;
	scanf("%d",&test);
	int tt=1;
	while(test--)
	{
		scanf("%d",&n);
		int column = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<5;j++)	
			{
				char s[4];
				scanf("%s",s);
				int tmp1=0,tmp2=0;
				if(s[0]>='A'&&s[0]<='Z')
				{
					tmp1=s[0]-'A'+10;
				}
				else tmp1 = s[0]-'0';
				tmp1 = tmp1*16;
				if(s[1]>='A'&&s[1]<'Z')
				{
					tmp2=s[1]-'A'+10;
				}
				else tmp2 = s[1]-'0';
				int tmp = tmp1+tmp2;
				for(int k=0;k<7;k++)
				{
					if(tmp&(1<<k))
					{
						grid[k][column]='#';
			//			printf("%d %c\n",column,grid[k][column]);
					}
					else grid[k][column]=' ';
				}
				column++;
			}
			if(i!=n-1)
			{
			for(int k=0;k<7;k++)
			{
				grid[k][column]=' ';
			}
			column++;
			}
		}
//		printf("%d\n",column);
		for(int k=0;k<7;k++)
		grid[k][column]='\0';
		printf("Case %d:\n",tt++);
printf("\n");
		for(int i=0;i<7;i++)
			printf("%s\n",grid[i]);
printf("\n");
	}
	return 0;
}

