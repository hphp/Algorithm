#include <stdio.h>
#include <string.h>

#define MAXN 1000

int a[MAXN];

int main(){
	freopen("f:\\1.in", "r", stdin);
	freopen("f:\\1.out", "w", stdout);
	int t_case = 1, cases;
	scanf("%d", &cases);
	while(cases--){
		int n, m, k, sum = 0;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 0; i < n; ++i){
			scanf("%d", a + i);
			sum += a[i];
		}
		double res = (double)sum / n * m;
		printf("Case %d: %.5f\n", t_case++, res);
	}
	return 0;
}