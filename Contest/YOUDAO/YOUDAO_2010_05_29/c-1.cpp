#include <stdio.h>
#define N 50010
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))

typedef int Int;

Int mb[N],ma[N],mbs[N],mas[N];
int v[N];
Int sum[N];

int main()
{
	int test;
	scanf("%d",&test);
	int n;
	while(test--)
	{
		scanf("%d",&n);
		sum[0] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);
			sum[i] = sum[i-1] + v[i];
		}	
		Int a = 0;
		mb[0] = -MAX;
		int st = 0,ed = n+1;
		Int mxmx = -MAX;
		for(int i=1;i<=n;i++)
		{
			if(a < 0)
			{
				st = i;
				a = v[i];
			}
			else
			{
				a = a + v[i];
			}
			ed = i;
			mb[i] = Max(mb[i-1],a);
			if(mb[i] > mxmx)
			{
				mxmx = mb[i];
				st = st;
				ed = i;
			}
		}
		a = 0;
		ma[n+1] = -MAX;
		for(int i=n;i>=0;i--)
		{
			if(a < 0)
				a = v[i];
			else a += v[i];
			ma[i] = Max(ma[i+1],a);
		}
		Int mx = -MAX;
		for(int i=2;i<=n;i++)
		{
			if(ma[i] + mb[i-1] > mx)
				mx = ma[i] + mb[i-1];	
		}
		
		Int cmx = -MAX;
		int bid = 0;
		a = 0;
		mbs[0] = -MAX;
		for(int i=1;i<=n;i++)
		{
			a += v[i];
			mbs[i] = Max(mbs[i-1],a);
		}
		a = 0;
		mas[n+1] = -MAX;
		for(int j=n;j>=1;j--)
		{
			a += v[j];
			mas[j] = Max(mas[j+1],a);
		}
		
		int cs = st,ce = ed;
		
		int flag = 0;
		printf("%d %d\n",cs,ed);
		while(cs <= ce)
		{
			Int cur = sum[ce];
			if(cs)
				cur -= sum[cs-1];
			Int b = (cs <= 0) ? 0 : mbs[cs-1];
			mx = Max(b + mas[ce+1] + cur,mx);
			if(flag == 0)
			{
				cs ++;
			}
			else if(flag == 1)
			{
				ce --;
				cs --;
			}
			else
			{
				cs ++;
			}
			flag ++;
			if(flag == 3)
				flag  = 0;
		}
		
		printf("%d\n",mx);
		
	}
}
/*
7
9 8 -4 6 7 -2 5
*/
