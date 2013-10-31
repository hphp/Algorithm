#include<iostream>
using namespace std;
int T[310][4010];
bool flag[1010];
int kind;
void creat(int id,int pos,int l,int r){
	T[id][pos]=0;
	if(l==r) return ;
	int mid=(l+r)>>1;
	creat(id,pos*2,l,mid);
	creat(id,pos*2+1,mid+1,r);
}
void insert(int id,int pos,int l,int r,int s,int e){
	if(l==s&&r==e){
		T[id][pos]=kind;
		return ;
	}
	int mid=(l+r)>>1;
	if(T[id][pos]>=0) T[id][pos*2]=T[id][pos*2+1]=T[id][pos],T[id][pos]=-1;
	if(e<=mid) insert(id,pos*2,l,mid,s,e);
	else if(s>mid) insert(id,pos*2+1,mid+1,r,s,e);
	else{
		insert(id,pos*2,l,mid,s,mid);
		insert(id,pos*2+1,mid+1,r,mid+1,e);
	}
}
void sum(int id,int pos){
	if(T[id][pos]>=0){
		flag[T[id][pos]]=1;
		return ;	
	}
	sum(id,pos*2);
	sum(id,pos*2+1);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int i,row,col,m,ans,j,x1,y1,x2,y2;
	//long start=clock(),end(0);
	while(~scanf("%d%d%d",&row,&col,&m)){
		for(i=1;i<=row;i++) creat(i,1,1,col);
		for(i=1;i<=m;i++){
			kind=i;
			flag[i]=0;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(j=x1;j<=x2;j++) insert(j,1,1,col,y1,y2);
		}
		ans=0;
		for(i=1;i<=row;i++) sum(i,1);
		for(i=1;i<=m;i++) if(!flag[i]) ans++;	
		printf("%d\n",ans);
	}
	//end=clock();
	//printf("%d\n",(end-start)/1000);  
	return 0;
}
