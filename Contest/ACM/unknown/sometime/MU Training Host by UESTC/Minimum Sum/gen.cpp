#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int mod = 1000000000;

int test[] = {10, 100, 1000, 999, 99999, 100000};

int RAND()
{
	return abs((rand() << 20) + (rand()<<10) + rand());	
}

int main()
{
	freopen("1.in", "w", stdout);
	
	int T = 7;	cout << T << endl;
	puts("1\n1\n1\n0 0");
	for(int t=0; t<T; t++)
	{
		int N = test[t];	cout << N << endl;
		for(int i=0; i<N; i++)	
		{
			if(t%2)	printf("%d ", RAND()%mod + 1);	
			else	printf("%d ", RAND()%10000 + 1);	
		}
		int Q = N;	cout << endl << Q << endl;
		while(Q --)
		{
			int l = RAND() % N;
			int r = RAND() % (N-l);
			printf("%d %d\n", l, l+r);	
		}
	}
	
	
	return 0;	
}
