#include <stdio.h>
#define ABS(x) ((x)>0?(x):(-(x)))
int main(){
    double x,m=0;
    while(scanf("%lf",&x)!=EOF)
    if(ABS(x)-((int)ABS(x))>0&&ABS(x)>m)m=ABS(x);
    printf("%lf\n",m);
    return 0;}
