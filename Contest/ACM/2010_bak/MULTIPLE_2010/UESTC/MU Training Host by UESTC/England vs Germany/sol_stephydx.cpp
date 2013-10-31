#include <cstdio>
#include <cmath>
const double eps=1e-10;
const double pi=acos(double(-1));
int sgn(double x){return x<-eps?-1:x>eps;}
struct Point{
	double x,y,z;
	Point(){}
	Point(double x,double y,double z):x(x),y(y),z(z){}
};
Point operator -(const Point &p,const Point &q){
	return Point(p.x-q.x,p.y-q.y,p.z-q.z);
}
Point operator *(const Point &p,double s){
	return Point(p.x*s,p.y*s,p.z*s);
}
Point operator *(const Point &p,const Point &q){
	return Point(p.y*q.z-p.z*q.y , -(p.x*q.z-p.z*q.x) , p.x*q.y-p.y*q.x);
}
double operator &(const Point &p,const Point &q){
	return p.x*q.x+p.y*q.y+p.z*q.z;
}
Point cross(const Point &o,const Point &p,const Point &q){
	return (p-o)*(q-o);
}
struct PolyG{
	Point pts[5],N;
	int np;
	void setN(){N=cross(pts[0],pts[1],pts[2]);}
};
bool inter_pl_ln(const PolyG &pg,const Point &p,const Point &v,Point &res){
	double t1=(p-pg.pts[0])&pg.N,t2=v&pg.N;
	if(sgn(t2)==0) return false;
	t1/=t2; res=p-v*t1;
	return true;
}
bool inside_pt_pg(const PolyG &pg,const Point &p){
	int s0=sgn(cross(p,pg.pts[0],pg.pts[1])&pg.N),s;
	for(int i=1;i<pg.np;++i){
		if(sgn(cross(p,pg.pts[i],pg.pts[i+1])&pg.N)!=s0)
		    return false;
	}
	return true;
}
int side(const PolyG &pg,const Point &p){
	return sgn((p-pg.pts[0])&pg.N);
}
Point pts[8],p,v;
int main(){
	int TT;
	scanf("%d",&TT);
	for(int cas=1;cas<=TT;++cas){
		scanf("%lf %lf %lf",&p.x,&p.y,&p.z);
		scanf("%lf %lf %lf",&v.x,&v.y,&v.z);
		for(int i=0;i<8;++i){
			scanf("%lf %lf %lf",&pts[i].x,&pts[i].y,&pts[i].z);
		}
		PolyG pg;
		pg.np=4;
		pg.pts[0]=pg.pts[4]=pts[0];
		pg.pts[1]=pts[1];
		pg.pts[2]=pts[2];
		pg.pts[3]=pts[3];
		pg.setN();

		printf("Case %d: ",cas);
		if(side(pg,p)>0||sgn(v&pg.N)<=0) puts("Intelligent Larrionda!!!");
		else{
			Point it;
			inter_pl_ln(pg,p,v,it);
			puts(inside_pt_pg(pg,it)?"Stupid Larrionda!!!":"Intelligent Larrionda!!!");
		}
	}
	return 0;
}
