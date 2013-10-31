#include <stdio.h>
#include <stdlib.h>
#define N 11
#define M 11
#define MAX 1<<30

struct State
{
	int pju;
	int pma;
	int ppao; 
}queue[N*M*N*M*N*M];
int step[110][110][110];//ju ma pao 
int s,f,n,m,des;
int stm[N*M];
int spma,spju,sppao,stp;
int consting[8][4]={{-1,2,0,1},{-2,1,-1,0},{-2,-1,-1,0},{-1,-2,0,-1},{1,-2,0,-1},{2,-1,1,0},{2,1,1,0},{1,2,0,1}};
int chgpao[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int chgeju[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

void init(void)
{
	for(int i=0;i<110;i++)
		for(int j=0;j<110;j++)
			for(int k=0;k<110;k++)
				step[i][j][k]=MAX;
}

int taken(int x,int y)
{
	int state=x*m+y;
	if(stm[state]==-1)
		return 1;
	if(state==spma)
		return 1;
	if(state==spju)
		return 1;
	if(state==sppao)
		return 1;
}

int avl(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
	{
		if(taken(x,y))
			return 0;
			return 1;
	}
	return 0;
}

void changeju(int state)
{
	int xx=state/m;
	int yy=state%m;
	int tsju;
	for(int i=0;i<4;i++)
	{
		int x=xx+chgeju[i][0];
		int y=yy+chgeju[i][1];
		while(avl(x,y))
		{
			tsju=x*m+y;
			if(step[tsju][spma][sppao]>stp+1)
			{
				queue[f].pju=tsju;
				queue[f].pma=spma;
				queue[f].ppao=sppao;
				step[tsju][spma][sppao]=stp+1;
				f++;
			}
			x++;
		}
	}
}

void changema(int state)
{
	int x=state/m;
	int y=state%m;
	for(int i=0;i<8;i++)
	{
		int xx=x+consting[i][0];
		int yy=y+consting[i][1];
		if(avl(xx,yy))
		{
			int xxx=x+consting[i][2];
			int yyy=y+consting[i][3];
			if((taken(xxx,yyy)==0)&&(xxx*m+yyy)!=des)
			{
				int stma=xx*m+yy;
				if(step[spju][stma][sppao]>stp+1)
				{
					queue[f].pju=spju;
					queue[f].pma=stma;
					queue[f].ppao=sppao;
					step[spju][stma][sppao]=stp+1;
					f++;
				}
			}
		}
	}
}

void changepao(int state)
{
	int xx=state/m;
	int yy=state%m;
	for(int i=0;i<4;i++)
	{
		int x=xx+chgpao[i][0];
		int y=yy+chgpao[i][1];
		int flag=0;
		while(1)
		{
			int stpao=x*m+y;
			if(avl(x,y))
			{
				if(stpao==des)
					break;
				if(step[spju][spma][stpao]>stp+1)
				{
					queue[f].pju=spju;
					queue[f].pma=spma;
					queue[f].ppao=stpao;
		//			printf("%d %d\n",x,y);
					step[spju][spma][stpao]=stp+1;
					f++;
				}
		//		printf("2:%d %d %d %d %d %d\n",queue[f-1].pju[0],queue[f-1].pju[1],queue[f-1].pma[0],queue[f-1].pma[1],queue[f-1].ppao[0],queue[f-1].ppao[1]);
			}
			else 
			{
				if(flag==0)
				{
					flag=1;
					if(step[spju][spma][stpao]>stp+1)
					{
						if(stpao==des)
						{
							queue[f].pju=spju;
							queue[f].pma=spma;
							queue[f].ppao=stpao;
				//			printf("%d %d\n",x,y);
							step[spju][spma][stpao]=stp+1;
							f++;						
						}
					}
				}
				else break;
			}
			x+=chgpao[i][0];
			y+=chgpao[i][1];
		}
	}
}

int dfs(void)
{
	s=0;
	f=1;
	spju=queue[s].pju;
	spma=queue[s].pma;
	sppao=queue[s].ppao;
	step[spju][spma][sppao]=0;
	while(s<f)
	{
	//	printf("%d:\n",s);
		spju=queue[s].pju;
		spma=queue[s].pma;
		sppao=queue[s].ppao;
		stp=step[spju][spma][sppao];
		if(spju==des||spma==des||sppao==des)
			return stp+1;
//		printf("ju:%d %d ma:%d %d pao:%d %d %d\n",pju[0],pju[1],pma[0],pma[1],ppao[0],ppao[1],stp);
		changeju(spju);
		changema(spma);
		changema(sppao);
		s++;
	}
	return -1;
}
char graph[N+10][M+10];

int main()
{
	char a;
	int tt=1;
//	freopen("1101010.in","r",stdin);
//	freopen("1010.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		init();
		for(int i=0;i<n;i++)
			scanf("%s",graph[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				a=graph[i][j];
				int temp=i*m+j;
				stm[temp]=0;
				switch(a)
				{
					case 'D':stm[temp]=-1;break;
					case 'S':des=temp;break;
					case 'M':queue[0].pma=temp;break;
					case 'P':queue[0].ppao=temp;break;
					case 'C':queue[0].pju=temp;break;
					default :break;
				}
			}
		}
		int ans=dfs();
		printf("Scenario #%d\n",tt++);
		if(ans==-1)
			printf("OH!That's impossible!\n");
		else printf("%d\n",ans);
		printf("\n");
	}
	return 0;
}/*
5 5
..DSD
...D.
C....
P.D..
...M.

3 7
..DDSDD
....PC.
.....M.

4 7
.CD.DSD
....P.D
..DD...
.....M.

5  7
...SP..
.MC....
.......
.......
.......


5  7
...SP..
..M....
..C....
.......
.......


5 5
..DSD
...D.
C....
P.D..
...M.

3 7
..DDSDD
....PC.
.....M.

4 7
.CD.DSD
....P.D
..DD...
.....M.

5  7
...SP..
.MC....
.......
.......
.......


5  7
...SP..
..M....
..C....
.......
.......

10 10 
CDDSDD....
DPD..x.....
.D.x......
.x.......
..........
..........
..........
DDD.DDDDD.
..M.......
..........
*/
