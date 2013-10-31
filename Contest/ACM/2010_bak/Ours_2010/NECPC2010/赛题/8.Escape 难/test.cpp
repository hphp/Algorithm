#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#define INF 10000000
#define eps 1e-7
bool dp[2][101][101];
int dir[5][2] = {0, 1, 0, -1, 1, 0, -1, 0, 0, 0};

typedef struct
{
    int  t, v, id;
    char dir;
    bool isgun;
}Gun;
Gun gun[101][101];

typedef struct
{
    int t, v, x, y;
    char dir;
}Castle;
Castle cas[101];

typedef struct
{
    int id[4];
    int l;
}Reach;
Reach reach[101][101];

void init()
{
    for(int i = 0; i < 101; ++i)
        for(int j = 0; j < 101; ++j)
            gun[i][j].isgun = false, reach[i][j].l = 0;
    memset(dp, false, sizeof(dp));
}

bool cal_reach(int m, int n)
{   
    
    for(int i = 0; i <= m; ++i)
        for(int j = 0; j <= n; ++j)
        {   
            if(gun[i][j].isgun) continue;
            for(int k = 0; k < 4; ++k)
            {   
                int x = i, y = j;
                while(1)
                {
                    x = x + dir[k][0];
                    y = y + dir[k][1];
                    if(x < 0 || y < 0 || x > m || y > n)  // 超出坐标范围 
                        break;
                    if(gun[x][y].isgun)                 // 遇到了该方向上的第一个碉堡 
                    {   
                        if(k == 0 && gun[x][y].dir == 'W')
                            reach[i][j].id[reach[i][j].l++] = gun[x][y].id;
                        if(k == 1 && gun[x][y].dir == 'E')
                            reach[i][j].id[reach[i][j].l++] = gun[x][y].id;
                        if(k == 2 && gun[x][y].dir == 'N')
                            reach[i][j].id[reach[i][j].l++] = gun[x][y].id;
                        if(k == 3 && gun[x][y].dir == 'S')
                            reach[i][j].id[reach[i][j].l++] = gun[x][y].id;
                        break;
                    }
                }
            }
        }
    //for(int i = 0; i <= m; ++i)
    //    for(int j = 0; j <= n; ++j)
    //     printf("i = %d j = %d l = %d\n", i, j, reach[i][j].l);
}
bool ok(int x, int y, int m, int n)
{
    if(x >= 0 && x <= m && y >= 0 && y <= n && !(gun[x][y].isgun))
        return true;
    return false;
}

bool can(int t, int x, int y)
{   
    int cnt = 0;
    for(int i = 0; i < reach[x][y].l; ++i)
    {   
        int id = reach[x][y].id[i];
        double d = (abs(x - cas[id].x) + abs(y - cas[id].y)) * 1.0;
        double v = cas[id].v * 1.0;
        double tt = d / v;
        //printf("tt = %.3lf\n", tt);
        if(fabs(tt - (int)tt) > eps)
            cnt++;
        else
        {
            int tx = (int)tt;
            
            if(!(t >= tx && (t - tx) % cas[id].t == 0))
                cnt++;
        }
    }
    if(cnt == reach[x][y].l) return true;
    return false;
}
int main()
{
    int n, m, k, d;
    freopen("in.in", "r", stdin);
    freopen("test.out", "w", stdout);
    //int nowt = clock();
    while(scanf("%d%d%d%d", &m, &n, &k, &d) != EOF)
    {   
		init();
        getchar();
        for(int i = 0; i < k; ++i)
        {   
            char ch;
            int x, y, t, v;
            scanf("%c%d%d%d%d", &ch, &t, &v, &x, &y);
            getchar();
            cas[i].dir = ch;
            cas[i].x = x;
            cas[i].y = y;
            cas[i].t = t;
            cas[i].v = v;
            gun[x][y].isgun = true;
            gun[x][y].dir = ch;
            gun[x][y].t = t;
            gun[x][y].v = v;
            gun[x][y].id = i;
        }
        cal_reach(m, n);
        dp[0][0][0] = true;
        int now = 1, next = 0;
        int ans = INF;
        bool flag = false;
        for(int t = 1; t <= d && !flag; ++t)
        {
            now = !now;
            next = !now;
            for(int i = 0; i <= m && !flag; ++i)
                for(int j = 0; j <= n && !flag; ++j)
                    if(dp[now][i][j])
                    {
                           for(int k = 0; k < 5; ++k)
                           {
                                int x = i + dir[k][0];
                                int y = j + dir[k][1];
                                if(ok(x, y, m, n) && can(t, x, y))
                                {   
                                    //printf("t = %d x = %d y = %d\n", t, x, y);
                                    dp[next][x][y] = true;
                                    if(x == m && y == n)
                                    {
                                        flag = true;
                                        ans = t;
                                        break;
                                    }
                                }
                           }
                    }
        }
        if(flag) printf("%d\n", ans);
        else printf("Bad luck!\n");
    }
    //printf("%dms\n", clock() - nowt);
}
