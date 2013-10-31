#include <stdio.h>
#include <algorithm>
#define MAX 100000000000000000LL
#define N 10100000
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

typedef long long Int;
int n;

int main()
{
	int tc;
	scanf("%d",&tc);
	int tt = 1;
	while(tc--)
	{
		scanf("%d",&n);
		Int a = 0;
		Int mn  = MAX;
		Int mx  = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a);
			mx = Max(a,mx);
			mn = Min(a,mn);
		}
		printf("Case %d: %lld %lld\n",tt++,mx-mn,mx-mn+1);
	}
}
