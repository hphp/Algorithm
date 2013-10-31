#include <stdio.h>
#define N 11000

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int cnt = 0;
	for(int i=1;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if((i+j)%2==1 && (i+j)%3==0)
			{
//				printf("%d %d\n",i,j);
				cnt ++;
			}
		}	
	}	
	printf("%d\n",cnt);
	return 0;
}
