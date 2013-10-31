#include <stdio.h>
#define MOD 1000000007

int power(int base,int exponent){

	if( exponent == 0 )
		return 1;

	int half_result = power( base , exponent/2 );

	int if_odd = exponent & 1 ;

	long long part_result = half_result * half_result % MOD;

	if(if_odd == 0)
		return (int)( part_result );
	else
		return (int)( part_result * ( base % MOD ) % MOD );
}

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		printf("%d\n",power(a,b));
	}
	return 0;
}
