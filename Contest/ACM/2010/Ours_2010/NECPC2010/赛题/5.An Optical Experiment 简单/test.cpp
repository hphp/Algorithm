#include<stdio.h>
#include<stdlib.h>

int main()
{
	freopen("in.in","r",stdin);
	freopen("test.out","w",stdout);
	double x_0,y_0,y_1;
	int n;
	double total=0.0;
	double x_b,x_e;
	double scale;
	while(scanf("%lf%lf%lf%d",&x_0,&y_0,&y_1,&n)!=EOF){
		scale=y_0/(y_0-y_1);
		total=0.0;
		while(n--){
			scanf("%lf%lf",&x_b,&x_e);
			total=total+(x_e-x_b)*scale;
		}
		printf("%.2lf\n",total);
	}
	return 0;
}
