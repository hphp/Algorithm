#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 105
#define INF 1 << 28
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)

//#define _DEBUG
//#define _TIME

inline int ABS(int x)
{
    return x > 0 ? x:-x;
}

int matchx[N], matchy[N], x[N], y[N];
int lx[N], ly[N], g[N][N];

bool dfs(int u, int n)
{
    x[u] = 1;
    for(int i = 1; i <= n; i++)
    {
        int wt = lx[u] + ly[i] - g[u][i];
        if(!y[i] && !wt)
        {
            y[i] = 1;
            if(matchx[i] == -1 || dfs(matchx[i], n))
            {
                matchx[i] = u;
                matchy[u] = i;
                return 1;
            }
        }
    }
    return 0;
}

int KM(int n)
{
    memset(ly, 0, sizeof(ly));
    memset(matchx, -1, sizeof(matchx));
    for(int i = 1; i <= n; i++)
    {
        lx[i] = -INF;
        for(int j = 1; j <= n; j++)
            lx[i] = MAX(lx[i], g[i][j]);
    }
    for(int k = 1; k <= n; k++)
    {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        while(!dfs(k, n))
        {
            int d = INF;
            for(int i = 1; i <= n; i++)
                if(x[i])
                    for(int j = 1; j <= n; j++)
                        if(!y[j])
                            d = MIN(d, lx[i] + ly[j] - g[i][j]);
            for(int i = 1; i <= n; i++)
            {
                if(x[i]) lx[i] -= d, x[i] = 0;
                if(y[i]) ly[i] += d, y[i] = 0;
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++)
        sum += g[matchx[i]][i];
    return sum;
}

int main()
{
	#ifdef _DEBUG
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	#ifdef _TIME
		clock_t timeStart, timeEnd;
		timeStart = clock();
	#endif
    int cas = 1, t, n, m, b[N][N];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
            {
                scanf("%d", &b[i][j]);
            }
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                g[i][j] = 0;
                for(int k = 1; k <= m; k++)
                {
                    g[i][j] -= ABS(b[k][i] - j);
                }
            }
        }
        int ans = -KM(n);
        printf("Case #%d: %d\n", cas++, ans);
        //for(int i = 1; i <= n; i++)
//        {
//        	printf("%d", matchy[i]);
//        	if(i != n) printf(" ");
//        	else printf("\n");
//		}
    }
    #ifdef _TIME
    	timeEnd = clock();
    	double timeDuration = (double)(timeEnd - timeStart) / CLOCKS_PER_SEC;
    	printf("Time cost = %lf\n", timeDuration);
    #endif
    return 0;
}
