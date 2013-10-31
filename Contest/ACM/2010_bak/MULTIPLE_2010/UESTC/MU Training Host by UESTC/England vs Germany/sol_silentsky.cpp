#include<cstdio>
#include<cmath>
using namespace std;

struct point{
	double x , y , z ; 
};

struct plane{
	point p[4];
};

struct vec{
	double x , y , z ; 
};

const double eps = 1e-7 ; 

int dblcmp(double a ){
	if( fabs(a) < eps )return 0 ; 
	if( a  < 0 )return -1 ; 
	return 1 ; 
}
double  mix_product(vec d , vec b , vec c){
	return b.x * c.y * d.z - b.x * c.z * d.y - b.y * c.x * d.z + b.y * c.z * d.x + b.z * c.x * d.y - b.z * c.y*d.x ; 
}

void changetovec(point p1 , point p2 ,vec &v ){
	v.x = p2.x - p1.x , v.y = p2.y - p1.y , v.z =p2.z - p1.z ; 
	return ; 
}
bool isintheplane(point p1 , plane pl){
	vec a, b, c ; 
	changetovec(pl.p[0] , p1,a);
	changetovec(pl.p[0], pl.p[1],b);
	changetovec(pl.p[0], pl.p[3],c);
	if( dblcmp( mix_product(a,b,c) )== 0 )return true;
	return false;
}


bool isopp(point p1 ,point p2 ,  plane pl){
	vec a, b, c ; 
	changetovec(pl.p[0] , p1,a);
	changetovec(pl.p[0], pl.p[1],b);
	changetovec(pl.p[0], pl.p[3],c);

	vec a1, b1, c1 ; 
	changetovec(pl.p[0] , p2 ,a1);
	changetovec(pl.p[0], pl.p[1],b1);
	changetovec(pl.p[0], pl.p[3],c1);

	if( dblcmp( mix_product( a , b , c ) * mix_product( a1 ,b1 , c1 )  )  < 0 )
		return true ; 
	return false;
}


void product( vec a , vec b , vec &d ){
	d.x = a.y * b.z - a.z * b.y ; 
	d.y = a.z * b.x - a.x * b.z ; 
	d.z = a.x * b.y - a.y * b.x ;
	return ;
}

bool isinthepoly(point p1 , plane pl){
	vec v ; 
	vec a , b , c   ; 
	changetovec(pl.p[0] , pl.p[1], a ) ;
	changetovec(pl.p[0] , pl.p[3] , b ) ; 
	product(a, b ,v ) ;
	changetovec( pl.p[0] , p1,c);
	double temp = mix_product(c,a,v);
	for(int i = 1 ; i<4 ;++i ){
		changetovec(pl.p[i], pl.p[(i+1)%4] , a ) ;
		changetovec( pl.p[i], p1 , c ) ; 
		if( dblcmp( mix_product( c,a , v ) * temp ) <= 0 )
			return false; 
	}
	return true;
}

void line_inser_plane(vec v1 , point p1 , vec v2 , point p2, point &jp ){
	double a = v1.x , b = v1.y , c = v1.z , x1 = p1.x , y1 = p1.y , z1 = p1.z ; 
	double r = v2.x , s = v2.y , t = v2.z , m = p2.x , n = p2.y , p = p2.z ;

	double k = (m*r + s * n + t * p - t * z1 -s * y1 - r * x1 ) / ( a * r + s * b + c * t );
	jp.x = a * k + x1 , jp.y = b * k + y1 , jp.z = c * k + z1 ;
	return ;
}

int main(){
	point p, A,B,C,D,E,F,G,H,temp; 
	vec v ; 
	int t ;
	scanf("%d",&t);
	int cases =1 ; 
	while(t--){
		scanf("%lf%lf%lf",&p.x,&p.y,&p.z);
		scanf("%lf%lf%lf",&v.x,&v.y,&v.z);
		scanf("%lf%lf%lf",&A.x,&A.y,&A.z);
		scanf("%lf%lf%lf",&B.x,&B.y,&B.z);
		scanf("%lf%lf%lf",&D.x,&D.y,&D.z);
		scanf("%lf%lf%lf",&C.x,&C.y,&C.z);
		scanf("%lf%lf%lf",&E.x,&E.y,&E.z);
		scanf("%lf%lf%lf",&F.x,&F.y,&F.z);
		scanf("%lf%lf%lf",&G.x,&G.y,&G.z);
		scanf("%lf%lf%lf",&H.x,&H.y,&H.z);
		
		plane qm;
		qm.p[0] = A , qm.p[1]  = B , qm.p[2] = D , qm.p[3] = C ; 
		printf("Case %d: ",cases++);
		if(dblcmp(v.x) ==0 &&dblcmp(v.y)== 0 &&dblcmp(v.z)==0 ){
			puts("Intelligent Larrionda!!!");
			continue;
		}
		if( isintheplane(p,qm) ){
			if( isinthepoly(p,qm)){
				temp.x = p.x + v.x , temp.y = p.y + v.y , temp.z = p.z  + v.z ; 
				if( isintheplane(temp,qm) )
					puts("Intelligent Larrionda!!!");
				else{
					if( !isopp(temp,E,qm) )
						puts("Stupid Larrionda!!!");
					else 
						puts("Intelligent Larrionda!!!");
				}
			}
			else 
				puts("Intelligent Larrionda!!!");
		}
		else{
			if( !isopp(p,E,qm) )
				puts("Intelligent Larrionda!!!");
			else{
				vec tv ; 
				vec v1,v2; 
				changetovec(A,C,v1);
				changetovec(A,B,v2);
				product(v1,v2,tv);
				if( dblcmp(v.x * tv.x + v.y *tv.y + v.z *tv.z ) == 0 )
						puts("Intelligent Larrionda!!!");	
				else{
					line_inser_plane(v,p,tv,A,temp);
					if(isinthepoly(temp,qm))
						puts("Stupid Larrionda!!!");
					else
						puts("Intelligent Larrionda!!!");	
				}
			}
		}
	}
	return 0 ;
}