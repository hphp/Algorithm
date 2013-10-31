#include <stdio.h>

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	double x0, y0, y1;
	int n,i;
	double ans;
	double a,b,temp;
	while(scanf("%lf %lf %lf %d", &x0, &y0, &y1, &n)!=EOF)
	{
		ans = 0;
		for(i=0; i<n; ++i)
		{
			scanf("%lf %lf", &a, &b);
			if(a<b)
			{
				temp = a;
				a = b;
				b = temp;
			}
			ans = ans+(a-b)*y0/(y0-y1);
		}
		printf("%.2lf\n",ans);
	}
}
