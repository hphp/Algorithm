#include <stdio.h>
#define N 50010
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))

typedef int Int;

Int mb[N],ma[N];
int v[N];

int main()
{
	int test;
	scanf("%d",&test);
	int n;
	while(test--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&v[i]);	
		}	
		Int a = 0;
		for(int i=1;i<=n;i++)
		{
			if(a < 0)
				a = v[i];
			else a = a + v[i];
			mb[i] = Max(mb[i-1],a);
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
		for(int i=1;i<=n;i++)
		{
			a += v[i];
			if(a > cmx)
			{
				cmx = a;
				bid = i; 
			}
		}
		a = 0;
		Int amx = -MAX;
		int aid = n+1;
		for(int j=n;j>bid;j--)
		{
			a += v[j];
			if(a > amx)
			{
				amx = a;
				aid = j;	
			}
		}
		a = -MAX;
		Int cc = -MAX;
		for(int j=bid+1;j<aid;j++)
		{
			if(a < 0)
				a = v[j];
			else a+=v[j];
			if(a > cc)
			{
				cc = a;	
			}
		}
		
		Int mxmx = cmx + amx;
		printf("%d %d %d\n",cmx,amx,cc);
		if(cc > 0)
			mxmx += cc;
		printf("%d\n",Max(mx,mxmx));
	}
}
/*
7
9 8 -4 6 7 -2 5
*/
