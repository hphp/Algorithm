#include <stdio.h>
#define N 2000010
#define K 110
#define MAX 100000000000LL
#define Min(a,b) ((a)<(b)?(a):(b))

typedef __int64 Int;
Int s[N];
Int rmn[2][N];
int n,k,l;

int main()
{
	int test;
	int a;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d%d",&n,&k,&l);
		s[0] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			s[i] = s[i-1]+a;
		}
		Int tmp = MAX;
		Int mnmn = MAX;
		for(int i=1;i<=k;i++)
		{
			for(int j=0;j<i*l;j++)
				rmn[1][j] = rmn[1][j+l] = MAX;
			rmn[0][0] = 0;
			for(int j=i*l;j<=n;j++)
			{
				tmp = rmn[0][j] + i*s[j];
				if(tmp < mnmn)
					mnmn = tmp;
				rmn[1][j+l] = Min(rmn[1][j+l-1],tmp-(i+1)*s[j]);
			}
			for(int j=0;j<=n;j++)
				rmn[0][j] = rmn[1][j];
		}
		printf("%I64d\n",mnmn);
	}
}
