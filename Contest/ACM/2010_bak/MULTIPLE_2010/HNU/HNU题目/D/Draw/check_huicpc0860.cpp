#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void get(){scanf("%lf%lf",&x,&y);}
};
struct poly{
    point p[205];
    int n;
    void get(){for(int i=0;i<n;i++)p[i].get();p[n]=p[0];}
};
inline int dcmp(double x){
    return (x>eps)-(x<-eps);
}
point operator*(const double &s,const point &p){
    return point(s*p.x,s*p.y);
}
point operator+(const point &a,const point &b){
    return point(a.x+b.x,a.y+b.y);
}
bool operator<(const point &a,const point &b){
    return a.y+eps<b.y||a.y<b.y+eps&&a.x+eps<b.x;
}
inline double cross(const point &o,const point &p,const point &q){
    return (p.x-o.x)*(q.y-o.y)-(p.y-o.y)*(q.x-o.x);
}
inline point lineinter(const point &p1,const point &p2,const point &p3,const point &p4){
    double u=cross(p1,p2,p3),v=cross(p2,p1,p4);
    return point((p3.x*v+p4.x*u)/(v+u),(p3.y*v+p4.y*u)/(v+u));
}
inline void convex(poly a,poly &b){
    b.n=0;
    sort(a.p,a.p+a.n);
    for(int i=0;i<a.n;i++){
        while(b.n>1&&dcmp(cross(b.p[b.n-2],b.p[b.n-1],a.p[i]))<=0)b.n--;
        b.p[b.n++]=a.p[i];
    }
    int k=b.n;
    for(int i=a.n-2;i>=0;i--){
        while(b.n>k&&dcmp(cross(b.p[b.n-2],b.p[b.n-1],a.p[i]))<=0)b.n--;
        b.p[b.n++]=a.p[i];
    }
    if(b.n>1)b.n--;
    b.p[b.n]=b.p[0];
}      
inline void cut(const point &a,const point &b,poly tg,poly &g){
    g.n=0;
    for(int i=0;i<tg.n;i++){
        int u=dcmp(cross(a,b,tg.p[i]));
        int v=dcmp(cross(a,b,tg.p[i+1]));
        if(u>=0)g.p[g.n++]=tg.p[i];
        if(u*v<0) g.p[g.n++]=lineinter(a,b,tg.p[i],tg.p[i+1]);
    }
    g.p[g.n]=g.p[0];
}   
inline double area(const poly &g){
    double s=0.0;
    for(int i=2;i<g.n;i++)s+=cross(g.p[0],g.p[i-1],g.p[i]);
    return 0.5*s;
}
inline double copulate(poly a,poly b,point dir){
    for(int i=0;i<a.n;i++)a.p[i+a.n]=a.p[i]+dir;
    a.n<<=1,a.p[a.n]=a.p[0];
    convex(a,a);
    for(int i=0;i<a.n;i++)cut(a.p[i],a.p[i+1],b,b);
    return area(b);
}
int main(){
    poly ga,gb;
    double a,k;
    freopen("1.std.in","r",stdin);
    freopen("out.txt","w",stdout); 
    while(~scanf("%d",&ga.n)){
        ga.get();
        scanf("%d",&gb.n);
        gb.get();
        scanf("%lf%lf",&a,&k);
        point dir(cos(pi*a/180.0),sin(pi*a/180.0));
        double s=(1.0-k)*area(ga),l=0,r=20000,m;
        if(dcmp(copulate(gb,ga,20000*dir)-s)<0)r=-1;
        while(dcmp(l-r)<0){
            m=(l+r)/2;
            if(dcmp(copulate(gb,ga,m*dir)-s)>=0)r=m;
            else l=m;
        }
        if(dcmp(l-20000)&&r!=-1)printf("%.4lf\n",l);
        else puts("-1");
    }
    return 0;
}
