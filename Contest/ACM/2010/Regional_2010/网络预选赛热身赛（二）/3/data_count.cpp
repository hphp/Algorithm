#include <iostream>
#include <fstream>
using namespace std;

struct abc{
    int num;
    char str[21];
}que[200010];

int n,t;   

int random(int low, int high){
    return low + rand()%(high-low+1);
}
    
int cmp(const void *a, const void *b){
    abc * f1=(abc *)a;
    abc * f2=(abc *)b;
    return  strcmp(f1->str,f2->str);
}  
  
void genStr(int k){
    int len = random(3, 6);
    for(int i=0; i<len; i++){
        que[k].str[i] = 'A' + random(0, 5);
    }
    que[k].str[len] = '\0';
}
        
int main(){
    ofstream fin("count.in");
    ofstream fout("count.out");
    srand(time(NULL));
    int count[200010];
    int t;
    t = random(15, 15);
    for(int k=1; k<=t; k++){
        
        n = random(100, 90000);
        
        fin << n << endl;
        
        for(int i=0;i<n;i++){
            
            genStr(i);
            
            fin << que[i].str << endl;
            
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
        fout << "Case " << k << ":" << endl;
        for(i=1;i<=n;i++){
            if(count[i]>0)fout << i << " " << count[i] << endl;
        }             
    }
    return 1;
}            
