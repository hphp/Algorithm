#include <stdio.h>

int main(){
	int a;
	while(scanf("%d",&a)!=EOF){
		int t = a&1;
		if (t == 0)
			printf("even\n");
		else printf("odd:%d\n",t);
	}
	return 0;
}
