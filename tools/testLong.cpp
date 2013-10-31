#include <stdio.h>

int main(){
	long long a,b;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		printf("%lld\n",a*b);
		printf("%lld\n",a*b%1000000007);
		printf("%d\n",(int)((a*b)%1000000007));
	}
	return 0;
}
