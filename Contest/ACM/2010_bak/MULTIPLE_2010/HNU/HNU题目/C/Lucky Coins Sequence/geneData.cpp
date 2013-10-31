#include<iostream>
using namespace std;

int maxn = 1000000000;

int main() {
    freopen("1.std.in","w",stdout); 
    for( int i = 1; i <= 10;i++)
         printf("%d\n",i);
    srand(time(0));
    int n = 200;
    while( n-- ) {
          int num = (1ll*rand()*rand())%maxn+1;
          cout<<num<<endl;
    }
}
