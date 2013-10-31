#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10240;

int main()
{
	int T, a[N], b[N];
	
	scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		int n, k; scanf("%d %d", &n, &k);
		for(int i = 0; i < n; i++) scanf("%d", &a[i]);
		for(int i = 0; i < n; i++) scanf("%d", &b[i]);
		sort(a, a+n); sort(b, b+n);
		int lo = a[0]*b[0], hi = a[n-1]*b[n-1];
		while(lo != hi) {
			int mid = (lo+hi+1)/2;
			int pa = 0, pb = n-1, cnt = 0;
			for(; pa < n; pa++) {
				for(; pb >= 0 && a[pa]*b[pb] >= mid; pb--);
				cnt += n-1-pb;
			}
			if(cnt >= k) lo = mid;
			else hi = mid-1;
		}
		printf("%d\n", lo);
	}
	
	return 0;
}
