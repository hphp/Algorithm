#include <stdio.h>
#include <math.h>

const double eps = 1e-9;
struct point{
	double x,y,z;
	point(){}
	point(double x,double y,double z):x(x),y(y),z(z){}
	void getP(){scanf("%lf%lf%lf",&x,&y,&z);}
};
int sign(double x){return(x<-eps)?-1:(x>eps);}
double dot(point a,point b){return a.x*b.x+a.y*b.y+a.z*b.z;}
point sub(point a,point b){return point(b.x-a.x,b.y-a.y,b.z-a.z);}
point cross(point a,point b){
	return point(a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
}
double dot(point a,point b,point c){
	point a1 = point(b.x-a.x,b.y-a.y,b.z-a.z);
	point a2 = point(c.x-a.x,c.y-a.y,c.z-a.z);
	return dot(a1,a2);
}
point cross(point a,point b,point c){
	point a1 = point(b.x-a.x,b.y-a.y,b.z-a.z);
	point a2 = point(c.x-a.x,c.y-a.y,c.z-a.z);
	return cross(a1,a2);
}
double side(point n,point a,point b,point c){
	return dot(n,cross(a,b,c));
}
bool LinePlaneCross(point n0,double d0,point n1,point p,point &o){
	double dd = dot(n0,n1);
	if (sign(dd) == 0) return false;
	double k = (d0-dot(p,n0)) / dot(n0,n1);
	o = point(p.x+k*n1.x,p.y+k*n1.y,p.z+k*n1.z);
	return true;
}
void getPlane(point a,point b,point c,point &o,double &d){
	o = cross(a,b,c);
	d = dot(o,a);
}
bool ins(point n0,point a[],point o){
	a[4] = a[0];
	int s0 = sign(side(n0,a[0],a[1],o)),i;
	point c;
	for (i = 1;i < 4;i++)
		if (sign(side(n0,a[i],a[i+1],o)) != s0)
			break;
	return i == 4;
}
int main(){
	point a[8],ca,n0,P,dir,tp;
	int T,t,i,fail,c;
	double d0;
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		printf("Case %d: ",t);
		P.getP(),dir.getP();
		for (i = 0;i < 8;i++)
			a[i].getP();
		ca = a[1],a[1] = a[3],a[3] = ca;
		getPlane(a[0],a[1],a[3],n0,d0);
		fail = true;
		if (sign(dot(sub(a[0],P),n0)) >= 0 && LinePlaneCross(n0,d0,dir,P,tp))
			if (ins(n0,a,tp)){
				c = sign(dot(sub(P,tp),dir));
				if (c > 0 || (c == 0 && sign(dot(dir,n0)) < 0))
					fail = false;
			}
		printf("%s Larrionda!!!\n",fail?"Intelligent":"Stupid");
	}
}
