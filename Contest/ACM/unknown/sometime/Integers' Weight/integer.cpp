/**********************************************************************
Author: hanshuai
Created Time:  2010/7/16 14:47:46
File Name: len.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;
const int MOD = 100007;
int getA(int n, int m){
//    printf("%d %d\n", n, m);
    if(n == 1) return 1;
    map<int,int> mm;
    int tm;
    LL now = 0;
    for(int i = 1; ; i ++){ 
        if(mm.count(now)){
            tm = i - mm[now];
            break;
        }
        mm[now] = i;
        now = (now*10+2) % m;
    }
    int a = getA(n-1, tm);
    now = 0;
    while(a --){
        now = now*10+2;
        if(now >= MOD){
            LL x = (now - MOD)/m;
            now -= x * m;
        }
    }
    return now;
}
int main() {
//    freopen("len.in", "r", stdin);
//    freopen("len.out", "w", stdout);
    vector<int> vec; 
    for(int i = 1; i <= 10; i ++) vec.push_back((getA(i, MOD)*9+1)%MOD);
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 1){
            printf("1\n"); continue;
        }
        n -= 2;
        if(n < 10) printf("%d\n", vec[n]);
        else if(n&1){
            printf("%d\n", vec[9]);
        }else printf("%d\n", vec[8]);
    }
    return 0;
}

