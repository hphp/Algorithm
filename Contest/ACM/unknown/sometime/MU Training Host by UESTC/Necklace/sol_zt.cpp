#include <stdio.h>
#include <string.h>
#define Max 1000010

int sk[Max<<1],ct[Max<<1],a[Max];
char st[Max<<1];
int main(){
	int T,t,i,c,L,L2,sn,tn,r;
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		scanf("%s",st+1);
		L = strlen(st+1);
		memcpy(st+L+1,st+1,L);
		L2 = L << 1;
		sn = 0,tn = -1;
		for (ct[0] = 0,c = 0,i = 1;i <= L2;i++){
			ct[i] = c += st[i] == 'C'?1:-1;
			while (sn <= tn && sk[sn]+L <= i) ++sn;
			while (sn <= tn && ct[sk[tn]] >= c) --tn;
			sk[++tn] = i;
			if (i >= L)
				a[i-L] = ct[sk[sn]] >= ct[i-L];
		}
		sn = 0,tn = -1;
		for (ct[L2] = 0,c = 0,i = L2-1;i > 0;--i){
			ct[i] = c += st[i] == 'C'?1:-1;
			while (sn <= tn && i+L <= sk[sn]) ++sn;
			while (sn <= tn && ct[sk[tn]] >= c) --tn;
			sk[++tn] = i;
			if (i <= L)
				a[i-1] |= ct[sk[sn]] >= ct[i+L];
		}
		for (r = 0,i = 0;i < L;i++)
			r += a[i];
		printf("Case %d: %d\n",t,r);
	}
}
