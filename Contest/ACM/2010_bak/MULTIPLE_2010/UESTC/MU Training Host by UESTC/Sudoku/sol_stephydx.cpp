#include <cstdio>
#include <cstring>
#include <set>
#include <string>
#include <windows.h>
using namespace std;
const int Nsdk=2,SZsdk=Nsdk*Nsdk,TTsdk=SZsdk*SZsdk;
const int MaxNode=TTsdk*SZsdk*10,MaxCol=TTsdk*5;

struct Node{
	Node *L,*R,*U,*D,*C;
	int S,N;

	void delrow(){ L->R=R, R->L=L;}
	void delcol(){ U->D=D, D->U=U; --(C->S);}
	void recrow(){ L->R=R->L=this;}
	void reccol(){ U->D=D->U=this; ++(C->S);}
	void insrow(Node *x){
		x->L=L;	x->R=this;
		L->R=x;	L=x;
	}
	void inscol(Node *x){
		x->U=U; x->D=this;
		U->D=x;	U=x;
		++S;
	}
};

void covercol(Node *col){
	col->delrow();
	for(Node *p=col->D;p!=col;p=p->D)
	    for(Node *q=p->R;q!=p;q=q->R)
	        q->delcol();
}
void uncovercol(Node *col){
	for(Node *p=col->U;p!=col;p=p->U)
	    for(Node *q=p->L;q!=p;q=q->L)
	        q->reccol();
	col->recrow();
}

Node *path[MaxNode];
int tot_sol;
void exactcover(Node *H,int dep){
	void output(Node *path[],int len);
	if(H->R==H){
		output(path,dep);
		++tot_sol;
		return;
	}

	Node *col=H->R;
	for(Node *p=col->R;p!=H;p=p->R)
	    if(p->S<col->S) col=p;
	if(col->D==col) return;

	covercol(col);
	for(Node *p=col->D;p!=col;p=p->D){
		path[dep]=p;
	    for(Node *q=p->R;q!=p;q=q->R)
			covercol(q->C);
		exactcover(H,dep+1);
		for(Node *q=p->L;q!=p;q=q->L)
		    uncovercol(q->C);
	}
	uncovercol(col);
}

inline int ID(int tp,int a,int b){ return a*SZsdk+b+tp*TTsdk; }
bool sdk2link(int sdk[SZsdk][SZsdk],Node *H){
	Node *nxt=H+1,*hr;
	H->L=H->R=H;
	for(int i=0;i<TTsdk*4;++i){
		H->insrow(nxt);
		nxt->U=nxt->D=nxt;
		nxt->S=0,nxt->N=i;
		++nxt;
	}

	for(int i=0;i<SZsdk;++i){
	    for(int j=0;j<SZsdk;++j){
			int b=i/Nsdk*Nsdk+j/Nsdk;
			for(int d=0;d<SZsdk;++d){
				int idx[]={ID(0,i,j),ID(1,i,d),ID(2,j,d),ID(3,b,d)};
				for(int t=0;t<4;++t){
					if(t>0) hr->insrow(nxt);
					else hr=nxt->L=nxt->R=nxt;
					nxt->C=H+(idx[t]+1);
					nxt->C->inscol(nxt);
					++nxt;
				}
			}
		}
	}

	bool vst[TTsdk*4];
	memset(vst,0,sizeof(vst));
	for(int i=0;i<SZsdk;++i){
		for(int j=0;j<SZsdk;++j) if(sdk[i][j]>=0){
			int d=sdk[i][j],b=i/Nsdk*Nsdk+j/Nsdk;
			int idx[]={ID(0,i,j),ID(1,i,d),ID(2,j,d),ID(3,b,d)};
			for(int t=0;t<4;++t)
				if(vst[idx[t]]) return false;
				else{
					vst[idx[t]]=true;
					covercol(H+(idx[t]+1));
				}
		}
	}
}

Node node[MaxNode];
int src[SZsdk][SZsdk];
char sol[300][TTsdk+1];
int nsol;

void output(Node *path[],int len){
	for(int i=0;i<len;++i){
		int x,y,d;
		Node *p=path[i];
		do{
			int name=p->C->N;
			if(name<TTsdk) x=name/SZsdk%SZsdk,y=name%SZsdk;
			else if(name<TTsdk*2) d=name%SZsdk;
			p=p->R;
		}while(p!=path[i]);
		sol[tot_sol][ID(0,x,y)]=d+'1';
	}
	sol[tot_sol][TTsdk]=0;
}

int uni[10],cnt_sol[10],nu;

bool cmp(char *ans,char *puz){
	for(;*ans;++puz,++ans){
		if(*puz&&*puz!=*ans) return false;
	}
	return true;
}

char *cursol;
int cursid;
bool first=true;
void dfs(int dep,int beg){
	if(dep>=4){
		for(int i=0;i<nsol;++i)
			if(i!=cursid&&cmp(sol[i],cursol))
			    return;
	}
			    
	++tot_sol;
	for(int i=beg,tmp;i<TTsdk;++i){
		tmp=cursol[i];
		cursol[i]=0;
		dfs(dep+1,i+1);
		cursol[i]=tmp;
	}
}
void LRshf(char sdk[]){
	for(int x=0;x<Nsdk;++x)
		for(int y=0;y<SZsdk;++y)
			swap(sdk[ID(0,x,y)],sdk[ID(0,x+Nsdk,y)]);
}
void UDshf(char sdk[]){
	for(int x=0;x<SZsdk;++x)
	    for(int y=0;y<Nsdk;++y)
	        swap(sdk[ID(0,x,y)],sdk[ID(0,x,y+Nsdk)]);
}
int main(){
   	unsigned time0=GetTickCount();

	memset(src,-1,sizeof(src));
	sdk2link(src,node);
	exactcover(node,0);
	nsol=tot_sol;
//	printf("%d\n",tot_sol);

	set<string> st;
	nu=0;
	for(int i=0;i<tot_sol;++i){
		if(st.find(sol[i])==st.end()){
			int idx[SZsdk];
			char tmp[TTsdk+1];
			
			uni[nu]=i;
			for(int k=0;k<SZsdk;++k) idx[k]=k;
			tmp[TTsdk]=0;
			
			do{
				for(int k=0;k<TTsdk;++k)
					tmp[k]=idx[sol[i][k]-'1']+'1';
					
				st.insert(tmp);
				LRshf(tmp);st.insert(tmp);
				UDshf(tmp);st.insert(tmp);
				LRshf(tmp);st.insert(tmp);
			}while(next_permutation(idx,idx+4));
			cnt_sol[nu++]=st.size();
		}
	}
	for(int i=nu-1;i>=1;--i) cnt_sol[i]-=cnt_sol[i-1];
	for(int i=0;i<nu;++i) printf("%d ",cnt_sol[i]);puts("");
	int res=0;
	for(int i=0;i<nu;++i){
		printf("case %d %d:",i,uni[i]);
		tot_sol=0;
		cursol=sol[uni[i]];
		cursid=uni[i];
		dfs(0,0);
		res+=tot_sol*cnt_sol[i];
		printf("%d %d\n",tot_sol,res);
	}
	printf("%d %d\n",res,GetTickCount()-time0);
	system("pause");
	return 0;
}

