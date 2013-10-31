#include<time.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    freopen("E_in.txt", "w", stdout);
    srand((unsigned int )(time(NULL)));
	
	printf("10 2 5\n");
	printf("1 2 3 6 2 8 9 3 4 5\n");
	
	printf("9 0 0\n");
	printf("1 3 6 5 2 6 3 5 9\n");
	
	printf("5 3 5\n");
	printf("1 2 3 4 5\n");
	
	printf("5 5 2\n");
	printf("1 2 3 4 5\n");
	
	int n = 100000,m = 0,k = 10;
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;i++)
		printf("%d ",2);
	printf("\n");
	
	n = 100000 , m = 5 , k = 100000;
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%100000);
	printf("\n");
	
	n = 100000 , m = 99999, k = 99999;
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;i++)
		printf("%d ",i);
	printf("\n");
	
	n=100000,m=80,k=90;
	printf("%d %d %d\n",n,m,k);
	for(int i=1;i<=n;i++)
		printf("%d ",rand()%100+1);
	printf("\n");
    
	for(int t = 1; t <= 10; ++t)
    {
        n = abs(rand()) % 10000+1;
        k = abs(rand()) % 1000000+1;
        m = abs(rand()) % k +1;
        printf("%d %d %d\n", n,m, k);
        for(int i = 1; i <= n; ++i)
        {
            printf("%d ", abs(rand()) % 1000000);
        }
        printf("\n");
    }
}
