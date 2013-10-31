#include<stdio.h>
#include<string.h>
int start[200005],len[200005],seq[200005],last[86405];
struct
{
	int l,r,maxi;
}tree[800005];
int ll(int i)
{return i<<1;}
int rr(int i)
{return (i<<1)+1;}
int Maxi(int a,int b)
{
	if(a>b)
		return a;
	return b;
}
void build(int l,int r,int t)
{
	int mid=(l+r)/2;
	tree[t].l=l;
	tree[t].r=r;
	if(l==r)
	{
		tree[t].maxi=len[l];
		return ;
	}
	build(l,mid,ll(t));
	build(mid+1,r,rr(t));
	tree[t].maxi=Maxi(tree[ll(t)].maxi,tree[rr(t)].maxi);
}
int query(int l,int r,int t)
{
	int mid=(tree[t].l+tree[t].r)/2,t1,t2;
	if(l<=tree[t].l&&r>=tree[t].r)
		return tree[t].maxi;
	if(l>mid)
		return query(l,r,rr(t));
	else if(r<=mid)
		return query(l,r,ll(t));
	else
	{
		t1=query(l,mid,ll(t));
		t2=query(mid+1,r,rr(t));
		return t1>t2?t1:t2;
	}
}
int binary_search(int l,int r)
{
	int des=l,mid,ret=l;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(start[mid]>des)
		{
			ret=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	return ret;
}
int main()
{
	int i,n,m,mid,t;
	int a,b,ret,tmp;
	//freopen("data1_in.txt","r",stdin);
	//freopen("data1_out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		tmp=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&seq[i]);
			if(seq[i]>tmp)
				tmp=seq[i];
		}		
		for(i=1;i<=tmp;i++)
			last[i]=0;
		start[1]=1;
		len[1]=1;
		last[seq[1]]=1;
		for(i=2;i<=n;i++)
		{
			start[i]=Maxi(start[i-1],last[seq[i]]+1);
			len[i]=i-start[i]+1;
			last[seq[i]]=i;
		}
		build(1,n,1);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			if(a>b)
			{
				t=a;
				a=b;
				b=t;
			}
			if(start[b]<=a)
				ret=b-a+1;
			else
			{
				mid=binary_search(a,b);
				ret=Maxi(mid-a,query(mid,b,1));
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}
