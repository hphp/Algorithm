#include <stdio.h>

int times(int n,int m){
	if(m<0)return 0;
	int ans = 1;
	for(int i = 0 ;i < m ; i++)
		ans *= n;
	return ans;
}

int main(){
	int n , m ;
	while(scanf("%d%d",&n,&m)!=EOF){
		int sum = (n-n/2)*(times(n,m-1)-n/2*(times(n,m-2)-times(n-n/2,m-2)));
		printf("%d\n",sum);
	}
	return 0;
}
