#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
char rec[100][100];
int cot[100][100][1<<6],mp[100][100];
int xe[5]={1,2,3,4,5};
struct stu
{
	int x,y,a;
}w,v;
int ar[4]={0,0,-1,1},br[4]={-1,1,0,0};
int main()
{
	int n,m,i,j,sx,sy,ex,ey,ii,jj,x,y;	

	freopen("in","r",stdin);
	freopen("out","w",stdout);

	int t,cas=0;
	scanf("%d",&t);
	while (t--)
	{
		cas++;
		scanf("%d %d",&n,&m);		
		memset(cot,-1,sizeof(cot));
		memset(mp,0,sizeof(mp));
		for(i=0;i<n;i++)
		{
			scanf("%s",rec[i]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(rec[i][j]=='#')
				{
					mp[i][j]=-1;
					continue;
				}
				if(rec[i][j]=='$')
				{
					sx=i;
					sy=j;
					continue;
				}
				if(rec[i][j]=='!')
				{
					ex=i;
					ey=j;
					continue;
				}
				if(rec[i][j]=='A')
				{
					mp[i][j]=-1;
					for(ii=-2;ii<3;ii++)
					{
						for(jj=-2;jj<3;jj++)
						{
							if(abs(ii)+abs(jj)>2)continue;
							x=i+ii;
							y=j+jj;
							if(x<0||x>=n||y<0||y>=m||mp[x][y]==-1)continue;
							mp[x][y]|=1;
						}
					}
				}

				if(rec[i][j]=='B')
				{
					mp[i][j]=-1;
					for(ii=-3;ii<4;ii++)
					{
						for(jj=-3;jj<4;jj++)
						{
							if(abs(ii)+abs(jj)>3)continue;
							x=i+ii;
							y=j+jj;
							if(x<0||x>=n||y<0||y>=m||mp[x][y]==-1)continue;
							mp[x][y]|=1<<1;
						}
					}
				}

				if(rec[i][j]=='C')
				{
					mp[i][j]|=1<<2;
				}

				if(rec[i][j]=='D')
				{
					mp[i][j]=-1;
					for(ii=-2;ii<3;ii++)
					{
						for(jj=-2;jj<3;jj++)
						{
							if(abs(ii)+abs(jj)>2)continue;
							x=i+ii;
							y=j+jj;
							if(x<0||x>=n||y<0||y>=m||mp[x][y]==-1)continue;
							mp[x][y]|=1<<3;
						}
					}
				}

				if(rec[i][j]=='E')
				{
					mp[i][j]=-1;
					for(ii=0;ii<4;ii++)
					{
						x=i+ar[ii];
						y=j+br[ii];
						if(x<0||x>=n||y<0||y>=m||mp[x][y]==-1)continue;
							mp[x][y]|=1<<4;
					}
				}
			}
		}
		w.x=sx,w.y=sy;w.a=0;
		cot[w.x][w.y][0]=0;
		queue<stu>q;
		q.push(w);
		int b,a,c;
		while(!q.empty())
		{
			w=q.front();
			q.pop();
			for(i=0;i<4;i++)
			{
				b=0;
				v.x=w.x+ar[i];
				v.y=w.y+br[i];
				if(v.x>=n||v.x<0||w.y>=m||w.y<0||mp[v.x][v.y]==-1)continue;
				for(j=0;j<5;j++)
				{
					a=mp[v.x][v.y]&(1<<j);
					c=w.a&(1<<j);
					if(a!=0&&c==0)
					{
						b+=xe[j];
					}
				}
				b+=cot[w.x][w.y][w.a];
				v.a=w.a|mp[v.x][v.y];
				if(cot[v.x][v.y][v.a]==-1||cot[v.x][v.y][v.a]>b)
				{
					cot[v.x][v.y][v.a]=b;
					q.push(v);
				}
			}
		}
		int ans=-1;
		for(i=0;i< (1<<6);i++)
		{
			if(cot[ex][ey][i]!=-1&& (cot[ex][ey][i]<ans ||ans==-1))
			{
				ans=cot[ex][ey][i];
			}
		}
		printf("Case %d: %d\n",cas,ans);
	}


	return 0;
}