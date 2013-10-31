#include <stdio.h>
#define N 2010
#define M 110

int mx[N][M];

struct ss
{
	int st,ed,cost;
};
ss sign[MAX];

inline void Read(int &x){
   x=0;
   char ch;
   ch=getchar();
   while (ch==' ' || ch=='\n') ch=getchar();//去掉空格和回车
   while (ch!=' ' && ch!='\n' && ch!=':'){
		//if(ch!='.')//去掉小数点
         x=x*10+ch-'0';
         ch=getchar();  
   }
}

void input()
{
	int x1,y1,z1,x2,y2,z2;
	char st[50],ed[50];
	int co;
	for(int i=1;i<=N;i++)
	{
		Read(x1);Read(y1);Read(z1);
		Read(x2);Read(y2);Read(z2);
		Read(co);
		sign[i].st=x1*3600+y1*60+z1;
		sign[i].ed=x2*3600+y2*60+z2;
		sign[i].cost=co;
	}
}

int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
			
	}
}
