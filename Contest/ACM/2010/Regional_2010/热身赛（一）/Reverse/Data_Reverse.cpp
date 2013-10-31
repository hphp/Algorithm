#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
int a[10000];
int n;
int random(int low, int high){
    return low+rand()%(high-low+1);
}    
int main(){
    srand(time(NULL));
    ofstream fin("Reverse.in");
    ofstream fout("Reverse.out");
    int t;
    t = random(100, 1000);
    fin << t << endl;
    while(t--){
        n = random(100, 1000);
        fin << n << endl;
        for(int i=1; i<=n; i++){
            a[i] = random(0, 10000);
            fin << a[i] << ' ';
        }
        fin << endl;
        for(int i=n; i>1; i--){
            fout << a[i] << ' ';
        }
        fout << a[1] << endl;
    }
    return 0;
}               
        
    
