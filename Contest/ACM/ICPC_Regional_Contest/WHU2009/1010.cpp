#include <stdio.h>
#define N 2048
#define S 1010
#define MAX (1<<30)
#define Max(a,b) ((a)>(b)?(a):(b))

int h[N],w[N],v[N],s[N];
int sums,n;
int mx[S][S];
int mxl,mxh;

void dp_init()
{
	for(int i=0;i<S;i++)
		for(int j=0;j<S;j++)
			mx[i][j] = 0;
	for(int i=0;i<S;i++)
		mx[i][0] = mx[0][i] = 0;
}

int dp()
{
	int mxmx = 0;
	for(int x=1;x<=mxl;x++)
	{
		for(int y=1;y<=mxh;y++)	
		{
			for(int i=1;i<=n;i++)	
			{
				if(h[i]<=y&&w[i]<=x)
				{
					int part1 = mx[w[i]][y-h[i]];
					int part2 = mx[x-w[i]][y];
					int tmp = v[i]+part1+part2;
					if(tmp > mx[x][y])
						mx[x][y] = tmp;
					part1 = mx[x][y-h[i]];
					part2 = mx[x-w[i]][h[i]];
					tmp = v[i]+part1+part2;
					if(tmp > mx[x][y])
						mx[x][y] = tmp;
			}
			if(w[i]<=y&&h[i]<=x)
			{
		int part1 =mx[h[i]][y-w[i]];
		int part2 = mx[x-h[i]][y];
		int tmp = v[i]+part1+part2;
		if(tmp > mx[x][y])
			mx[x][y] = tmp;
		part1 = mx[x][y-w[i]];
		part2 = mx[x-h[i]][w[i]];
		tmp = v[i]+part1+part2;
		if(tmp > mx[x][y])
			mx[x][y] = tmp;
			}
		}
		if(mx[x][y]>mxmx)
			mxmx = mx[x][y];
		}
	}
	return mxmx;
}

/*int dp(int x,int y)
{
	if(x<0||y<0)
		return -MAX;
	if(mx[x][y]>=0)
		return mx[x][y];
	mx[x][y] = 0;
	for(int i=1;i<=n;i++)
	{		int part1 = dp(w[i],y-h[i]);
		int part2 = dp(x-w[i],y);
		int tmp = v[i]+part1+part2;
		if(tmp > mx[x][y])
			mx[x][y] = tmp;
		part1 = dp(x,y-h[i]);
		part2 = dp(x-w[i],h[i]);
		tmp = v[i]+part1+part2;
		if(tmp > mx[x][y])
			mx[x][y] = tmp;
		part1 = dp(h[i],y-w[i]);
		part2 = dp(x-h[i],y);
		tmp = v[i]+part1+part2;
		if(tmp > mx[x][y])
			mx[x][y] = tmp;
		part1 = dp(x,y-w[i]);
		part2 = dp(x-h[i],w[i]);
		tmp = v[i]+part1+part2;
		if(tmp > mx[x][y])
			mx[x][y] = tmp;
	
	}
	//printf("%d %d %d\n",x,y,mx[x][y]);
	return mx[x][y];
}*/

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		int x,y;
		scanf("%d %d",&x,&y);
		mxl = x;
		mxh = y;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&h[i],&w[i],&v[i]);
		}
		dp_init();
		int ans = dp();
		printf("%d\n",ans);
	}
	return 0;
}
