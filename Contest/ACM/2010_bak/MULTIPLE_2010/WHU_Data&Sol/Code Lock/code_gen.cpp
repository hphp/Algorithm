/**********************************************************************
Author: hanshuai
Created Time:  2010/3/30 16:13:52
File Name: gene.cpp
Description: 
**********************************************************************/
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    freopen("string.in", "w", stdout);
    int test = 10;
    printf("%d\n", test);
    while(test --){
        int n, m = 1000;
        if(test==9) n = 100;
        else if(test>5) n = 1000;
        else if(test==5) n = 345345;
        else if(test==4) n = 10000000;
        else n = 500;
        printf("%d %d\n", n, m);
        for(int i = 0; i < m; i ++){
            int L = rand()%n+1, R = rand()%n + 1;
            if(L > R) swap(L, R);
            printf("%d %d\n", L, R);
        }
    }
    return 0;
}

