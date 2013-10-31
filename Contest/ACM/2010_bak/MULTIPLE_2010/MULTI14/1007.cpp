#include <stdio.h>
#define N 110
#define M 4100
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))

int mx[N][M];
int n;
int a[N];
void init(int sum)
{
	for(int i =0 ;i <= n; i ++)
		for(int j =0 ;j <= sum+2000; j++)	
			mx[i][j] = -MAX;
	mx[0][2000] = 0;
}

int main()
{
	int tc;
	scanf("%d",&tc);
	for(int tt = 1; tt <= tc ; tt++){
		scanf("%d",&n);
		int sum = 0 ;
		int sign = 0;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			if(a[j] == 0)
				sign ++;
			sum += a[j];
		}
		init(sum);
		for(int i =1 ; i <= n ;i ++){
			for(int j=0;j<=sum+2000;j++){
				mx[i][j] = mx[i-1][j];
				if(j>=a[i])
					mx[i][j] = Max(mx[i][j],mx[i-1][j-a[i]]+a[i]);
				if(j+a[i]<=sum+2000)
					mx[i][j] = Max(mx[i][j],mx[i-1][j+a[i]]);
			}
		}
		if(sign < 1 && mx[n][2000] == 0)
			mx[n][2000] = -1;
		printf("Case %d: %d\n",tt,mx[n][2000]);
	}
}
