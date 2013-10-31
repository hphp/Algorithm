#include <stdio.h>
#include <string.h>
#define maxn 30
#define maxh 1989102317
#define ROUND 100

long n;
long c[maxn],hh[maxn],h[maxn],ph[maxn];
long bn[1000],bp;

void mul (long x) {
	long i,j;

	j = 0;
	for (i=0;i<bp;i++) {
		j += x * bn[i];
		bn[i] = j % 10;
		j /= 10;
	}

	while (j) {
		bn[bp++] = j % 10;
		j /= 10;
		}
}

void div (long x) {
	long i,j;

	j = 0;
	for (i=bp-1;i>=0;i--) {
		j = j * 10 + bn[i];
		bn[i] = j / x;
		j %= x;
	}
	while (bp > 1 && bn[bp-1] == 0)
		bp --;
}

void output (int nowcase) {
	long i;

	printf("Case %d: ", nowcase);
	for (i=bp-1;i>=0;i--)
		printf("%ld",bn[i]);
	printf("\n");
}

int main () {
	long i,j,k,l;
	unsigned long t;
	
	int task;
	scanf("%d", &task);

	for (int nowcase = 1; nowcase <= task; ++nowcase)
	{
		scanf("%ld",&n);
		for (i=0;i<n;i++) {
			scanf("%ld",c+i);
			c[i] --;
		}
		for (i=0;i<n;i++) {
			for (k=0;k<n;k++)
				h[k] = 123456789;
			h[i] = 147804506;
			for (j = 0; j < ROUND; j ++) {
			memcpy(ph,h,sizeof(h));
			for (k=0;k<n;k++) {
				h[k] = 987654321;
				h[k] = (h[k] + ph[c[k]]) * (long long) 235827407 % maxh;
				t = 124907589;
				for (l=0;l<n;l++)
				if (c[l] == k) {
			t = t + ph[l];
			if (t >= maxh)
			t -= maxh;
			}
			h[k] = (h[k] + t) * (long long) 357828371 % maxh;
			}
			}
			hh[i] = h[i];
			}
		bn[0] = 1;
		bp = 1;
		for (i=1;i<=n;i++)
		mul(i);
		memset(h,0,sizeof(h));
		for (i=0;i<n;i++)
		if (!h[i]) {
		k = 0;
		for (j=0;j<n;j++)
		if (hh[i] == hh[j]) {
		h[j] = 1;
		k ++;
		}
		for (j=1;j<=k;j++)
		div(j);
		}
		output(nowcase);
	}
return 0;
}
