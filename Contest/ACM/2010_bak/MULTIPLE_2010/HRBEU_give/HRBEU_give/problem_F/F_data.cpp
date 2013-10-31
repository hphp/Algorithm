#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
#define N 1000
#define M 500
int d[N + 1][N + 1];
int main(){
    freopen("F_in.txt", "w", stdout);
    srand(unsigned(time(NULL)));
    
    for(int i = 0; i < 10; ++i){
        int n = abs(rand()) % 10 + 1;
        int m = abs(rand()) % 5 + 1;
        printf("%d %d\n", n, m);
        for(int ii = 0; ii < n; ++ii){
            for(int jj = 0; jj < n; ++jj){
                printf("%d ", abs(rand()) % 2);
            }
            printf("\n");
        }
        for(int ii = 0; ii < m; ++ii){
            for(int jj = 0; jj < m; ++jj)
                printf("%d ", abs(rand()) % 2);
                printf("\n");
        }
    }
    
    
    for(int i = 0; i < 3; ++i){
        int n = abs(rand()) % N + 1;
        int m = abs(rand()) % M + 1;
        printf("%d %d\n", n, m);
        for(int ii = 0; ii < n; ++ii){
            for(int jj = 0; jj < n; ++jj){
                printf("0 ");
            }
            printf("\n");
        }
        for(int ii = 0; ii < m; ++ii){
            if(ii < m -1)
                for(int jj = 0; jj < m; ++jj)
                    printf("0 ");
            else{
                
                for(int jj = 0; jj < m - 1; ++jj)
                    printf("0 ");
                printf("1");
            }
            printf("\n");
        }
    }
    
    int n = 1000;
    int m = 500;
    printf("%d %d\n", n, m);
    for(int ii = 0; ii < n; ++ii){
        for(int jj = 0; jj < n; ++jj){
            if(ii == n - 1){
                if(jj != n - 1)
                    printf("1 ");
                else printf("0 ");
            }else printf("1 ");
        }
        printf("\n");
    }
    for(int ii = 0; ii < m; ++ii){
        if(ii < m -1)
            for(int jj = 0; jj < m; ++jj)
                printf("1 ");
        else{
            for(int jj = 0; jj < m - 1; ++jj)
                printf("1 ");
            printf("0");
        }
        printf("\n");
    }
    
    
    for(int i = 0; i < 3; ++i){
        int n = abs(rand()) % N + 1;
        int m = abs(rand()) % (M - 10) + 8;
        printf("%d %d\n", n, m);
        for(int ii = 0; ii < n; ++ii){
            for(int jj = 0; jj < n; ++jj){
                printf("1 ");
            }
            printf("\n");
        }
        for(int ii = 0; ii < m; ++ii)
            for(int jj = 0; jj < m; ++jj)
                d[ii][jj] = 1;
        d[m / 2 + 1][m / 2 + 3] = 0;
        for(int ii = 0; ii < m; ++ii){
            for(int jj = 0; jj < m; ++jj)
                printf("%d ", d[ii][jj]);
            printf("\n");
        }
    }
}
