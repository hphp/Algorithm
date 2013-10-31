#include <stdio.h>
#define N 1000000
bool np[N];
int main()
{
	for(int i=2;i<N;i++)
	{
		if(!np[i])
			for(int j=2;j*i<N;j++)
				np[i*j] = 1;
	}
	int cnt =0;
	for(int i=2;i<N;i++)
		if(!np[i])
			cnt++;
	printf("%d\n",cnt);
}
