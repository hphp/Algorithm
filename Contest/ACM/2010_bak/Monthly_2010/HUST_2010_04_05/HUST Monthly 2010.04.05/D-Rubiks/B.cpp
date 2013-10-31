#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
using namespace std;

#define maxn 1010
#define LEN 10010

struct node{
	int p,v,g;
};
node nd[maxn];
int n,m;
int g;
int gn[maxn];
int gv[maxn];
int gp[maxn];
char f[2][LEN];
int v[2][LEN];

bool cmp(const node &a, const node &b){
	return a.g < b.g;
}
void solve(){
	int i,j,k;
	int tmp;
	int res;
	int last;
	for(i=0;i<n;++i) scanf("%d",&nd[i].p);
	for(i=0;i<n;++i) scanf("%d",&nd[i].v);
	for(i=0;i<n;++i) nd[i].g=0;
	scanf("%d",&g);
	for(i=0,j=1;i<g;++i){
		scanf("%d",gn+j);
		if(gn[j]!=1){
			gp[j]=0;
			gv[j]=0;
			for(k=0;k<gn[j];++k){
				scanf("%d",&tmp);
				gp[j]+=nd[tmp-1].p;
				gv[j]+=nd[tmp-1].v;
				nd[tmp-1].g=j;
			}
			scanf("%d",&tmp);
			gv[j]+=tmp;
			++j;
		}else{
			scanf("%d",&k);
			scanf("%d",&tmp);
			nd[k-1].v+=tmp;
		}
	}
	g=j-1;
	gv[0]=0;gp[0]=LEN;gn[0]=maxn;
	sort(nd,nd+n,cmp);
	nd[n].g=maxn; nd[n].p=LEN; nd[n].v=0;
	memset(f[0],0,sizeof(f[0][0])*(m+1));
	memset(f[1],0,sizeof(f[1][0])*(m+1));
	memset(v[0],0,sizeof(v[0][0])*(m+1));
	memset(v[1],0,sizeof(v[1][0])*(m+1));
	f[0][0]=f[1][0]=1;
	//v[0][0]=v[1][0]=0;
	last=0;
//	for(i=0;i<n;++i) printf("%d %d %d\n",nd[i].p,nd[i].v,nd[i].g);
	for(i=0;i<=n;++i){
		if(nd[i].g>last){
			for(j=m;j>=gp[last];--j){
				k=j-gp[last];
				if(f[1][k] && v[1][k]+gv[last]> v[1][j]){
					v[1][j]=v[1][k]+gv[last];
				}
			}
			memcpy(f[1],f[0],sizeof(f[0][0])*(m+1));
			for(j=0;j<=m;++j){
				if(v[1][j]>=v[0][j]) v[0][j]=v[1][j];
				else v[1][j]=v[0][j];
			}
			++last;
			//last=nd[i].g;
		}
		for(j=m;j>=nd[i].p;--j){
			k=j-nd[i].p;
			if(f[0][k]){
				if(!f[0][j]){
					f[0][j]=1;
					v[0][j]=v[0][k]+nd[i].v;
				}else{
					if(v[0][k]+ nd[i].v > v[0][j]){
						v[0][j]=v[0][k]+ nd[i].v;
					}
				}
			}
		}
	}
	res=0;
	for(i=0;i<=m;++i) if(f[0][i] && v[0][i]>res) res=v[0][i];
	printf("%d\n",res);
}
int main(){
	while(EOF!=scanf("%d%d", &n,&m)) solve();
	return 0;
}
