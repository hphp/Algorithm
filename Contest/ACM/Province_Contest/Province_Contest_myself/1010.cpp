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
int s,f,n,m,desx,desy;
int map[N+1][M+1];
int spma,spju,sppao,pju[2],pma[2],ppao[2],tsju,tsma,tspao,stp;
int consting[8][4]={{-1,2,0,1},{-2,1,-1,0},{-2,-1,-1,0},{-1,-2,0,-1},{1,-2,0,-1},{2,-1,1,0},{2,1,1,0},{1,2,0,1}};

void init(void)
{
	for(int i=0;i<110;i++)
		for(int j=0;j<110;j++)
			for(int k=0;k<110;k++)
				step[i][j][k]=MAX;
}

int taken(int x,int y)
{
	if(map[x][y]==-1)
	{
	//	printf("-1:%d %d\n",x,y);
		return 1;
	}
	if((pju[0]==x)&&(pju[1]==y))
	{
	//	printf("ju:%d %d\n",x,y);
		return 1;
	}
	if((ppao[0]==x)&&(ppao[1]==y))
	{
	//	printf("pao %d %d\n",x,y);
		return 1;
	}
	if((pma[0]==x)&&(pma[1]==y))
	{
	//	printf("ma :%d %d\n",x,y);
		return 1;
	}
	return 0;
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

int win(int x,int y,int flag)
{
	int count=0;
	switch(flag)
	{
		case 0:
			{
				count=0;
				if(y==desy)
				{
					int start=x;
					if(x<desx)
					{
						start=x+1;
						while(start<=desx)
						{
							if(taken(start,y))
								count++;
							start++;
						}
						if(count==0)
							return 1;
					}
					else if(x>desx)
					{
						count=0;
						start=x-1;
						while(start>=desx)
						{
							if(taken(start,y))
								count++;
							start--;
						}
						if(count==0)
							return 1;
					}
				}
				if(x==desx)
				{
					int start=y;
					if(y<=desy)
					{
						count=0;
						start=y+1;
						while(start<=desy)
						{
							if(taken(x,start))
								count++;
							start++;
						}
						if(count==0)
							return 1;
					}
					else if(y>desy)
					{
						count=0;
						start=y-1;
						while(start>=desy)
						{
							if(taken(x,start))
								count++;
							start--;
						}
						if(count==0)
							return 1;
					}
				}
				return 0;
			}
		case 1:
			{
				for(int i=0;i<8;i++)
				{
					int xx=x+consting[i][0];
					int yy=y+consting[i][1];
					if((xx==desx)&&(yy==desy))
					{
						int xxx=x+consting[i][2];
						int yyy=y+consting[i][3];
						if((taken(xxx,yyy)==0)&&(!((xxx==desx)&&(yyy==desy))))
								return 1;
					}
				}
				return 0;
			}
		case 2:
			{
				count=0;
				if(y==desy)
				{
					int start=x;
					if(x<desx)
					{
						start=x+1;
						while(start<=desx)
						{
							if(taken(start,y))
							{
			//					printf("%d %d\n",start,y);
								count++;
							}
							start++;
						}
						if(count==1)
						{
					//		printf("1\n");
							return 1;
						}
					}
					else if(x>desx)
					{
						start=x-1;
						while(start>=desx)
						{
							if(taken(start,y))
							{
			//					printf("> %d %d\n",start,y);
								count++;
							}
							start--;
						}
						if(count==1)
						{
						//	printf("2\n");
							return 1;
						}
					}
				}
				else if(x==desx)
				{
					int start=y;
					if(y<desy)
					{
						count=0;
						start=y+1;
						while(start<=desy)
						{
							if(taken(x,start))
								count++;
							start++;
						}
						if(count==1)
						{
					//		printf("3\n");
							return 1;
						}
					}
					else if(y>desy)
					{
						count=0;
						start=y-1;
						while(start>=desy)
						{
							if(taken(x,start))
								count++;
							start--;
						}
						if(count==1)
						{
					//		printf("4\n");
							return 1;
						}
					}
				}
				return 0;				
			}
		}
}

void changeju(int xx,int yy)
{
//	printf("che\n");
	int x=xx+1;
	int y=yy;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
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
//		printf("1:%d %d\n",x,y);
		x++;
	}
	x=xx;
	y=yy+1;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
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
//		printf("2:%d %d\n",x,y);
		y++;
	}
	x=xx-1;
	y=yy;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
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
//		printf("3:%d %d\n",x,y);
		x--;
	}	
	x=xx;
	y=yy-1;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
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
//		printf("4:%d %d\n",x,y);
		y--;
	}
}

