#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

char s[1100000];
int used[30];

int random(int low, int high){
    return low+rand()%(high-low+1);
}

void genStr(){
    int n;
    n = random(10000, 999999);
    for(int i=0; i<n; i++){
        s[i] = random(0, 25) + 'A';
    }
    s[n] = '\0';
}           
int main(){
    ofstream fin("input.in");
    ofstream fout("output.out");
    
    srand(time(NULL));
    int k, t, z;
    for(int num=0; num<10; num++){
        genStr();
        fin << s << endl;
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
        fout << z << endl;
    }    
    return 0;
}


