/**********************************************************************
Author: hanshuai
Created Time:  2010/7/16 22:17:51
File Name: test.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int maxn = 10005;
string a[maxn];
int main() {
    int n;
    freopen ("ancient.in", "r", stdin);
    while(cin >> n){
        int ans = 0, tmax = 0;
        for(int i = 0; i < n; i ++){
            cin >> a[i];
            ans += (2 * a[i].size() + 1);
            tmax = max(tmax, (int)a[i].size());
        }
        ans -= tmax;
        sort(a, a + n);
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < a[i].size() && j < a[i-1].size(); j ++){
                if(a[i][j] != a[i-1][j]) break;
                ans -= 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


