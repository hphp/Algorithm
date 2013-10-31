#include <stdio.h>#include <string.h>#define MAX 100000000#define avl(x,y) ((x>=0&&x<r&&y>=0&&y<c)==1?1:0)#define N 150#define K 300 struct Queue{	int x,y;	int arr;}queue[N*N];int get[N][13][14];int sign[N][N];char grid[N][N];int cntp,cnte;int id[N];int arr[N][N];int getout[N];int posp[N];int kind[4][2]={{1,0},{-1,0},{0,1},{0,-1}};int r,c;void bfs(int curid,int pos){	int x=pos/r;	int y=pos%r;	int s=0,f=1;	queue[0].x=x;	queue[0].y=y;	queue[0].arr=0;	while(s<f)	{		int x=queue[s].x;		int y=queue[s].y;		int step=queue[s].arr;		if(sign[x][y]==1)		{			arr[curid][id[x*r+y]]=step;		}		for(int i=0;i<4;i++)			{			int xx=x+kind[i][0];			int yy=y+kind[i][1];
			if(avl(xx,yy))			{				//if(grid[xx][yy]!='X')				if(get[curid][xx][yy]>step+1)				{					queue[f].x=xx;					queue[f].y=yy;					queue[f].arr=step+1;					get[curid][xx][yy]=step+1;					f++;				}			}		}		s++;	}}void init(void){	cntp=0;cnte=0;	int lim=r*r;	for(int i=0;i<lim;i++)		getout[i]=0;	for(int i=0;i<lim;i++)		for(int j=0;j<r;j++)			for(int k=0;k<c;k++)			{				get[i][j][k]=MAX;				sign[j][k]=0;				}	for(int i=0;i<lim;i++)		for(int j=0;j<lim;j++)			arr[i][j]=MAX;}int visit[N];int match[N];int con[N][N]={0};bool dfs(int v){	int i;	for(i=0;i<cnte;i++)	{		if(con[v][i]&&visit[i]==-1)		{            visit[i]=1;            int t=match[i];
 match[i]=v;            if(t==-1||dfs(t)) 				return true;            match[i]=t;		}		}	return false;	}int Max_Match(){	memset(match,-1,sizeof(match));	int i,sum=0;	for(i=0;i<cntp;i++)	{		memset(visit,-1,sizeof(visit));		if(dfs(i))		{			getout[i]=1;			sum++;		}		}	return sum;	}int main(){	int t;	while(scanf("%d%d%d",&r,&c,&t)!=EOF)	{		init();		for(int i=0;i<r;i++)				scanf("%s",grid[i]);		for(int i=0;i<r;i++)			for(int j=0;j<c;j++)			{				if(grid[i][j]=='E')				{					id[i*r+j]=cnte;					sign[i][j]=1;					cnte++;				}				else if(grid[i][j]=='.')				{					posp[cntp]=i*r+j;					cntp++;				}			}		for(int i=0;i<cntp;i++)			bfs(i,posp[i]);		/*for(int i=0;i<cntp;i++)		{			for(int j=0;j<cnte;j++)				printf("%d ",arr[i][j]);				printf("\n");		}*/		int cnt=0;		int sum=0;		int i=1;		for(i=1;i<=t&&i<=250;i++)		{			memset(con,0,sizeof(con));			for(int j=0;j<cntp;j++)				if(getout[j]==0)				for(int k=0;k<cnte;k++)					if(arr[j][k]<=i)						con[j][k]=1;			int ans=Max_Match();			sum+=ans;			if(sum==cntp)				break;		}		if(i<=t)			printf("%d\n",i);		else printf("impossible\n");	}	return 0;}/*5 5 100XXXXXX...XX...XX.E.XXXEXX
12 12 100
XXXXXXXXXXXX
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
X..........X
XXXXXXXXXXXX*/ 

