#include <iostream>
#include <fstream>
using namespace std;

struct abc{
    int num;
    char str[21];
}que[200010];

int n,t;   


int cmp(const void *a, const void *b){
    abc * f1=(abc *)a;
    abc * f2=(abc *)b;
    return  strcmp(f1->str,f2->str);
}  
  

int main(){
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);

    int count[200010];
    int k=0;
    while(cin >> n){

        for(int i=0;i<n;i++){        
            cin >> que[i].str;
            que[i].num=0;
            count[i]=0;
        }
        
        qsort(que,n,sizeof(que[0]),cmp);  
        int i=1;
        int num=1;
        while(i<n){
            if(strcmp(que[i].str,que[i-1].str)==0){
                ++num;
                i++;
                continue;
            }
            count[num]++;
            num=1;
            i++;
        }
        count[num]++;
        cout << "Case " << ++k << ":" << endl;
        for(i=1;i<=n;i++){
            if(count[i]>0)cout << i << " " << count[i] << endl;
        }             
    }
    return 1;
}            
