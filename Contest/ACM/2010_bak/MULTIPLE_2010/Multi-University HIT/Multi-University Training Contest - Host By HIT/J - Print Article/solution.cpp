#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
long long num[500005];
long long sum[500005];
long long head,tail;
long long a[500005];
long long dp[500005];
long long G(long long a,long long b)
{
  return dp[a]+sum[a]*sum[a]-dp[b]-sum[b]*sum[b];
}
long long S(long long a,long long b)
{
  return 2*(sum[a]-sum[b]);
}
long long front(long long t)
{
    while (head-tail>0&&G(a[tail],a[tail+1])>=t*S(a[tail],a[tail+1]))
        tail++;
    return a[tail];
}
long long push(long long t)
{
    while (head-tail>0&&G(t,a[head])*S(a[head],a[head-1])<=G(a[head],a[head-1])*S(t,a[head]))
        head--;
    a[++head]=t;
}
int main()
{
    long long n,m;
    long long i,j;
   //freopen("in.txt","r",stdin);
    while (scanf("%lld %lld",&n,&m)==2)
    {
        head=0;
        tail=1;
        memset(num,0,sizeof(num));
        memset(sum,0,sizeof(sum));
        for (i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            sum[i]=num[i]+sum[i-1];
        }
        push(0);
        for(i=1;i<=n;i++)
           {
            j=front(sum[i]);
             dp[i]=dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
             push(i);
           }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
