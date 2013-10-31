#include <stdio.h>
#define MAGIC 987654321

int n, m;

int main () {
    long long ans, i;
    
    freopen("good.in", "r", stdin);
//    freopen("good.out", "w", stdout);
    
    while (scanf("%d%d", &n, &m) , n > 0) {
        if (m <= 2 || n < m) {
            ans = 1;
            for (i = 0; i < n; i ++)
                ans = (ans * m) % MAGIC;
            }
        else {
            ans = 1;
            for (i = 1; i <= m; i ++)
                ans = (ans * i) % MAGIC;
            ans = (ans + m) % MAGIC;
            }
        printf("%I64d\n", ans);
        }
    
    return 0;
    }
