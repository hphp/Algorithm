#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAXN 201

struct Peo{
	int v1, v2, num, native;
}peo1[MAXN], peo2[MAXN], temp[MAXN];

bool cmp1(Peo p1, Peo p2){
	return p1.v1 > p2.v1;
}

bool cmp2(Peo p1, Peo p2){
	return p1.v2 > p2.v2;
}

bool cmp2s(Peo p1, Peo p2){
	return p1.v2 < p2.v2;
}

int rank1[MAXN], rank2[MAXN];
bool used[MAXN];

int main(){
	int cases;
	scanf("%d", &cases);
	for(int caseT = 1; caseT <= cases; ++caseT){
		int n, g;
		scanf("%d%d", &n, &g);
		for(int i = 0; i < n; ++i){
			scanf("%d%d%d", &peo1[i].v1, &peo1[i].v2, &peo1[i].native);
			peo1[i].num = i;
			peo2[i] = peo1[i];
		}
		sort(peo1, peo1 + n, cmp1);
		sort(peo2, peo2 + n, cmp2);
		int res = 0;
		for(int i = g - 1; i < n; ++i){
			int cnt = 0;
			memset(used, false, sizeof(used));
			for(int j = 0; j <= i; ++j)
				if(peo1[j].native) ++cnt;
			if(cnt <= g){
				int curr = 0;
				for(int j = 0; j <= i; ++j)
					if(peo1[j].native == 0) temp[curr++] = peo1[j];
				sort(temp, temp + curr, cmp2s);
				for(int j = 0; j < i - g + 1; ++j){
					used[temp[j].num] = true;
			//		printf("%d ", temp[j].num);
				}
				for(int j = i + 1; j < n; ++j)
					if(peo1[j].native){
						used[peo1[j].num] = true;
		//				printf("%d ", peo1[j].num);
					}
	//			putchar('\n');
				int total = 0;
				for(int j = 0; j < n && total < g; ++j)
					if(used[peo2[j].num]){
						++total;
						if(peo2[j].native) ++cnt;
					}
				if(res < cnt) res = cnt;
	//			printf("%d %d\n", i, cnt);
			}
			else{
				int curr = 0;
				for(int j = 0; j <= i; ++j)
					if(peo1[j].native) temp[curr++] = peo1[j];
					else{
						used[peo1[j].num] = true;
//						printf("aa%d ", peo1[j].num);
					}
				sort(temp, temp + curr, cmp2);
				for(int j = 0; j < cnt - g; ++j){
					used[temp[j].num] = true;
//					printf("bb%d ", temp[j].num);
				}
				for(int j = i + 1; j < n; ++j)
					if(peo1[j].native){
						used[peo1[j].num] = true;
//						printf("cc%d ", peo1[j].num);
					}
				int total = 0;
				cnt = g;
				for(int j = 0; j < n && total < g; ++j)
					if(used[peo2[j].num]){
						++total;
						if(peo2[j].native) ++cnt;
					}
				if(res < cnt) res = cnt;
//				printf("%d %d\n", i, cnt);
			}
		}
		printf("Case %d: %d\n", caseT, res);
	}
	return 0;
}              