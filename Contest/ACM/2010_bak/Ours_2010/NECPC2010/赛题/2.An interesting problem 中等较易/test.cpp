#include <stdio.h>

int ans[10][1000];

void init()
{
	int i,j;
	int t,s;
	for(i=1; i<10; ++i)
	{
		ans[i][0] = 1;
		t = i;
		while(1)
		{
			s = t/i;
			ans[i][ans[i][0]++] = s;
			if((t%i==0) && (s==i))
			{
				break;
			}	
			t = t%i*10 +s;
		}
	}
}

int main()
{
	int d,k;
	int i,j;
	freopen("in.in", "r", stdin);
    freopen("test.out", "w", stdout);
	init();
	while(scanf("%d %d",&d, &k) != EOF)
	{
		for(i=0; i<k; ++i)
		{
			for(j=1; j<ans[d][0]; ++j)
			{
				printf("%d",ans[d][j]);
			}
		}
		printf("\n");
	}
} 
