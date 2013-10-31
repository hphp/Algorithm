#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct item {
    int p, q, v;
    void input() {
        scanf("%d%d%d", &p, &q, &v);
    }
};

bool operator<(const item& i1, const item& i2) {
    return i1.q - i1.p < i2.q - i2.p;
}

const int max_n = 500 + 10, max_m = 5000 + 10;

int n, m, max_value[max_m];
item items[max_n];

bool solve();
int get_max_value();

int main() {
    freopen ("proud.in", "r", stdin);
    freopen ("proud_dumbear.out", "w", stdout);
    while (solve());
    return 0;
}

bool solve() {
    if (scanf("%d%d", &n, &m) == EOF)
        return false;
    for (int i = 0; i < n; ++i)
        items[i].input();
    printf("%d\n", get_max_value());
    return true;
}

int get_max_value() {
    sort(items, items + n);
    memset(max_value, 0, sizeof(max_value));
    for (int i = 0; i < n; ++i)
        for (int j = m; j >= items[i].q; --j)
            max_value[j] = max(max_value[j], max_value[j - items[i].p] + items[i].v);
    return max_value[m];
}
