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
int main(){
	int T,N,M,Q,t,i,d;
	int cN,cM,offsetX,offsetY;
	int nX,nY,maxD,minD,cA,cB;
	char dX,dY;
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
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
			if (s[i] == 'L' || s[i] == 'R'){
				cA = A[s[i] == 'L'][i];
				cB = A[s[i] == 'R'][i];
				if (cA > cB)
					maxD = cA,minD = cB;
				else
					maxD = cB,minD = cA;
				cN = cA+cB;
				if (s[i] == 'L'){
					swp(hX,tX),dX = -dX;
					offsetX -= dX*maxD;
				}
				if ((cA < cB) == (s[i] == 'L'))
					d = offsetX+dX*D[i];
				else
					d = offsetX+dX*(cN-D[i]);
				if (nX){
					add(tX,newB(d),dX == 1);
					nX += unfold(tX,tX->s[dX != 1],d,d-dX*minD,dX == 1);
				}else
					hX = tX = newB(d);
				if (cA < cB){
					swp(hX,tX),dX = -dX;
					offsetX -= dX*cN;
				}
				if (s[i] == 'L'){
					swp(hX,tX),dX = -dX;
					offsetX -= dX*cN;
				}
				++nX;
			}else{
				cA = A[s[i] == 'D'][i];
				cB = A[s[i] == 'U'][i];
				if (cA > cB)
					maxD = cA,minD = cB;
				else
					maxD = cB,minD = cA;
				cN = cA+cB;
				if (s[i] == 'D'){
					swp(hY,tY),dY = -dY;
					offsetY -= dY*maxD;
				}
				if ((cA < cB) == (s[i] == 'D'))
					d = offsetY+dY*D[i];
				else
					d = offsetY+dY*(cN-D[i]);
				if (nY){
					add(tY,newB(d),dY == 1);
					nY += unfold(tY,tY->s[dY != 1],d,d-dY*minD,dY == 1);
				}else
					hY = tY = newB(d);
				if (cA < cB){
					swp(hY,tY),dY = -dY;
					offsetY -= dY*cN;
				}
				if (s[i] == 'D'){
					swp(hY,tY),dY = -dY;
					offsetY -= dY*cN;
				}
				++nY;
			}
		printf("Case %d: %lld\n",t,(LL)nX*M+(LL)nY*N);
	}
	fclose(stdout);
}
