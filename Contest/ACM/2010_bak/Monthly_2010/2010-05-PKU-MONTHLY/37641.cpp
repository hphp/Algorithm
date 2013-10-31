#include<iostream>
#include<algorithm>
#define MAXX (1<<30)
#define Max(a,b) ((a)>(b)?(a):(b))
using namespace std;
const int MAX = 2100;
const int inf=1000000;
struct Node 
{
	int id,cost;
	Node *next;
};
Node node[MAX*2],edge[10000000];

struct ss
{
	int st,ed,cost;
};

ss sign[MAX];
int tt,N,K;

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

bool cmp(ss a , ss b)
{
	if(a.ed < b.ed)
		return 1;
		return 0;	
}

void Make_map()
{
	
}

int mx[MAX][110];

void Solve()
{
	std::sort(sign+1,sign+N+1,cmp);
	for(int i=1;i<=N;i++)
		printf("%d ",sign[i].ed);
		printf("\n");
	int last[MAX],stbfr[MAX];
	for(int i=0;i<=N;i++)
	{
		last[i] = 0;
		for(int j=0;j<=K;j++)
			mx[i][j] = -MAXX;
		for(int j=i-1;j>0;j--)
			if(sign[j].ed <= sign[i].st)
			{
				last[i] = j;break;
			}
		for(int j=i-1;j>0;j--)
			if(sign[j].ed <= sign[i].st)
			{
				stbfr[i] = j;break;
			}
		printf("%d ",last[i]);
	}
	for(int i=0;i<=N;i++)
		mx[i][0] = 0;
	int mxmx = 0;
	for(int i=1;i<=N;i++)
	{
		int k = last[i];
		int kk = stbfr[i];
		for(int j=1;j<=K;j++)
		{
			int tmp = mx[i-1][j-1];
			if(mx[i-1][j-1] > -1)
			{
				tmp += sign[i].cost;
			}
			mx[i][j] = Max(mx[i-1][j],tmp);
			if( k > -1)
			{
				tmp = mx[k][j];
				if(tmp > -1)
					tmp += sign[i].cost;
				mx[i][j] = Max(tmp,mx[i][j]);
			}
/*			if( kk > -1 && j < K)
			{
				tmp = mx[kk][j+1];
				if(tmp > -1)
					tmp += sign[i].cost;
				mx[i][j] = Max(tmp,mx[i][j]);
			}*/
			
			if(mx[i][j] > mxmx)
				mxmx = mx[i][j];
			for(int ii=i-1;ii>0;ii--)
				mx[ii][j+1]
		}
	}
	printf("%d\n",mxmx);
	int a,b;
	while(scanf("%d %d",&a,&b)!=EOF)
	{
		if(!(a||b))break;
		printf("%d\n",mx[a][b]);	
	}
}
int main()
{
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		tt=0;
		input();
		Solve();	
	}
	return 0;
}

/*
5 2
09:00:00 09:30:00 2
07:00:00 09:31:00 3
09:29:00 09:59:00 10
09:40:00 10:00:00 3
09:30:00 23:59:59 4

*/
