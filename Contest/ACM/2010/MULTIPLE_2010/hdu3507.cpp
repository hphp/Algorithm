#include <stdio.h>

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i =1 ;i <= n; i ++){
			scanf("%d",&a[i]);
			sum[i] = a[i]+sum[i-1];
		}
		for(int i = 1; i <=n ; i ++){
			mn[i] = mnn[i] = MAX;
			}
		mn[0] = mnn[0] = 0;
		for(int i = 1 ;i <=n ; i ++){
			mn[i] = mnn[i-1] + sum[i]*sum[i] + m;	
			mnn[i] = Min(mn[i],mnn[i-1]);
		}
		
	}	
}
