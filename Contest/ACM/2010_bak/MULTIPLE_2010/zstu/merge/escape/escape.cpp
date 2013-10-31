#include<stdio.h>
#include<string.h>
const int MAX=100005;
const int INF=1000000000;
bool dig(char x){return x>='0'&&x<='9';}
int get_val()
{
	int ret=0;
	char c=' ';
	do{
		c=getchar();
	}while(!dig(c));
	do{
		ret=ret*10+c-'0';
		c=getchar();
	}while(dig(c));
	return ret;
}


struct
{
	int v,c,next;
}edge[1000000];
int E,head[MAX];
int gap[MAX],cur[MAX];
int pre[MAX],dis[MAX];
void add_edge(int s,int t,int c,int cc)
{
	/*加边的时候同时加两条，
	一条正的，一条反的，
	一般情况下反的容量是0 */
	edge[E].v=t; edge[E].c=c;
	edge[E].next=head[s];
	head[s]=E++;
	edge[E].v=s; edge[E].c=cc;
	edge[E].next=head[t];
	head[t]=E++;
}
int min(int a,int b){return (a==-1||b<a)?b:a;}
int SAP(int s,int t,int n)
{
	memset(gap,0,sizeof(int)*n);
	gap[0]=n;
	memset(dis,0,sizeof(int)*n);
	int i;
	for(i=0;i<n;i++)cur[i]=head[i];
	int u=pre[s]=s,max_flow=0,aug=-1,v;
	while(dis[s]<n)
	{
loop:	for(i=cur[u];i!=-1;i=edge[i].next)
		{
			v=edge[i].v;
			if(edge[i].c>0&&dis[u]==dis[v]+1)
			{
				aug=min(aug,edge[i].c);
				pre[v]=u;
				cur[u]=i;
				u=v;
				if(u==t)
				{
					for(u=pre[u];v!=s;v=u,u=pre[u])
					{
						edge[cur[u]].c-=aug;
						edge[cur[u]^1].c+=aug;
					}
					max_flow+=aug;
					aug=-1;
				}
				goto loop;
			}
		}
		int _min=n;
		for(i=head[u];i!=-1;i=edge[i].next)
		{
			v=edge[i].v;
			if(edge[i].c>0&&dis[v]<_min)
			{
				cur[u]=i;
				_min=dis[v];
			}
		}
		if((--gap[dis[u]])==0)break;
		gap[dis[u]=_min+1]++;
		u=pre[u];
	}
	return max_flow;
}
int sum[1<<10];
int main()
{
	int n,m;
	//freopen("data24.in","r",stdin);
	//freopen("data24.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{

		int s=0;
		int t=(1<<m)+m+1;
		memset(head,-1,sizeof(int)*(t+1));
		E=0;
		memset(sum,0,sizeof(sum));
		int tmp,i,a;
		int p,save;
		save=n;
		while(n--)
		{
			tmp=0;
			p=1;
			for(i=0;i<m;i++,p<<=1)
			{
				scanf("%d",&a);
				//a=get_val();
				if(a)tmp|=p;
			}
			sum[tmp]++;
		}
		//建图
		for(i=0;i<(1<<m);i++)
		{
			//printf("sum[%d]=%d\n",i,sum[i]);
			add_edge(s,i+1,sum[i],0);
		}
		for(i=0;i<m;i++)
		{
			scanf("%d",&a);
			//a=get_val();
			add_edge((1<<m)+i+1,t,a,0);
		}
		int j;
		for(i=0;i<(1<<m);i++)
		{
			if(sum[i]==0)continue;
			for(j=0;j<m;j++)
			{
				if(i&(1<<j))
				{
					add_edge(i+1,j+1+(1<<m),INF,0);
				}
			}
		}
		tmp=SAP(s,t,t+1);
		if(tmp>=save)puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
1 1
1
1

2 2
1 0
1 0
1 1

*/
