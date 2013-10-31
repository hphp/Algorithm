#include<cstring>
#include<cstdio>
int const S=10;
int const ND=4;
int const NORTH=0,SOUTH=1,WEST=2,EAST=3,STAY=4;
int const D[ND][2]={{-1,0},{1,0},{0,-1},{0,1}};
char const *DSTR="udlrs";
bool g[S][S][4];
int r,c,endx,endy,ex,ey,mx,my;
int q[2][S*S*S*S+1];
bool b[S*S*S*S];
int mv[S*S*S*S],pre[S*S*S*S];
bool ok;
bool readin()
{
	int nw,x1,y1,x2,y2;
	if(scanf("%d%d",&r,&c)==EOF)
		return false;
	scanf("%d%d%d%d%d%d",&endx,&endy,&ex,&ey,&mx,&my);
	scanf("%d",&nw);
	memset(g,false,sizeof(g));
	while(nw--)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1!=x2)
		{
			if(x1<x2)
			{
				g[x1][y1][SOUTH]=true;
				g[x2][y2][NORTH]=true;
			}
			else
			{
				g[x1][y1][NORTH]=true;
				g[x2][y2][SOUTH]=true;
			}
		}
		else
		{
			if(y1<y2)
			{
				g[x1][y1][EAST]=true;
				g[x2][y2][WEST]=true;
			}
			else
			{
				g[x1][y1][WEST]=true;
				g[x2][y2][EAST]=true;
			}
		}
	}
	return true;
}
inline bool in(int x,int y)
{
	return x>=0&&x<r&&y>=0&&y<c;
}
inline bool canMove(int x,int y,int d)
{
	return in(x+D[d][0],y+D[d][1])&&!g[x][y][d];
}
inline int hash(int x1,int y1,int x2,int y2)
{
	return (x1*c+y1)*(r*c)+x2*c+y2;
}
inline void dehash(int status,int &x1,int &y1,int &x2,int &y2)
{
	int status1=status/(r*c),status2=status%(r*c);
	x1=status1/c;y1=status1%c;
	x2=status2/c;y2=status2%c;
}
int mummyStep()
{
	int d=-1;
	if(my!=ey)
	{
		d=my<ey?EAST:WEST;
		if(canMove(mx,my,d))
			return d;
	}
	if(mx!=ex)
	{
		d=mx<ex?SOUTH:NORTH;
		if(canMove(mx,my,d))
			return d;
	}
	return -1;
}
bool mummyMove()
{
	static int const S=2;
	int s,d;
	for(s=0;s<S;++s)
	{
		if((d=mummyStep())==-1)
			return true;
		if(mx+D[d][0]==ex&&my+D[d][1]==ey)
			return false;
		mx+=D[d][0];
		my+=D[d][1];
	}
	return true;
}
void output()
{
	char ans[S*S*S*S+10];
	int l=0,d,s=hash(ex,ey,mx,my),k;
	while((d=mv[s])!=-1)
	{
		ans[l++]=DSTR[d];
		s=pre[s];
	}
	for(k=l-1;k>=0;--k)
		putchar(ans[k]);
	putchar('\n');
}
void solve()
{
	int tx,ty,px,py,s,index,i,j,k;
	memset(b,false,sizeof(b));
	ok=false;
	q[0][1]=hash(ex,ey,mx,my);
	q[0][0]=1;
	b[q[0][1]]=true;
	mv[q[0][1]]=-1;
	for(i=1,index=1;;++i,index=1-index)
	{
		if(q[1-index][0]==0)
		{
			break;
		}
		q[index][0]=0;
		for(j=1;j<=q[1-index][0];++j)
		{
			dehash(q[1-index][j],ex,ey,mx,my);
			if(ex==endx&&ey==endy)
			{
				ok=true;
				goto END;
			}
			tx=ex;ty=ey;
			px=mx;py=my;
			//go
			for(k=0;k<ND;++k)
			{
				if(!canMove(tx,ty,k))
					continue;
				ex=tx+D[k][0];ey=ty+D[k][1];
				mx=px;my=py;
				if(mummyMove())
				{
					s=hash(ex,ey,mx,my);
					if(!b[s])
					{
						q[index][++q[index][0]]=s;
						b[s]=true;
						mv[s]=k;pre[s]=q[1-index][j];
					}
				}
			}
			//stay
			ex=tx;ey=ty;
			mx=px;my=py;
			if(mummyMove())
			{
				s=hash(ex,ey,mx,my);
				if(!b[s])
				{
					q[index][++q[index][0]]=s;
					b[s]=true;
					mv[s]=STAY;pre[s]=q[1-index][j];
				}
			}
		}
	}
	END:
		;
	if(ok)
	{
		printf("%d\n",i-1);
		//output();
	}
	else
	{
		printf("impossible\n");
	}
}
int main()
{
	freopen("maze1.in","r",stdin);
	freopen("maze1.out","w",stdout);
	while(readin())
		solve();
	return 0;
}
