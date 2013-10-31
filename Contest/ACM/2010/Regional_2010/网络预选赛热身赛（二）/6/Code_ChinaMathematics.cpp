#include <iostream>
using namespace std;

char str[1000];

int track(int i, int &k){
    
    int wj = i;
    
    int arr[100];
    char op[100];
    int n = 0;
    
    int result = 0;
    int x = 0;
    int num = 0;
    int pre = 0;
    int next = 0;
    int finish = 0;
    int j;
    while(str[i]!='\0'){
        if(str[i]=='['){
            if(pre==0){
                ++n;
                arr[n] = track(i+1, j);
                op[n] = '+';
            }    
            else if(pre==1){
                ++n;
                arr[n] = track(i+1, j);
                op[n] = '*';
            }    
            pre = 1;
            i = j;
        }
        else if(str[i]=='|' || str[i]==','){
            while(str[i]=='|' || str[i]==','){
                if(str[i]=='|')++x;
                else if(str[i]==','){
                    num = num*8+x;
                    x = 0;
                }
                i++;
            }   
            num = num*8+x;    
             
            ++n;
            arr[n] = num;
            op[n] = '+';
            
            num = 0;
            x = 0;
            pre = 0;
        }
        else if(str[i]==']'){
            break;
        }
    }
    k = i+1;
    for(i=1;i<n;){
/*
        if(wj==1){
            for(int t=1;t<=n;t++){
                cout << op[t]<<arr[t];
            }
            cout << endl;
        }  
*/  
        if(op[i+1]=='*'){
            arr[i] = arr[i]*arr[i+1];
            for(int t=i+1; t<n; t++){
                arr[t] = arr[t+1];
            }
            for(int t=i+1; t<n; t++){
                op[t] = op[t+1];
            }
            n--;
        }
        else ++i;
    }
    for(i=1; i<=n; i++){
        result = result + arr[i];
    }                
                          
    return result;
}                
            
                
    
int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        cin >> str;
        int i=0;
        cout << track(0,i) << endl;
    }
    return 0;
}        
        
