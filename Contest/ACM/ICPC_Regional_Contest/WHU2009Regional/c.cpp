#include <stdio.h>
#include <algorithm>
#define N 11

struct Boat
{
	double p,v,l;
}boat[N];
int n;
double D;

bool cmp(Boat a,Boat b)
{
	if(a.p<b.p)return 1;
	return 0;
}

int main()
{
	int tt = 1;
	while(scanf("%d %lf",&n,&D)!=EOF)	
	{
		if(n==0&&D<0.00005)break;
		double ll =0;
		for(int i=0;i<n;i++)	
		{
			scanf("%lf%lf%lf",&boat[i].p,&boat[i].l,&boat[i].v);
			ll += boat[i].l;
		}
//		std::sort(boat,boat+n,cmp);
		double sum = D-ll;
		for(int i=0;i<n;i++)
		{
			sum += (boat[i].l*2.0/boat[i].v);
		}
		printf("Case %d: %.3f\n\n",tt++,sum);
	}
}
