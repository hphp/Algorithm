#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64;

int main()
{
	//freopen("help.in","r",stdin);
	//freopen("help.out","w",stdout);
	int T, N, R, B;
	scanf("%d", &T);
	for (int ct = 1;ct <= T;ct++)
	{
		int64 sumR = 0, sumB = 0, res = 0;
		scanf("%d", &N);
		while (N--)
		{
			scanf("%d %d", &R, &B);
			res += sumR * B + sumB * R;
			sumR += R; sumB += B;
		}
		printf("Case %d: %I64d\n", ct , res);
	}
	//fclose(stdout);
	//fclose(stdin);
	return 0;
}
