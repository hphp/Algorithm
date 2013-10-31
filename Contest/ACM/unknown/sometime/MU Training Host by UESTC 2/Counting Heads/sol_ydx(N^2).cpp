#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

#define F(x) (adv+min(G-(x),cx)+min(G-(both-(x)),cy))

const int Max=256;
int x[Max],y[Max],f[Max];
int rx[Max],ry[Max];
bool vst[Max];

bool cmpx(int i,int j){
	return x[i]>x[j];
}
bool cmpy(int i,int j){
	return y[i]>y[j];
}
int main(){

	int TT;
	scanf("%d",&TT);
	for(int cas=1;cas<=TT;++cas){
		int N,G;
		scanf("%d %d",&N,&G);
		for(int i=0;i<N;++i){
			scanf("%d %d %d",x+i,y+i,f+i);
			rx[i]=ry[i]=i;
		}
		sort(rx,rx+N,cmpx);
		sort(ry,ry+N,cmpy);
		memset(vst,0,sizeof(vst));
		
		int ans=0,fx=0,G2=G*2;
		for(int i=0;i<N;++i){
			vst[rx[i]]=true;
			if(f[rx[i]]==1) ++fx;
			int fy=0,both=0,adv=0;
			for(int j=0;j<N;++j){
				if(f[ry[j]]==1) ++fy;
				if(vst[ry[j]]){
					++both;
					if(f[ry[j]]==1) ++adv;
				}
				if(both>G2) break;
				
				int cx=fx-adv,cy=fy-adv;
				int lb=max(0,both-G),ub=min(both,G);
				ans=max(ans,F(lb)),ans=max(ans,F(ub));
				int tmp=G-cx;
				if(lb<=tmp&&tmp<=ub) ans=max(ans,F(tmp));
				tmp=both-G+cy;
				if(lb<=tmp&&tmp<=ub) ans=max(ans,F(tmp));
			}
		}
		printf("Case %d: %d\n",cas, ans);
	}
	return 0;
}
