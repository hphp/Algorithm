#include <stdio.h>
#define N 100010

struct Node{
	int flag;
	int p;
	int l;
	int r;
}seg[N*4];

void build(int root,int s, int e){
	seg[root].s = s;
	seg[root].e = e;
	seg[root].p = 0;
	if(s < e)
	{
		int mid = (s+e)/2;
		build(root*2,s,mid);
		build(root*2+1,mid+1,e);
	}
}

void insert(int root , int s, int e , int add){
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s&& fe <= e){
		seg[root].p+=add;
		seg[root].flag = 1;
		return;
	}
	int mid = (fs+fe)/2;
	if(s <= mid){
		insert(root*2,s,e,add);
	}
	if(e > mid){
		insert(root*2+1,s,e,add);
	}
}

int query(int root,int s , int e){
	int fs = seg[root].s;
	int fe = seg[root].e;
	if(fs >= s&& fe <= e){
		return seg[root].p;
	}
	if(seg[root].flag == 1){
		seg[root].flag = 0;
		seg[root*2].p += seg[root].p;
		seg[root*2+1].p += seg[root].p;
		seg[root*2].flag = 1;
		seg[root*2+1].flag = 1;
	}
	int mid = (fs+fe)/2;
	if(s <= mid){
		return query(2*root,s,e);
	}
	if(e > mid){
		return query(2*root+1,s,e);
	}
}


int main(){
	int tc;
	scanf("%d",&tc);
	for(int tt = 1; tt <= tc ; tt ++){
		scanf("%d",&n);
		build(1,0,n);
		for(int i =0 ;i < n ;i ++){
			scanf("%d",&a);
			insert(1,a,n,1);
		}
		for(int i = 0; i < n ;i ++){
			int p = query(1,i,i);
			printf("%d ",p);
		}
		printf("\n");
	}
}
