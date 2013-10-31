#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

struct Point{
	double x,y,z;
	Point(){}
	Point(double x,double y,double z):x(x),y(y),z(z){}
	Point rotX(double sin,double cos){
		return Point(x,y*cos-z*sin,y*sin+z*cos);
	}
	Point rotY(double sin,double cos){
		return Point(x*cos-z*sin,y,x*sin+z*cos);
	}
};
void initrand(){
	int *seed=new int;
	srand((unsigned)seed);
	delete seed;
}
Point pts[8],p,v;
int X,Y,Z,px,py,pz,vx,vy,vz;
bool validP(){
	return !(0<px&&px<X&&
			 0<py&&py<Y&&
			 0<pz&&pz<Z);
}
void randP(int lmt=500){
	do{
		px=rand()%(lmt*2)-lmt;
		py=rand()%(lmt*2)-lmt;
		pz=rand()%(lmt*2)-lmt;
	}while(!validP());
}
void randV(int lmt=500){
	vx=rand()%(lmt*2)-lmt;
	vy=rand()%(lmt*2)-lmt;
	vz=rand()%(lmt*2)-lmt;
}
int main(){
	initrand();
	int TT=10000;
	printf("%d\n",TT);
	for(int cas=1;cas<=TT;++cas){
		X=rand()%100+10;
		Y=rand()%100+10;
		Z=rand()%100+10;
		
		pts[0]=Point(0,0,Z);
		pts[1]=Point(X,0,Z);
		pts[2]=Point(X,0,0);
		pts[3]=Point(0,0,0);
		
		pts[4]=Point(0,Y,Z);
		pts[5]=Point(X,Y,Z);
		pts[6]=Point(X,Y,0);
		pts[7]=Point(0,Y,0);
		
		bool toTrans=false;
		if(cas<=10){
			//v=0
			randP();
			vx=vy=vz=0;
		}
		else if(cas<=100){
			//平行
			randP();
			randV();
			vy=0;
		}
		else if(cas<=200){
			//点在框面内向内
			px=rand()%(X-1)+1;
			py=0;
			pz=rand()%(Z-1)+1;
			do randV(); while(vy<=0);
		}
		else if(cas<=300){
			//点在框面内向外
			px=rand()%(X-1)+1;
			py=0;
			pz=rand()%(Z-1)+1;
			do randV(); while(vy>=0);
		}
		else if(cas<=400){
			//点在框面内，速度平行
			randP();
			py=0;
			randV();
			vy=0;
		}
		else{
			int tp=rand()%10;
			if(tp==0){
				//交点在框上
				int L=rand()%(2*X+2*Z);
				vy=0;
				if(L<=X) vx=L,vz=Z;
				else if(L<=X+Z) vx=X,vz=Z-(L-Z);
				else if(L<=2*X+Z) vx=X-(L-X-Z),vz=0;
				else vx=0,vz=L-2*X-Z;
				randP();
			}
			else if(tp==1){
				//交点在框外
				do randP(); while(0<=px&&px<=X&&0<=pz&&pz<=Z);
				vx=px,vy=0,vz=pz;
				randP();
				if(vy!=py) toTrans=true;
			}
			else{
				//交点在框内
				do randP(X); while(!(0<px&&px<X&&0<pz&&pz<Z));
				vx=px,vy=0,vz=pz;
				randP();
				if(vy!=py) toTrans=true;
			}
			vx-=px,vy-=py,vz-=pz;
		}
		p=Point(px,py,pz);
		v=Point(vx,vy,vz);
		
		if(toTrans){
			int dx,dy,dz;
			double rx,ry,sinx,cosx,siny,cosy;
			dx=rand()%100-50;
			dy=rand()%100-50;
			dz=rand()%100-50;

			rx=(rand()%360)*acos(double(-1))/180;
			ry=(rand()%360)*acos(double(-1))/180;
			sinx=sin(rx),cosx=cos(rx);
			siny=sin(ry),cosy=cos(ry);

			for(int i=0;i<8;++i){
				pts[i]=pts[i].rotX(sinx,cosx).rotY(siny,cosy);
			}
			p=p.rotX(sinx,cosx).rotY(siny,cosy);
			v=v.rotX(sinx,cosx).rotY(siny,cosy);

			for(int i=0;i<8;++i){
				pts[i].x+=dx;
				pts[i].y+=dy;
				pts[i].z+=dz;
			}
			p.x+=dx,p.y+=dy,p.z+=dz;
		}
		
		printf("%f %f %f\n",p.x,p.y,p.z);
		printf("%f %f %f\n",v.x,v.y,v.z);
		for(int i=0;i<8;++i)
			printf("%f %f %f\n",pts[i].x,pts[i].y,pts[i].z);
		puts("");
	}
	return 0;
}
