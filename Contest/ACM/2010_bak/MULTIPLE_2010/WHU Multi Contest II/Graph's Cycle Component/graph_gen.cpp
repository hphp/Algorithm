/*
 * Author: momodi
 * Created Time:  2010/3/27 14:27:05
 * File Name: gen.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <ctime>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
struct Edge {
    int u, v, c;
    Edge(int u, int v, int c):u(u), v(v), c(c) {}
};
void output(int n, const vector<Edge> &edge) {
    printf("%d %d\n", n, SZ(edge));
    for (int i = 0; i < SZ(edge); ++i) {
        //printf("%d %d %d\n", edge[i].u, edge[i].v, edge[i].c);
        printf("%d %d\n", edge[i].u, edge[i].v);
    }
}

void gen1() {
    vector<Edge> edge;
    int n = rand() % 10 + 1;
    int m = n * (n - 1) / 2;
    m = rand() % (m + 1);
    set<pair<int, int> > hash;
    for (int i = 0; i < m; ++i) {
        int u, v;
        do {
            u = rand() % n, v = rand() % n;
        } while (u == v || hash.count(make_pair(u, v)) || hash.count(make_pair(v, u)));
        hash.insert(make_pair(u, v));
        edge.push_back(Edge(u, v, rand() % 10000 + 1));
    }
    output(n, edge);
}
void gen2() {
    vector<Edge> edge;
    int n = 10000;
    int m = 100000;
    set<pair<int, int> > hash;
    for (int i = 0; i < m; ++i) {
        int u, v;
        do {
            u = rand() % n, v = rand() % n;
        } while (u == v || hash.count(make_pair(u, v)) || hash.count(make_pair(v, u)));
        hash.insert(make_pair(u, v));
        edge.push_back(Edge(u, v, rand() % 10000 + 1));
    }
    output(n, edge); 
}
void gen3() {
    vector<Edge> edge;
    int n = 10000;
    int m = 20000;
    set<pair<int, int> > hash;
    for (int i = 0; i < m; ++i) {
        int u, v;
        do {
            u = rand() % n, v = rand() % n;
        } while (u == v || hash.count(make_pair(u, v)) || hash.count(make_pair(v, u)));
        hash.insert(make_pair(u, v));
        edge.push_back(Edge(u, v, rand() % 10000 + 1));
    }
    output(n, edge); 
}
void gen4() {
    vector<Edge> edge;
    int n = 100000;
    for (int i = 0; i < n; ++i) {
        edge.push_back(Edge(i, (i + 1) % n, 0));
    }
    output(n, edge);
}
void gen5() {
    vector<Edge> edge;
    int n = 100000;
    for (int i = 0; i < n; ++i) {
        edge.push_back(Edge(i, (i + 1) % n, 0));
    }
    edge.push_back(Edge(10000, 2000, 1));
    output(n, edge);
}
void gen6() {
    vector<Edge> edge;
    int n = 100000;
    for (int i = n - 1; i >= 0; --i) {
        edge.push_back(Edge(i, (i - 1 + n) % n, 0));
    }
    output(n, edge);
}
void gen7() {
    vector<Edge> edge;
    int n = 100000;
    for (int i = n - 1; i >= 0; --i) {
        edge.push_back(Edge(i, (i - 1 + n) % n, 0));
    }
    edge.push_back(Edge(10000, 2000, 1));
    output(n, edge);
}
int main() {
    srand(time(NULL));
    freopen("CycleGraph.in", "w", stdout);
    for (int i = 0; i < 10000; ++i) {
        //out(i);
        gen1();
    }
    for (int i = 0; i < 3; ++i) {
        gen2();
    }
    for (int i = 0; i < 4; ++i) {
        gen3();
    }
    gen4();
    gen5();
    gen6();
    gen7();
    puts("0 0");
    return 0;
}


