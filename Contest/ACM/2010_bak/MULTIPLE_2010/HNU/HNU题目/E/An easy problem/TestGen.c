#include <stdio.h>
#include <stdio.h>
#include <math.h>
#define LOOP(x) for(x=0;x<n;++x)
#define EPS 1.e-8
#define N 100
int n;
double MMax(double a[N][N],int *r,int *c){
int i,j;double Max=0;
for(i=0;i<n-1;++i)for(j=i+1;j<n;++j)if(fabs(a[i][j])>Max){Max=fabs(a[i][j]);*r=i;*c=j;}
return Max;}
void QR(double a[N][N],double lmda[N]){
double h[N],theta,c,s,t1,t2;int i,j,m,k;
while(MMax(a,&k,&m)>EPS){
    theta=.5*atan2(2*a[k][m],a[k][k]-a[m][m]);
    c=cos(theta);s=sin(theta);
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
    int i,j,a[100][100];
    double b[N][N],c[N],t[N][N],m;
    srand((int)time(NULL));
    while(n=rand()%101){
    for(i=0;i<n;++i)for(j=0;j<=i;++j)a[i][j]=a[j][i]=(rand())*(rand()&1?1:-1);
    LOOP(i)LOOP(j)t[i][j]=b[i][j]=a[i][j]*.0001;
    QR(t,c);
    m=0;LOOP(i)if(fabs(c[i])>m)m=fabs(c[i]);
    if(m<10){printf("%d\n",n);
    for(i=0;i<n;++i)for(j=0;j<n;++j)printf("%lf%c",b[i][j],j==n-1?10:32);}}
    printf("0\n");
    return 0;}
