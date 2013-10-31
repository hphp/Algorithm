#include<iostream>
using namespace std;
const int maxn=10005;
const int maxm=11;
const int SIZE=maxn*maxm;
typedef struct MM
{
    int love,pos;    
    }MM;
MM mm[SIZE];
int a[SIZE],b[SIZE],c[2*SIZE],use[2*SIZE],p[maxn][maxm],num[maxn];
inline int find(int x)
{
    int r=x,p;
    while(r!=c[r])r=c[r];
    while(r!=x){p=c[x];c[x]=r;x=p;}
    return r;
    }
inline void unit(int u,int v){c[u]=v;}    
void paidui(MM mm[],int a[],int n)//待处理序列，存放序列，序列长度 
{
    int i,j,k,t;
    for(i=1;i<=n*2;i++){c[i]=i;use[i]=-1;}
    for(i=1;i<=n;i++)
    {
        t=mm[i].pos;             
        if(use[t]==-1)//有空位子，坐下
        {
           use[t]=mm[i].love;
           if(t>1&&use[t-1]!=-1)c[find(t-1)]=t;
           if(t+1<=n*2&&use[t+1]!=-1)c[t]=find(t+1);                                   
           }
        else //有人占了位置
        {
           k=find(t)+1;
           use[k]=mm[i].love;
           c[find(t)]=k;
           if(k+1<=n*2&&use[k+1]!=-1)c[k]=find(k+1);  
           }                  
        }
    a[0]=0;
    for(i=1;i<=n+n;i++)if(use[i]!=-1)a[++a[0]]=use[i];    
    }
/////// 树状数组        
inline int lowbit(int k){return k&(k^(k-1));}
inline int max(int x,int y){return x>y?x:y;}
int query(int x)
{
    int k=-1;
    while(x>0)
    {
          k=max(k,c[x]);
          x-=lowbit(x);    
          }
    return k;      
    }    
void add(int x,int t,int n)
{
    while(x<=n+1)
    {
          c[x]=max(c[x],t);
          x+=lowbit(x);       
          } 
    }    
int slove(int a[],int b[],int n,int m)
{
    int i,j,k,len=n*m;
    for(i=1;i<=n;i++)num[i]=0;
    for(i=0;i<=len+1;i++)c[i]=0;
    for(i=1;i<=len;i++){num[a[i]]++;p[a[i]][num[a[i]]]=i;}
/*    cout<<"a:";
    for(i=1;i<=len;i++)cout<<a[i]<<" ";
    cout<<endl;
    
    cout<<"b:";
    for(i=1;i<=len;i++)cout<<b[i]<<" ";
    cout<<endl;*/    
    
    for(i=1;i<=len;i++)for(j=m;j>=1;j--)
    {
        k=query(p[b[i]][j])+1;
        add(p[b[i]][j]+1,k,len);                                
        }
    return query(len+1);    
    }
/*int dp[2005][2005];    
int check(int a[],int n,int b[],int m)
{
    int i,j,ans=0;
    for(i=0;i<=n;i++)for(j=0;j<=m;j++)dp[i][j]=0;
    
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)
    {                
        dp[i][j]=dp[i-1][j-1];                           
        if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        ans=max(ans,dp[i][j]);                              
        }
    return ans;    
    }*/            
int main()
{
    int test,count=1,n,m,i,j,k;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    //double t1=clock();
    scanf("%d",&test);
    while(test--)
    {
          scanf("%d%d",&n,&m);
          for(i=1;i<=n*m;i++){scanf("%d%d",&mm[i].love,&mm[i].pos);}
          paidui(mm,a,n*m);      
          
          for(i=1;i<=n*m;i++){scanf("%d%d",&mm[i].love,&mm[i].pos);}
          paidui(mm,b,n*m);
          
          printf("Case #%d: %d\n",count++,slove(a,b,n,m));      
          }
    //printf("time use=%.2lf\n",clock()-t1);           
    return 0;
    }
/*
1
3 2
1 3 1 4 3 2 2 5 2 2 3 1
3 1 1 4 2 2 3 1 2 4 1 3


3 3 1 1 2 2
3 2 3 1 2 1
*/
