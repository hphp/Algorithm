#include <cstdio>
#include <cstring>
const int Max=1000010;
char buf[Max];//,tmp[Max];
int lt[Max],rt[Max],d[Max];
int min(int a,int b){return a<b?a:b;}
int main(){
	int TT;
	scanf("%d",&TT);
	for(int cas=1;cas<=TT;++cas){
		scanf("%s",buf+1);
		//strcpy(tmp+1,buf+1);
		int N=strlen(buf+1);
		d[0]=0;
		for(int i=1;i<=N;++i)
			d[i]=d[i-1]+(buf[i]=='C'?1:-1);
		lt[0]=rt[N+1]=Max;
		for(int i=1,j=N;i<=N;++i,--j){
			lt[i]= min(d[i],lt[i-1]);
			rt[j]= min(d[j],rt[j+1]);
		}
		int D=d[N];
		for(int i=1;i<=N;++i)
			buf[i]=(rt[i]-d[i-1]>=0&&D-d[i-1]+lt[i-1]>=0);
		buf[N+1]=buf[1];
		
		d[N+1]=0;
		for(int i=N;i>=1;--i) d[i]=D-d[i-1];
		lt[0]=rt[N+1]=Max;
		for(int i=1,j=N;i<=N;++i,--j){
			lt[i]= min(d[i],lt[i-1]);
			rt[j]= min(d[j],rt[j+1]);
		}
		int cnt=0;
		for(int i=1;i<=N;++i){
			cnt+=buf[i+1]||(lt[i]-d[i+1]>=0&&D-d[i+1]+rt[i+1]>=0);
//			if(buf[i+1]||lt[i]-d[i+1]>=0&&D-d[i+1]+rt[i+1]>=0) printf("%d ",i);
		}
		printf("Case %d: %d\n",cas,cnt);
	}
	return 0;
}
