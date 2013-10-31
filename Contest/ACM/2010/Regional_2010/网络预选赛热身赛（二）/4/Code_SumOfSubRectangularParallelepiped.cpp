#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int MAX = 110;

int rect[MAX][MAX][MAX];
int H,M,N;

int maxSum1(int n, int a[MAX]){
    int sum = 0;
    int b = 0;
    for(int i=1; i<=n; i++){
        if(b>0)b = b+a[i];
        else b = a[i];
        if(b>sum)sum = b;
    }
    return sum;
}

int maxSum2(int m, int n, int a[MAX][MAX]){
    int sum = 0;
    int b[MAX];
    for(int i=1; i<=m; i++){
        memset(b, 0, sizeof(b));
        for(int j=i; j<=m; j++){
            for(int k=1; k<=n; k++)b[k] = b[k] +a[j][k];
            int max = maxSum1(n, b);
            if(max>sum)sum = max;
        }
    }
    return sum;
}
int maxSum3(int h, int m, int n, int a[MAX][MAX][MAX]){
    int sum = 0;
    int b[MAX][MAX];
    for(int i=1; i<=h; i++){
        memset(b, 0, sizeof(b));
        for(int j=i; j<=h; j++){
            for(int r=1; r<=m; r++){
                for(int s=1; s<=n; s++){
                    b[r][s] = b[r][s] + a[j][r][s];
                }
            }
            int max = maxSum2(m, n, b);
            if(max>sum)sum = max;
        }
    }
    return sum;
}                     

int random(int low, int high){
    return low + rand()%(high-low+1);
}    
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &H, &M, &N);
        for(int i=1; i<=H; i++){
            for(int j=1; j<=M; j++){
                for(int k=1; k<=N; k++){
                    scanf("%d", &rect[i][j][k]);
                }    
            }
        }
        printf("%d\n",maxSum3(H, M, N, rect));
    }
    return 0;
}                                    
        
