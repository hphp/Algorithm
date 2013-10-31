#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void gen(int n)
{
    int i,h,v;
    printf("%d\n",n);
    for(i=0;i<n;i++)
    {
        h=rand()*rand()%100000000+1;
        v=rand()%10000+1;
        printf("%d %d\n",h,v);
    }
    puts("");
}
int main()
{
    freopen("traval.in","w",stdout);
    srand(unsigned(time(NULL)));
    int n,h,v=0;
    printf("%d\n",5);
    puts("100000000 10000");
    puts("100000000 10000");
    puts("100000000 10000");
    puts("100000000 10000");
    puts("100000000 10000");
    int p=1;
    int i;
    for(i=0;i<10;i++)
    {
        if((i&1)==0)
        {
            if(p<100000)
                p*=10;
        }
        n=rand()*rand()%p;
        if(n<p/10)n+=p/10;
        if(n==0)n++;
        gen(n);
    }
    n=100000;
    printf("%d\n",n);
    p=0;
    for(i=0;i<n;i++,p++)
    {
        if(rand()&1)printf("%d ",50000000-p);
        else printf("%d ",50000000+p);
        printf("%d\n",rand()%10000+1);
    }
    puts("");
    return 0;
}

