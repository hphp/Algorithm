#include <iostream>
using namespace std;

#define N 100

bool mark[N];

int main()
{
	srand(time(NULL));
	freopen("in.txt", "w", stdout);
	int testCase = 100;
	cout << testCase << endl;
	for(int i = 0; i < testCase; i++)
	{
		int n = rand() % N + 1, m = rand() % N + 1;
		cout << n <<" "<< m << endl;
		for(int i = 0; i < m; i++)
		{
			memset(mark, 0, sizeof(mark));
			for(int i = 0; i < n; i++)
			{
				int t = rand() % n;
				while(mark[t])
				{
					t = rand() % n;
				}
				mark[t] = 1;
				cout << t + 1  <<" ";
			}
			cout << endl;
		}
	}
	return 0;
}
