#include <stdio.h>
#include <vector>
#include<algorithm>
#define N 17
#define STM (1<<(N))

using namespace std;

vector <int> ones[N];

void booling()
{
	for(int i=0;i<STM;i++)
	{
		int cnt = 0;
		for(int j=0;j<N;j++)
			if(i&(1<<j))
				cnt++;
		ones[cnt].push_back(i);
	}
}

#define K 100010

int stm[K];
int num[STM];
int rec[STM],real[STM];
int flag[N];
int sign[STM];

int main()
{
	booling();
//	for(int i=0;i<N;i++)
//		printf("%d ",ones[i].size());
	int n,m,k,p,a;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		int cnt =0;
		for(int i=0;i<STM;i++)
		{
			sign[i] = num[i] = 0;
		}
		for(int i=0;i<N;i++)
			flag[i] = 0;
		int rrcnt = 0;
		for(int i=0;i<k;i++)
		{
			scanf("%d",&p);
			stm[cnt] = 0;
			for(int j=0;j<p;j++)
			{
				scanf("%d",&a);
				flag[a] = 1;
				stm[cnt] += (1<<(a-1));
			}
			if(p <= m)
			{
				num[stm[cnt]]++;
				if(sign[stm[cnt]]==0)
				{
					real[rrcnt++] = stm[cnt];
					sign[stm[cnt]] = 1;
				}
				cnt ++;
			}
		}
		if(n == m)
		{
			printf("%d\n",k);
			continue;
		}
		int tt =0;
		for(int i=1;i<=n;i++)
			if(flag[i])
				tt ++;
		if(tt <= m)
		{
			printf("%d\n",k);
			continue;
		}
		int size = ones[m].size();
		int ann =0 ;
		for(int i=0;i<size;i++)
		{
			int cur = ones[m][i];
			int ans = 0;
			for(int j=0;j<rrcnt;j++)
				if((cur & real[j])== real[j])
				{
					ans+=num[real[j]];
				}
			if(ans > ann)
				ann = ans;
		}
		printf("%d\n",ann);
	}
	return 0;
}
