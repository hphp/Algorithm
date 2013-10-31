#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{   
    int pre[200];
    int d[200];
    int x, k; 
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int now = clock();
    while(scanf("%d %d", &x, &k) != EOF)
    {
        int l = 199;
        memset(pre, 0, sizeof(pre));
        pre[199] = x;
        int p = 0;
        while(1)
        {
            d[l] = (pre[l] * x + p) % 10;
            p = ((pre[l] * x) + p) / 10;
            if(d[l] == x && p == 0)
                break;
            pre[l - 1] = d[l];
            l--;
        }
        for(int i = 1; i <= k; ++i)
        {
            for(int j = l; j < 200; ++j)
                printf("%d", pre[j]);
        }
        printf("\n");
    }
    //printf("%dms\n", clock() - now);
}
