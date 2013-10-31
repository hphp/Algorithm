#include <iostream>
using namespace std;
char m[1000][1000];
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    
    int n;
    int flag;
    char c;
    while(cin >> n){
        memset(m, 0, sizeof(m));
        if(n%2==0)flag = 1;
        else flag = 0;
        int rows = 2*n-1;
        for(int r=1; r<=n; r++){
            if((r+flag)%2==0) c = '.';
            else c = '*';
            for(int i=r; i<=n; i++){
                m[i][r] = c;
                m[rows-i+1][r] = c;
                m[i][rows-r+1] = c;
                m[rows-i+1][rows-r+1] = c;
            }
            for(int j=r; j<=n; j++){
                m[r][j] = c;
                m[r][rows-j+1] = c;
                m[rows-r+1][j] = c;
                m[rows-r+1][rows-j+1] =c;
            }
        }                
                        
        for(int i=1; i<=rows; i++){
            m[i][rows+1] = '\0';
        }
        for(int i=1; i<=rows; i++){
                printf("%s\n", m[i]+1);  
        }
    }
    return 0;
}                        
            
