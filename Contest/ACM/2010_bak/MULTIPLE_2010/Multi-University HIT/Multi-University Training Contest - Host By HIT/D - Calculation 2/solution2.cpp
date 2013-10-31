#include <cstdio>
struct factor
{
    int num,time;
}factor[50];

int power(int a,int n)
{
    int pow = 1, i;
    for (i = 0;i < n;i++)  pow *= a;
    return pow;
}

int main()
{
    int m, i, j, k, status;
    long long n, ans;
    while (scanf("%lld", &n) == 1 && n)
    {
        for (i = 0;i < 50;i++)
            factor[i].num = factor[i].time = 0;
        m = n;
        status = j = 0;
        ans = 1;
        for (i = 2;i * i <= n;i++)
        {
            status = 0;
            if (m % i == 0)
            {
                factor[j].num = i;
                status = 1;
            }
            while (m % i == 0)
            {
                factor[j].time++;
                m /= i;
            }
            if (status == 1)  j++;
            if (m == 1)  break;
        }
        if (m == n)
        {
            ans = n * (n - 1);
            ans >>= 1;
            printf("%lld\n", (n * (n - 1) / 2 - ans) % 1000000007);
            continue;
        }
        if (m > 1 && m < n)
        {
            factor[j].num = m;
            factor[j].time = 1;
            j++;
        }
        for (k = 0;k < j;k++)
            ans *= (power(factor[k].num,factor[k].time - 1) * (factor[k].num - 1));
        ans *= n;
        ans >>= 1;
        printf("%lld\n", (n * (n - 1) / 2 - ans) % 1000000007);
    }
    return 0;
}
