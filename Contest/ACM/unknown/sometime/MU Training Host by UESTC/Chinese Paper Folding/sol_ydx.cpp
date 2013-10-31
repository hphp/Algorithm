#include <cstdio>
#include <cstring>
typedef long long llong;
const int Max=1000010;
int ctx[Max],cty[Max];
int L,R,D,U;

void swap(int &a,int &b){
	int tmp=a;a=b;b=tmp;
}
int abs(int x){return x<0?-x:x;}
int Fold(int val[],int &st,int &ed,int v){
	int res=0;
	if(v>abs(st-ed)-v){
		res=Fold(val,ed,st,abs(st-ed)-v);
		swap(st,ed);
	}
	else{
		int bs=(st<ed?st+v:st-v);
		int delt=(st<ed?1:-1);
		for(int i=0,off=delt;i<v;++i,off+=delt){
			val[bs+off]+=val[bs-off];
			val[bs-off]=0;
		}
		res=val[bs];
		val[bs]=0,st=bs;
	}
	return res;
}
int main(){
	int TT;
	freopen("folding.in","r",stdin);
	freopen("folding2.out","w",stdout);
	scanf("%d",&TT);
	for(int cas=1;cas<=TT;++cas){
		char buf[10];
		int X,Y,N,v;
		scanf("%d %d %d",&X,&Y,&N);
		for(int i=0;i<=X;++i) ctx[i]=1;
		for(int i=0;i<=Y;++i) cty[i]=1;
		ctx[0]=ctx[X]=cty[0]=cty[Y]=0;
		L=0,R=X,D=0,U=Y;
		int totx=0,toty=0;
		for(int i=0;i<N;++i){
			scanf("%s %d",buf,&v);
			if(buf[0]=='L') totx+=Fold(ctx,L,R,v);
			else if(buf[0]=='R') totx+=Fold(ctx,R,L,abs(L-R)-v);
			else if(buf[0]=='D') toty+=Fold(cty,D,U,v);
			else if(buf[0]=='U') toty+=Fold(cty,U,D,abs(D-U)-v);
		}
		printf("Case %d: %lld\n",cas,llong(totx)*Y+llong(toty)*X);
	}
	fclose(stdout);
	return 0;
}
