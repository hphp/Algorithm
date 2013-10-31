#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int INF = (1 << 29);
const int N = 305, M = 500005, E = N * N * 3, K = 26;

struct graphNode {
    int v, f; graphNode *next, *pair;
};
struct trieNode {
    int v, idx; trieNode *next[K], *fail;
};
trieNode trie[M], *qq, *root, *que[M];
graphNode pool[E], *pp, *G[N], *path[N], *cur[N];
int n, s, t, d[N], num[N], pred[N];
int mat[N][N], love[N], hate[N], profit[N];

void clearTrie(trieNode *now) {
    now -> v = 0; now -> idx = -1; now -> fail = NULL;
    for(int i = 0; i < K; i ++) { if(now -> next[i] != NULL)
        clearTrie(now -> next[i]);
        now -> next[i] = NULL;
    }
}
void initTrie() {
    root = trie;
    qq = trie + 1;
    clearTrie(root);
    memset(mat, 0, sizeof(mat));
    memset(profit, 0, sizeof(profit));
}
void insertTrie(char* word, int v, int idx) {
    int i, j; trieNode *p = root;
    for(i = 0; word[i]; i ++) {
        j = word[i] - 'a';
        if(p -> next[j] == NULL) {
            qq -> v = 0; qq -> idx = -1;
            memset(qq -> next, 0, sizeof(qq -> next));
            p -> next[j] = qq ++;
        }
        p = p -> next[j];
    }
    p -> v = v; p -> idx = idx;
}
void buildAC() {
    int i, head, tail; trieNode *p, *q;
    root -> fail = NULL; head = tail = 0; que[tail ++] = root;
    while(head < tail) {
        p = que[head ++];
        for(i = 0; i < K; i++) {
            if(p -> next[i] != NULL) {
                for(q = p -> fail; q && q -> next[i] == NULL; q = q -> fail);
                 if(q == NULL) p -> next[i] -> fail = root;
                else p -> next[i] -> fail = q -> next[i];
                que[tail++] = p -> next[i];
            }
        }
    }
}
int searchAC(char* text, int idx) {
    int i, j, ret = 0; trieNode *p, *q;
    for(i = 0, p = root; text[i]; i ++){
        j = text[i] - 'a';
        for(; p && p -> next[j] == NULL; p = p -> fail);
        if(p == NULL) p = root;
        else{
            p = p -> next[j];
            for(q = p; q; q = q -> fail)
                if(q -> v > 0) { mat[idx][q -> idx] = 1; ret += q -> v; }
        }
    }
    return ret;
}

graphNode *create(int v, int f, graphNode *next) {
    pp -> v = v, pp -> f = f, pp -> next = next;
    return pp ++;
}
void initGraph() {
    pp = pool; pred[s] = -1;
    memset(G, 0, sizeof(G));
    memset(cur, 0, sizeof(cur));
    memset(num, 0, sizeof(num));
    for(int i = 0; i <= n; i++) d[i] = n;
}
void addEdge(int u, int v, int f) {
    G[u] = create(v, f, G[u]);
    G[v] = create(u, 0, G[v]);
    G[u] -> pair = G[v];
    G[v] -> pair = G[u];
}
void calDis(){
    int Q[E], head = -1, tail = 0, u;
    d[t] = 0, Q[tail] = t;
    while(head < tail){
        u = Q[++ head];
        for(graphNode *p = G[u]; p; p = p -> next)
            if(p -> f == 0 && d[p -> v] == n) {
                d[p -> v] = d[u] + 1;
                num[d[p -> v]] ++;
                Q[++tail] = p->v;
            }
    }
}
void augment(int &sum) {
    int mini = INF;
    for(int u = t; u != s; u = pred[u])
        mini =  mini < path[u] -> f ? mini : path[u] -> f;
    sum += mini;
    for(int u = t; u != s; u = pred[u])
        path[u] -> f -= mini, path[u] -> pair -> f += mini;
}
int maxFlow() {
    bool update;
    int u = s, res = 0;
    calDis();
    for(int i = 0; i < n; i++) cur[i] = G[i];
    while(d[s] < n) {
        update = false;
        for(graphNode *p = cur[u]; p; p = p -> next){
            if(d[p -> v] + 1 == d[u] && p -> f > 0){
                update = true;
                pred[p -> v] = u; path[p -> v] = p; cur[u] = p;
                u = p -> v;
                if(u == t){ augment(res); u = s; }
                break;
            }
        }
        if(!update){
            if(--num[d[u]] == 0) break;
            cur[u] = G[u]; d[u] = n;
            for(graphNode *p = G[u]; p; p = p->next)
                if(p -> f > 0 && d[u] > d[p -> v] + 1) d[u] = d[p -> v] + 1;
            if(d[u] < n) num[d[u]] ++;
            if(u != s) u = pred[u];
        }
    }
    return res;
}
int main() {
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int i, j, cas, cs, x, y, tot;
    char word[55], text[1005];
    scanf("%d", &cas);
    for(cs = 1; cs <= cas; cs ++) {
        initTrie();
        scanf("%d%d", &x, &y);
        for(i = 0; i < x; i ++) {
            scanf("%d%d%s", &love[i], &hate[i], word);
            insertTrie(word, love[i], i);
        }
        buildAC();
        for(i = 0; i < y; i ++) {
            scanf("%s", text);
            profit[i] += searchAC(text, i);
        }

        n = x + y + 2; s = x + y; t = x + y + 1; tot = 0;
        initGraph();
        for(i = 0; i < y; i ++) {
            tot += profit[i];
            for(j = 0; j < x; j ++) if(mat[i][j] == 1) addEdge(i, j + y, INF);
        }
        for(i = 0; i < y; i ++) addEdge(s, i, profit[i]);
        for(i = 0; i < x; i ++) addEdge(i + y, t, hate[i]);
        printf("Case %d: %d\n", cs, tot - maxFlow());
    }
    return 0;
}
