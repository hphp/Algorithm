#include <iostream>
#include <cmath>
using namespace std;
const int MOD = 1000000007;

int main()
{
    int n, m, t, ans;

    while(1 == scanf("%d", &n) && n)
    {
        ans = 1;
        m = n;
        t = (int) sqrt(1.0 * n);
        for(int i = 2;i <= t;++i)
        {
            if(m % i)
                continue;
            while(m % i == 0)
            {
                m /= i;
                if(m % i == 0)
                    ans *= i;
            }
            ans *= (i - 1);
            if(m == 1)
                break;
            t = (int) sqrt(1.0 * n);
        }
        if(m > 1)
            ans *= (m - 1);
        if(m == n)
            ans = n - 1;
        printf("%lld\n", ( (long long) n * (n - 1) / 2 - (long long) ans * n / 2) % MOD);
    }
}
