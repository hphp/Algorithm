/*
 * Author: xay
 * Created Time:  2010-4-16 14:56:05
 * File Name: calc.cpp
 * Description: 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
const int maxint = -1u>>1;
const int limit = 100000000;
bool isoper(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int Map(char c) {
    switch (c) {
        case '+': return 1;
        case '-': return 2;
        case '*': return 3;
        case '/': return 4;
    }
    return 0;
}
bool cal(int a, int op, int b, int &c) {
    switch (op) {
        case 1:
            c = a + b; break;
        case 2:
            c = a - b; break;
        case 3:
            c = a * b; break;
        case 4:
            if (b == 0) return false;
            c = a / b;
    }
    if (abs(c) >= limit) return false;
    return true;
}
bool work(const char *s, int &dis) {
    int len = strlen(s);
    dis = 0;
    int opr = 0, fopr = 0, fnum = 0, rec = 0;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '=') {
            if (opr) {
                fopr = opr;
                fnum = dis;
                if (!cal(rec, opr, dis, dis)) return false;
                opr = 0;
            } else if (fopr) {
                if (!cal(dis, fopr, fnum, dis)) return false;
            }
        } else if (isdigit(s[i])) {
            int num = 0;
            while (i < len && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
                if (abs(num) >= limit) num /= 10;
                ++i;
            }
            --i;
            fopr = 0;
            dis = num;
        } else if (isoper(s[i])) {
            while (i + 1 < len && isoper(s[i + 1])) ++i;
            if (opr) {
                if (!cal(rec, opr, dis, dis)) return false;
            }
            opr = Map(s[i]);
            rec = dis;
        }
    }
    return true;
}
int main() {
    int t, ca = 0;
    scanf("%d", &t);
    char s[102];
    gets(s);
    while (t--) {
        gets(s);
        printf("Case %d: ", ++ca);
        int dis = 0;
        bool flag = work(s, dis);
        if (!flag) printf("ERROR\n");
        else printf("%d\n", dis);
    }
    return 0;
}

