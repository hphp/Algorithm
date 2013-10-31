#include <stdio.h>
#include <string.h>
#define N 1100

char s[N][N];
int k;

int main()
{
	int tc;
	scanf("%d",&tc);
	int a,b;
	for(int tt = 1; tt <= tc ; tt++){
		
		scanf("%d%d",&a,&b);
		int row = 2*a+4;
		int size = 0;
		for(int i =0 ; i < row ; i ++)
		{
			gets(s[i]);
			size = strlen(s[i]);
		}
		printf("%d\n",size);
		size = (size+1)/(a+3);
		printf("%d\n",size);
		int nrow = 2*b+4;
		int ncol = size * (b+2);
		for(int i = 0 ; i < nrow; i ++)
			for(int j = 0;j<size; j++)
			{
				if(flag == 1)
					printf(" ");
				
			}
			
	}
	return 0;
}
