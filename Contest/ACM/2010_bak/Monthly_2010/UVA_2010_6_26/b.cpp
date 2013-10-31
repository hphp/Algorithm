#include <stdio.h>

int main()
{
	int tc,n,k,p;
	scanf("%d",&tc);
	for(int tt = 1 ; tt <= tc; tt ++)
	{
		scanf("%d%d%d",&n,&k,&p);
		int ans = (p%n+k-1)%n + 1;
		printf("Case %d: %d\n",tt,ans);
	}
	return 0;
}
