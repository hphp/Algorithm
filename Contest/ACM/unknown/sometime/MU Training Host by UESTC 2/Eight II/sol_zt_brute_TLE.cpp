#include <stdio.h>
#include <string.h>
#define MAX 362880

struct box{
	int d;
	char st[10],x;
}Q[MAX],cp;
int rm[9] = {1,1,2,6,24,120,720,5040,40320};
int vm[9] = {6,14,12,7,15,13,3,11,9};
int move[4] = {-3,1,3,-1},order[4] = {2,3,1,0};
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
	freopen("EightII2.out","w",stdout);
	int T,L,t,i,j,k,x,x1,d,cs,cd,cx;
	int pd,qd,rd,nd,rx,gd;
	char st[10],s1[10],goal[10];
	bool find;
	scanf("%d",&T);
	for (t = 1;t <= T;t++){
		scanf("%s%s",s1,goal);
		for (i = 0;i < 9;i++)
			if (s1[i] == 'X')
				s1[i] = '0',x1 = i;
		d = getS(s1);
		for (i = 0;i < 9;i++)
			if (goal[i] == 'X')
				goal[i] = '0',x = i;
		gd = getS(goal);
//		printf("%s(%d) %s(%d)\n",s1,d,goal,gd);
        printf("Case %d: ",t);
		if (d == gd) puts("0\n");
		else{
			memset(u,-1,sizeof(u));
			QNum = 0;
			addS(s1,d,x1,0);
			fa[d] = -1;
			i = 0,find = false;
			while (i < QNum && !find){
				cp = Q[i++];
				cs = u[cp.d] & 1;
				cd = u[cp.d] >> 1;
				//printf("%d : %s %d %d(%d,%d) %c %d\n",i-1,cp.st,cp.d,cp.x,cs,cd,w[cp.d],fa[cp.d]);getchar();
				for (k = 0;k < 4;k++){
					j = order[k];
					if (vm[cp.x] & (1 << j)){
						cx = cp.x+move[j];
						strcpy(st,cp.st);
						swp(st+cp.x,st+cx);
						d = getS(st);
						//printf("expand %s %d\n",st,d);
						if (u[d] == -1){
							addS(st,d,cx,u[cp.d]+2);
							w[d] = ms[cs][j],fa[d] = cp.d;
							if (d == gd){
								find = true;
								break;
							}
						}
					}
				}
			}
//			printf("goal %d | %d\n",u[gd],cd);
			if (find){
				//printf("=> %d %c %d\n",rd,x1,nd);
				//printf("%d\n",u[gd] >> 1);;
				printf("%d\n",u[gd] >> 1);;
				output(gd);
				putchar('\n');
			}else
				puts("unsolvable");
		}
	}
	fclose(stdout);
}
