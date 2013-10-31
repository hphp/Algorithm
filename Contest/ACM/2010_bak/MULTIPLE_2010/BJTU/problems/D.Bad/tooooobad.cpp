#include <stdio.h>
#include <string.h>
#define MAGIC 987654321

using namespace std;

int n, m;
int per[1001][1001], rep[1001][1001];
int fac[1001], pow[1001];
int count[1001];

int main () {
    long long ans;
    int i, j, k, tmp;
    
//    freopen("bad.in", "r", stdin);
//    freopen("tooooobad.out", "w", stdout);
    
    fac[0] = 1;
    for (i = 1; i <= 1000; i ++)
        fac[i] = fac[i - 1] * (long long)i % MAGIC;
    
    while (scanf("%d%d", &n, &m) > 0) {
        
        if (m == 1)
            ans = 0;
        else {
            pow[0] = 1;
            for (i = 1; i <= n; i ++)
                pow[i] = pow[i - 1] * (long long)m % MAGIC;
   
            for (j = 1; j <= n; j ++) {
                tmp = 0;
                for (i = 0; i <= n; i ++) {
                    per[i][j] = rep[i][j] = 0;
                    tmp = (tmp * (long long) m) % MAGIC;
                    if (j == 1 && i == m)
                        tmp = (tmp + 1) % MAGIC;
                    if (j > 1 && i >= m)
                        tmp = (tmp + per[i - m][j - 1] + (long long)rep[i - m][j - 1]) % MAGIC;
                    for (k = (0 >? i - m + 1); k < i; k ++) {
                        //Per after Per
                        per[i][j] = (per[i][j] + per[k][j - 1] * (long long)fac[i - k]) % MAGIC;
                        //Per after Rep
                        if (k == i - m + 1)
                            per[i][j] = (per[i][j] + rep[k][j - 1] * (long long) fac[m - 1]) % MAGIC;
                        //Rep after Per
                        if (k == i - m + 1)
                            rep[i][j] = (rep[i][j] + per[k][j - 1]) % MAGIC;
                        //Rep after Rep
                        if (k >= i - m + 1)
                            rep[i][j] = (rep[i][j] + rep[k][j - 1]) % MAGIC;
                        }
                    //Per after Space
                    per[i][j] = (per[i][j] + tmp * (long long) fac[m]) % MAGIC;
                    //Rep after Space
                    rep[i][j] = (rep[i][j] + tmp * (long long) m) % MAGIC;
                    }
                }
            memset(count, 0, sizeof(count));
            for (i = 0; i <= n; i ++)
                 for (j = 0; j <= n; j ++)
                     count[j] = (count[j] + (per[i][j] + rep[i][j]) * (long long) pow[n - i]) % MAGIC;
            count[0] = pow[n];
                
            ans = 0;
            for (i = 0; i <= n; i ++)
                if (i & 1)
                    ans = (ans + MAGIC - count[i]) % MAGIC;
                else
                    ans = (ans + count[i]) % MAGIC;
            }
        
        printf("%I64d\n", ans);
        }
    
    return 0;
    }
