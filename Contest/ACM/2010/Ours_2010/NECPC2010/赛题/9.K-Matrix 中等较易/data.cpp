#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    freopen("KArray.in","w",stdout);
    srand((unsigned)time(NULL));
    for(int i=1;i<=200;++i)
    {
        int n=abs(rand())%50+1;
        int k=abs(rand())%4000000;
        //int k=1000000;
        printf("%d %d\n",n,k);
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=n;++k)
                printf("%d ",abs(rand())%40);
            printf("\n");
        }
    }
}
