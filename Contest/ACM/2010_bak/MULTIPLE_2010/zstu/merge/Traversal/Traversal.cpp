#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAX=100005;
int dcre[MAX],c;
int h[MAX],v[MAX];
int dp[MAX];
struct seg_tree
{
	int l,r,max_;
	int mid(){return (l+r)>>1;}
}node[MAX<<2];
int bin(int aim)
{
	int low=0,high=c-1;
	int mid;
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(dcre[mid]==aim)return mid;
		if(dcre[mid]<aim)low=mid+1;
		else high=mid-1;
	}
	return -1;
}
void clr(int l,int r,int tag)
{
	node[tag].l=l;
	node[tag].r=r;
	node[tag].max_=0;
	if(l==r-1)return ;
	int mid=node[tag].mid();
	clr(l,mid,tag<<1);
	clr(mid,r,1+(tag<<1));
}
int query(int l,int r,int tag)
{
	if(l<=node[tag].l&&node[tag].r<=r)
		return node[tag].max_;
	int mid=node[tag].mid();
	if(r<=mid)return query(l,r,tag<<1);
	else if(l>=mid)return query(l,r,1+(tag<<1));
	else
	{
		int a=query(l,mid,tag<<1);
		int b=query(mid,r,1+(tag<<1));
		if(a>b)return a;
		return b;
	}
	return -1;
}
void ins(int id,int v,int tag)
{
	if(v>node[tag].max_)
		node[tag].max_=v;
	if(node[tag].l==node[tag].r-1)return ;
	int mid=node[tag].mid();
	if(id<mid)ins(id,v,tag<<1);
	else ins(id,v,1+(tag<<1));
}
bool cmp(int a,int b){return a<b;}
int main()
{
	int i,n,j;
	//freopen("traval0.in","r",stdin);
	//freopen("traval0.out","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&h[i],&v[i]);
			dcre[c++]=h[i];
		}
		sort(dcre,dcre+c,cmp);
		j=1;
		for(i=1;i<c;i++)
		{
			if(dcre[i]!=dcre[i-1])
				dcre[j++]=dcre[i];
		}
		c=j;
		for(i=0;i<n;i++)
			h[i]=bin(h[i])+1;
		clr(0,c+1,1);
		int ans=0,tmp;
		for(i=0;i<n;i++)
		{
			tmp=query(0,h[i],1)+v[i];
			if(tmp>ans)ans=tmp;
			ins(h[i],tmp,1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
