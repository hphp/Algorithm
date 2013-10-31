#include <stdio.h>

typedef __int64 LL;

#define N 1000010

int n, s, c;
LL m, sum[N];
LL max[N];
int queue[N], head, tail;
int num[N], pre[N];

void track(int i)
{
	if (i == 0)
		return ;
	track(pre[i]);
	printf("%d %d\n", pre[i]+1, i);
}

int main()
{
	//freopen("rand2.in","r",stdin);
	//freopen("out.out","w",stdout);
	while (scanf("%d %I64d %d %d", &n, &m, &s, &c) != EOF)
	{
		sum[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &sum[i]);
			sum[i] += sum[i-1];
		}
		sum[n+1] = sum[n];

		head = 0, tail = 1;
		queue[0] = 0;
		max[0] = sum[1] * s;
		num[0] = 0;
		pre[0] = -1;
		for (int i = 1; i <= n; i++)
		{
			while (head<tail && sum[i]-sum[queue[head]]>m)
				head++;

			max[i] = max[queue[head]] - s * (sum[i]-sum[i-1]) + s * (sum[i+1]-sum[i]) + c;
			num[i] = num[queue[head]] + 1;
			pre[i] = queue[head];

			//printf("%d: %I64d %d\n", i, max[i], queue[head]);

			while (head<tail && max[i]>max[queue[tail-1]])
				tail--;
			queue[tail++] = i;
		}

		printf("%I64d %d\n", max[n]+sum[n], num[n]);
		track(n);
	}
}
