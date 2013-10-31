#include <cstdio>

const int M = 7;
const int N = 8;
const int MAX = 20;

char arr[M][N+1];
int cnt;
int X[MAX], Y[MAX];
char D[MAX];

int dx[4]={-1,0,0,1};
int dy[4]={0,-1,1,0};
char dir[]="ULRD";

inline bool out(int x, int y){
    return x < 0 || x >= M || y < 0 || y >= N;
}

bool Dfs(int dep){
    if (dep == cnt){
        for (int i = 0; i < cnt; ++i) printf("%d %d %c\n", X[i], Y[i], D[i]);
        return 1;
    }
    int x, y, hit, xx, yy;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            if (arr[i][j] == 'O'){
                arr[i][j] = 'X';
                for (int k = 0; k < 4; ++k){
                    x = i+dx[k], y = j+dy[k];
                    if (!out(x, y) && arr[x][y] == 'O') continue;   //相邻的格子就有球， 不能移动
                    hit = 0;
                    while (!out(x, y)){
                        xx = x+dx[k], yy = y+dy[k];
                        if (!out(xx, yy) && arr[xx][yy] == 'O'){
                            ++hit;
                            arr[x][y] = 'O';
                            arr[xx][yy] = 'X';
                        }
                        x = xx, y = yy;
                    }
                    if (hit){
                        X[dep] = i, Y[dep] = j, D[dep] = dir[k];
                        if (Dfs(dep+1)) return 1;
                        x = x-dx[k], y = y-dy[k];
                        while (x != i || y != j){
                            xx = x-dx[k], yy = y-dy[k];
                            if (arr[xx][yy] == 'O'){
                                arr[x][y] = 'O';
                                arr[xx][yy] = 'X';
                            }
                            x = xx, y = yy;
                        }
                    }
                }
                arr[i][j] = 'O';
            }
    return 0;
}

int main()
{
    freopen("fling.in.0","r",stdin);
    freopen("fling.out.0","w",stdout);

    int cas = 0;
    while (scanf("%s", arr[0]) == 1){
        if (cas++) putchar('\n');
        for (int i = 1; i < M; ++i) scanf("%s", arr[i]);
//        for (int i = 0; i < M; ++i) puts(arr[i]);
        cnt = 0;
        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                if (arr[i][j] == 'O')
                    ++cnt;
        if (cnt) --cnt;
        printf("CASE #%d:\n", cas);
        Dfs(0);
    }
    return 0;
}
