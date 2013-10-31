#include <iostream>
#include <cstdlib>
using namespace std;
int a[10000];
int n;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        for(int i=n; i>1; i--){
            printf("%d ", a[i]);
        }
        printf("%d\n", a[1]);
    }
    return 0;
}               
        
    
