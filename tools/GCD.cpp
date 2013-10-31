#include <stdio.h>

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

int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		int A = a>b?a:b;
		int B = a<b?a:b;
		printf("%d\n",GCD(A,B));
	}
	return 0;
}
