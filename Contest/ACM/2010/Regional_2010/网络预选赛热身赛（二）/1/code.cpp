#include <iostream>
using namespace std;
int arr[10000];
int res[10000];
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    while(cin >> n){
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        for(int i=0; i<n; i++){
            res[i] = (arr[(n+i-1)%n]+1)/2 + arr[(i+1)%n]/2; 
        }   
        cout << res[0];
        for(int i=1; i<n; i++){
            cout << ' ' << res[i];
        }    
        cout << endl;
    }
    return 0;        
}    
