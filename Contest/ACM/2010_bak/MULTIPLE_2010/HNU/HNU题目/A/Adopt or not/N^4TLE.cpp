#include<stdio.h>
#include<string.h>
#include<time.h>

#define N 205

int a,b,n;
int g[N][N]; 
int info[N][N];

void build()
{
     scanf("%d %d %d",&a,&b,&n);
     
     memset(info,0,sizeof(info));
     memset(g,0,sizeof(g));
     
     int i,j,k,x,y,m;
     for(i=1;i<=n;i++)
     {
         scanf("%d %d",&info[i][0],&m);
         for(j=1;j<=m;j++)
         {
             scanf("%d",&x);
             info[i][x]=1;
         }
     }
     
     for(i=1;i<=n;i++)
     for(j=i+1;j<=n;j++)
     {
         if(info[i][info[j][0]] || info[j][info[i][0]])
         g[i][j]=g[j][i]=1;
     }
}

int link[N];
int flag[N];
int ans[N],del[N];

int find(int x)
{
    for(int i=1;i<=n;i++)
    if(g[x][i] && !flag[i] && !del[i])
    {
        flag[i]=1;
        if(!link[i] || find(link[i]))
        {
            link[i]=x;
            return 1;
        }
    }
    return 0;
}

int hungary()
{
    memset(link,0,sizeof(link));
    int i,ans=0;
    for(i=1;i<=n;i++)
    if(!del[i])
    {
        memset(flag,0,sizeof(flag));
        if(find(i))ans++;
    }
    return ans/2;
}

void solve()
{
     memset(link,0,sizeof(link));
     
     int i,max=hungary();
     printf("%d\n",n-max);
     
     memset(ans,0,sizeof(ans));
     memset(del,0,sizeof(del));
     
     for(i=1;i<=n;i++)
     {
         del[i]=1;
         
         int match=hungary();
         if(match==max)
         ans[info[i][0]]=1;
         
         del[i]=0;
     }
     
     int cnt=0;
     for(i=1;i<=a+b;i++)
     if(ans[i])cnt++;
     
     printf("%d",cnt);
     
     for(i=1;i<=a+b;i++)
     if(ans[i])
     printf(" %d",i);
     puts("");
}

int main()
{
   //double st=clock();
    
  //  char read[10]="in1.txt";
  //  char write[10]="N4 1.txt";
    
   // for(read[2]='1';read[2]<='5';read[2]++)
   // {
      //  write[3]=read[2];
        
      //  freopen(read,"r",stdin);
      //  freopen(write,"w",stdout);
        
        int t,cnt=0;
        scanf("%d",&t);
        while(t--)
        {
              build();
              solve();
        }
    //}
    //printf("time=%.0lfms\n",clock()-st);
    //while(1);
}
