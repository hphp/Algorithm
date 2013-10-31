#include <stdio.h>
#include <iostream>
#define MOD 1000000007
using namespace std;

long long power(int base,int exponent){

	if( exponent == 0 )
		return 1;

	long long half_result = power( base , exponent/2 );

	int if_odd = exponent & 1 ;

	long long part_result = half_result * half_result % MOD;

	if(if_odd == 0)
		return ( part_result );
	else
		return ( part_result * ( base % MOD ) % MOD );
}

int validstring(int n,int m) {
	long long ans = 1;
	ans = ( (n-n/2) % MOD) * ( ( power(n,m-2) * (n-n/2) % MOD + n/2 * power(n-n/2,m-2) % MOD ) % MOD ) % MOD;
	return (int)ans;
}

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
		cout << validstring(a,b) << endl;
		//cout << "a:" << a << " b:" << b << " res:" << validstring(a,b) << endl;		
	return 0;
}
