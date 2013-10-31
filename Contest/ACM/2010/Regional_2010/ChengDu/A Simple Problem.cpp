#include <stdio.h>
#include <string.h>
#define N 110
#define abss(a) ((a)<0?(-(a)):(a))
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
#define MAX (1<<28)
int mn[N][10][10];

int main()
{
	char s[110];
	
	while(scanf("%s",s+1)!=EOF)
	{
		int size = strlen(s+1);
		for(int i=0;i<=size;i++)
			for(int j=0;j<10;j++)
				for(int k=0;k<10;k++)
					mn[i][j][k] = MAX;
		mn[0][4][5] = 0;
		for(int i=1;i<=size;i++)
		{
			int cur = (s[i]-'0'+10-1)%10;
			for(int j=cur+1;j<10;j++)// l: cur
			{
				for(int k=0;k<10;k++)
					for(int m=k+1;m<10;m++)
					{
						mn[i][cur][j] = Min(mn[i][cur][j],mn[i-1][k][m] + Max(abss(cur-k)+1,abss(m-j)));
						if(mn[i][cur][j] < MAX);
			//			printf(";%d %d %d;",cur,j,mn[i][cur][j]);
					}
			}
			for(int j=0;j<cur;j++)
			{
				for(int k=0;k<10;k++)
					for(int m=k+1;m<10;m++)
					{
						mn[i][j][cur] = Min(mn[i][j][cur],mn[i-1][k][m] + Max(abss(j-k),abss(cur-m)+1));
						if(mn[i][j][cur] < MAX);
			//			printf(";%d %d %d;",j,cur,mn[i][j][cur]);
					}
			}
	/*		for(int j=cur+1;j<10;j++)
			{
				if(mn[i][cur][j] < MAX)
						printf(";%d %d %d;",cur,j,mn[i][cur][j]);
			}
			printf("\n");
			for(int j=0;j<cur;j++)
			{
				if(mn[i][j][cur] < MAX)
						printf(";%d %d %d;",j,cur,mn[i][j][cur]);
			}
			printf("\n\n");*/
		}
		int mnmn = MAX;
		int cur = (s[size]-'0'+10-1)%10;
		for(int i=cur+1;i<10;i++)
		{
			mnmn = Min(mnmn,mn[size][cur][i]);
		}
		for(int i=0;i<cur;i++)
		{
			mnmn = Min(mnmn,mn[size][i][cur]);
		}
		printf("%d\n",mnmn);
	}
}
