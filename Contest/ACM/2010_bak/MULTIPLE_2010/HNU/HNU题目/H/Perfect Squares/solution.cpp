#include<stdio.h>

const int mod = 10007;
const int inv = 3336;
int t[50];

//tpow(n) return 2^n % mod
int tpow(int n)
{
    int i = 0, ans = 1;
    while(n)
    {
        if(n % 2 == 1)
            ans = (ans * t[i]) % mod;
        i ++;
        n >>= 1;
    }
    
    return ans;
}
int main()
{
    t[0] = 2;
    int i, test, n, ans;
    for(i = 1; i < 32; i ++)
        t[i] = (t[i - 1] * t[i - 1]) % mod;
    scanf("%d", &test);
    for(i = 1; i <= test; i ++)
    {
        scanf("%d\n", &n);
        if(n % 2 == 1)
            ans = (tpow(n - 1) + 5) * 3336;
        else
            ans = (tpow(n - 1) + 4) * 3336;
        
        printf("Case #%d: %d\n", i, ans % mod);
    }
    return 0;
}
