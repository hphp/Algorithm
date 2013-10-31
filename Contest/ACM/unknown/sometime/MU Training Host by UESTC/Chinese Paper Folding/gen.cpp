#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define Max 100000
#define MD 500000
#define MF 5000
#define MT 50
#define C 6

char sr[5] = "LRUD";
int D[Max],dir[Max];
int main(){
    int cnt = 0;
	int T,N,M,Q,cN,cM,mQ,t,ct,i,x,y,cd,d;
	srand((unsigned int)time(0));
	freopen("folding.in","w",stdout);
	FILE *ef = fopen("statistics.txt","w");
	printf("%d\n",T = MT);
	for (t = 0,--T;t < MT;t++,--T){
		if (T < 10) N = MD,M = MD;
		else{
			cd = MD / (T / 10+1);
			N = rand() % (MD-cd+1)+cd,M = rand() % (MD-cd+1)+cd;
		}
		printf("%d %d\n",N,M);
		cN = N,cM = M;
		if (T < 10) mQ = Max;
        else mQ = rand() % (Max-MF+1)+MF;
		for (Q = 0;(cN > 1 || cM > 1) && Q < mQ;Q++){
			if (cN == 1) cd = rand() % 2+2;
			else if (cM == 1) cd = rand() % 2;
			else cd = rand() % 4;
			if (cd < 2){
				if (T < 10 && rand() % 2)
					x = rand() % 2?cN-1:1;
				else{
					for (i = T < 10?1:C;i > 0;i++)
						if (rand() % 2)
							break;
					if (i == 0)
						x = rand() % 2?cN-1:1;
					else{
						if (T < 10) i = C;
						d = (cN-1) / (1 << (i << 1));
						if (d == 0) d = 1;
						x = rand() % d+1;
						if (rand() % 2) x = cN-x;
					}
				}
				y = cN-x;
				cN = x > y?x:y;
			}else{
				if (T < 10 && rand() % 2)
					x = rand() % 2?cM-1:1;
				else{
					for (i = T < 10?1:C;i > 0;i++)
						if (rand() % 2)
							break;
					if (i == 0)
						x = rand() % 2?cM-1:1;
					else{
						if (T < 10) i = C;
						d = (cM-1) / (1 << (i << 1));
						if (d == 0) d = 1;
						x = rand() % d+1;
						if (rand() % 2) x = cM-x;
					}
				}
				y = cM-x;
				cM = x > y?x:y;
			}
			dir[Q] = sr[cd],D[Q] = x;
		}
		printf("%d\n",Q);
		for (i = 0;i < Q;i++)
			printf("%c %d\n",dir[i],D[i]);
		fprintf(ef,"Case %d: %d %d %d | %d %d\n",t,N,M,Q,cN,cM);
	}
	fclose(stdout);
	fclose(ef);
}
