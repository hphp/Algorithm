#include<iostream>
#include <queue>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<math.h>
#include<time.h>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define ll long long
using namespace std;
const int MAX = 10005;
struct Node{
	int id;
	ll var;
	Node *next;
};
struct H{
	int key;
	ll var;
};
H heap[MAX];
int sign[MAX];
Node node[MAX],edge[1000005];
bool vis[MAX];
ll dis[MAX],cnt[MAX],son[MAX];
int edge_n,N,S,M,Q;
ll mod;
void add(int fr,int to,ll var){
	edge[edge_n].id=to;
	edge[edge_n].var=var;
	edge[edge_n].next=node[fr].next;
	node[fr].next=&edge[edge_n];
	edge_n++;
}
void initial(){
	for(int i=0;i<=N;i++)
		node[i].next=NULL,sign[i]=-1;
	edge_n=0;
}
bool readIn(){
	if(scanf("%d%d%d",&N,&M,&Q)==EOF)
		return false;
	initial();
	int x,y;
	ll z;
	while(M--){
		scanf("%d%d%lld",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	return true;
}
void insert(int x,int num){
	int lc=x*2,rc=x*2+1,j=x;
	if(lc<=num&&heap[j].var>heap[lc].var)
		j=lc;
	if(rc<=num&&heap[j].var>heap[rc].var)
		j=rc;
	if(j!=x){
		swap(sign[heap[j].key],sign[heap[x].key]);
		swap(heap[j],heap[x]);
		insert(j,num);
	}
	return ;
}
void up(int x){
	while(x>1){
		int j=x/2;
		if(heap[j].var>heap[x].var){
			swap(sign[heap[j].key],sign[heap[x].key]);
			swap(heap[j],heap[x]);
			x/=2;
		} else break;
	}
}
ll arr_son[MAX];
void dfs(int id){
	if(vis[id])return;
	vis[id]=true;
	son[id]=0;
	for(Node *cur=node[id].next;cur;cur=cur->next){
		int key=cur->id;
		ll var=cur->var;
		if(dis[id]+var==dis[key]){
			dfs(key);
			//son[id]=(son[id]+son[key]+cnt[key])%mod;
			// printf("%d===%d**%d===%d\n",id,son[id],key,son[key]);
			arr_son[id]=(arr_son[id]+arr_son[key]+1)%mod;
		}
	}
	son[id]=(cnt[id]*arr_son[id])%mod;
}

struct TMP
{
	int id;
	ll dis;
};

bool operator<(const TMP a,const TMP b) 
{
	if(a.dis > b.dis)
		return 1;
	return 0;
}

void Solve(){
	int num=1;
	for(int i=0;i<=N;i++)
		vis[i]=false,dis[i]=-1,cnt[i]=0,son[i]=0,arr_son[i]=0;
	S=0;
	cnt[S]=1,dis[S]=0;
	priority_queue <TMP> p;
	TMP a = {0,0};
	p.push(a);
	while(!(p.empty()))
	{
		TMP t = p.top();
		p.pop();
		int id = t.id;	
		if(vis[id])continue;
		vis[id] = 1;
		for(Node * tmp = node[id].next; tmp != NULL ; tmp = tmp->next)
		{
			int next = tmp->id;
			ll var = tmp->var;
			if(dis[id] + var == dis[next])
			{
				cnt[next] = (cnt[id] + cnt[next])%mod;
			}
			if(dis[next] == -1 || dis[id] + var < dis[next])
			{
				dis[next] = dis[id] + var;
				cnt[next] = cnt[id];
				TMP pp = {next,dis[next]};
				p.push(pp);
			}
		}
	}
/*	sign[S]=1;heap[1].key=S,heap[1].var=0;
	while(num){
		H hh = heap[1];
		swap(sign[heap[1].key],sign[heap[num].key]);
		swap(heap[1],heap[num]);
		num--;
		insert(1,num);
		sign[hh.key]=-2;
		int key=hh.key;
		for(Node *cur=node[key].next;cur;cur=cur->next){
			int id=cur->id;
			ll var=cur->var;
			if(dis[id]==-1||dis[id]>dis[key]+var){
				dis[id]=dis[key]+var;
				cnt[id]=cnt[key];
				if(sign[id]==-1&&!vis[id]){
					sign[id]=++num;
					vis[id]=true;
					heap[num].key=id;
					heap[num].var=dis[id];
					up(num);
				} else if(sign[id]!=-1){
					heap[sign[id]].var=dis[id];
					up(sign[id]);
				}
			} else if(dis[id]==dis[key]+var){
				cnt[id]=(cnt[id]+cnt[key])%mod;
			}
		}
	}*/
	memset(vis,false,sizeof(vis));
	dfs(S);
	// for(int i=0;i<N;i++)
	// printf("%d   %d\n",cnt[i],son[i]);
	while(Q--){
		int key;
		scanf("%d",&key);
		ll ans	=(cnt[key]+son[key])%mod;
		ll tmp = ans;
		int cnt = 0;
		int rec[200];
		while(tmp)
		{rec[cnt++] = tmp%10;tmp/=10;}
		int i =0;
		for(i = 0 ;i  < 10-cnt;i++)
			printf("0");
		int j =0;
		for(;i<=10,j<=10;i++,j++)
			printf("%d",rec[i]);
		printf("\n");
//		printf("%010lld\n",ans);
	}
}
int main()
{ mod=1;
	for(int i=1;i<=10;i++)
		mod*=10;
	//printf("%I64d==\n",mod);
	while(readIn()){
		Solve();
	}
}
