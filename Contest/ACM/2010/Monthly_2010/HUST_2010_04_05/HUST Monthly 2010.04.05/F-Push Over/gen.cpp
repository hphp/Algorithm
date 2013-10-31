#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#define MAXV 2000
#define PI 3.14159265358979323846
#define eps 1e-8
#define zero(x) (fabs(x)<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
using namespace std;

//¶þÎ¬µã
struct pt
{
	int x, y;
};

double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}

pt S, A, B, T;


int N = 100;

int f(int a)
{
	return (rand() - 16384) % a;
}

int main()
{
	srand(time(0));
/*
	for (int i = 0, j = -99999999, k = 99999999; i < 1000000000; i++)
	{
		int a = rand() - 16384;
		j = max(j, a);
		k = min(k, a);
		printf("%d %d\n", k, j);
	}
*/

	for (int i = 0; i < N; i++)
	{
		S.x = f(50);
		S.y = f(50);
		A.x = f(50);
		A.y = f(50);
		B.x = f(50);
		B.y = f(50);
		T.x = f(50);
		T.y = f(50);
		if (dis(S, A) > eps && dis(S, B) > eps && dis(S, T) > eps && dis(A, B) > eps && dis(A, T) > eps && dis(B, T) > eps)
		{
			printf("%d\n", 1 + abs(f(70)));
			printf("%d %d\n", S.x, S.y);
			printf("%d %d %d %d\n", A.x, A.y, f(50), f(50));
			printf("%d %d %d %d\n", B.x, B.y, f(50), f(50));
			printf("%d %d\n\n", T.x, T.y);
		}
	}
	return 0;
}
