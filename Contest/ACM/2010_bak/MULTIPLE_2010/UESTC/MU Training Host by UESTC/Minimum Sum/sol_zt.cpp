#include <stdio.h>
#include <string.h>
#include <algorithm>
#define Max 100010
#define Mlog 18
#define Mq 100010
#define Mq2 200010

using namespace std;
typedef long long LL;
struct box{
	int x,c,d;LL s;
	box(){}
	box(int x,int c,LL s):x(x),c(c),s(s){}
}rQ[Mq2];
struct qbox{int x,y;}qr[Mq];
int a[Max],sv[Max],sc[Max],ctC[Max];
int v[2][Max],tl[Mlog][Max],len[Mq];
LL ctN[Max],R[Mq];
bool cmp(int i,int j){return a[i] < a[j];}
bool cmpR(const box &i,const box &j){return i.x < j.x;}
void build(char p,int c,int s,int t){
	if (s == t) return;
	char cp = p&1,np = (p&1)^1;
	int d = (s+t) >> 1,nc = c << 1;
	int i,mid = d,lc = s,rc = d+1;
	for (i = s;i <= t;i++){
		if (v[cp][i] <= mid)
			v[np][lc++] = v[cp][i];
		else
			v[np][rc++] = v[cp][i];
		tl[p][i] = lc-s;
	}
	build(p+1,nc,s,d);
	build(p+1,nc+1,d+1,t);
}
int query(char p,int c,int s,int t,int qs,int qt,int k){
	if (s == t) return s;
	int sm = qs == s?0:tl[p][qs-1],tm = tl[p][qt];
	int d = (s+t) >> 1,nc = c << 1,qm = tm-sm;
	if (k <= qm) return query(p+1,nc,s,d,s+sm,s+tm-1,k);
	return query(p+1,nc+1,d+1,t,d+1+qs-s-sm,d+qt-s+1-tm,k-qm);
}
template <typename T>
void add1(T h[],int x,int v){
	while (x < Max){
		h[x] += v;
		x += x & -x;
	}
}
template <typename T>
T read1(T h[],int x){
	T r = 0;
	while (x){
		r += h[x];
		x -= x & -x;
	}
	return r;
}
void add2(int x,int v){
	while (x){
		ctN[x] += v;
		x -= x & -x;
	}
}
LL read2(int x){
	LL r = 0;
	while (x < Max){
		r += ctN[x];
		x += x & -x;
	}
	return r;
}
int main(){
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\zt.out", "w", stdout);
	int T,N,Q,t,i,j;
	int md,rn,cd,x,y;
	LL cS;
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		scanf("%d",&N);
		for (i = 1;i <= N;i++){
			scanf("%d",&a[i]);
			sc[i] = i;
		}
		sort(sc+1,sc+N+1,cmp);
		for (i = 1;i <= N;i++){
			sv[i] = a[sc[i]];
			v[0][sc[i]] = i;
		}
		build(0,1,1,N);
		scanf("%d",&Q);
		for (rn = 0,i = 1;i <= Q;i++){
			scanf("%d%d",&x,&y);
			qr[i].x = ++x,qr[i].y = ++y;
			len[i] = y-x+1;
			md = (len[i]+1) >> 1;
			rQ[rn++] = box(sv[query(0,1,1,N,x,y,md)],i,0);
			if (!(len[i] & 1))
				rQ[rn++] = box(sv[query(0,1,1,N,x,y,md+1)],i,0);
		}
		sort(rQ,rQ+rn,cmpR);
		memset(ctN,0,sizeof(ctN));
		memset(ctC,0,sizeof(ctC));
		for (i = 0,j = 1;i < rn;i++){
			x = rQ[i].x;
			while (j <= N && a[sc[j]] < x){
				//printf("do %d at %d %d\n",j,sc[j],a[sc[j]]);
				add1(ctN,sc[j],a[sc[j]]);
				add1(ctC,sc[j],1);
				++j;
			}
			y = rQ[i].c;
			cS = read1(ctN,qr[y].y)-read1(ctN,qr[y].x-1);
			cd = read1(ctC,qr[y].y)-read1(ctC,qr[y].x-1);
			rQ[i].s = (LL)cd*rQ[i].x-cS;
		}
		memset(ctN,0,sizeof(ctN));
		memset(ctC,0,sizeof(ctC));
		for (i = rn-1,j = N;i >= 0;i--){
			x = rQ[i].x;
			while (j >= 1 && a[sc[j]] > x){
				add2(sc[j],a[sc[j]]);
				add1(ctC,sc[j],1);
				--j;
			}
			y = rQ[i].c;
			cS = read2(qr[y].x)-read2(qr[y].y+1);
			cd = read1(ctC,qr[y].y)-read1(ctC,qr[y].x-1);
			rQ[i].s += cS-(LL)cd*rQ[i].x;
		}
		memset(R,-1,sizeof(R));
		for (i = 0;i < rn;i++){
			j = rQ[i].c;
			if (rQ[i].s < R[j] || R[j] == -1)
				R[j] = rQ[i].s;
		}
		printf("Case #%d:\n",t);
		for (i = 1;i <= Q;i++)
			printf("%lld\n",R[i]);
		putchar('\n');
	}
}