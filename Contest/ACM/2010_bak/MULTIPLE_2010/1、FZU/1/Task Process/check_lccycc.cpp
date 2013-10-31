#include <iostream>
using namespace std;
inline int Max(int a,int b){return a>b?a:b;}
const int maxn=60,maxm=210;
int f[maxm];
int a[maxn],b[maxn];
int n,x,y;
int dp(int T)
{
	int i,j,k;
	memset(f,0,sizeof(f));
	for (i=1;i<maxm;i++) f[i]=-999999999;
	for (i=1;i<=n;i++)
		for (j=x;j>=0;j--)
		{
			f[j]+=T/b[i];
			for (k=0;k<j;k++) if (T>=(j-k)*a[i]) 
				f[j]=Max(f[j],f[k]+(T-(j-k)*a[i])/b[i]);
		}
	return f[x]>=y;
}
int main()
{
	//freopen("in","r",stdin);
	//freopen("G:\out.out","w",stdout);
	int i,j,cas=0,cass;
	for (scanf("%d",&cass);cass--;)
	{
		cas++;
		scanf("%d%d%d",&n,&x,&y);
		for (i=1;i<=n;i++) scanf("%d%d",a+i,b+i);
		int l=0,r=a[1]*x+b[1]*y;
		while (l+1<r)
		{
			int mid=(l+r)/2;
			if (dp(mid)) r=mid;else l=mid;
		}
		printf("Case %d: %d\n",cas,r);
	}
	return 0;
}

			

