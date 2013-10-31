#include <stdio.h>
#define M 110000
#define N 110

int use[M],exist[M];
int n,m,cnt[N];
int v[N];
void dp()
{
	for(int j = 0 ; j <= m ; j ++)
		exist[j] = 0;
	exist[0] = 1;
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		for(int j = 0 ; j <= m ; j ++)
			use[j] = 0;
		for(int j = 0 ; j <= m ; j ++)
		{
			if(exist[j] == 1)
				if(j + v[i] <= m && use[j] < cnt[i] && exist[j+v[i]] == 0)
				{
					exist[j+v[i]] = 1 ;
					use[j+v[i]] = use[j] + 1;
					ans ++;;
				}
		}
	}
	printf("%d\n",ans);
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&v[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&cnt[i]);
		}
		dp();
	}
	return 0;
}


