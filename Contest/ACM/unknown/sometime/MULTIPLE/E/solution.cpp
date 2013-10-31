#include<iostream>
using namespace std;
int dp[2][1010];
char text[1000010],key[1010];
int main(){
    int i,j,now,ans,lim,last;
    while(~scanf("%s",&text[1])){
        scanf("%s%d",&key[1],&lim);
        int ll=lim;
        for(dp[0][0]=0,i=1;key[i];i++)
            dp[0][i]=i;
        now=1;ans=last=lim+1;
        for(i=1;text[i];i++,now^=1){
            dp[now][0]=0;
            for(j=1;j<last;j++)
                if(key[j]==text[i])dp[now][j]=dp[now^1][j-1];
                else dp[now][j]=1+min(min(dp[now^1][j-1],dp[now^1][j]),dp[now][j-1]);
            if(key[last]==text[i])dp[now][last]=dp[now^1][last-1];
            else dp[now][last]=1+min(dp[now^1][last-1],dp[now][last-1]);
            while(dp[now][last]>lim)last--;
            if(!key[last+1]){
                if(dp[now][last]<ans)ans=dp[now][last];
                if(ans<lim)lim=ans;
            }else last++;
        }
        if(ans>ll)ans=-1;
        printf("%d\n",ans);
    }
} 
