/**********************************************************************
Author: hanshuai
Created Time:  2010/7/17 18:44:54
File Name: g.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 20005;
bool p[maxn];
vector<int> vec;
void init() {
    memset(p, false, sizeof(p));
    for(int i = 2; i < maxn; i ++){
        if(!p[i]){
//            printf("%d\n", i);
            if(i != 2) vec.push_back(i);
        }
        for(int j = i * i; j < maxn; j += i){
            p[j] = true;
        }
    }
}

int main() {    
    init();
    int n;
    freopen ("goldbach.in", "r", stdin);
    freopen ("goldbach_hanshuai.out", "w", stdout);
    while(scanf("%d", &n) == 1){
        int ans = 0;
        if(n & 1){
            for(int i = 0; i < (int)vec.size(); i ++){
                if(3*vec[i] >= n) break;
                for(int j = i + 1; j < (int)vec.size(); j ++){
                    if(vec[i]+2*vec[j] >= n) break;
                    if(!p[n-vec[i]-vec[j]]) ans ++;
                }
            }
        }else{
            for(int i = 0; i < (int)vec.size(); i ++){
                if(2*vec[i] >= n) break;
                if(!p[n-vec[i]]) ans ++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


