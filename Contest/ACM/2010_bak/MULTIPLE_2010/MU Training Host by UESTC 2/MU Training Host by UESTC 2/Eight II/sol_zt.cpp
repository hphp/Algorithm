#include <stdio.h>
#include <string.h>
#define MAX 362880

struct box{
	int d;
	char st[10],x;
}Q[MAX],cp;
int rm[9] = {1,1,2,6,24,120,720,5040,40320};
int vm[9] = {6,14,12,7,15,13,3,11,9};
int move[4] = {-3,1,3,-1},order[2][4] = {2,3,1,0,0,1,3,2};
int u[MAX],fa[MAX],id[MAX],QNum;
char w[MAX],ms[2][5] = {"urdl","dlur"};
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
//	printf("%d %d : %c\n",x,fa[x],w[x]);
	output(fa[x]);
	putchar(w[x]);
}
int main(){
	freopen("EightII.in","r",stdin);
	freopen("EightII.out","w",stdout);
	int T,L,t,i,j,k,x,x1,d,cs,cd,cx;
	int pd,qd,rd,nd,rx;
	char st[10],s1[10];
	bool find;
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		scanf("%s%s",s1,st);
		for (i = 0;i < 9;i++)
			if (s1[i] == 'X')
				s1[i] = '0',x1 = i;
		d = getS(s1);
		for (i = 0;i < 9;i++)
			if (st[i] == 'X')
				st[i] = '0',x = i;
//		printf("%s %s\n",s1,st);
		cd = getS(st);
		printf("Case %d: ",t);
		if (d == cd) puts("0\n");
		else{
			memset(u,-1,sizeof(u));
			QNum = 0;
			addS(s1,d,x1,0);
			addS(st,cd,x,1);
			fa[d] = fa[cd] = -1;
			i = 0,find = false,rd = nd = -1;
			while (i < QNum){
				cp = Q[i++];
				cs = u[cp.d] & 1;
				cd = u[cp.d] >> 1;
				//printf("%d : %s %d %d(%d,%d) %c %d\n",i-1,cp.st,cp.d,cp.x,cs,cd,w[cp.d],fa[cp.d]);getchar();
				if (find){
					if (cd > L) break;
					if (cs == 0) continue;
				}
				for (k = 0;k < 4;k++){
					j = order[cs][k];
					if (vm[cp.x] & (1 << j)){
						cx = cp.x+move[j];
						strcpy(st,cp.st);
						swp(st+cp.x,st+cx);
						d = getS(st);
						//printf("expand %s %d\n",st,d);
						if (u[d] == -1){
							addS(st,d,cx,u[cp.d]+2);
							w[d] = ms[cs][j],fa[d] = cp.d;
						}else if ((u[d] & 1) != cs){
							if (u[d] & 1)
								pd = cp.d,qd = d;
							else
								pd = d,qd = cp.d;
							if (rd == -1 || id[pd] < id[rd]){
								rd = pd,L = cd,nd = qd;
								rx = cd+(u[pd] >> 1)+1;
								x1 = ms[cs][j];
								find = true;
							}else if (id[pd] == id[rd] && ms[cs][j] < x1){
								nd = qd;
								x1 = ms[cs][j];
							}
						}else if ((u[d] & 1) && u[d] > u[cp.d]){
							if (ms[cs][j] < w[d])
								w[d] = ms[cs][j],fa[d] = cp.d;
						}
					}
				}
			}
			//printf("=> %d %c %d\n",rd,x1,nd);
			printf("%d\n",rx);
			output(rd);
			putchar(x1);
			while (fa[nd] != -1){
				putchar(w[nd]);
				nd = fa[nd];
			}
			putchar('\n');
		}
	}
	fclose(stdout);
}
