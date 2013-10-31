#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 
#define M 362880

struct box{
	int d;
	char st[10],x;
}Q[M],cp;
int rm[9] = {1,1,2,6,24,120,720,5040,40320};
int vm[9] = {6,14,12,7,15,13,3,11,9};
int move[4] = {-3,1,3,-1},order[4] = {2,3,1,0};
int u[M],fa[M],id[M],QNum;
char w[M],ms[2][5] = {"urdl","dlur"};
int getS(char *st){
	int r = 0,i,j,c;
	for (i = 0;i < 9;i++){
		c = 0;
		for (j = i+1;j < 9;j++)
			if (st[i] > st[j])
				c++;
		r += c*rm[8-i];
	}
	return r;
}
void swp(char*i,char*j){char c=*i;*i=*j,*j=c;}
void addS(char *s,int d,char x,int dis){
	box &p = Q[QNum++];
	strcpy(p.st,s),p.x = x;
	u[p.d = d] = dis;
	id[d] = QNum-1;
}
void output(int x){
	if (fa[x] == -1) return;
	//printf("%d %d : %c\n",x,fa[x],w[x]);
	output(fa[x]);
	putchar(w[x]);
}
int main(){
	freopen("EightII.in","w",stdout);
	int T,L,i,j,k,x,x1,d,cs,cd,cx;
	int pd,qd,rd,nd,rx,gd,step;
	char st[10],s1[10],goal[10];
	bool find;
	srand((unsigned int)time(0));
	T = 500;
	printf("%d\n",T);
	for (int t = 1;t <= T;t++){
		bool ct[10];
		cd = d = rand() % M*rand() % M;
		memset(ct,0,sizeof(ct));
		for (i = 0;i < 9;i++){
			j = d / rm[8-i];
			d %= rm[8-i];
			for (k = 0,x = 0;x <= j;k++)
				x += !ct[k];
			ct[--k] = true;
			putchar(k?k+'0':'X');
			s1[i] = k+'0';
			if (k == 0) x1 = i;
		}
		s1[9] = '\0';
		putchar('\n');
		memset(u,-1,sizeof(u));
		QNum = 0;
		addS(s1,cd,x1,0);
		fa[cd] = -1;
		i = 0;
		while (i < QNum){
			cp = Q[i++];
			cs = u[cp.d] & 1;
			cd = u[cp.d] >> 1;
			for (k = 0;k < 4;k++){
				j = order[k];
				if (vm[cp.x] & (1 << j)){
					cx = cp.x+move[j];
					strcpy(st,cp.st);
					swp(st+cp.x,st+cx);
					d = getS(st);
					if (u[d] == -1){
						addS(st,d,cx,u[cp.d]+2);
						w[d] = ms[cs][j],fa[d] = cp.d;
					}
				}
			}
		}
		step = (rand() % (cd+1)*rand() % (cd+1)+rand()) % (cd+1);
		if (step < cd / 2 || (step == 0))
			if ((rand() & 1) || (rand() & 1))
				step += cd / 2;
		d = -1;
		for (i = 0;i < M;i++)
			if ((u[i] >> 1) == step)
				if (d == -1 || (rand() & 1))
					d = i;
//		printf("step = %d| %d %d %d\n",step,d,u[d] >> 1,fa[d]);
//		output(d),putchar('\n');
		memset(ct,0,sizeof(ct));
		for (i = 0;i < 9;i++){
			j = d / rm[8-i];
			d %= rm[8-i];
			for (k = 0,x = 0;x <= j;k++)
				x += !ct[k];
			ct[--k] = true;
			putchar(k?k+'0':'X');
		}
		putchar('\n');
		//getchar();
	}
	fclose(stdout);
}
