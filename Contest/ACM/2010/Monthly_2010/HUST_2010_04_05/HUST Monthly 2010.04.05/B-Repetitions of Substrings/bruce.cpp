#include <stdio.h>
#include <cstring>
#define maxl 20000

char str[maxl];
int n, k;

bool check(int a, int b)
{
	int len = b - a + 1;
	for(int l=1; l<=len; ++l)
	{
		if(len % l) continue;

		int d = len / l, flag = 1;
		for(int x=0; x<d; ++x)
		{
			for(int y=0; y<l; ++y)
			{
				if(str[x * l + y + a] != str[y + a])
				{
					flag = 0;
					break;
				}
			}
			if(!flag) break;
		}
		if(flag && d >= k) return 1;
	}
	return 0;
}

void solve()
{
	int ans = 0;

	n = strlen(str);
	for(int i=0; i<n; ++i)
	{
		for(int j=i; j<n; ++j)
		{
			if(check(i, j))
			{
				ans++;
				/*
				printf("%d %d %d ", ans, i, j);
				for(int x=i; x<=j; ++x) printf("%c", str[x]);
				puts("");
				*/
			}
		}
	}

	printf("%d\n", ans);
}

int main()
{
	while(scanf("%s%d", str, &k) != EOF)
	{
		solve();
	}
	return 0;
}

