#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
long long getmod(long long _0,long long _1,long long _2){
    long long prod,base;
    for(prod=1,base=_0;_1;_1/=2){
        if(_1%2) prod=prod*base%_2;
        base=base*base%_2;
    }
    return prod;
}
main(){
    long long p,n,y,x,k,v,u,w,z;
    srand(time(NULL));
    while(~scanf("%lld",&p)){
        if(p%4==3){
            printf("Illegal\n");
            continue;
        }else printf("Legal ");
        while(1){
            n=rand()%(p-1)+1;
            x=getmod(n,(p-1)/4,p);
            if(x*x%p==p-1) break;
        }
        y=1;
        while(1){
            if(x>p/2) x=p-x;
            if(y>p/2) y=p-y;
            k=(x*x+y*y)/p;
            if(k==1) break;
            u=x%k,v=y%k;
            if(u>k/2) u=u-k;
            if(v>k/2) v=v-k;
            w=(u*x+v*y)/k;
            z=(v*x-u*y)/k;
            if(w<0) w=-w;
            if(z<0) z=-z;
            x=w,y=z;
        }
        if(x>y) printf("%lld %lld\n",y,x);
        else printf("%lld %lld\n",x,y);
    }
    return 0;
}

