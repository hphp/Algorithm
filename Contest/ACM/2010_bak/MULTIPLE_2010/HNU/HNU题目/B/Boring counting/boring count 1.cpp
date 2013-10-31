#include<cstdio>
#include<iostream>
using namespace std;
#include<algorithm>
#include<string.h>
#include<memory.h>
const int MAXN = 210110;
//const int MAXLOG = 14;
//int rmq[MAXN][MAXLOG];
int r[MAXN];
int wa[MAXN],wb[MAXN],wv[MAXN],wws[MAXN];
int SA[MAXN];
int B[MAXN],n;
char str[ MAXN ];
int cmp(int *r,int a,int b,int l)
{return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) wws[i]=0;
     for(i=0;i<n;i++) wws[x[i]=r[i]]++;
     for(i=1;i<m;i++) wws[i]+=wws[i-1];
     for(i=n-1;i>=0;i--) sa[--wws[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
       for(p=0,i=n-j;i<n;i++) y[p++]=i;
       for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
       for(i=0;i<n;i++) wv[i]=x[y[i]];
       for(i=0;i<m;i++) wws[i]=0;
       for(i=0;i<n;i++) wws[wv[i]]++;
       for(i=1;i<m;i++) wws[i]+=wws[i-1];
       for(i=n-1;i>=0;i--) sa[--wws[wv[i]]]=y[i];
       for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
       x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
int rank[MAXN],height[MAXN];
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++) rank[sa[i]]=i;
     for(i=0;i<n;height[rank[i++]]=k)
     for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
     return;
}

int stack[ MAXN ],top;
long long ans;
void scan(int h)
{
     int i,J,k;
     int minn,maxn;
     for(i = 1;i <= n;i++)
      if(height[i] >= h)
      {
         minn = min(SA[i - 1],SA[i]);
         maxn = max(SA[i - 1],SA[i]);
         for(J = i + 1;J <= n && height[J] >= h;J++)
         {
             minn = min(minn,SA[J]);
             maxn = max(maxn,SA[J]);  
         }
         if( abs(maxn - minn) >= h ) ans++;
        i = J - 1; 
      }
}
int main()
{
    int i,J,k;
    freopen("data1.txt","r",stdin);
    freopen("ans1.txt","w",stdout);
    while( scanf("%s",str),strcmp(str,"#") )
    {

           n = strlen( str );
           for(i = 0;i < n;i++)
            r[i] = str[i];
           r[n] = 0;
           da(r,SA,n + 1,256);
           calheight(r,SA,n);
           /*
           for(i = 0;i <= n;i++)
           {
               printf("%s\n",str + SA[i]);
           }
           putchar('\n');
           for(i = 1;i <= n;i++)
            printf("%d ",height[i]);
           putchar('\n'); */  
          ans = 0;
          for(i = 1;(i<<1) <= n;i++)
           scan(i);
         cout<<ans<<endl;  
    }
  return 0;
}  
