#include <stdio.h>
#define MOD 1000000007
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d\n",(a-b)%1000000007);
		printf("%d\n",(a+MOD-b)%1000000007);
	}
	return 0;
}

