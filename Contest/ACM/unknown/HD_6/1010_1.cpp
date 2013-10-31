#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1010
#define M 10010

int n,m;
int tt;
int arr[N][N];

int mearn[N][N][2];
int maxt;
int maxmax;

int kind[5][2]={{-1,0},{1,0},{0,1},{0,-1}};

int avl(int x,int y)
{
	if(x>0&&x<=n&&y>0&&y<=n)
		return 1;
		return 0;
}
int abss(int a)
{
	if(a<0)
		return -a;
		return a;
}

void dp_init(void)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int add=0;
			if(arr[i][j]==0)
				add=1;
			mearn[i][j][0]=add;
			mearn[i][j][1]=0;
		}
}

void init(void)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			arr[i][j]=-1;
}

/*int dp(int cur)
{
	if(mearn[cur]>-1)
		return mearn[cur];
	mearn[cur]=1;
	for(Node *temp=node[cur].arr;temp!=NULL;temp=temp->arr)
	{
		int next=temp->id;
		int ans=dp(next);
		if(ans+1>mearn[cur])
			mearn[cur]=ans+1;
	}
	return mearn[cur];
}*/

void dp(void)
{
	dp_init();
	maxmax=0;
	int flag=0;
	for(int i=1;i<=maxt;i++)
	{
		for(int xx=1;xx<=n;xx++)
			for(int yy=1;yy<=n;yy++)
			{
				for(int k=0;k<5;k++)
				{
					int x=xx+kind[k][0];
					int y=yy+kind[k][1];
					if(avl(x,y))
					{
						int add=0;
						if(arr[xx][yy]==i)
							add=1;
						int temp = mearn[x][y][flag]+add;
						if(temp>mearn[xx][yy][1-flag])
						{
							mearn[xx][yy][1-flag]=temp;
							if(maxmax<temp)
							{
			//					printf("\n%d %d %d %d %d\n",maxmax,xx,yy,x,y);
								maxmax=temp;
							}
						}
					}
				}
			}
		for(int xx=1;xx<=n;xx++)
			for(int yy=1;yy<=n;yy++)
				mearn[xx][yy][flag]=mearn[xx][yy][1-flag];
	}
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(!(n||m))break;
		init();
		maxt=0;
		for(int i=0;i<m;i++)	
		{
			int t,x,y;
			scanf("%d%d%d",&t,&x,&y);
			arr[x][y]=t;
			if(maxt<t)
				maxt=t;
		}
		dp();
		printf("%d\n",maxmax);
		/*for(int i=0;i<m;i++)
			printf("%d %d\n",inf[i].arrt,inf[i].x);*/
		/*for(int i=m-1;i>0;i--)
		{
			for(int j=i-1;j>=0;j--)	
			{
				int dif1=inf[i].arrt-inf[j].arrt;
				int dif2=abs(inf[i].x-inf[j].x)+abs(inf[i].y-inf[j].y);
				if(dif1>=dif2)	
				{
					edge[tt].id=j;
					edge[tt].arr=node[i].arr;
					node[i].arr=&edge[tt];
					tt++;
				}
			}
		}
		dp_init();
		int maxmax=0;
		for(int i=m-1;i>=0;i--)
		{
			int ans=dp(i)	;
			if(ans>maxmax)
				maxmax=ans;
		}*/
		printf("%d\n",maxmax);
	}
	return 0;
}
