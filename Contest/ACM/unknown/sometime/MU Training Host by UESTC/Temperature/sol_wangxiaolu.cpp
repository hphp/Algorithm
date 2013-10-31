#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	freopen("f:\\1.in","r",stdin);
	freopen("f:\\2.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t = 1; t <= T; t++)
	{
		int u,u0,u1,t1,n,p,s;
		printf("Case %d:\n", t);
		scanf("%d%d%d%d%d",&u,&u0,&u1,&t1,&n);
		if(u==u0&&u0==u1)
		{
			for(int i=0;i<n;i++)
			{
				scanf("%d%d",&p,&s);
				printf("%.2f\n",u + 0.0);
			}
			printf("\n");
			continue;
		}
		double k=1.0/t1*log(1.0*(u0-u)/(u1-u));
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&p,&s);
			if(p==1)
			{
				double ans=u+(u0-u)*exp(-1.0*k*s);
				printf("%.2f\n",ans);
			}
			else 
			{
				double ans=log(1.0*(s-u)/(u0-u))/(-1.0*k);
				printf("%.2f\n",ans);
			}
		}
		printf("\n");
	}
	return 0;
}

