#include<stdio.h>
#include<string.h>
#include<time.h>

#define N 205

int a,b,n;
int g[N][N]; 
int info[N][N];
int id[2][N],num[2];

void build()
{
     scanf("%d %d %d",&a,&b,&n);
     
     memset(num,0,sizeof(num));
     memset(info,0,sizeof(info));
     memset(g,0,sizeof(g));
     
     int i,j,k,x,y,m;
     for(i=1;i<=n;i++)
     {
         scanf("%d %d",&info[i][0],&m);
         
         if(info[i][0]<=a)
         {
            id[0][++num[0]]=i;
         }
         else
         {
            id[1][++num[1]]=i;
         }
         
         for(j=1;j<=m;j++)
         {
             scanf("%d",&x);
             info[i][x]=1;
         }
     }
     
     for(i=1;i<=num[0];i++)
     for(j=1;j<=num[1];j++)
     {
         x=id[0][i];
         y=id[1][j];
         
         if(info[x][info[y][0]] || info[y][info[x][0]])
         g[i][j]=1;
     }
}

int linkx[N],linky[N];
int flag[N];

int find(int x)
{
    for(int i=1;i<=num[1];i++)
    if(g[x][i] && !flag[i])
    {
        flag[i]=1;
        if(!linkx[i] || find(linkx[i]))
        {
            linkx[i]=x;
            linky[x]=i;
            return 1;
        }
    }
    return 0;
}

int ans[N],del[N];

int checkx(int x)
{
    for(int i=1;i<=num[1];i++)
    if(g[x][i] && !flag[i] && !del[i])
    {
        flag[i]=1;
        if(!linkx[i] || checkx(linkx[i]))
        {
            return 1;
        }
    }
    return 0;
}

int checky(int y)
{
    for(int i=1;i<=num[0];i++)
    if(g[i][y] && !flag[i] && !del[i])
    {
        flag[i]=1;
        if(!linky[i] || checky(linky[i]))
        {
            return 1;
        }
    }
    return 0;
}

void solve()
{
     memset(linkx,0,sizeof(linkx));
     memset(linky,0,sizeof(linky));
     
     int i,match=0;
     for(i=1;i<=num[0];i++)
     {
         memset(flag,0,sizeof(flag));
         if(find(i))match++;
     }
     printf("%d\n",n-match);
     
     memset(ans,0,sizeof(ans));
     memset(del,0,sizeof(del));
     
     for(i=1;i<=num[0];i++)
     if(!linky[i])
     {
         ans[info[id[0][i]][0]]=1;
     }
     for(i=1;i<=num[1];i++)
     if(!linkx[i])
     {
         ans[info[id[1][i]][0]]=1;
     }
     
     for(i=1;i<=num[0];i++)
     if(linky[i])
     {
         memset(flag,0,sizeof(flag));

         del[linky[i]]=1;
         if(checkx(i))ans[info[id[1][linky[i]]][0]]=1;
         del[linky[i]]=0;
         
         memset(flag,0,sizeof(flag));
         
         del[i]=1;
         if(checky(linky[i]))ans[info[id[0][i]][0]]=1;
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
    
    //char read[10]="in2.txt";
    //char write[10]="out1.txt";
    
    //for(read[2]='1';read[2]<='5';read[2]++)
    //{
    //    write[3]=read[2];
        
        freopen("std.in","r",stdin);
        freopen("std.out","w",stdout);
        
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
