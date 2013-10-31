#include <stdio.h>

#define LONG __int64 

LONG N,M,S,C;
LONG A[1000005];
LONG ans[1000005];
LONG num[1000005];
LONG front[1000005];


void dp()
{
	int i,j,k;
	LONG temp;
	LONG ansTemp;
	ans[0] = 0;
	num[0] = 0;
	ans[1] = A[1] + C;
	front[1] = 1;
	num[1] = 1;
	for(i=2; i<=N; ++i)
	{
		temp = A[i];
		j = i-1;
		ans[i] = ans[j]+A[i] + C;
		num[i] = num[j] + 1;
		front[i] = i;
		while(j>=1)
		{
			temp = temp+A[j];
			if(temp>M) //¿ÉÄÜ= 
			{
				break; 
			}
		//	printf("%d\n",temp);
			ansTemp = ans[j-1] + temp +S*A[j] - S*A[i] +C;
			if(ansTemp > ans[i])
			{
				ans[i] = ansTemp;
				num[i] = num[j-1] + 1;
				front[i] = j;
			}
			j--;
		}
	}
}

bool input()
{
	int i;
	if(scanf("%I64d %I64d %I64d %I64d", &N, &M, &S, &C)!=EOF)
	{
		for(i=1; i<=N; ++i)
		{
			scanf("%I64d", &A[i]);
			ans[i] = num[i] = front[i] = 0;
		}
		return true;
	}	
	return false;
}

void output()
{
	int i = N;
	printf("%I64d %d\n", ans[N], num[N]);
	/*while(i)
	{
		printf("%d %d\n", i, front[i]);
		i =  front[i] - 1;
	}*/
}
int main()
{
	freopen("rand2.in","r",stdin);
	freopen("test.out","w",stdout);
	while(input())
	{
		dp();
		output();
	}
}
