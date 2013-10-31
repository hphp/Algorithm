#include <stdio.h>
#include <algorithm>
#include <queue>
#define N 25010
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
long long t[N],d[N];
long long st[N];

struct P
{
long long	t,d;
}S[N];

bool cmp(P a , P b)
{
	if(a.d < b.d || (a.d==b.d&&a.t>b.t))
		return 1;
	return 0;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&S[i].t,&S[i].d);
		}
		std::sort(S+1,S+n+1,cmp);
		int last = 0;
		priority_queue <long long int> q;
		long long sum = 0;
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			q.push(S[i].t);
			sum += S[i].t; while(sum > S[i].d&&cnt <k) {
				sum -= (q.top());
				q.pop();
				cnt ++;
			}
			if(cnt >= k)
				break;
		}
		if(cnt >= k)
			cnt = -1;
		printf("%d\n",cnt);
	}
	return 0;
}
