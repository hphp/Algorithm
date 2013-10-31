#include <stdio.h>
#include <string.h>
#define Max 100010
#define MH 1000010
#define swp(x,y) cp = x,x = y,y = cp

typedef long long LL;
struct box{
	int d;
	box *s[2];
}H[MH],*hX,*tX,*hY,*tY,*cp,*cH;
int A[2][Max],D[Max];
char s[Max];
box *newB(int d){
	cH->d = d,cH->s[0] = cH->s[1] = NULL;
	return cH++;
}
void add(box *&th,box *np,char dir){
	np->s[!dir] = th,th->s[dir] = np,th = np;
}
int unfold(box *&th,box *fp,int mid,int sd,char dir){
	int ct;
	for (ct = 0;fp&&(dir?(fp->d>sd):(fp->d<sd));fp=fp->s[!dir],++ct)
		add(th,newB(mid*2-fp->d),dir);
	return ct;
}
void update(int &ct,int &ot,char &dr,box *&hd,box *&tl,char bc,int i){
	int cA = A[bc][i],cB = A[!bc][i];
	int cN,d,maxD,minD;
	if (cA > cB)
		maxD = cA,minD = cB;
	else
		maxD = cB,minD = cA;
	cN = cA+cB;
	if (bc){
		swp(hd,tl),dr = -dr;
		ot -= dr*maxD;
	}
	if ((cA < cB) ^ bc)
		d = ot+dr*(cN-D[i]);
	else
		d = ot+dr*D[i];
	if (ct){
		add(tl,newB(d),dr == 1);
		ct += unfold(tl,tl->s[dr != 1],d,d-dr*minD,dr == 1);
	}else
		hd = tl = newB(d);
	if ((cA < cB) ^ bc){
		swp(hd,tl),dr = -dr;
		ot -= dr*cN;
	}
	++ct;
}
int main(){
	int T,N,M,Q,t,i,d,nX,nY;
	int cN,cM,offsetX,offsetY;
	char dX,dY;
	freopen("folding.in","r",stdin);
	freopen("folding3.out","w",stdout);
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		scanf("%d%d%d",&N,&M,&Q);
		cN = N,cM = M,cH = H;
		for (i = 0;i < Q;i++){
			scanf("%s%d",s+i,&d);
			D[i] = d;
			if (s[i] == 'L' || s[i] == 'R'){
				A[0][i] = d,A[1][i] = cN-d;
				cN = A[A[0][i] < A[1][i]][i];
			}else{
				A[0][i] = d,A[1][i] = cM-d;
				cM = A[A[0][i] < A[1][i]][i];
			}
		}
		dX = dY = 1,nX = nY = 0;
		offsetX = offsetY = 0;
		hX = tX = hY = tY = NULL;
		for (--i;i >= 0;--i)
			if (s[i] == 'L' || s[i] == 'R')
				update(nX,offsetX,dX,hX,tX,s[i] == 'L',i);
			else
				update(nY,offsetY,dY,hY,tY,s[i] == 'D',i);
		printf("Case %d: %lld\n",t,(LL)nX*M+(LL)nY*N);
	}
	fclose(stdout);
}
