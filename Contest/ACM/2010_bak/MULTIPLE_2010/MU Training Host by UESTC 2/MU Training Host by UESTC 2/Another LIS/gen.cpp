#include <cstdio>
#include <iostream>

using namespace std;

const int MaxN = 100000;

int dataSize[] = {1, 5, 50, 1000, 10000, 50000, 100000};

int RAND()
{
	return (rand()<<10) + rand();	
}

int main()
{
	freopen("1.in", "w", stdout);
	
	int T = 7;	cout << T << endl;
	for(int t=0; t<T; t++)
	{
		int N = dataSize[t];	cout << N << endl;
		for(int i=1; i<=N; i++)	printf("%d ", RAND()%i);
		putchar('\n');
	}
	
	
	return 0;	
}
