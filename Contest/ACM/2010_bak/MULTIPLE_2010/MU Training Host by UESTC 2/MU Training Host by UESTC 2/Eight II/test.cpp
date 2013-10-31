#include <stdio.h>
#include <string.h>
#define MAX 362880

struct box{
	int d;
	char st[10],x;
}Q[MAX],cp;
int rm[9] = {1,1,2,6,24,120,720,5040,40320};
int vm[9] = {6,14,12,7,15,13,3,11,9};
int move[4] = {-3,1,3,-1};
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
	int T,L,i,j,x,x1,d,cs,cd,cx;
	int pd,qd,rd,nd,rx;
	char st[10],s1[10];
	bool find;
	FILE *pin = fopen("EightII.in","r");
	FILE *pout = fopen("EightII2.out","r");
	fscanf(pin,"%d",&T);
	for (int t = 1;t <= T;t++){
//		printf("Case %d : \n",t);//getchar();
		fscanf(pin,"%s",s1);
		for (i = 0;i < 9;i++)
			if (s1[i] == 'X')
				s1[i] = '0',x1 = i;
//		printf("Start : %s\n",s1);
		fscanf(pout,"%*s%*s%d",&rd);
		if (rd) fscanf(pout,"%s",st);
		//printf("Oper : %s\n",st);
		for (i = 0;i < rd;i++){
			for (j = 0;j < 4;j++)
				if (st[i] == ms[0][j])
					break;
			if (vm[x1] & (1 << j)){
				x = x1+move[j];
				swp(s1+x1,s1+x);
				x1 = x;
			}else
				break;
			//printf("Step %d(%c) : %s\n",i,st[i],s1);
		}
		printf("Case %d : ",t);
		if (i < rd){
			fscanf(pin,"%s",st);
			for (i = 0;i < 9;i++)
				if (st[i] == 'X')
					st[i] = '0';
			printf("Case %d\n",t);
			puts("Fail during operation.");getchar();
			continue;
		}
		fscanf(pin,"%s",st);
		for (i = 0;i < 9;i++)
			if (st[i] == 'X')
				st[i] = '0';
		if (strcmp(st,s1)){
			printf("The result is not match!");getchar();
		}else
			puts("OK!");
	}
	while (1);
}
