/*
 * Author: iSea
 * Created Time:  2010/8/17 18:53:06
 * File Name: divide.cpp
 */
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <map>

using namespace std;

const int maxn = 50000 + 10;
const int inf = (-1u) >> 1;

char s[maxn];

int main() {
    freopen ("divide.out", "w", stdout);
    while (scanf ("%s", &s) != EOF) {
        int n = strlen(s);
        if ((n == 1) || (n == 2 && s[0] == s[1])) {
            puts ("No");
            continue;
        }
        if (n == 3 && s[0] != s[1] && s[0] == s[2]) {
            puts ("No");
            continue;
        }
        if (n == 4 && s[0] != s[1] && s[1] == s[2] && s[0] == s[3]) {
            puts ("No");
            continue;
        }
        puts ("Yes");
    } 
    return 0;
}

