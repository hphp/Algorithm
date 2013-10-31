#include <stdio.h>
#define N 50010
#define CON 1000000007
typedef int Int;

struct Node
{
	int s,e;
	Int sum;
}node[N*4];

int n,m;

void build(int s,int e,int root)
{
	node[root].s=s;
	node[root].e=e;
	node[root].sum=0;
	int mid = (s+e)/2;
	if(s>=e)
		return;
	build(s,mid,2*root);
	build(mid+1,e,2*root+1);
}

void change(int s,int e,int ch,int root)
{
	int fs  = node[root].s;
	int fe = node[root].e;
	if(s<=fs&&e>=fe)
	{
		node[root].sum = ch;
	}
	else
	{
		int mid = (fs+fe)/2;
		if(s<=mid)
		{
			change(s,e,ch,2*root);
		}
		if(e>mid)
		{
			change(s,e,ch,2*root+1);
		}
		node[root].sum = (node[2*root].sum*node[2*root+1].sum)%CON;
	}
}

Int query(int s,int e,int root)
{
	int fs=node[root].s;
	int fe=node[root].e;
	if(s<=fs&&e>=fe)
	{
		return node[root].sum;
	}
	else
	{
		int mid = (fs+fe)/2;
		Int sum = 1;
		if(s<=mid)	
		{
			sum *= query(s,e,2*root);
			sum %= CON;
		}
		if(e>mid)
		{
			sum *= query(s,e,2*root+1);
			sum %= CON;
		}
		return sum;
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	int a,b,c;
	while(test--)
	{
		scanf("%d",&n);
		build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			change(i,i,a,1);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			if(a==0)
			{
				Int sum = query(b,c,1);
				printf("%d\n",sum);
			}
			else
			{
				change(b,b,c,1);
			}
		}
	}
	return 0;
}
