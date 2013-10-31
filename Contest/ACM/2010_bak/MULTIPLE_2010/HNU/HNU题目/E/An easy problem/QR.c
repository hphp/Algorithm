#include <stdio.h>
#include <math.h>
#define LOOP(x) for(x=0;x<n;++x)
#define EPS 1.e-16
#define N 100
int n;
void MMul(double a[N][N],double b[N][N],double c[N][N]){
double d[N][N];int i,j,k;
LOOP(i)LOOP(j){d[i][j]=0;LOOP(k)d[i][j]+=a[i][k]*b[k][j];}
LOOP(i)LOOP(j)c[i][j]=d[i][j];}
double MMax(double a[N][N],int *r,int *c){
int i,j;double Max=0;
for(i=0;i<n-1;++i)for(j=i+1;j<n;++j)if(fabs(a[i][j])>Max){Max=fabs(a[i][j]);*r=i;*c=j;}
return Max;}
void Trans(double a[N][N],double b[N][N]){
int i,j;double c[N][N];
LOOP(i)LOOP(j)c[i][j]=a[j][i];
LOOP(i)LOOP(j)b[i][j]=c[i][j];}
void QR(double a[N][N],double lmda[N],double t[N][N]){
double h[N],theta,c,s,t1,t2;int i,j,m,k;
LOOP(i)LOOP(j)t[i][j]=(i==j?1:0);
while(MMax(a,&k,&m)>EPS){
    theta=.5*atan2(2*a[k][m],a[k][k]-a[m][m]);
    c=cos(theta);s=sin(theta);
    LOOP(i)h[i]=t[i][k]*c+t[i][m]*s;
    LOOP(i)t[i][m]=t[i][m]*c-t[i][k]*s;
    LOOP(i)t[i][k]=h[i];
    t1=a[k][k]*c*c+a[m][m]*s*s+2*a[k][m]*s*c;
    t2=a[m][m]*c*c+a[k][k]*s*s-2*a[k][m]*s*c;;
    LOOP(i)h[i]=a[i][k]*c+a[i][m]*s;
    LOOP(i)a[i][m]=a[i][m]*c-a[i][k]*s;
    LOOP(i)a[i][k]=h[i];
    LOOP(i){a[k][i]=a[i][k];a[m][i]=a[i][m];}
    a[k][m]=a[m][k]=0;a[k][k]=t1;a[m][m]=t2;
   }
LOOP(i)lmda[i]=a[i][i];}
int main(){
    int i,j;double a[N][N],lmda[N],t[N][N];
    freopen("std.in","r",stdin);
    freopen("std.out","w",stdout);
    while(scanf("%d",&n),n){
        LOOP(i)LOOP(j)scanf("%lf",&a[i][j]);
        QR(a,lmda,t);
        LOOP(i)lmda[i]=exp(lmda[i]);
        LOOP(i)LOOP(j)a[i][j]=t[i][j]*lmda[j];
        Trans(t,t);
        MMul(a,t,a);
        LOOP(i){LOOP(j)printf("%.2lf ",a[i][j]);printf("\n");}}
return 0;}
    
