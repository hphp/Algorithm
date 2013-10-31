#include <stdio.h>
typedef __int64 Int;
int main()
{
	int test;
	scanf("%d",&test);
	int tt = 1;
	while(test--){
		int n,a,b;
		scanf("%d",&n);
		Int suma = 0 , sumb = 0;
		Int sum = 0 ;
		for(int i = 0 ;i < n ; i ++){
			scanf("%d%d",&a,&b);
			sum += a*sumb;
			sum += b*suma;
			sumb += b;
			suma += a;	
		}
		printf("Case %d: %I64d\n",tt++,sum);
	}	
}
