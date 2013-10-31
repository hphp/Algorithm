#include <stdio.h>
#include <math.h>
#define N 11
#define CON  ((sqrt(5.0)-1.0)/2)

int n,pos[N];
double p;

double powing(int cnt,double di)
{
	if(cnt==0)
		return 1.0;
	if(cnt%2==0)
	{
		double temp = powing(cnt/2,di);
		return temp*temp;
	}
	else
	{
		double temp=powing((cnt-1)/2,di);
		return temp*temp*di;
	}
}
double get(double curpos,int last,int cur)
{
//	printf("%d %d\n",last,cur);
	if(last>cur)
		return 0.0;
	if(last==cur)
		return curpos;
	if(p<CON)	
	{
//		printf("%ld")
		if((cur-last)%2==0)
		return powing((cur-last)/2,1-p);
		else return powing((cur-last)/2,(1-p))*p;
	}
	else
	{
		return powing(cur-last,p);
	}
}

int main()
{
	while(scanf("%d%lf",&n,&p)!=EOF)
	{
		for(int i=1;i<=n;i++)	
		{
			scanf("%d",&pos[i]);
		}
		int last,now=1;
		double curans=1.0;
		for(int i=1;i<=n;i++)	
		{
			last=now;
			now = pos[i];
			curans = get(curans,last,now-1);
			now++;
//			printf("%lf\n",curans);
			curans=(1-p)*curans;
		}
		printf("%.7lf\n",curans);
	}
	return 0;
}
