#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <time.h>
using namespace std;

const int MaxN=200,MaxS=10000;
set<int> dupx,dupy;
int x[MaxN],y[MaxN],f[MaxN];
pair<int,int> newscore(){
	int x=rand()%MaxS,y=rand()%MaxS;
	while(!dupx.insert(x).second) x=rand()%MaxS;
	while(!dupy.insert(y).second) y=rand()%MaxS;
	return make_pair(x,y);
}

int main(){
	srand(time(0));
	freopen("counthead.in","w",stdout);
	int TT=200;
	printf("%d\n",TT);
	for(int cas=1;cas<=TT;++cas){
		dupx.clear(),dupy.clear();
		int N,G;
		if(cas<=10){//G==0
			N=MaxN/5,G=0;
			for(int i=0;i<N;++i){
				pair<int,int> sc=newscore();
				x[i]=sc.first,y[i]=sc.second,f[i]=rand()%2;
			}
		}
		else if(cas<=20){//G==N/2
		    N=MaxN/5,G=N/2;
		    for(int i=0;i<N;++i){
			    pair<int,int> sc=newscore();
			    x[i]=sc.first,y[i]=sc.second,f[i]=rand()%2;
			}
		}
		else if(cas<=30){//reverse order
		    N=MaxN/5,G=rand()%(N/2+1);
		    for(int i=0;i<N;++i)
				x[i]=i,y[i]=N-i,f[i]=rand()%2;
		}
		else if(cas<=40){//no native
			N=MaxN/5,G=rand()%(N/2+1);
			for(int i=0;i<N;++i){
				pair<int,int> sc=newscore();
				x[i]=sc.first,y[i]=sc.second,f[i]=0;
			}
		}
		else if(cas<=50){//all native
		    N=MaxN/5,G=rand()%(N/2+1);
		    for(int i=0;i<N;++i){
				pair<int,int> sc=newscore();
				x[i]=sc.first,y[i]=sc.second,f[i]=1;
			}
		}
		else if(cas<=100){//small,random
		    N=rand()%(MaxN/4)+2,G=rand()%(N/2+1);
		    for(int i=0;i<N;++i){
				pair<int,int> sc=newscore();
				x[i]=sc.first,y[i]=sc.second,f[i]=rand()%2;
			}
		}
		else{//large,random
		    N=rand()%(MaxN/2)+MaxN/2,G=rand()%(N/2+1);
		    for(int i=0;i<N;++i){
				pair<int,int> sc=newscore();
				x[i]=sc.first,y[i]=sc.second,f[i]=rand()%2;
			}
		}
		printf("%d %d\n",N,G);
		for(int i=0;i<N;++i) printf("%d %d %d\n",x[i],y[i],f[i]);
	}
	return 0;
}
