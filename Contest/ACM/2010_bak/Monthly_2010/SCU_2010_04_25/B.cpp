#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAX=1100000;
int flag[MAX]={0};
bool dp[MAX];
int main(){
	int sum=0,ans=1,N=1;
	//memset(flag,0,sizeof(flag));
	for(int i=1;;i++){
		ans=ans*i;
		if(ans>1000000) break;
		flag[i]=ans;
//		printf("%d\n",ans);
		N=i;
	}
	for(int i=0;i<MAX;i++)dp[i]=false;
	dp[0]=true;
	for(int i=1;i<=N;i++){
		for(int j=1000000-flag[i];j>=0;j--){
			if(dp[j]){
				dp[j+flag[i]]=true;	
			}
		}
	}
	dp[0]=false;
	int a;
	while(scanf("%d",&a)!=EOF){
		if(a<0) break;
		if(dp[a]) printf("YES\n");
		else printf("NO\n");	
	}
}

