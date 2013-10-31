/*
solution:
f[n] = g[n-1] + f[n-1];
g[n] = f[n-1] + 2;
n > 3; 
f[n] 表示n位置以前存在当且仅当两个相邻位置状态相同且n-1 n位置不同的个数
g[n] 表示n位置以前存在当且仅当两个相邻位置状态相同且n-1 n位置相同的个数
*/
#include<iostream>
using namespace std;

struct matrix {
       int g[4][4];
};
const int M = 10007;
matrix start , factor;

void init() {
     memset(start.g,0,sizeof(start.g)); // start pos is 2;
     factor = start;
     factor.g[0][0] = factor.g[0][1] = factor.g[2][2] = 1;
     factor.g[1][0] = factor.g[2][1] = 1;
     start.g[0][1] = start.g[0][2] = 2;
}

inline matrix multi( matrix a,matrix b) {
       matrix ans ;
       memset(ans.g,0,sizeof(ans.g));
       for( int k = 0 ; k < 3;k++ )
            for( int i = 0 ; i < 3; i++)
                 for( int j = 0 ; j < 3;j++)
                      ans.g[i][j] = (ans.g[i][j]+a.g[i][k]*b.g[k][j])%M;
       return ans;
}

inline matrix solve(int k) {
       matrix ans = start,t = factor;
       while( k ) {
              if( k&1 ) ans = multi( ans,t );
              t = multi(t,t);
              k >>= 1;
       }
       return ans;
}

int mod( int a,int b,int m){
    int ans = 1 , t = a%m;
    while( b ){
           if( b&1 ) ans = (ans*t)%m;
           t =(t*t)%m;
           b >>= 1; 
    } 
    return ans;
}

void out( matrix a ) {
     for( int i = 0 ; i < 3; i++) {
          for( int j = 0 ; j < 3;j++)
               printf("%d ",a.g[i][j]);
          puts("");
     } 
}

int main() {
    init();
    //out(start);out(factor);
    int n ,i ;
   // freopen("1.std.in","r",stdin);
   // freopen("1.std.out","w",stdout); 
    while( scanf("%d",&n) != EOF ) {
           if( n < 3 ) puts("0");
           else {
                int tot = mod(2,n,M);
                tot -= 2;
                matrix ans = solve(n-2);  
                tot -= (ans.g[0][1]+ans.g[0][0]);
                cout<<(tot%M+M)%M<<endl;
           }
    }
    return 0;
}
