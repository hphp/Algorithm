#include<iostream>
#include<algorithm>
#include<utility>
#include<limits>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<ctime>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define INF 1e15
#define eps 1e-15
#define see(x) (cout<<"[Line : "<< __LINE__<<"] : "<<#x<<"="<<x<<endl)
#define spa system("pause")
#define clr clear
#define PB push_back
#define SZ(x) (x).size()
#define MP make_pair
#define X first
#define Y second
#define PII pair<int,int>
#define VI vector<int>
#define VD vector<double>
#define VS vector<string>
#define FORD(i,b,c) for((i)=(b);(i)>=c;(i)--)
#define REPD(i,c) FORD(i,c,0)
#define FOR(i,b,c) for(int i=(b);i<(c);i++)
#define REP(i,c) FOR(i,0,c)
#define PQ priority_queue
//const int dm[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
//const int dm[8][2]={{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
//const int dm[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int G[30][30];
int main(){
   int T=1,n,m;
   freopen("11.in","w",stdout);
   srand(time(0));
   while(T--){
      do {n=rand()%15+1;m=rand()%4;}while(m>=n);
      n=18;m=0;
      printf("%d %d\n",n,m);
      REP(i,n)REP(j,n)if(i==j) G[i][j]=-1;else G[i][j]=1;
      REP(r,n)REP(c,n)printf("%d%c",(G[r][c]==0||r==c)?-1:G[r][c],c==n-1?'\n':' ');
      while(m--){
         int a,b;
         do{a=rand()%n;b=rand()%n;}while(a==b||b==0);
         printf("%d %d\n",a,b);
      }
   }
   //REP(r,n)REP(c,n)printf("%d%c",(G[r][c]==0||r==c)?-1:G[r][c],c==n-1?'\n':' ');
}
