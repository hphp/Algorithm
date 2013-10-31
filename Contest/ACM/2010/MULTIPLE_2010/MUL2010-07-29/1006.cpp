#include <stdio.h>
#define N 10100
#define MOD 9997

int cnt,ans;
int rec[N];
void dfs(int n)
{
	if(n==0)
	{
		int sum = 1 ;
		/*for(int i=0;i<cnt;i++)
			printf("g %d ",rec[i]);
			printf("\n");*/
		for(int i=1;i<cnt;i++)
		{
			sum *= (rec[i-1]+rec[i]-1);
			sum %= MOD;
		}
//			printf("heil %d\n",sum);
		ans += sum;
		ans %= MOD;
		return;
	}
	for(int j=1;j<=n;j++)
	{
		rec[cnt] = j;
		cnt++;
		dfs(n-j);
		cnt--;
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		ans = 0;
		cnt=0;
		dfs(n);
		printf("%d\n",ans%9997);
	}
}
