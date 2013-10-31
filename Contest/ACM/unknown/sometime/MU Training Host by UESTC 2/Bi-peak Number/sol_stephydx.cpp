#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
#include <algorithm>
using namespace std;

typedef unsigned long long llong;
typedef unsigned long long int64;

int dp[21][10][2][2][8];
char a[30],b[30];
void tomax(int &a,int b){if(b>a) a=b;}
int DP(int pos,int dig,int sa,int sb,int n){
	int &cur=dp[pos][dig][sa][sb][n];
	if(cur!=-1) return cur;
	cur=-100000;
	++pos;
	if(pos>20){
		if(n==6) cur=dig;
	}
	else{
		int nsa,nsb,nn;
		for(int i=0;i<10;++i){
			if(sa&&i>a[pos]) continue;
			nsa=(sa&&i==a[pos]);
			if(sb&&i<b[pos]) continue;
			nsb=(sb&&i==b[pos]);
			if(n==0){
				if(i>0) tomax(cur,DP(pos,i,nsa,nsb,1));
				else tomax(cur,DP(pos,i,nsa,nsb,0));
			}
			else if(n==1||n==4){
				if(i<=dig) continue;
				tomax(cur,DP(pos,i,nsa,nsb,n+1)+dig);
			}
			else if(n==2||n==5){
				if(i==dig) continue;
				if(i<dig) tomax(cur,DP(pos,i,nsa,nsb,n+1)+dig);
				else tomax(cur,DP(pos,i,nsa,nsb,n)+dig);
			}
			else{
				if(n+1<=6&&i>0) tomax(cur,DP(pos,i,nsa,nsb,n+1)+dig);
				if(i<dig) tomax(cur,DP(pos,i,nsa,nsb,n)+dig);
			}
		}
	}
	return cur;
}

int main()
{
	freopen("f:\\bipeak.in", "r", stdin);
	freopen("f:\\bipeak.out", "w", stdout);
	int TT;
	scanf("%d",&TT);
	llong A,B;
	for(int cas=1;cas<=TT;++cas){
		scanf("%I64u %I64u",&A,&B);
		sprintf(b,"%021I64u",A);
		sprintf(a,"%021I64u",B);
		memset(dp,-1,sizeof(dp));
		for(int i=0;a[i];++i) a[i]-='0',b[i]-='0';
		int r=DP(0,0,1,1,0);
		if(r<0) r=0;
		printf("Case %d: %d\n",cas,r);
	}
	return 0;
}

