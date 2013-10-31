#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen("in.in","w",stdout);
	int N = 100;
	double x0,y0,y1;
	double a,b[300]; 
	int n;
	int i,j;
	while(N--)
	{
		x0 = 123.43;
		y0 = (rand()+837)/471.2;
		y1 = (rand()+234)/471.2;
		
		if(y0 < y1)
		{
			a = y0;
			y0 = y1;
			y1 = 1; 
		}
		if(y0-y1<1)
		{
			y0 += 1;
		}
		
		n = rand()%100+2;
		printf("%.2lf %.2lf %.2lf %d\n", x0, y0, y1, n);
		
		for(i=0; i<2*n; i++)
		{
			b[i] = (rand()+342)/34.2;
		}
		
		for(i=0; i<2*n; ++i)
		{
			for(j=i+1; j<2*n; ++j)
			{
				if(b[i] > b[j])
				{
					a = b[i];
					b[i] = b[j];
					b[j] = a;
				}
			}
		}
		for(i=0; i<2*n; i+=2)
		{
			printf("%.2lf %.2lf\n",b[i], b[i+1]);
		}
	}
	//system("pause");
}
