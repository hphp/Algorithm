#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 560
#define M 100110
int pre[N],num[N];

struct Node
{
	int s,e;
	int sum;
}node[M*4];

struct Segment
{
//	int blng;
	int avl;//-1not useable;
	int s,e;
};

struct Group
{
	int id;
	int owncnt;
	Segment own[N];
}group[N];
int ID[M],n;//,index[N],n;

bool cmp(Segment a,Segment b)
{
	if(a.s<b.s)	
		return 1;
	else if(a.s>b.s)
		return 0;
	else
	{
		if(a.e<b.e)	
			return 1;
			return 0;
	}
}

void ch_init()
{
	for(int i=0;i<N;i++)
	{
		pre[i]=-1;
		num[i]=-1;
	}
}
int find(int x)
{
	int r = x,tmp;
	while(pre[r]!=-1)
		r=pre[r];
	while(x!=r)
	{
		tmp = pre[x]	;
		pre[x]=r;
		x=tmp;
	}
	return r;
}void merge(int,int,int);
int conbination(int a,int b)
{
	int a1,b1;
	a1=find(a);
	b1=find(b);
	if(a1==b1)
		return 0;
	if(num[a1]<=num[b1])
	{
		pre[b1]=a1;
		num[a1]+=num[b1];
		merge(a1,b1,a1);
	}
	else 
	{
		pre[a1]=b1;
		num[b1]+=num[a1];
		merge(a1,b1,b1);
	}
	return 0;
}
void change(int,int,int,int);
void merge(int a,int b,int boss)
{
	Segment backup[10*N];
	int i=0;
	int j=0;
	int cnt =0;
	while(i<group[a].owncnt&&j<group[b].owncnt)
	{
		if(group[a].own[i].s<group[b].own[j].s&&group[a].own[i].e<group[b].own[j].s)
		{
		backup[cnt].s = group[a].own[i].s;
		backup[cnt].e = group[b].own[i].e;
		cnt++;
		i++;
		}
		else break;
	}
	while(i<group[a].owncnt&&j<group[b].owncnt)
	{
		if(group[a].own[i].s>group[b].own[j].e)
		{
		backup[cnt].s = group[a].own[i].s;
		backup[cnt].e = group[b].own[i].e;
		cnt++;
		j++;
		}
		else break;
	}
	while(i<group[a].owncnt&&j<group[b].owncnt)
	{
		if(group[a].own[i].e<group[b].own[j].s)
		{
			backup[cnt].e = group[a].own[i].e;
			cnt++;
			i++;continue;	
		}
		if(group[a].own[i].s>group[b].own[j].e)
		{
			backup[cnt].e = group[b].own[j].e;
			cnt++;
			j++;continue;		
		}
		Segment ba = group[a].own[i];
		Segment bb = group[b].own[j];
		backup[cnt].s = ba.s<bb.s?ba.s:bb.s;
		if(ba.e>bb.s)
		{
			change(bb.s,ba.e,-1,1);
			i++;
			continue;
		}
		if(bb.e>ba.s)
		{
			change(bb.e,ba.s,-1,1);
			j++;continue;
		}
/*		int ds = ba.s>bb.s?ba.s:bb.s;
		int de = ba.e<bb.e?ba.e:bb.e;
		change(ds,de,-1,1);*/
	}
/*			group[a].own[i].avl = -1;
			group[b].own[j].avl = -1;
				int ls = ba.s<bb.s?ba.s:bb.s;
			int re = ba.e>bb.e?ba.e:bb.e;
			if(ls<ds)
			{
				backup[cnt].s = ls;
				backup[cnt].e = ds-1;
				cnt++;
			}
			backup[cnt].s=ds;
			backup[cnt].e=de;
			cnt++;
			if(de<re)
			{
				backup[cnt].s = de+1;
				backup[cnt].e = re;
				cnt++;
			}
		}
	}
	for(int j=0;j<group[a].owncnt;j++)
		if(group[a].own[j].avl==-1)
		{
			backup[cnt]=group[a].own[j];
			cnt++;
		}
	for(int j=0;j<group[a].owncnt;j++)
		if(group[a].own[j].avl==-1)
		{
			backup[cnt]=group[a].own[j];
			cnt++;
		}*/
	sort(backup,backup+cnt,cmp);
	Segment ans[N];
	ans[0].s=backup[0].s;
	int anscnt=0;
	for(int i=1;i<cnt;i++)
	{
		if(backup[i].s>backup[i-1].e)	
		{
			ans[anscnt].e= backup[i-1].e;
			anscnt++;
			ans[anscnt].s = backup[i].s;
		}
	}
	ans[anscnt].e=backup[cnt-1].e;
	anscnt++;
	group[boss].owncnt = anscnt;
	for(int i=0;i<cnt;i++)
	{
		group[boss].own[i]=ans[i];
	}
}

void init()
{
	for(int i=0;i<M;i++)
	{
		ID[i]=-1;
	}
	for(int i=0;i<N;i++)
	{
		group[i].owncnt =0;
	}
	n=0;
	ch_init();
}

void build(int s,int e,int root)
{
	node[root].s=s;
	node[root].e=e;
	node[root].sum =0;
	if(s==e)
		return;
	int mid = (s+e)/2;
	build(s,mid,2*root);
	build(mid+1,e,2*root+1);
}

void change(int s,int e,int ch,int root)
{
	int fs = node[root].s;
	int fe = node[root].e;
	if(s<=fs&&e>=fe)
	{
		node[root].sum += ch;
		return ;
	}
	else
	{
		int mid = (fs+fe)/2;
		if(s<=mid)
		{
			change(s,e,ch,root*2);
		}
		if(e>mid)
		{
			change(s,e,ch,root*2+1);
		}
	}
}

int query(int s,int e,int root)
{
	int fs = node[root].s;
	int fe = node[root].e;
	if(s<=fs&&e>=fe)
	{
		return node[root].sum;
	}
	int mid = (fs+fe)/2;
	int parta=0,partb=0;
	if(s<=mid)
		parta = query(s,e,2*root);
	if(e>mid)
		partb = query(s,e,2*root+1);
	return (node[root].sum+parta+partb);
}

int main()
{
	int m;
	int a,b,c,sign;
	while(scanf("%d",&m)!=EOF)
	{
		build(1,M,1);
		init();
		for(int i=0;i<m;i++)	
		{
			scanf("%d",&sign);
			if(sign==1)
			{
				scanf("%d%d%d",&a,&b,&c);
				if(ID[a]==-1)
				{
					ID[a]=n;
			//		index[n]=a;
					n++;
				}
				int s = b<c?b:c;
				int e= b>c?b:c;
				int owncnt = group[ID[a]].owncnt;
				group[ID[a]].own[owncnt].e=e;
				group[ID[a]].own[owncnt].s=s;
				group[ID[a]].owncnt++;
				sort(group[ID[a]].own,group[ID[a]].own+group[ID[a]].owncnt,cmp);
				change(b,c,1,1);
			}
			else if(sign==3)
			{
				scanf("%d%d",&a,&b);
				conbination(ID[a],ID[b]);
			}
			else
			{
				scanf("%d",&a);
				int ans = query(a,a,1);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
