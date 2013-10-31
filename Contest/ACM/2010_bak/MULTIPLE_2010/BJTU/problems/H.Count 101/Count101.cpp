#include<cstring>
#include<iostream>

using namespace std;

const int module=9997;

int ans[10000];
int d[10000],e[10000];
int n;

int main(){
    freopen("count101.in","r",stdin);
    freopen("count101.ans","w",stdout);
    d[1]=e[1]=1;d[2]=e[2]=2;
    for (int i=3;i<10000;i++){
        d[i]=(d[i-1]+e[i-2])%module;
        e[i]=(d[i-1]+e[i-1])%module;
    }
    for (int i=1;i<10000;i++) ans[i]=(d[i]+e[i])%module;
    while (cin >> n,n!=-1){
          cout << ans[n] << endl;
          }
    return 0;
}
