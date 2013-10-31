#include<cstdio>

int main()
{
	int i, j, n = 100000;
	j = 6;
	freopen("large.txt", "w", stdout);
	for(i = 0; i < n; i ++)
	{
		printf("%d", j);
		if(j <= 0)j = 9;
	}
	return 0;
}
