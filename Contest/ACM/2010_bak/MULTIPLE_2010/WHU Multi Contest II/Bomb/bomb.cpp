#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long lt;

lt ans,N,T,dig[21],f[21][3];
int len;

int get_next_state(int cur_state , int d){
    if(cur_state == 0){
        if(d == 4)    return 1;
        return 0;
    }
    else if(cur_state == 1){
        if(d == 4)    return 1;
        else if(d == 9)   return 2;
        return 0;
    }
    else{
        return 2;
    }
}

int main(){
    freopen("bomb.in","r",stdin);
    freopen("bomb.out","w",stdout);
    int i,j,k,l;
    scanf("%I64d",&T);
    while(scanf("%I64d",&N)!=EOF){
        N++;
        lt temp = N;
        len = 0;
        while(temp){
            dig[++ len] = temp % 10;
            temp /= 10;
        }
        int cur_state = 0;
        k = 0;
        ans = 0;
        for(i = len;i >= 1;i --){
            ++ k;
            for(j = 0;j < dig[i];j ++){
                memset(f,0,sizeof(f));
                f[k][get_next_state(cur_state,j)] = 1;
                for(l = k + 1;l <= len;l ++){
                    f[l][0] = 9 * f[l-1][0] + 8 * f[l-1][1];
                    f[l][1] = f[l-1][0] + f[l-1][1];
                    f[l][2] = f[l-1][1] + 10 * f[l-1][2];
                }
                ans += f[len][2];
            }
            cur_state = get_next_state(cur_state , dig[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
