//12:27--
#include <stdio.h>
#define N 110
#define W 50010

double mx[W];
int need[W];
struct Stuff
{
	int c;
	int v;
	int type;
}stuff[N];
int w,n;
int sum;
int recmx;

void dp_init()
{
	for(int i=0;i<=w;i++)
		mx[i]=0;
	recmx = 0;
}

void dp()
{
	dp_init();
	double mxmx = 0;
	for(int i=1;i<=n;i++)
	{
		if(stuff[i].type==0)	
		{
			for(int j=recmx;j>=0;j--)
			{
				double tmp = 0;
				if(j+stuff[i].c>w)continue;
				tmp = mx[j]+stuff[i].v;
				if(tmp > mx[j+stuff[i].c])
				{
					mx[j+stuff[i].c]=tmp;
					if(mxmx < tmp )mxmx = tmp;
				}
			}
		}
		else
		{
/*			for(int j=0;j<=w;j++)
				need[j]=0;
			double reca = stuff[i].v*1.0/stuff[i].c;
			for(int j=0;j<=recmx&&j<w;j++)
			{
				if(mx[j]>=0&&need[j]<stuff[i].c)
				{
					double tmp = reca+mx[j];
					if(mx[j+1]<tmp)
					{
						mx[j+1]=tmp;
						need[j+1]=need[j]+1;
						printf("%d %d %.2lf\n",j,need[j],tmp);
						if(tmp > mxmx)
							mxmx = tmp;
						if(recmx)
					}
				}
			}*/
		}
		recmx += stuff[i].c;
		if(recmx>w)
			recmx = w;
	}
	printf("%.2lf\n",mxmx);
}

int main()
{
	while(scanf("%d %d",&n,&w)!=EOF)	
	{
		sum = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d %d %d",&stuff[i].c,&stuff[i].v,&stuff[i].type);
			sum += stuff[i].c;
		}
		w = w<sum ? w : sum;
		dp();
	}
	return 0;
}
