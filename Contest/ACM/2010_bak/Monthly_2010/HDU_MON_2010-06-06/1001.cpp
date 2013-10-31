#include <stdio.h>
#define N 100100

#define Max(a,b) ((a)>(b)?(a):(b))

typedef __int64 Int;

int head,tail,lst[N];
Int a[N],sum[N];

int main()
{
	int test;
	int n,k;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d",&n,&k);
		
		sum[0] = 0;
		for(int i=0;i<=n+4;i++)
			a[i] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			sum[i] = sum[i-1]+a[i];
		}
		head = 1 ; tail = 1;
		lst[1] = 0;
		Int mxmx = a[1];
		int lm = 1,rm = 1;
		for(int i=1;i<=n;i++)
		{
			int lim = Max(i - k,0);
			while(head < tail && lst[head] < lim)
			{
				head ++;
			}
			while(head < tail && sum[i] - sum[lst[head]] < 0)
				head ++;
			Int tmp = sum[i] - sum[lst[head]];
			if(tmp > mxmx)
			{
				mxmx = tmp;
				lm = lst[head]+1;
				rm = i;	
			}
			lst[++tail] = i;
		}
		int st = n - k;
		for(int i=1;i<=k;i++)
			lst[i] = st++;
		head = 1;
		tail = k;
//		printf("%d %d\n",st,lst[tail]);
		for(int i=1;i<k;i++)
		{
			int lim = n - (k - i);
			while(head < tail && lst[head] < lim)
			{
				head ++;
			}
			while(head < tail && a[lst[head]+1] < 0)
			{
				head ++;
			}
			
			Int tmp = sum[i] + sum[n] - sum[lst[head]];
			
			if(tmp > mxmx)
			{
				mxmx = tmp;
				lm = lst[head]+1;
				rm = i;	
			}
		}
		printf("%I64d %d %d\n",mxmx,lm,rm);
	}
}
/*

5 2
1 2 3 -2 4 



11 3
2 -2 3 1 2 -2 3 3 -10  0 4

5 4
1 2 -3 4 5

10 7
0 1 0 0 -1 0  2 0 2 3

11 7
0 0 1 0 0 -1 0  2 0 2 3

11 6
0 0 1 0 0 -1 0  2 0 2 3

10 9
1 -1 3 3 2 1 1 2 3 3

10 10
1 2 3 3 -2 1 1 2 3 3

10 4
1 2 3 3 -2 1 1 2 3 3


*/
