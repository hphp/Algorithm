#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int max_r = 100 + 10, max_c = 100 + 10, max_n = 52 + 5;
const int steps[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int r, c, n, dis[max_n][max_r][max_c], matching[max_r * max_c];
char m[max_r][max_c];
pair<int, int> pos[max_n];
vector<int> g[max_n];
bool is_visited[max_r * max_c];

bool solve();
int get_max_value();
void bfs(int, int, int);
int get_max_matching();
bool can_match(int);

int main() {
    freopen ("treasure.in", "r", stdin);
    freopen ("treasure_dumbear.out", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d%d", &r, &c) == EOF)
        return false;
    for (int i = 0; i < r; ++i)
        scanf("%s", m[i]);
    printf("%d\n", get_max_value());
    return true;
}

int get_max_value() {
    n = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (m[i][j] >= 'A' && m[i][j] <= 'Z') {
                int k = m[i][j] - 'A';
                pos[k] = make_pair(i, j);
                bfs(i, j, k);
                n = max(n, k + 1);
            } else if (m[i][j] >= 'a' && m[i][j] <= 'z') {
                int k = 26 + m[i][j] - 'a';
                pos[k] = make_pair(i, j);
                bfs(i, j, k);
                n = max(n, k + 1);
            }
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        if (dis[i][pos[i + 1].first][pos[i + 1].second] == -1)
            return -1;
        g[i].clear();
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (m[i][j] != '*')
                continue;
            for (int k = 0; k < n - 1; ++k)
                if (dis[k][i][j] + dis[k + 1][i][j] == dis[k][pos[k + 1].first][pos[k + 1].second])
                    g[k].push_back(i * c + j);
        }
    }
    return get_max_matching();
}

void bfs(int x0, int y0, int k) {
    memset(dis[k], -1, sizeof(dis[k]));
    queue<pair<int, int> > q;
    dis[k][x0][y0] = 0;
    q.push(make_pair(x0, y0));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int next_x = x + steps[i][0], next_y = y + steps[i][1];
            if (next_x >= 0 && next_x < r && next_y >= 0 && next_y < c && m[next_x][next_y] != '#' && dis[k][next_x][next_y] == -1) {
                dis[k][next_x][next_y] = dis[k][x][y] + 1;
                q.push(make_pair(next_x, next_y));
            }
        }
    }
}

int get_max_matching() {
    int res = 0;
    memset(matching, -1, sizeof(matching));
    for (int i = 0; i < n - 1; ++i) {
        memset(is_visited, 0, sizeof(is_visited));
        if (can_match(i))
            ++res;
    }
    return res;
}

bool can_match(int v) {
    for (vector<int>::iterator i = g[v].begin(); i != g[v].end(); ++i) {
        if (is_visited[*i])
            continue;
        is_visited[*i] = true;
        if (matching[*i] == -1 || can_match(matching[*i])) {
            matching[*i] = v;
            return true;
        }
    }
    return false;
}

