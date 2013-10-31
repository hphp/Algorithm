#include <stdio.h>
#include <string.h>
#define N 210
#define MAX (1<<20)
typedef int Int;
Int kind[N][N][N];

int n;
Int m;
int k;

Int dp(int n,int k,int most)
{
	if(k == 0 && n == 0)
		return 1;
	if(k == 0 && n != 0)
		return 0;
	if(kind[n][k][most] >= 0)
		return kind[n][k][most];
	Int sum =0;
	for(int j=2;j<=most&&j<=n;j++)
	{
		sum += dp(n-j,k-1,j);
		sum %= m;
	}
	kind[n][k][most] = sum;
	return sum;
}

int main()
{
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)	
	{
		Int sum =0;
		memset(kind,-1,sizeof(kind));
		if(n == k)
		{
			if(n%2==0){
				if(m != 1)
				  printf("1\n");
				else printf("0\n");
			}
			else printf("0\n");
			continue;
		}
		for(int i=1;i<n&&i<k;i+=2)
		{
			sum += dp(n-i,k-i,n-i);
			sum %= m;
		}
		printf("%d\n",sum);
	}
	return 0;
}
