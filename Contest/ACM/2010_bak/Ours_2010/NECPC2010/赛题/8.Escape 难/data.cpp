#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char s[4] = {'N', 'E', 'W', 'S'};
bool map[101][101];
int main()
{
    freopen("5.in", "w", stdout);
    srand(unsigned(time(NULL)));
    for(int i = 0; i <20; ++i)
    {   
        memset(map, false, sizeof(map));
        int n, m, k, d;
        n = abs(rand()) % 98 + 2;
        m = abs(rand()) % 98 + 2;
        int mod  = m * n < 100 ? m * n : 100;
        k = abs(rand()) % mod;
        d = abs(rand()) % 1000;
        printf("%d %d %d %d\n", n, m, k, d);
        while(k--)
        {
            int j = abs(rand()) % 4;
            int t = abs(rand()) % 10 + 1;
            int v = abs(rand()) % 10 + 1;
            int x, y;
            while(true)
            {
                x = abs(rand()) % n + 1;
                y = abs(rand()) % m + 1;
                if(!map[x][y])
                    break;
            }
            map[x][y] = true;
            printf("%c %d %d %d %d\n", s[j], t, v, x, y);
        }
    }
}
