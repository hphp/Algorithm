#include <cstdio>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long i64;

const int N = 100010;
const int M = 500010;
const int L = 16;
const i64 LINF = 1LL << 60;

struct List {
    int v, dis;
    List *next;
} pool[M<<1], *c[N], *g[N], *pp;

inline void add_edge(int u, int v, int dis, List *c[])
{
    pp->v = v;
    pp->dis = dis;
    pp->next = c[u];
    c[u] = pp++;
}

struct Node {
    int v;
    i64 dis;
    bool operator < (const Node &b) const {
        return dis > b.dis;
    }
} n1, n2;

int n, m, src, dest, label;
i64 ds[N], dt[N];
bool flag[N];
map<string, int> dict;

inline int Getidx(char *s)
{
    if(dict.count(s))   return dict[s];
    return dict[s] = label++;
}

void Dijkstra(int src, i64 *d, List *c[])
{
    priority_queue<Node> Q;
    n1.v = src, n1.dis = 0;
    Q.push(n1);
    for(int i = 0; i < n; ++i)  d[i] = LINF, flag[i] = false;
    d[src] = 0;

    while( !Q.empty() ) {
        n1 = Q.top(); Q.pop();
        int u = n1.v;
        if(flag[u]) continue;
        flag[u] = true;
        for(List *p = c[u]; p; p = p->next) {
            int v = p->v;
            if(!flag[v] && d[u] + p->dis < d[v]) {
                d[v] = d[u] + p->dis;
                n2.v = v, n2.dis = d[v];
                Q.push(n2);
            }
        }
    }
}

int main()
{
    int i, j;
    char str1[L], str2[L];

    while( scanf("%d %d", &n, &m) == 2 ) {
        dict.clear(), label = 0;
        for(i = 0; i < n; ++i)  c[i] = g[i] = NULL;
        pp = pool;
        while( m-- ) {
            int u, v, dis;
            scanf("%s %s %d", str1, str2, &dis);
            u = Getidx(str1), v = Getidx(str2);
            add_edge(u, v, dis, c);
            add_edge(v, u, dis, g);
        }
        scanf("%s %s", str1, str2);
        src = dict[str1], dest = dict[str2];

        Dijkstra(src, ds, c);
        Dijkstra(dest, dt, g);

        i64 ans = LINF;
        for(i = 0; i < n; ++i)
            for(List *p = c[i]; p; p = p->next) {
                j = p->v;
                if(ds[i] < LINF && dt[j] < LINF)
                    ans = min(ans, ds[i]+dt[j]+(p->dis)/2);
            }
        if(ans == LINF) ans = -1;

        printf("%lld\n", ans);
    }

    return 0;
}