void changema(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int xx=x+consting[i][0];
		int yy=y+consting[i][1];
		if(avl(xx,yy)&&(!((xx==desx)&&(yy==desy))))
		{
			int xxx=x+consting[i][2];
			int yyy=y+consting[i][3];
			if((taken(xxx,yyy)==0)&&(!((xxx==desx)&&(yyy==desy))))
			{
		//		printf("%d %d\n",xx,yy);
				int stma=xx*m+yy;
				if(step[spju][stma][sppao]>stp+1)
				{
					queue[f].pju=spju;
					queue[f].pma=stma;
					queue[f].ppao=sppao;
					step[spju][stma][sppao]=stp+1;
					f++;
	//				printf("ma:%d %d %d %d %d %d\n",queue[f-1].pju[0],queue[f-1].pju[1],queue[f-1].pma[0],queue[f-1].pma[1],queue[f-1].ppao[0],queue[f-1].ppao[1]);
				}
			}
		}
	}
}

void changepao(int xx,int yy)
{
	int x=xx+1;
	int y=yy;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
	{
		int stpao=x*m+y;
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
		x++;
	}
	x=xx;
	y=yy+1;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
	{
		int stpao=x*m+y;
		if(step[spju][spma][stpao]>stp+1)
		{
			queue[f].pju=spju;
			queue[f].pma=spma;
			queue[f].ppao=stpao;
			step[spju][spma][stpao]=stp+1;
			f++;
		}
//		printf("2:%d %d %d %d %d %d\n",queue[f-1].pju[0],queue[f-1].pju[1],queue[f-1].pma[0],queue[f-1].pma[1],queue[f-1].ppao[0],queue[f-1].ppao[1]);
		y++;
	}
	x=xx-1;
	y=yy;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
	{
		int stpao=x*m+y;
		if(step[spju][spma][stpao]>stp+1)
		{
			queue[f].pju=spju;
			queue[f].pma=spma;
			queue[f].ppao=stpao;
			step[spju][spma][stpao]=stp+1;
			f++;
		}
//		printf("2:%d %d %d %d %d %d\n",queue[f-1].pju[0],queue[f-1].pju[1],queue[f-1].pma[0],queue[f-1].pma[1],queue[f-1].ppao[0],queue[f-1].ppao[1]);
		x--;
	}	
	x=xx;
	y=yy-1;
	while(avl(x,y)&&(!((x==desx)&&(y==desy))))
	{
		int stpao=x*m+y;
		if(step[spju][spma][stpao]>stp+1)
		{
			queue[f].pju=spju;
			queue[f].pma=spma;
			queue[f].ppao=stpao;
			step[spju][spma][stpao]=stp+1;
			f++;
		}
//		printf("2:%d %d %d %d %d %d\n",queue[f-1].pju[0],queue[f-1].pju[1],queue[f-1].pma[0],queue[f-1].pma[1],queue[f-1].ppao[0],queue[f-1].ppao[1]);
		y--;
	}		
}

int dfs(void)
{
	s=0;
	f=1;
	pju[0]=queue[s].pju/m;
	pju[1]=queue[s].pju%m;
	pma[0]=queue[s].pma/m;
	pma[1]=queue[s].pma%m;
	ppao[0]=queue[s].ppao/m;
	ppao[1]=queue[s].ppao%m;
	spju=pju[0]*m+pju[1];
	spma=pma[0]*m+pma[1];
	sppao=ppao[0]*m+ppao[1];
	step[spju][spma][sppao]=0;
	while(s<f)
	{
	//	printf("%d:\n",s);
		pju[0]=queue[s].pju/m;
		pju[1]=queue[s].pju%m;
		pma[0]=queue[s].pma/m;
		pma[1]=queue[s].pma%m;
		ppao[0]=queue[s].ppao/m;
		ppao[1]=queue[s].ppao%m;
		spju=pju[0]*m+pju[1];
		spma=pma[0]*m+pma[1];
		sppao=ppao[0]*m+ppao[1];
		stp=step[spju][spma][sppao];
//		printf("ju:%d %d ma:%d %d pao:%d %d %d\n",pju[0],pju[1],pma[0],pma[1],ppao[0],ppao[1],stp);
		int x=pju[0];
//		system("pause");
		int y=pju[1];
		if(win(x,y,0))
		{
	//		printf("ju\n");
			return stp+1;
		}
		changeju(x,y);
		x=pma[0];
		y=pma[1];
		if(win(x,y,1))
		{
	//		printf("ma\n");
			return stp+1;
		}
		changema(x,y);
		x=ppao[0];
		y=ppao[1];
		if(win(x,y,2))
		{
	//		printf("pao\n");
			return stp+1;
		}
		changepao(x,y);
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
	//			printf("%c,",a);
				switch(a)
				{
					case 'D':map[i][j]=-1;break;
					case 'S':map[i][j]=0;desx=i;desy=j;break;
					case 'M':map[i][j]=0;queue[0].pma=i*m+j;break;
					case 'P':map[i][j]=0;queue[0].ppao=i*m+j;break;
					case 'C':map[i][j]=0;queue[0].pju=i*m+j;break;
					case '.':map[i][j]=0;break;
				}
			}
		}
	/*	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				printf("%d ",map[i][j]);
				printf("\n");
		}*/
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
