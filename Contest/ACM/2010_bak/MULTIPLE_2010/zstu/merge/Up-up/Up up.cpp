#include<stdio.h>
#include<math.h>
typedef __int64 lld;
const lld MAX=10005;
const lld MOD=100000000;
bool is[MAX]={0};
lld p[MAX],c;
lld mod(lld a,lld b,lld m)
{
	lld ret=1;
	a%=m;
	while(b)
	{
		if(b&1)
			ret=ret*a%m;
		a=a*a%m;
		b>>=1;
	}
	return ret;
}
lld large(lld a,lld b,lld m)
{
	lld ret=1;
	for(;b>0&&ret<m;b--)
		ret*=a;
	return ret>=m;
}
lld fphi(lld n)
{
	lld k=sqrt(n),i,tmp=n;
	for(i=0;p[i]<=k&&n>1;i++)
	{
		if(n%p[i]==0)
		{
			tmp-=tmp/p[i];
			while(n%p[i]==0)
				n/=p[i];
		}
	}
	if(n>1)
		tmp-=tmp/n;
	return tmp;
}
lld up(lld a,lld k,lld m)
{
	lld phi,ans,bk;
	if(k==1)
		return a%m;
	phi=fphi(m);
	bk=up(a,k-1,phi);
	ans=mod(a,bk,m);
	ans+=large(a,bk,m)*m;
	return ans;
}
int main()
{
	lld i,j,a,k;
	is[0]=is[1]=1;
	for(i=2;i*i<MAX;i++)
	{
		if(!is[i])
		{
			for(j=i*i;j<MAX;j+=i)
				is[j]=1;
		}
	}
	for(i=2,c=0;i<MAX;i++)
	{
		if(!is[i])
			p[c++]=i;
	}
//	freopen("Up-up.in","r",stdin);
//	freopen("Up-up.out","w",stdout);
	while(scanf("%I64d%I64d",&a,&k)!=EOF)
		printf("%I64d\n",up(a,k,MOD)%MOD);
	return 0;
}
