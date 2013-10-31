#include <stdio.h>
#include <iostream>
#define MOD 1000000007


using namespace std;

long long power(int a,int b){
	if(b==0)
		return 1;
	long long t = power(a,b/2);
	int tt = b&1;
	if(tt == 0)
		return (t*t%MOD);
	else return (t*t%MOD*a)%MOD;
}

int validstring(int n,int m) {
	long long ans = 1;
	ans = ( (n-n/2) % MOD) * ( ( power(n,m-2) * (n-n/2) % MOD + n/2 * power(n-n/2,m-2) % MOD ) % MOD ) % MOD;
	return (int)ans;
}

int main(){
	cout << validstring(2,2) << endl;
	cout << validstring(2,3) << endl;
	cout << validstring(3,3) << endl;
	cout << validstring(4,4) << endl;
	cout << validstring(5,5) << endl;
	cout << validstring(40000,40000) << endl;
	cout << validstring(1000000000,1000000000) << endl;
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		cout << validstring(a,b) << endl;
	}
	return 0;
}
