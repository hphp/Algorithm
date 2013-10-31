#include <cstdio>

const int N = 18;
const int SIZE = 256;
const int INF = 1<<29;

int f[N][1<<N];
int map[SIZE][SIZE];
int idx[SIZE][SIZE];
int dis[N+2][N+2];
int X[N], Y[N];
int getHP[N];
int m, n, startHP, tot;

int q[SIZE*SIZE];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void BFS(int x, int y, int d[N]){
    bool visit[SIZE][SIZE]={};
    int front = 0, rear = 0, r = 0, dist = -1;
    for (int i = 0; i < tot; ++i) d[i] = INF;
    visit[x][y] = 1;
    q[rear++] = (x<<10)+y;
    while (front != rear){
        if (front == r) ++dist, r = rear;
        x = q[front]>>10;
        y = q[front]&((1<<10)-1);
        ++front;
        if (idx[x][y] != -1) d[idx[x][y]] = dist;
        if (x == 0 && y == 0) d[tot-2] = dist;
        if (x == m-1 && y == n-1) d[tot-1] = dist;
        for (int k = 0; k < 4; ++k){
            int xx = x+dx[k], yy = y+dy[k];
            if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
            if (visit[xx][yy] || map[xx][yy] < 0) continue;
            visit[xx][yy] = 1;
            q[rear++] = (xx<<10)+yy;
        }
    }
}
int main()
{
   // freopen("xxxx.in", "r", stdin);
    //freopen("xxxx.out", "w",stdout);
    while (scanf("%d %d", &m, &n) == 2){
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j){
                scanf("%d", &map[i][j]);
            }
        startHP = map[0][0];
        map[0][0] = 0;
        tot = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (map[i][j] > 0){
                    X[tot] = i, Y[tot] = j, getHP[tot] = map[i][j];
                    idx[i][j] = tot++;
                }
                else idx[i][j] = -1;
        X[tot] = 0, Y[tot] = 0;
        if (idx[0][0] == -1) idx[0][0] = tot;
        ++tot;
        X[tot] = m-1, Y[tot] = n-1;
        if (idx[m-1][n-1] == -1) idx[m-1][n-1] = tot;
        ++tot;
        for (int i = 0; i < tot; ++i) BFS(X[i], Y[i], dis[i]);
        tot-=2;
        int max = 1<<tot;
        for (int i = 0; i < tot; ++i)
            for (int j = 0; j < max; ++j)
                f[i][j] = -1;
        for (int i = 0; i < tot; ++i)
            if (startHP >= dis[tot][i])
                f[i][1<<i] = startHP-dis[tot][i]+getHP[i];
        int ans = -1;
        if (ans < startHP - dis[tot][tot+1]) ans = startHP-dis[tot][tot+1];
        for (int k = 0; k < max; ++k)
            for (int i = 0; i < tot; ++i){
                if (f[i][k] < 0) continue;
                int tmp = f[i][k] - dis[i][tot+1];
                if (tmp > ans) ans = tmp;
                for (int j = 0, test = 1; j < tot; ++j, test <<= 1){
                    if (k & test) continue;
                    if (f[i][k] - dis[i][j] >= 0 && f[j][k|test] < f[i][k]-dis[i][j]+getHP[j])
                        f[j][k|test] = f[i][k]-dis[i][j]+getHP[j];
                }
            }
        if (ans == -1) puts("you loss!");
        else printf("%d\n", ans);
    }
    return 0;
}

