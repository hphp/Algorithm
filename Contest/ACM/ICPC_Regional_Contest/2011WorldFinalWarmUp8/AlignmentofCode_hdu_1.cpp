#include <stdio.h>
#include<string.h>

#define S 1010
#define N 200

char word[S][N][100];
int wn[S];
char s[S];
int start[N];

int main()
{
	int tc;
	scanf("%d",&tc);
	getchar();
	while(tc--)
	{
		int no = 0;
		while(gets(s))
		{
			if(strcmp(s,"@") == 0)
				break;
			int size = strlen(s);
			int c = 0;
			while((s[c] == ' ') && (c < size))c++;
			int flag = 0 , cnt = 0;
			int nn = 0;
			while(1)
			{
				if(c == size)
				{
					word[no][nn][cnt] = '\0';
					nn++;
					cnt = 0;
					flag = 0;
					break;
				}
				else if(c > size)
				{
					break;
				}
				if(flag == 0)
				{
					word[no][nn][cnt] = s[c];
					cnt ++;
					c ++;
				}
				else if(flag == 1)
				{
					word[no][nn][cnt] = '\0';
					nn++;
					cnt = 0;
					flag = 0;
				}
				while((s[c] == ' ') && (c < size))
				{
					c ++;
					flag = 1;
				}
			}
			wn[no] = nn;
			no ++;
		}
		int mx = 0;
		for(int i =0 ; i < no ; i ++)
		{
	//		printf("%d ",wn[i]);
			if(mx < wn[i])
				mx = wn[i];
		}
		//printf("%d %d\n",no,mx);
		start[0] = 0;
		for(int i =1 ;i < mx; i ++)
		{
			int mxx = 0;
			for(int j=0 ;j < no ;j ++)
			{
				if(wn[j] < i)continue;
//				printf("%d %d :: " , wn[j],i);
				if(mxx < strlen(word[j][i-1]))
					mxx = strlen(word[j][i-1]);
	//				printf("%d ",mxx);
			}
		//	printf("\n");
			start[i] = start[i-1] + mxx + 1;
			//printf("%d \n",start[i]);
		}
		for(int jj = 0 ; jj < no ; jj ++)
		{
			bool ff = 0;
			int nn = wn[jj];
			for(int i = 0 ; i < nn ; i ++)
			{
				ff = 1;
				printf("%s",word[jj][i]);
				if(i == nn-1);
				else
				{
					int sn = start[i+1]-start[i]-strlen(word[jj][i]);
					for(int kk=0;kk<sn;kk++)
						printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
/*
2011-01-22
13:57 - 15:17
-15:31 Accepted.
*/
