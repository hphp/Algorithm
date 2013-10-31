/**********************************************************************
Author: hanshuai
Created Time:  2010-3-27 12:23:50
File Name: game.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int test, n, cas = 0;
    scanf("%d", &test);
    while(test --){
        scanf("%d", &n); 
        int ans = 0, t;
        for(int i = 1; i <= n; i ++){
            scanf("%d", &t);
            if(i%3==0){
                if(i%2==0) ans ^= t;
            }else{
                if(i%3==2) ans ^= t;
            }
        }
        printf("Case %d: ", ++cas);
        if(ans == 0) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}

