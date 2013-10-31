#include <stdio.h>
#include <string.h>
#define MAGIC 987654321
#define HASH 70001

using namespace std;

int n, m;

struct node {
    int dp;
    int data[20];
    
    int hashcode () const {
        int re = 0;
        
        for (int i = 0; i < dp; i ++)
            re = (re * 4793 + data[i] + 508) % HASH;
        return re;
        }
    
    void add (int x) {
        int max = -1, i;
        for (i = 0; i < dp; i ++)
            max >?= data[i];
        if (x > max)
            x = max + 1;
        data[dp ++] = x;
        }
    
    void del () {
        int i, j, k;
        
        dp --;
        for (i = 0; i < dp; i ++)
            data[i] = - 1 - data[i + 1];
        k = 0;
        for (i = 0; i < dp; i ++)
            if (data[i] < 0) {
                for (j = i + 1; j < dp; j ++)
                    if (data[j] == data[i])
                        data[j] = k;
                data[i] = k ++;
                }
        }
    
    int good () {
        if (dp < m)
            return 0;
        
        int f = 1, i;
        
        for (i = 0; i < dp; i ++)
            if (data[i] > 0)
                f = 0;
        
        return (f || data[dp - 1] == dp - 1);
        }
    
    } hash[HASH], stack[HASH], cur, neo;
int dp[101][HASH];
int flag[HASH];
int next[HASH][20];
int hp;

bool operator == (const node& a, const node& b) {
    if (a.dp != b.dp)
        return 0;
    for (int i = 0; i < a.dp; i ++)
        if (a.data[i] != b.data[i])
            return 0;
    return 1;
    }

int place (const node& a) {
    int c = a.hashcode();
    
    while (flag[c] != -1 && !(a == hash[c])) {
        c ++;
        if (c == HASH)
            c = 0;
        }
    
    if (flag[c] != -1) {
        return flag[c];
        }
    
    stack[hp] = a;
    flag[c] = hp;
    hash[c] = a;
    hp ++;

    return flag[c];
    }

int main () {
    long long ans;
    int i, j, k, hq, c;
    
    freopen("bad.in", "r", stdin);
//    freopen("bad.out", "w", stdout);
    
    while (scanf("%d%d", &n, &m) , n > 0) {
        
        memset(flag, -1, sizeof(flag));
        if (n < m) {
            ans = 1;
            for (i = 0; i < n; i ++)
                ans = (ans * m) % MAGIC;
            }
        else
            if (m <= 2)
                ans = 0;
            else {
                cur.dp = 0;
                hp = 0;
                place(cur);
                memset(dp, 0, sizeof(dp));
                memset(next, -1, sizeof(next));
                dp[0][0] = 1;
                
                for (i = 0; i < n; i ++) {
                    hq = hp;
                    for (j = 0; j < hq; j ++) {
                        cur = stack[j];
                        for (k = 0; k < m; k ++) {
                            if (next[j][k] == -1) {
                                neo = cur;
                                neo.add(k);
                            
                                if (!neo.good()) {
                                    if (neo.dp == m)
                                        neo.del();
                                    c = place(neo);
                                    dp[i + 1][c] += dp[i][j];
                                    dp[i + 1][c] %= MAGIC;
                                    next[j][k] = c;
                                    }
                                else
                                    next[j][k] = -2;
                                }
                            else {
                                if (next[j][k] != -2) {
                                    c = next[j][k];
                                    dp[i + 1][c] += dp[i][j];
                                    dp[i + 1][c] %= MAGIC;
                                    }
                                }
                            }
                        }
                    }
                ans = 0;
                for (i = 0; i < hp; i ++)
                    ans = (ans + dp[n][i]) % MAGIC;
                }
        
        printf("%I64d\n", ans);
        }
    
    return 0;
    }
