#include <iostream>
using namespace std;

char s[1100000];
int used[30];

int main(){
    freopen("test.in" ,"r", stdin);
    freopen("test.out", "w", stdout);
    int k, t, z;
    while(scanf("%s", s) != EOF){
        memset(used, 0, sizeof(used));
        for(int i=0; s[i]!='\0'; i++)used[s[i]-'A']=1;
        k=0;
        for(int i=0; i<26; i++){
            k += used[i];
        }    
        
        memset(used, 0, sizeof(used));
        t=0;
        z=1;
        for(int i=0; s[i]!='\0'; i++){
            if(used[s[i]-'A']==0){
                used[s[i]-'A']=1; 
                t++;
            }
            if(t==k){
                memset(used, 0, sizeof(used));
                t=0;
                z++;
            }
        }
        printf("%d\n", z);
    }    
    return 0;
}


