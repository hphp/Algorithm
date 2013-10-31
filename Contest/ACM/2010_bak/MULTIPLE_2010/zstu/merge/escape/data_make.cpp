#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
	
	srand(unsigned(time(NULL)));
	freopen("data22.in","w",stdout);
	int n(100000),m(10);
	int i,j;
	printf("%d %d\n",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			printf("%d ",1);
		puts("");
	}
	for(i=0;i<m;i++)
		printf("1  ");
	puts("");
	return 0;
}
