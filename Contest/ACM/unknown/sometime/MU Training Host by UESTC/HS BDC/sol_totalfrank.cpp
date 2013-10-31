#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAXN 30
#define MAXM 100000
#define INF 0x3f3f3f3f

struct Edge{
	int v, e;
	Edge *link, *reverse;
}edge[MAXM], *adj[MAXN], *adj2[MAXN], *curr[MAXN];

int tEdge;
int dIn[MAXN], dOut[MAXN];
bool visited[MAXN], used[MAXN];
char str[100];

void addEdge(int u, int v, int e){
	Edge *p1 = &edge[tEdge++], *p2 = &edge[tEdge++];
	p1->v = v; p1->e = e; p1->link = adj[u]; adj[u] = p1; p1->reverse = p2;
	p2->v = u; p2->e = 0; p2->link = adj[v]; adj[v] = p2; p2->reverse = p1;
}

void addEdge2(int u, int v, int e){
	Edge *p = &edge[tEdge++];
	p->v = v; p->e = e; p->link = adj2[u]; adj2[u] = p;
}

void dfs(int u){
	visited[u] = true;
	Edge *p = adj2[u];
	while(p){
		if(!visited[p->v]) dfs(p->v);
		p = p->link;
	}
}

int n, s, t;
int dis[MAXN], num[MAXN];

int updatePath(int u, int flow){
	if(u == t) return flow;
	Edge *p = curr[u];
	while(p){
		if(p->e && dis[u] == dis[p->v] + 1){
			curr[u] = p;
			int temp = updatePath(p->v, flow < p->e? flow: p->e);
			if(temp){
				p->e -= temp;
				p->reverse->e += temp;
				return temp;
			}
			else if(dis[s] == n) return 0;
		}
		p = p->link;
	}
	p = curr[u] = adj[u];
	int temp = dis[u];
	dis[u] = n;
	--num[temp];
	while(p){
		if(p->e && dis[p->v] < dis[u]) dis[u] = dis[p->v] + 1;
		p = p->link;
	}
	++num[dis[u]];
	if(!num[temp] && num[temp + 1]) dis[s] = n;
	return 0;
}

int maxFlow(){
	memcpy(curr, adj, sizeof(curr));
	memset(dis, 0, sizeof(dis));
	memset(num, 0, sizeof(num));
	num[0] = n;
	int res = 0;
	while(dis[s] < n) res += updatePath(s, INF);
	return res;
}

int main(){
	int cases, case_t = 1;
	scanf("%d", &cases);
	while(cases--){
		printf("Case %d: ", case_t++);
		tEdge = 0;
		memset(adj, NULL, sizeof(adj));
		memset(adj2, NULL, sizeof(adj2));
		memset(dIn, 0, sizeof(dIn));
		memset(dOut, 0, sizeof(dOut));
		memset(visited, false, sizeof(visited));
		memset(used, false, sizeof(used));
		int N, flag;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%s%d", str, &flag);
			int u = str[0] - 'a' + 1, v = str[strlen(str) - 1] - 'a' + 1;
			++dOut[u];
			++dIn[v];
			used[u] = used[v] = true;
			addEdge2(u, v, 1);
			addEdge2(v, u, 1);
			if(flag) addEdge(v, u, 1);
		}
		flag = 0;
		for(int i = 1; i <= 26; ++i)
			if(used[i]){
				dfs(i);break;
			}
			for(int i = 1; i <= 26; ++i)
				if(used[i] && !visited[i]) flag = 1;
			if(flag == 1){
				puts("Poor boy!");continue;
			}
			int total = 0, u, v;
			for(int i = 1; i <= 26; ++i){
				if((dOut[i] - dIn[i]) % 2 != 0){
					++total;
					if(total == 1) u = i;
					else if(total == 2) v = i;
				}
			}
			if(total == 1 || total > 2){
				puts("Poor boy!");continue;
			}
			if(total == 2){
				++dOut[u];
				++dIn[v];
				addEdge(v, u, 1);
			}
			int sum = 0;
			n = 28, s = 0, t = n - 1;
			for(int i = 1; i <= 26; ++i){
				if(!used[i]) continue;
				if(dIn[i] > dOut[i]){
					addEdge(s, i, dIn[i] - dOut[i]);
					sum += (dIn[i] - dOut[i]) / 2;
				}
				else addEdge(i, t, (dOut[i] - dIn[i]) / 2);
			}
			if(maxFlow() == sum) puts("Well done!");
			else puts("Poor boy!");

	}
	return 0;
}