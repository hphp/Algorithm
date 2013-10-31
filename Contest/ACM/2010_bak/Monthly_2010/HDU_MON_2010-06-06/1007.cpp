#include <stdio.h>
#define N 1100000
#define MAX (1<<28)

typedef __int64 Int;

int st,ed;
int ast,aed;
int a[N];

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		int n;
		scanf("%d",&n);
		Int mxmx = -MAX;
		Int mx = -MAX;
		Int sum = 0;
		int cnt = 0;
		a[0] = -1;
		int flag = -1;
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
			
			if(a[j] > mx)
				mx = a[j];
			//flag = 0 前一个是0 flag = 1 前一个是正的 flag = -1 负的 
			if(a[j] >= 0 && flag >=0 )
			{
				sum += a[j];
				flag = a[j];
				continue;
			}
			else if(a[j] > 0 && flag < 0)
			{
				sum += a[j];
				flag = a[j];
				cnt ++;
				continue;
			}
			if(a[j] < 0)
			{
				flag = -1;
				continue;
			}
			else if(a[j] == 0 && flag < 0)
			{
				flag = -1;	
				continue;
			}
			else if(a[j] >= 0 && flag == 0)
			{
				flag = a[j];
			}
		}
		printf("Case %d:\n",i);
		printf("%d %I64d\n",cnt,sum);
		if(i!=T)
			printf("\n");
	}
	return 0;
}
/*
11
1 2 0 0 -1 0 0 -3 0 0 4
*/
