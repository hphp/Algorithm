#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long llong;

//modular solution
const llong Mod=1234567894987654321LL;
const llong MC=100000000000000000LL;
const int MSZ=64;

llong mul(llong a,llong b,llong m){
	llong r=0;
	for(;b;b>>=1){
		if(b&1) if((r+=a)>=m) r-=m;
		if((a<<=1)>=m) a-=m;
	}
	return r;
}
void gcdxy(llong a,llong b,llong &x,llong &y){
	if(a==0){ x=0,y=1; return;}
	gcdxy(b%a,a,y,x);
	x-=b/a*y;
}
llong inv(llong a,llong m){
	static llong x,y;
	gcdxy(a,m,x,y);
	if((x%=m)<0) x+=m;
	return x;
}
void swap(llong r1[],llong r2[],int N,int st){
	for(;st<=N;++st) swap(r1[st],r2[st]);
}
void add(llong r1[],llong r2[],int N,int st,llong k){
	for(;st<=N;++st)
		if((r2[st]+=mul(k,r1[st],Mod))>=Mod)
			r2[st]-=Mod;
}
void solve(llong mx[MSZ][MSZ],llong x[MSZ],int N){
	for(int i=0;i<N;++i){
		int sw=i;
		while(mx[sw][i]==0) ++sw;
		if(sw>i) swap(mx[i],mx[sw],N,i);
		llong div=inv(Mod-mx[i][i],Mod);
		for(int j=i+1;j<N;++j) if(mx[j][i]){
			add(mx[i],mx[j],N,i,mul(div,mx[j][i],Mod));
		}
	}
	
	for(int i=N-1;i>=0;--i){
		llong a=mx[i][i],b=mx[i][N];
		for(int j=i+1;j<N;++j)
			if((b-=mul(mx[i][j],x[j],Mod))<0) b+=Mod;
		x[i]=mul(b,inv(a,Mod),Mod);
	}
}

llong mx[MSZ][MSZ];
llong x[MSZ][MSZ],X[MSZ];

int main(){
	freopen("f:\\sphere.in","r",stdin);
	freopen("f:\\sphere2.out","w",stdout);
	
	int TT;
	scanf("%d",&TT);
	
	for(int cas=1;cas<=TT;++cas){
		int N;
		scanf("%d",&N);
		
		for(int i=0;i<=N;++i)
			for(int j=0;j<N;++j){
				scanf("%I64d",x[i]+j);
			}

		for(int i=0;i<N;++i){
			llong sum=0,t1,t2;
			for(int j=0;j<N;++j){
				if((t1=x[i][j]-x[N][j])<0) t1+=Mod;
				if((t2=x[i][j]+x[N][j])<0) t2+=Mod;
				
				mx[i][j]=t1;
				if((sum+=mul(t1,t2,Mod))>=Mod) sum-=Mod;
			}
			mx[i][N]=mul(sum,inv(2,Mod),Mod);
		}
		
		printf("Case %d:\n", cas);
		solve(mx,X,N);
		for(int i=0;i<N;++i){
			if(X[i]>MC) X[i]-=Mod;
			printf("%I64d%c",(X[i]<MC?X[i]:X[i]-Mod),(i<N-1?' ':'\n'));
		}
	}
	return 0;
}
