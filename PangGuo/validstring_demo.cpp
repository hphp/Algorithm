#include <stdio.h>

int times(int n,int m){
	int ans = 1;
	for(int i = 0 ;i < m ; i++)
		ans *= n;
	return ans;
}

int main(){
	int n , m ;
	while(scanf("%d%d",&n,&m)!=EOF){
		int sum = 0;
		sum = times(n,m) - (n/2)*times(n,m-1);
		int part = (n-n/2)*times(n/2,2);
		int part2 = 0;
		for(int i = m -3 ; i >=0 ; i --){
			part2 += times(n,i)*times(n-n/2,m-3-i);
		}
		printf("%d\n",sum-part*part2);
	}
	return 0;
}
