#include <cstdio>
#include <cstring>
#include <time.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef long long llong;

const llong MaxC=100000000000000000LL;
const int MaxSz=50;
llong Rand(llong x,llong y){
	if(y<x) return x;
	llong t=rand()&127;
	for(int b=7;b<63;b+=8) t=(t<<8)|(rand()&255);
	return x+t%(y-x+1);
}
set<vector<llong> > dup;
vector<llong> gen(const vector<llong> &bs){
	vector<llong> r=bs;
	while(true){
		random_shuffle(r.begin(),r.end());
		for(int i=0;i<r.size();++i)
			if(rand()&1) r[i]=-r[i];
		if(dup.find(r)==dup.end()){
			dup.insert(r);
			break;
		}
	}
	return r;
}
int main(){
	FILE *in=fopen("sphere.in","w");
	FILE *out=fopen("sphere.out","w");

	srand(time(0));
	int TT=10;
	fprintf(in,"%d\n",TT);

	for(int cas=1;cas<=TT;++cas){
		int N=(cas<=3?cas:MaxSz);
		vector<llong> dt(N),x0(N);
		fprintf(in,"%d\n",N);

		dup.clear();
		llong bd=MaxC/2;
		for(int i=0;i<N;++i) dt[i]=Rand(-bd,bd);
		for(int i=0;i<N;++i) x0[i]=Rand(-bd,bd);
		for(int i=0;i<=N;++i){
			vector<llong> tmp=gen(dt);
			for(int j=0;j<N;++j)
				fprintf(in,"%lld%c",tmp[j]+x0[j],j==N-1?'\n':' ');
		}

		for(int i=0;i<N;++i) fprintf(out,"%lld%c",x0[i],i==N-1?'\n':' ');
	}
	fclose(in);
	fclose(out);
	return 0;
}
