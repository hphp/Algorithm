//1162261467
//129140163
//262144
#include <stdio.h>
#include <map>
using namespace std;
#define M 100000010
#define STM 131072
#define N 19
int num[STM];
long long sum[STM];
long long power_3[N];

map<long long,int> to;
void booling(void)
{
	power_3[0]=1;	
	for(int i=1;i<N;i++)
		power_3[i]=3*power_3[i-1];
	for(int i=0;i<STM;i++)
	{
		sum[i]=0;
		int cnt =0;
		for(int j=0;j<N;j++)
		{
			if(i&(1<<j))
			{
				sum[i]+=power_3[i];
				cnt++;
			}
			num[i]=cnt;
		}
		to[sum[i]]=i;
	}
}

int main()
{
	booling();
	long long m;
	int ans1,ans2;
	while(scanf("%lld",&m)!=EOF)
	{
		for(int i=0;i<STM;i++)
		{
			int temp = sum[i]+m;
			if(to[temp]!=0)
			{
				ans1=i;
				ans2=to[temp];
				break;
			}
		}
		printf("%d",num[ans1]);
		for(int i=0;i<N;i++)
			if((ans1|(1<<i)))
				printf(" %lld",power_3[i]);
				printf("\n");
		printf("%d",num[ans2]);
		for(int i=0;i<N;i++)
			if((ans2|(1<<i)))
				printf(" %lld",power_3[i]);
				printf("\n");
	}
	return 0;
}
