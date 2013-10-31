#include<iostream>

#define N 2048
#define MAX 500000000
using namespace std;

int f[N][N], s[N][N];

int main()
{
    int n;
    int i, j, k, len;
    int num[N], sum[N];
    int ans;
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    sum[0] = 0;

    while (scanf("%d", &n) == 1 && n)
    {
        for (i=1; i<=n; i++)
            scanf("%d", &num[i]);
        for (i=n+1 ; i<2*n; i++)
            num[i] = num[i-n];
        n *= 2;

        for (i=1; i<=n; i++)
        {
            sum[i] = sum[i-1] + num[i];
            f[i][i] = 0;
            s[i][i] = i;
        }

        for (len=2; len<=n/2; len++)
            for (i=1; i<=n-len+1; i++)
            {

                j = i + len - 1;
                f[i][j] = MAX;

                for (k=s[i][j-1]; k<=s[i+1][j]; k++)
                    if (f[i][k-1]+f[k][j]+sum[j]-sum[i-1] < f[i][j])
                    {
                        f[i][j] = f[i][k-1]+f[k][j]+sum[j]-sum[i-1];
                        s[i][j] = k;
                    }
            }

        ans = f[1][n/2];
        for (i=2; i<=n/2; i++)
            ans = min(ans, f[i][i+n/2-1]);
        printf("%d\n", ans);
    }

    return 0;
}
