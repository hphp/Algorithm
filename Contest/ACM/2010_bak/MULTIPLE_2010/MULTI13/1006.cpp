#include <stdio.h>

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int tt = 1; tt <= tc ; tt++)	{
		int n,m,k,a;
		scanf("%d%d%d",&n,&m,&k);
		double sum = 0 ;
		for(int i =0 ;i < n ;i ++){
			scanf("%d",&a);
			sum += a;
		}
		sum *= m;
		sum /= n;
		printf("Case %d: %.5lf\n",tt,sum);
	}
	return 0;
}
