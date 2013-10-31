#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int arr[10000];
int res[10000];

int random(int low, int high){
    return low+rand()%(high-low+1);
}    

int main(){
    srand(time(NULL));
    ofstream fin("input.in");
    ofstream fout("output.out");

    int n;
    for(int t=0; t<10; t++){
        n = random(5, 9999);
        fin << n << endl;
        arr[0] = random(1, 100);
        fin << arr[0];
        for(int i=1; i<n; i++){
            arr[i] = random(1, 100);
            fin << ' ' << arr[i];
        }
        fin << endl;
        for(int i=0; i<n; i++){
            res[i] = (arr[(n+i-1)%n]+1)/2 + arr[(i+1)%n]/2; 
        }   
        fout << res[0];
        for(int i=1; i<n; i++){
            fout << ' ' << res[i];
        }    
        fout << endl;
    }
    return 0;        
}    
