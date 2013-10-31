/*
 * Author: iSea
 * Created Time:  2010/4/21 13:41:40
 * File Name: date_gen.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl

const int maxn = 1000 + 10;
const int inf = (-1u) >> 1;

int main() {
    freopen ("date.in", "w", stdout);
    //printf ("100\n");
    printf ("2 2\n3\n12:03\n");
    printf ("2 3\n2 2\n12:00\n");
    for (int i = 0; i < 8; ++i) {
        int n = rand() % 5 + 1;
        int m = rand() % 5 + 1;
        printf ("%d %d\n", n + 1, m + 1);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                printf ("%d%c", rand() % 5 + 1, k == m - 1? '\n' : ' ');
        printf ("12:%02d\n", rand() % 60);
    }
    for (int i = 0; i < 10; ++i) {
        int n = rand() % 10 + 1;
        int m = rand() % 10 + 1;
        printf ("%d %d\n", n + 1, m + 1);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                printf ("%d%c", rand() % 10 + 1, k == m - 1? '\n' : ' ');
        printf ("00:%02d\n", rand() % 60);
    }
    for (int i = 0; i < 10; ++i) {
        int n = rand() % 29 + 1;
        int m = rand() % 29 + 1;
        printf ("%d %d\n", n + 1, m + 1);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                printf ("%d%c", rand() % 10 + 1, k == m - 1? '\n' : ' ');
        printf ("%02d:%02d\n", rand() % 12, rand() % 60);
    }for (int i = 0; i < 70; ++i) {
        int n = 29;
        int m = 29;
        printf ("%d %d\n", n + 1, m + 1);
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < m; ++k)
                printf ("%d%c", rand() % 10 + 1, k == m - 1? '\n' : ' ');
        printf ("00:%02d\n", rand() % 60);
    }
    return 0;
}

