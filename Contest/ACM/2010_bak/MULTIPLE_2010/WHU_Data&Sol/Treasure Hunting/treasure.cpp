/*
 * Author: iSea
 * Created Time:  2010/7/16 10:37:46
 * File Name: treasure.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 100 + 10;
const int inf = (-1u) >> 1;
const int d[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char s[maxn][maxn];
int n, m, match[maxn * maxn], rally_num, gold_num;
int dis[52][maxn * maxn], rally_dis[52];
bool v[maxn * maxn], g[52][maxn * maxn];

bool dfs(int x) {
    for (int i = 0; i < gold_num; ++i) {
        if (g[x][i] && !v[i]) {
            v[i] = true;
            int k = match[i];
            match[i] = x;
            if (k == -1 || dfs(k))
                return true;
            match[i] = k;
        }
    }
    return false;
}

int hungray() {
    int res = 0;
    memset (match, -1, sizeof(match));
    for (int i = 0; i < rally_num; ++i) {
        memset (v, 0, sizeof(v));
        if (dfs(i))
            ++res;
    }
    return res;
}

bool is_rally_point(int x, int y) {
    return (s[x][y] >= 'A' && s[x][y] <= 'Z') ||
        (s[x][y] >= 'a' && s[x][y] <= 'z');
}

int get_rally_num(int x, int y) {
    return s[x][y] <= 'Z'? s[x][y] - 'A' : s[x][y] - 'a' + 26;
}

int getid(int x, int y) {
    return x * m + y;
}

void bfs(int x, int y, int id) {
    memset (dis[id], -1, sizeof(dis[id]));
    queue <int> q;
    q.push(x), q.push(y);
    dis[id][getid(x, y)] = 0;
    while (!q.empty()) {
        x = q.front(); q.pop();
        y = q.front(); q.pop();
        int nowdis = dis[id][getid(x, y)];
        for (int i = 0; i < 4; ++i) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                s[nx][ny] != '#' && dis[id][getid(nx, ny)] == -1) {
                dis[id][getid(nx, ny)] = nowdis + 1;
                q.push(nx), q.push(ny);
                if (is_rally_point(nx, ny) && get_rally_num(nx, ny) == id + 1)
                    rally_dis[id] = nowdis + 1;
            }
        }
    }
}

void make() {
    memset (rally_dis, -1, sizeof(rally_dis));
    rally_num = gold_num = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (is_rally_point(i, j)) {
                rally_num = max(rally_num, get_rally_num(i, j));
                bfs(i, j, get_rally_num(i, j));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '*') {
                for (int k = 0; k < rally_num; ++k) {
                    if (dis[k][getid(i, j)] + dis[k + 1][getid(i, j)] == rally_dis[k])
                        g[k][gold_num] = true;
                    else
                        g[k][gold_num] = false;
                }
                ++gold_num;
            }
        }
    }
}

int main() {
    freopen ("treasure.out", "w", stdout);
    while (scanf ("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i)
            scanf ("%s", s[i]);
        make();
        bool flag = true;
        for (int i = 0; i < rally_num; ++i)
            if (rally_dis[i] == -1)
                flag = false;
        printf ("%d\n", flag? hungray() : -1);
    }
    return 0;
}

