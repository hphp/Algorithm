#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef long long LL;
int cnt[256],List[256];
int getN(int y){
	return (LL)(rand() % 10000)*(rand() % 10000) % y+1;
}
void add(int x,int v){
	while (x < 256){
		cnt[x] += v;
		x += x & -x;
	}
}
int getK(int x){
	int s = 0,k = 128;
	while (k){
		if (x > cnt[s+k]) x -= cnt[s += k];
		k >>= 1;
	}
	return s+1;
}
int main(){
	int T,n,P,Q,i,c,x,y;
	freopen("happy.in","w",stdout);
	T = 10;
	printf("%d\n",T);
	while (T--){
		printf("%d %d\n",n = 200,P = getN(2000000));
		memset(cnt,0,sizeof(cnt));
		for (i = 1;i <= n;i++)
			add(i,1);
		for (i = 0,c = n;i < n;i++,c--){
			add(x = getK(y = getN(c)),-1);
			if (i)
				printf("%d %d %d\n",x,List[getN(i)-1],getN(10000));
			List[i] = x;
		}
		printf("%d\n",Q = 10000);
		while (Q--)
			printf("%d\n",getN(10000));
	}
	fclose(stdout);
}
