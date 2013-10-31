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
#define FORD(i,b,c) for(int(i)=(b);(i)>=c;(i)--)
#define REPD(i,b) FORD(i,b,0)
#define FOR(i,b,c) for(int i=(b);i<(c);i++)
#define REP(i,c) FOR(i,0,c)
#define PQ priority_queue
//const int dm[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};
//const int dm[8][2]={{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};
//const int dm[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int G[30][30],dp[1<<21][21];
struct dalong{
   int pre,nxt;
}cd[20];
int m;
bool control(int sta,int k){
   REP(i,m)if(k==cd[i].nxt&&(((1<<cd[i].pre)&sta)==0))return false;
   return true;
}
int solve(int n){
   REP(i,(1<<n))REP(j,n)dp[i][j]=-1;
   dp[1][0]=0;
   REP(i,(1<<n))REP(j,n)if(dp[i][j]!=-1)
      REP(k,n)if(((1<<k)&i)==0&&G[j][k]!=-1){
         if(control(i,k)==false)continue;
         if(dp[(1<<k)|i][k]==-1)dp[(1<<k)|i][k]=dp[i][j]+G[j][k];
         else dp[(1<<k)|i][k]=min(dp[i][j]+G[j][k],dp[(1<<k)|i][k]);
      }
   int ans=INT_MAX;
   REP(i,n)if(dp[(1<<n)-1][i]!=-1)ans=min(dp[(1<<n)-1][i],ans);
   if(ans==INT_MAX)ans=-1;
   return ans;
}
int main(){
   int n;
   freopen("bigdata.in","r",stdin);
   freopen("bruteforcebigdata.out","w",stdout);
   while(scanf("%d%d",&n,&m)!=EOF){
      REP(r,n)REP(c,n)scanf("%d",&G[r][c]);
      REP(i,m)scanf("%d%d",&cd[i].pre,&cd[i].nxt);
      printf("%d\n",solve(n));
   }
}
/*
5
-1 2 6 5 2
5 -1 1 2 9
7 8 -1 6 9
9 3 6 -1 2
2 9 8 4 -1
*/
