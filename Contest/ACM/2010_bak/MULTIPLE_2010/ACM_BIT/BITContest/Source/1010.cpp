#include <cstdio>
#include <cmath>

const double PI = acos(-1.0);
double h, rd;

int main()
{
	//freopen("stargazer.in", "r", stdin);
	//freopen("stargazer.out", "w", stdout);
	while(scanf("%lf%lf", &h, &rd) != EOF)
		printf("%.2lf\n", asin((rd / 100) / h / 4) / PI * 180);
	return 0;
}