#include <iostream>
using namespace std;
int main(){
    freopen("abc.in", "r", stdin);
    freopen("abc.out", "w", stdout);
    int i;
    int n;
    int t;
    int a;
    long long work;
    long long num;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        work=0;
        num=0;
        for(i=0;i<n;i++){
            scanf("%d",&a);
            work+=(num+a)>0?(num+a):-(num+a);
            num=num+a;
        }
        printf("%lld\n",work);
    }
    return 0;
}          
