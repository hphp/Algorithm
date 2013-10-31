#include<iostream>
#include<algorithm>
using namespace std;
int a[100001],b[100001],c[1001];
int main()
{
    int test=5,n,m,i,j,k,x,len,mod;
    srand(time(NULL));
    freopen("in.txt","w",stdout);
    printf("%d\n",test); 
    string s;    
    while(test--)
    {
          n=rand()%1000+1;m=rand()%10+1;len=0;
          n=10000;m=10;mod=n*m;len=0;

          printf("%d %d\n",n,m);
          for(i=1;i<=n;i++)for(j=1;j<=m;j++){a[len++]=i;b[len-1]=rand()%mod+1;}
          random_shuffle(a,a+len);

          /////
          /*memset(c,0,sizeof(c));
          for(i=0;i<len;i++)c[a[i]]++;
          for(i=1;i<=n;i++)if(c[i]!=m)break;
          if(i==n+1)continue;
          puts("NO");*/
          ///// 
          
          for(i=0;i<len;i++)printf("%d %d ",a[i],b[i]);
          printf("\n");
          
          
          n=10000;m=10;mod=n*m;len=0; 
          for(i=1;i<=n;i++)for(j=1;j<=m;j++){a[len++]=i;b[len-1]=rand()%mod+1;}
          random_shuffle(a,a+len); 
          for(i=0;i<len;i++)printf("%d %d ",a[i],b[i]);
          printf("\n");         
          } 
    return 0;
    }
