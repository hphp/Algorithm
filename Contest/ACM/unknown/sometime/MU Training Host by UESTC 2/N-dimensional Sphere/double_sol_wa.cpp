#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const int MSZ=64;
const double eps=1e-6;

void swap(double r1[],double r2[],int N,int st){
	for(;st<=N;++st) swap(r1[st],r2[st]);
}
void add(double r1[],double r2[],int N,int st,double mul){
	for(;st<=N;++st) r2[st]+=mul*r1[st];
}
void out(int mx[MSZ][MSZ],int N){
	for(int i=0;i<N;++i){
		for(int j=0;j<=N;++j)printf("%.3f ",mx[i][j]);
		puts("");
	}
	puts("");
}
bool solve(double mx[MSZ][MSZ],double x[MSZ],int N){
	for(int i=0;i<N;++i){
		int sw=i;
		while(sw<N&&fabs(mx[sw][i])<eps) ++sw;
		if(sw>=N) return false;
		if(sw>i) swap(mx[i],mx[sw],N,i);
//		out(mx,N);
		for(int j=i+1;j<N;++j)
			if(fabs(mx[j][i])>eps) add(mx[i],mx[j],N,i,-mx[j][i]/mx[i][i]);
//		out(mx,N);
	}
	
	for(int i=N-1;i>=0;--i){
		double a=mx[i][i],b=mx[i][N];
		for(int j=i+1;j<N;++j) b-=mx[i][j]*x[j];
		x[i]=b/a;
	}
	return true;
}

double mx[MSZ][MSZ];
double x[MSZ][MSZ],X[MSZ];
int main(){
	freopen("sphere.in","r",stdin);
	freopen("sphere3.out","w",stdout);
	
	int TT;
	scanf("%d",&TT);
	
	for(int cas=1;cas<=TT;++cas){
		int N;
		scanf("%d",&N);
		
		for(int i=0;i<=N;++i)
			for(int j=0;j<N;++j)
				scanf("%lf",x[i]+j);

		for(int i=0;i<N;++i){
			double sum=0;
			for(int j=0;j<N;++j){
				mx[i][j]=x[i][j]-x[N][j];
				sum+=mx[i][j]*(x[i][j]+x[N][j]);
			}
			mx[i][N]=sum/2.;
		}
//		out(mx,N);
		
		solve(mx,X,N);
		for(int i=0;i<N;++i)
			printf("%.0f%c",X[i],(i<N-1?' ':'\n'));
	}
//	fprintf(stderr,"%u ms\n",GetTickCount()-Time0);while(true);
	return 0;
}
