#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

char str[10000000];

inline int random(int low, int high){
    return low+rand()%(high-low+1);
}    
long long int track(int i, int &k){
    
    int wj = i;
    
    long long int arr[100];
    char op[100];
    int n = 0;
    
    long long int result = 0;
    long long int x = 0;
    long long int num = 0;
    int pre = 0;
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
    
    if(wj==1){
            for(int t=1;t<=n;t++){
                cout << op[t]<<arr[t];
            }
            cout << endl;
    } 
        
    for(i=1;i<n;){
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
            
int genn(int depth, int i){
    if(depth>2)return i;
    int n = random(1,5);
    int p;
    //printf("%d  %d\n", depth, n);
    while(n--){

            

        if(random(0,1)==0){
            //for(int x=0;x<depth;x++)printf("  ");
            //printf("a\n");
            int t=random(0,3);
            str[i++] = '|';
            while(t--){
                if(random(0,1)==0){
                    str[i++] = '|';
                    continue;
                }
                str[i++] = ',';
            }
            if(depth==0){
                //for(int x=0;x<depth;x++)printf("  ");
                //printf("......%d\n", i);

            }
            continue;
        }
        //for(int x=0;x<depth;x++)printf("  ");
        //printf("b\n");
        str[i++] = '[';
        
        i = genn(depth+1, i);

        str[i++] = ']';
        if(depth==0){
            //for(int x=0;x<depth;x++)
            //printf("......%d\n", i);
            
        }
    }
    return i;
}               
                    
                    
    
int main(){
    srand(time(NULL));
    ofstream fout1("ChinaMathematics.in");
    ofstream fout2("ChinaMathematics.out");
    int t;
    t = random(50,100);
    fout1 << t << endl;
    while(t--){
        int i=0;
        
        str[0]='[';
        
        i = genn(0, 1);
        
        str[i++]=']';
        str[i]='\0';
        
        cout << i << endl;
        
        fout1 << str << endl;
        cout << str << endl;
        
        i=0;
        int x =  track(0,i);
        cout << x << endl;
        fout2 << x << endl;
    }
    system("pause");
    return 0;
}        
        
