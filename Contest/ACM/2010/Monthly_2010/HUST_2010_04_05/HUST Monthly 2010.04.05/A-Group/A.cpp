#define maxn 20020
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int n, k, l, a[maxn], s[maxn], opt[maxn][2];
void init(){
	scanf("%d%d%d", &n, &k, &l);
	s[0] = 0;
	for (int i=1; i<=n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
}

void solve(){
	memset(opt, 0x7f, sizeof opt);
	for (int i=l; i<=n; i++) opt[i][0] = s[i];
	int ans = s[n];
	for (int K=2; K<=k; K++){
		int tmp = 0x7f7f7f7f, t2;
		for (int j=K-1; j<=K-l-1; j++){
			if (opt[j][K%2] == 0x7f7f7f7f) continue;
			tmp = min(tmp, opt[j][K%2] - K*s[j]);
		}
		for (int i=K; i<=n; i++){
			if (i-l>=0 && opt[i-l][K%2]!=0x7f7f7f7f) tmp = min(tmp, opt[i-l][K%2] - K*s[i-l]);
			if (tmp!=0x7f7f7f7f) t2=tmp+K*s[i]; else t2=tmp;
			opt[i][1-K%2]=t2;
			if (i==n) ans = min(ans, opt[i][1-K%2]);
		}
	}
	printf("%d\n", ans);
}

int main(){
	int test; scanf("%d", &test);
	while (test--){
		init();
		solve();
	}
	return 0;
}
