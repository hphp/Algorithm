#include<stdio.h>
#include<string.h>
const int MAXP=24*3600+100;
const int MAXN=200005;
int dp[MAXN][20];
int pos[MAXP];
int ans[MAXN],Log[MAXN];
void getRMQ(int v[],int n)
{
	int i,j,x,y;
	for(i=1;i<=n;i++)
		dp[i][0]=v[i];
	for(j=1;(1<<j)<=n;j++)
	{
		for(i=1;i+(1<<j)-1<=n;i++)
		{
			x=dp[i][j-1];
			y=dp[i+(1<<j>>1)][j-1];
			if(x>y)dp[i][j]=x;
			else  dp[i][j]=y;
		}
	}
}
int askRMQ(int s,int e)
{
	int t=Log[e-s+1];
	int x=dp[s][t];
	int y=dp[e-(1<<t)+1][t];
	if(x>y)return x;
	return y;
}
void swap(int &a,int &b)
{
	int t=a;
	a=b;
	b=t;
}
int bin(int l,int r)
{
	int best=r+1,mid;
	const int lim=l;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(mid-ans[mid]+1>=lim)
		{
			best=mid;
			r=mid-1;
		}
		else l=mid+1;
	}
	return best;
}
int main()
{
	int n,m;
	int i;
	Log[0]=-1;
	for(i=1;i<MAXN;i++)
	{
		Log[i]=Log[i-1];
		if(!(i&(i-1)))
			Log[i]++;
	}
	while(scanf("%d",&n)!=EOF)
	{
		memset(pos,0,sizeof(pos));
		int j,tmp;
		ans[0]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&j);
			tmp=i-ans[i-1];
			if(pos[j]+1>tmp)tmp=pos[j]+1;
			ans[i]=i-tmp+1;
			pos[j]=i;
			//printf("ans[%d]=%d\n",i,ans[i]);
		}
		//puts("ok");
		//getRMQ(ans,n);
		scanf("%d",&m);
		int xx,xxx;
		while(m--)
		{
			scanf("%d%d",&i,&j);
			if(i>j)swap(i,j);
			/*tmp=bin(i,j);
			//printf("tmp=%d\n",tmp);
			xx=0;
			if(tmp-1>=i)
				xx=tmp-i;
			xxx=0;
			if(tmp<=j)
				xxx=askRMQ(tmp,j);
			if(xx>xxx)xxx=xx;*/
			xxx=0;
			int k;
		
			for(k=i;k<=j;k++)
			{
				if(k-ans[k]+1>=i)tmp=ans[k];
				else tmp=k-i+1;
				if(tmp>xxx)xxx=tmp;
			}
			printf("%d\n",xxx);
		}
	}
	return 0;
}
