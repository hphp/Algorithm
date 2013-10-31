#include <stdio.h>
#include <string.h>
#define Max 100010
#define MS 262144

int ct[Max],A[Max],R[Max];
struct box{char f;int ct;}seg[MS];
int findK(int c,int s,int t,int x){
	if (s == t){
		seg[c].f = seg[c].ct = 0;
		return s;
	}
	int d = (s+t) >> 1,nc = c << 1;
	if (seg[c].f == 1){
		seg[nc].f = 1,seg[nc].ct = d-s+1;
		seg[nc+1].f = 1,seg[nc+1].ct = t-d;
		seg[c].f = 0;
	}
	seg[c].ct = seg[nc].ct+seg[nc+1].ct-1;
	if (x > seg[nc].ct)
		return findK(nc+1,d+1,t,x-seg[nc].ct);
	return findK(nc,s,d,x);
}
void ins(int x,int v){
	while (x < Max){
		if (v > ct[x]) ct[x] = v;
		x += x & -x;
	}
}
int read(int x){
	int r = ct[x];
	while (x){
		if (ct[x] > r) r = ct[x];
		x -= x & -x;
	}
	return r;
}
int main(){
	int T,t,n,i;
	for (scanf("%d",&T),t = 1;t <= T;t++){
		scanf("%d",&n);
		for (i = 1;i <= n;i++)
			scanf("%d",&R[i]);
		memset(ct,0,sizeof(ct));
		seg[1].f = 1;
		for (i = n;i >= 1;i--)
			A[findK(1,1,n,R[i]+1)] = i;
		for (i = 1;i <= n;i++)
			ins(A[i],R[A[i]] = read(A[i])+1);
		printf("Case #%d:\n",t);
		for (i = 1;i <= n;i++){
			if (R[i-1] > R[i]) R[i] = R[i-1];
			printf("%d\n",R[i]);
		}
		putchar('\n');
	}
}

