#include <stdio.h>
#include <string.h>
#define MAX 100010

typedef long long LL;
struct box{int r,b;}a[MAX];
int main(){
	/freopen("help.in","r",stdin);
	//freopen("help.out","w",stdout);
	int T,n,i,t;
	LL sr,sb,r;
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		scanf("%d",&n);
		sr = sb = 0;
		for (i = 0;i < n;i++){
			scanf("%d%d",&a[i].r,&a[i].b);
			sr += a[i].r,sb += a[i].b;
		}
		r = 0;
		for (i = 0;i < n;i++)
			r += (sb-a[i].b)*a[i].r+(sr-a[i].r)*a[i].b;
		printf("Case %d: %I64d\n",t,r >> 1);
	}
	//fclose(stdout);
	//fclose(stdin);
}
