//by Dumbear
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>

using namespace std;

const int max_n = 30 + 5, max_m = 30 + 5;

int n, m, light_time[max_n][max_m], dis[max_n][max_m][2][2][2];

bool solve();
int get_min_path(int, int, int, int, int, int, int, int, int);
int get_time_cost(int, int, int, int);

int main() {
    freopen("date.in", "r", stdin);
    freopen("3.txt", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d%d", &n, &m) == EOF)
        return false;
    for (int i = 0; i <= n; ++i)
        light_time[i][0] = light_time[i][m] = 0;
    for (int i = 0; i <= m; ++i)
        light_time[0][i] = light_time[n][i] = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
            scanf("%d", &light_time[i][j]);
    int hh, mm;
    scanf("%d:%d", &hh, &mm);
    int t = hh * 60 + mm;
    t += get_min_path(1, 1, 0, 0, t, n - 1, m - 1, 1, 1);
    printf("%02d:%02d\n", t / 60, t % 60);
    return true;
}

int get_min_path(int x0, int y0, int v0, int h0, int t0, int x1, int y1, int v1, int h1) {
    int min_path = INT_MAX;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int v = 0; v < 2; ++v)
                for (int h = 0; h < 2; ++h)
                    dis[i][j][v][h][0] = dis[i][j][v][h][1] = INT_MAX;
    dis[x0][y0][v0][h0][0] = 0;
    while (true) {
        int min_x = -1, min_y = -1, min_v = -1, min_h = -1, min_f = -1, min_d = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                for (int v = 0; v < 2; ++v) {
                    for (int h = 0; h < 2; ++h) {
                        for (int f = 0; f < 2; ++f) {
                            if (dis[i][j][v][h][f] != -1 && dis[i][j][v][h][f] < min_d) {
                                min_x = i;
                                min_y = j;
                                min_v = v;
                                min_h = h;
                                min_f = f;
                                min_d = dis[i][j][v][h][f];
                            }
                        }
                    }
                }
            }
        }
        if (min_d == INT_MAX)
            break;
        if (min_x == x1 && min_y == y1 && min_v == v1 && min_h == h1)
            min_path = min(min_path, min_d);
        if (min_v == 0 && min_x > 0 && min_d + 1 < dis[min_x - 1][min_y][1][min_h][min_f])
            dis[min_x - 1][min_y][1][min_h][min_f] = min_d + 1;
        if (min_v == 1 && min_x < n && min_d + 1 < dis[min_x + 1][min_y][0][min_h][min_f])
            dis[min_x + 1][min_y][0][min_h][min_f] = min_d + 1;
        if (min_h == 0 && min_y > 0 && min_d + 2 < dis[min_x][min_y - 1][min_v][1][min_f])
            dis[min_x][min_y - 1][min_v][1][min_f] = min_d + 2;
        if (min_h == 1 && min_y < m && min_d + 2 < dis[min_x][min_y + 1][min_v][0][min_f])
            dis[min_x][min_y + 1][min_v][0][min_f] = min_d + 2;
        if (min_d + get_time_cost(min_x, min_y, 0, t0 + min_d) < dis[min_x][min_y][1 ^ min_v][min_h][min_f])
            dis[min_x][min_y][1 ^ min_v][min_h][min_f] = min_d + get_time_cost(min_x, min_y, 0, t0 + min_d);
        if (min_d + get_time_cost(min_x, min_y, 1, t0 + min_d) < dis[min_x][min_y][min_v][1 ^ min_h][min_f])
            dis[min_x][min_y][min_v][1 ^ min_h][min_f] = min_d + get_time_cost(min_x, min_y, 1, t0 + min_d);
        if (min_f == 0) {
            if (min_d + 1 < dis[min_x][min_y][1 ^ min_v][min_h][1])
                dis[min_x][min_y][1 ^ min_v][min_h][1] = min_d + 1;
            if (min_d + 1 < dis[min_x][min_y][min_v][1 ^ min_h][1])
                dis[min_x][min_y][min_v][1 ^ min_h][1] = min_d + 1;
        }
        dis[min_x][min_y][min_v][min_h][min_f] = -1;
    }
    return min_path;
}

int get_time_cost(int x0, int y0, int d, int t0) {
    if (light_time[x0][y0] == 0)
        return 0xffff;
    int t = t0 % (light_time[x0][y0] * 2);
    if (d == 0) {
        if (t < light_time[x0][y0])
            return light_time[x0][y0] - t + 1;
        else
            return 1;
    } else {
        if (t < light_time[x0][y0])
            return 1;
        else
            return light_time[x0][y0] * 2 - t + 1;
    }
}
