#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int GCD(int A,int B){
	int a = A>B?A:B;
	int b = A<B?A:B;	
	int r = 0;
	while( ( r = a%b ) != 0){
		a = b;
		b = r;
	}
	return b;
}

bool can(int a,int b,int c){
	int gcd = GCD(a,b);
	if( c % gcd == 0 )
		return true;
	else return false;
}

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
	cout << can(1,1,2) << endl;
	cout << can(7,5,3) << endl;
	cout << can(100,100,10) << endl;
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。                                               
