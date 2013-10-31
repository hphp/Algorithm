#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int random(int low, int high){
    return low+rand()%(high-low+1);
}    

int main(){
    srand(time(NULL));
    
    ofstream fin("ExchangeApples.in");
    ofstream fout("ExchangeApples.out");
    int i;
    int n;
    int t;
    int a;
    long long work;
    long long num;
    t = random(10, 100);
    fin << t << endl;
    while(t--){
        n = random(100, 1000);
        fin << n << endl;
        work=0;
        num=0;
        for(i=1;i<n;i++){
            a = random(-999, 999);
            fin << a << ' ';
            work+=(num+a)>0?(num+a):-(num+a);
            num=num+a;
        }
        fin << -num << endl;
        fout << work << endl;
    }
    return 0;
}          
