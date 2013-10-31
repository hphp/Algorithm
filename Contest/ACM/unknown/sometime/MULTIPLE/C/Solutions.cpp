#include<iostream>

#include<algorithm>

using namespace std;

typedef long long ll;

#define FORD(i,b,c) for(int(i)=(b);(i)>=c;(i)--)

#define REPD(i,b) FORD(i,b,0)

#define FOR(i,b,c) for(int i=(b);i<(c);i++)

#define REP(i,c) FOR(i,0,c)

#define INT_MAX (1<<29)

//const int dm[8][2]={{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};

//const int dm[8][2]={{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2}};

//const int dm[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

#define maxn 352716 //C[21][10]

int C[50][50],G[30][30];

int dp[2][maxn+5][21];

void init(){

   C[1][0]=C[1][1]=1;

   FOR(i,1,50){

      FOR(j,0,i+1){

         if(j==0||i==j)C[i][j]=1;

         else C[i][j]=C[i-1][j]+C[i-1][j-1];

      }

   }

}

struct dalong{

   int pre,nxt;

}cd[20];

int m;

bool control(int sta,int k){

   REP(i,m){

       if(cd[i].pre==0)continue;

       if(k==cd[i].nxt-1&&(((1<<(cd[i].pre-1))&sta)==0))return false;

   }

   return true;

}

int now,nxt;

inline int getsta(int n,int k,int rank){

   int ret=0;

   for(;k!=0;n--)if(rank>C[n-1][k]){

      rank-=C[n-1][k--];

      ret|=(1<<(n-1));

   }

   return ret;

}

void transfer(int n,int x,int idx,int s){

   if(n==x)return;

   int ret=0,pre=0,res[22],sta=getsta(n,x,idx+1);

   REPD(i,n-1){

      if(((1<<i)&sta)!=0){

         pre+=C[i][x+1];

         ret+=C[i][x--];

      }else{

         res[i]=pre+C[i][x+1]-ret;

      }

   }

   REP(i,n)if(((1<<i)&sta)==0&&G[s+1][i+1]!=-1){

      if(control(sta,i)==false)continue;

      res[i]+=ret;

      dp[nxt][res[i]][i]=min(dp[nxt][res[i]][i],dp[now][idx][s]+G[s+1][i+1]);

   }

}

int solve(int n){

   if(n==1)return 0;

   now=0;

   nxt=1;

   n--;

   REP(i,C[n][1])REP(j,n)dp[now][i][j]=INT_MAX;

   REP(i,n)if(G[0][i+1]!=-1){
       if(control(0,i)){
      dp[now][i][i]=G[0][i+1];

       }          

   }

   REP(i,n){

      REP(j,C[n][i+2])REP(k,n)dp[nxt][j][k]=INT_MAX;

      REP(j,C[n][i+1])REP(k,n)if(dp[now][j][k]<INT_MAX){

         transfer(n,i+1,j,k);

      }

      swap(now,nxt);

   }

   int ans=INT_MAX;

   REP(i,n)ans=min(dp[nxt][0][i],ans);

   if(ans==INT_MAX)ans=-1;

   return ans;

}

int main(){

   init();

   int n;

   while(scanf("%d%d",&n,&m)!=EOF&&n){

      REP(r,n)REP(c,n)scanf("%d",&G[r][c]);

      REP(i,m)scanf("%d%d",&cd[i].pre,&cd[i].nxt);

      printf("%d\n",solve(n));

   }

}
