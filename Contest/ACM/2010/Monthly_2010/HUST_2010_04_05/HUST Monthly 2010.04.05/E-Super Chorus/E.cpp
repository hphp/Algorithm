#include <cstdio>
#include <cstring>
#define Max(a,b) ((a)>(b)?(a):(b))
#define M 3001
int a[M],dp[M];

int main()
{
//    freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
    int n;
    while(scanf("%d", &n) != EOF) {
        int x;
        for(int i = 1; i <= n; i ++) {
            scanf("%d%d", a + i, &x);
            a[i] = (a[i] << 1) + x;
        }
        memset(dp, 0, sizeof(dp));
        int maxleft = 0;
        for(int i = n; i; i --) {
            for(int j = 1, k = 0; j <= i; j ++){
                if(a[i] >> 1 > a[j] >> 1 && k < dp[j]) {
                    k = dp[j];
                }
                else if(a[i] == a[j] && dp[j] < k + 1){
                    dp[j] = k +1;
                    maxleft = Max(maxleft, dp[j] * 2 - (i == j));
                }
            }
        }
        printf("%d\n", maxleft);
    }
}
