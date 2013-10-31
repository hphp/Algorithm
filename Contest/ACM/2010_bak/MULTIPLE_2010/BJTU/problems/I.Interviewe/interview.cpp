#include<cstring>
#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=262145;
const int maxm=20;

int ans,n,k;
int a[maxn];
int f[maxn][maxm];
int base[maxn];

void init(){
     memset(a,0,sizeof(a));
     memset(f,0,sizeof(f));
     memset(base,0,sizeof(base));
     for (int i=0;i<n;i++)
         scanf("%d",&a[i]);
     for (int i=2;i<=n;i++)
         base[i]=base[i>>1]+1;
     }
     
int max(int a,int b){
    return a>b?a:b;
    }

void prepare(){
     for (int i=0;i<n;i++)
         f[i][0]=a[i];
     for (int i=1;(1<<i)<=n;i++)
         for (int j=0;j<n;j++){
             if (j+(1<<i)/2<n)
                f[j][i]=max(f[j][i-1],f[j+(1<<i)/2][i-1]);
             else f[j][i]=f[j][i-1];
             }
     }
     
int _max(int l,int r){
    int len=base[r-l];
    if (l+(1<<len)==r)
       return f[l][len];
    if (l+(1<<len)>r) len-=1;
    return max(f[l][len],f[r-(1<<len)][len]);
    }

void work(){
     ans=-1;
     for (int i=n;i>=1;i--){
         int total=0,cur=0;
         for (int j=0;j<n/i;j++){
             total+=_max(j*i,(j+1)*i);
             cur++;
             if (total>k){
                          ans=cur;
                          return;
                          }
         }
     }
     }
     
void work2(){
     for (int i=1;i<=n;i++){
         int total=0;
         for (int j=0;j<i;j++){
             int cur=0;
             for (int t=j*(n/i);t<(j+1)*(n/i);t++)
                 if (a[t]>cur) cur=a[t];
             total+=cur;
         }
         if (total>k){
                      cout << i << endl;
                      return;
                      }
     }
     cout << -1 << endl;
     }

int main(){
    freopen("interview.in","r",stdin);
    freopen("interview.ans","w",stdout);
    while (scanf("%d%d",&n,&k)>0,n!=-1){
        init();
        prepare();
        work();
        cout << ans << endl;
      //  work2();
        }
    return 0;
}
