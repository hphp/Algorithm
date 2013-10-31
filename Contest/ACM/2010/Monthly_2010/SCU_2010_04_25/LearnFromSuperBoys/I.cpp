#include<iostream>
#define MAXN 52000
using namespace std;
int cost[MAXN],gas[MAXN];
int ans_sum,res_sum,n;
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		ans_sum=res_sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&gas[i]);
			ans_sum+=gas[i];
		}
		for(int i=0;i<n;i++){
			scanf("%d",&cost[i]);
			res_sum+=cost[i];	
		}
		if(res_sum<=ans_sum)printf("YES\n");
		else printf("NO\n");
	}
}
