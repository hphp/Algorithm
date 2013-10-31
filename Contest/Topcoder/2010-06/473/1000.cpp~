#include <stdio.h>
#define N 10100000
	int use[N];
int main()
{
	freopen("out.out","w",stdout);
	for(int i=1;i<N;i++)
	{
		int cur = i;
		int sum =0;
		while(cur)
		{
			sum += cur%10;
			cur/=10;	
		}
		if(i % sum ==0)
		use[i/sum] = 1;
	}
	int cnt =0;
	for(int i=1;i<N;i++)
		if(use[i] == 1)
		{
			printf("%d ",i);
			cnt ++;
			if(cnt%20 == 0)
			printf("\n");
		}
		printf("\n%d\n",cnt);
}
