#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int maxn=300010;

struct node{
	int left,right,father;
	int x;
	int total;
	bool reverse;
};

int n,root,now;
node a[maxn];

void leftrotate(int y){
	int x=a[y].father;
	a[y].father=a[x].father;
	if (a[x].father!=0){
		if (a[a[x].father].left==x)
			a[a[x].father].left=y;
		else a[a[x].father].right=y;
	}
	a[x].right=a[y].left;
	if (a[y].left!=0) a[a[y].left].father=x;
	a[y].left=x;
	a[x].father=y;
	a[x].total=1+a[a[x].left].total+a[a[x].right].total;
	a[y].total=1+a[a[y].left].total+a[a[y].right].total;
}

void rightrotate(int x){
	int y=a[x].father;
	a[x].father=a[y].father;
	if (a[y].father!=0){
		if (a[a[y].father].left==y)
			a[a[y].father].left=x;
		else a[a[y].father].right=x;
	}
	a[y].left=a[x].right;
	if (a[x].right!=0) a[a[x].right].father=y;
	a[x].right=y;
	a[y].father=x;
	a[y].total=1+a[a[y].left].total+a[a[y].right].total;
	a[x].total=1+a[a[x].left].total+a[a[x].right].total;
}

void splay(int cur){
	int p;
	while (a[cur].father!=0){
		p=a[cur].father;
		if (a[p].father==0){
			if (cur==a[p].left) rightrotate(cur);
			else leftrotate(cur);
			break;
		}
		if (cur==a[p].left)
			if (p==a[a[p].father].left){
				rightrotate(p);
				rightrotate(cur);
			}
			else{
				rightrotate(cur);
				leftrotate(cur);
			}
		else
			if (p==a[a[p].father].right){
				leftrotate(p);
				leftrotate(cur);
			}
			else{
				leftrotate(cur);
				rightrotate(cur);
			}
	}
	root=cur;
}

int build(int fa,int l,int r){
	if (l>r) return 0;
	else if (l==r){
		a[l].x=l;a[l].father=fa;a[l].total=1;
		return l;
	}
	int cur=(l+r)/2;
	a[cur].x=cur;a[cur].total=r-l+1;a[cur].father=fa;
	a[cur].left=build(cur,l,cur-1);
	a[cur].right=build(cur,cur+1,r);
	return cur;
}

void flip(int cur){
	swap(a[cur].left,a[cur].right);
	a[cur].reverse=false;
	if (a[cur].left!=0)
		if (a[a[cur].left].reverse)
			a[a[cur].left].reverse=false;
		else a[a[cur].left].reverse=true;
	if (a[cur].right!=0)
		if (a[a[cur].right].reverse)
			a[a[cur].right].reverse=false;
		else a[a[cur].right].reverse=true;
}

void getkth(int k){
	int cur=root;
	while (1){
		if (a[cur].reverse)
			flip(cur);
		if (k>a[a[cur].left].total+1){
			k-=(a[a[cur].left].total+1);
            cur=a[cur].right;
		}
		else if (k!=a[a[cur].left].total+1)
            cur=a[cur].left;
        else break;    
	}
	splay(cur);
}

void getmin(){
	int cur=root;
	while (1){
		if (a[cur].reverse)
			flip(cur);
		if (a[cur].left!=0) cur=a[cur].left;
		else break;
	}
	splay(cur);
}

void getmax(){
	int cur=root;
	while (1){
		if (a[cur].reverse)
			flip(cur);
		if (a[cur].right!=0) cur=a[cur].right;
		else break;
	}
	splay(cur);
}

void reverse(int x,int y){
	getkth(x);
	int tmpA=0,tmpB=0;
	if (a[root].left!=0){
		tmpA=a[root].left;
		a[root].total-=a[tmpA].total;
		a[root].left=0;
		a[tmpA].father=0;
	}
	getkth(y-x+1);
	if (a[root].right!=0){
		tmpB=a[root].right;
		a[root].total-=a[tmpB].total;
		a[root].right=0;
		a[tmpB].father=0;
	}
	if (a[root].reverse) a[root].reverse=false;
	else a[root].reverse=true;
	getmax();
	if (tmpB!=0){
		a[root].right=tmpB;
		a[tmpB].father=root;
		a[root].total+=a[tmpB].total;
	}
	getmin();
	if (tmpA!=0){
		a[root].left=tmpA;
		a[tmpA].father=root;
		a[root].total+=a[tmpA].total;
	}
}

void merge(int x,int y){
	if (x==0){
		root=y;
		return;
	}
	if (y==0){
		root=x;
		return;
	}
	root=x;
	getmax();
	if (y!=0){
		a[y].father=root;
		a[root].right=y;
		a[root].total+=a[y].total;
	}
	return;
}

void cut(int x,int y,int z){
	getkth(x);
	int tmpA=0,tmpB=0,tmpXY;
	if (a[root].left!=0){
		tmpA=a[root].left;
		a[root].total-=a[tmpA].total;
		a[tmpA].father=0;
		a[root].left=0;
	}
	getkth(y-x+1);
	if (a[root].right!=0){
		tmpB=a[root].right;
		a[root].total-=a[tmpB].total;
		a[tmpB].father=0;
		a[root].right=0;
	}
	tmpXY=root;
	merge(tmpA,tmpB);
	if (z==0){
		tmpB=root;
		tmpA=0;
	}
	else{
		getkth(z);
		tmpA=root;
		tmpB=a[root].right;
		if (tmpB!=0) a[tmpB].father=0;
		a[root].right=0;
	}

	merge(tmpA,tmpXY);
	tmpA=root;
	merge(tmpA,tmpB);
}

void print(int cur){
	now++;
	if (a[cur].reverse)
		flip(cur);
	if (a[cur].left!=0) print(a[cur].left);
	if (now<n) printf("%d ",a[cur].x);
	else printf("%d\n",a[cur].x);
	if (a[cur].right!=0) print(a[cur].right);
}

int main(){
	freopen("pchain.in","r",stdin);
    freopen("pchain.out","w",stdout);
    int command,x,y,z;
    while (scanf("%d%d",&n,&command)>0,n!=-1){
	      memset(a,0,sizeof(a));
	      root=now=0;
       	  char st[100];
	      root=build(0,1,n);
	      for (int i=0;i<command;i++){
		      scanf("%s",st);
		      if (st[0]=='C'){
			     scanf("%d%d%d",&x,&y,&z);
			     cut(x,y,z);
		      }
		      else{
			       scanf("%d%d",&x,&y);
			       reverse(x,y);
		        }
	         }
      	  now=0;print(root);   
          }
	return 0;
}
