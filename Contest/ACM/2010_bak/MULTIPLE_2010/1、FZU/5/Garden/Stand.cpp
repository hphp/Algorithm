#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;

typedef double db;
const db EPS = 1e-4;
const int maxn = 15;
const db G = 9.18;
int sign(db x){return x < - EPS ? - 1 : x > EPS;}
db sqr(db x){return x * x;}
bool bet(db x,db a,db b){return sign(x - a) >= 0 && sign(x - b) <= 0;}
struct TPoint{
	db x,y;
	TPoint(){}
	TPoint(db xx,db yy):x(xx),y(yy){}
	db X(TPoint P){return x * P.y - y * P.x;}
	db O(TPoint P){return x * P.x + y * P.y;}
	db len(){return sqrt(sqr(x) + sqr(y));}
	TPoint sub(TPoint P){return TPoint(x - P.x, y - P.y);}
	TPoint add(TPoint P){return TPoint(x + P.x, y + P.y);}
	TPoint rot(db k){return TPoint(cos(k) * x - sin(k) * y,sin(k) * x + cos(k) * y);}
	void get(){scanf("%lf%lf",&x,&y);}
	void out(){printf("(%.8f,%.8f)\n",x,y);}
	bool operator==(const TPoint P){return sign(x - P.x) == 0 && sign(y - P.y) == 0;}
};

struct TLine{
	TPoint a,b;
	db B,A,C; // Bx + Ay + C = 0 ;
	TPoint mid(){return TPoint((a.x + b.x) / 2.0, (a.y + b.y) / 2.0);}
	void init(TPoint aa,TPoint bb){
		a = aa;
		b = bb;
		A = a.x - b.x;
		B = b.y - a.y;
		C = b.X(a);
	}
	bool inter(TLine L,TPoint &ret){
		TPoint PA(A,L.A),PB(B,L.B),PC(C,L.C);
		db c = PA.X(PB);
		if(! sign(c)) return 0;
		ret = TPoint(PC.X(PA) / c, - PC.X(PB) / c);
		return 1;
	}
	bool on_ray(TPoint P){return sign(P.sub(a).O(b.sub(a))) >= 0;}
	bool on_seg(TPoint P){
		int flg = sign(P.sub(a).X(P.sub(b)));
		if(flg) return 0;
		db minx = min(a.x,b.x),maxx = max(a.x,b.x),miny=min(a.y,b.y),maxy = max(a.y,b.y);
		return bet(P.x,minx,maxx) && bet(P.y,miny,maxy);
	}
};
TPoint P[maxn];
struct TPoly{
	int n,typ;
	db k,h;
	TLine L[maxn];
	void get(){
		int i;
		scanf("%lf%d",&h,&n);
		for(i = 0; i < n; ++ i) P[i].get(); P[n] = P[0];
		for(i = 0; i < n; ++ i) L[i].init(P[i],P[i + 1]);
		scanf("%d%lf",&typ,&k);
	}
	bool operator<(const TPoly P)const{return sign(h - P.h) > 0;}
}Poly[maxn],PolyTmp;
TPoint now,pnow;
db H,nowH,ans,vlen;
int n;
void get(){
	int i,sz =0 ;
	now.get(); scanf("%lf",&H); nowH = H;
	scanf("%d",&n); 
	for(i = 0; i < n; ++ i) {
		PolyTmp.get();
		if(sign(PolyTmp.h - H) <= 0 && sign(PolyTmp.h) > 0) Poly[sz ++] = PolyTmp;
	}
	n = sz;
	sort(Poly,Poly + n);
}

void process(TPoly Poly){
	int i,n = Poly.n,c = 0;
	TLine L; TPoint P,Ptmp[2];
	L.init(pnow, pnow.add(now));
	for(i = 0; i < n; ++ i) if(Poly.L[i].inter(L,P) && L.on_ray(P) && Poly.L[i].on_seg(P) ) Ptmp[c ++] = P;
	if(c == 1){
		ans += Ptmp[0].sub(pnow).len() / vlen;
		pnow = Ptmp[0];
	}else{
		if(Ptmp[0] == pnow){
			ans += Ptmp[1].sub(pnow).len() / vlen;
			pnow = Ptmp[1];
		}else{
			ans += Ptmp[0].sub(pnow).len() / vlen;
			pnow = Ptmp[0];			
		}
	}
}
bool ponpoly(TPoint P,TPoly Poly){
	int i,j,c,n = Poly.n;
	TLine vec;
	TPoint in;
	for(i = 0; i < n; ++ i) if(Poly.L[i].on_seg(P)) return 1;
	for(i = 0; i < n; ++ i){
		vec.init(P,Poly.L[i].mid());
		c = 0;
		for(j = 0; j < n && c < 2; ++ j)
			if(Poly.L[j].inter(vec,in) && vec.on_ray(in) && Poly.L[j].on_seg(in)) ++ c;
		if(c == 2) return 0;
	}
	return 1;
}
int cas = 0;
void work(){
	int i,j;
	bool flg = 1;
	if(sign(H) < 0) flg = 0;
	if(! flg){
		printf("Case %d: Forever!\n",++ cas,ans);
		return ;
	}
	ans = 0.0;
	pnow = TPoint(0,0);
	vlen = now.len();
	for(i = 0; i < n; ++ i){
		db dH = nowH - Poly[i].h,dT = sqrt(2.0 * dH / G) ;
		if(! ponpoly(pnow.add(TPoint(dT * now.x,dT * now.y)),Poly[i])) continue;
		ans += dT;
		pnow.x += dT * now.x;
		pnow.y += dT * now.y;
		nowH = Poly[i].h;
		if(ponpoly(pnow,Poly[i])){
			if(Poly[i].typ == 0) now = now.rot(Poly[i].k);
			if(Poly[i].typ == 1) now.x = Poly[i].k;
			if(Poly[i].typ == 2) now.y = Poly[i].k;
			vlen = now.len();
			if(! sign(vlen)){flg = 0; break;}
			process(Poly[i]);
		}
	}
	ans += sqrt(nowH * 2.0 / G);
	if(! flg) printf("Case %d: Forever!\n",++ cas,ans);else
	printf("Case %d: %.2f\n",++ cas,ans);
}
int main(){
	//freopen("D:\\in.txt","r",stdin);
	//freopen("D:\\out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T --){
		get();
		work();
	}
	return 0;
}