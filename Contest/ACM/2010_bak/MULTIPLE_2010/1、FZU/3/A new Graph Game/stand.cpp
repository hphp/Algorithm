#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<ctime>

using namespace std;

const int maxn = 2005;
const int maxm = 100005;
const int inf = 0x2f2f2f2f;

int n,m;
int d[maxn],q[65537],v[maxn],pre[maxn],preh[maxn];
int vpt[maxm],next[maxm],head[maxm],flow[maxm],cost[maxm];
int l = 1;

void add(int a,int b,int f,int c){
	vpt[++l]=b;next[l]=head[a];head[a]=l;flow[l]=f;cost[l]=c;
	vpt[++l]=a;next[l]=head[b];head[b]=l;flow[l]=0;cost[l]=- c;
}

int spfa(int n,int s,int t){
	int i,l,r;
	for(i = 0; i < n; ++ i) d[i] = inf,v[i] = 0;
	d[q[l = 0] = s] = 0;r = 1;
	while(l ^ r){
		int x = q[l ++]; l &= 65535;
		v[x] = 0;
		for(i = head[x];i;i = next[i]){
			int y = vpt[i];
			if(flow[i] > 0 && d[x] + cost[i] < d[y]){
				d[y] = d[x] + cost[i];
				pre[y] = x;
				preh[y] = i;
				if(! v[y]) q[r ++] = y,v[y] = 1,r &= 65535;
			}
		}	
	}
	return d[t];
}

int mincostmaxflow(int n,int s,int t,int &f_ans){
	int ans = 0,i,f;
	f_ans = 0;
	while(true){
		f = spfa(n,s,t);
		if(f == inf) break;
		ans += f;
		f = inf;
		for(i = t; i != s; i = pre[i]) f = min(f,flow[preh[i]]); f_ans += f;
		for(i = t; i != s; i = pre[i]) flow[preh[i]] -= f, flow[preh[i] ^ 1] += f;
	}
	return ans;
}

void init(int n){
	l = 1;
	int i;
	for(i = 0; i < n; ++ i) head[i] = 0;
}

inline int readT(){
	char c;int ret;
	while(c = getchar(), c < '0' || c > '9');
	ret = c - '0';
	while(c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
	return ret;
}
int s,t;
int idx = 0;
int con[maxn >> 1][maxn >> 1];
int con_idx = 0;
int mat[maxn >> 1][maxn >> 1];
int lis[maxn * 5][2];

void get(){
	++ con_idx;
	n = readT(); m = readT();
	s = 0;
	t = n + n + 1;
	init(t + 1);
	int i;
	for( i = 0; i < m; ++ i){
		int a,b,c;
		a = readT(); b = readT(); c = readT();
		lis[i][0] = a; lis[i][1] = b; 
		if(con[a][b]  != con_idx) mat[a][b] = c;else mat[a][b] = min(mat[a][b],c);
		con[a][b] = con_idx;
	}
	++ con_idx;
	for(i = 0; i < m; ++ i){
		int a = lis[i][0],b = lis[i][1];
		if(con[a][b]  != con_idx) add(a,b + n,1,mat[a][b] ),add(b,a+n,1,mat[a][b]);
		con[a][b] = con_idx;
	}
}

void work(){
	++ idx;
	printf("Case %d: ",idx);
	int i,f;
	for(i = 1; i <= n; ++ i) add(s,i,1,0),add(i + n,t,1,0);
	int ans = mincostmaxflow(t + 1,s,t,f);
	if(f != n) puts("NO");
	else printf("%d\n",ans);
}

int main(){
	//freopen("D:\\in.txt","r",stdin);
	//freopen("D:\\out.txt","w",stdout);
	int T;
	T = readT();
	while(T --){
		get();
		work();
	}
	return 0;
}