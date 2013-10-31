#include <stdio.h>
#include <algorithm>
#define E 0.000000
using namespace std;

double stdd[3][3][2] = 
{
	{
		{0.25,7},{90,155},{125,290}
	},
	{
		{0.25,50},{90,300},{125,380}
	},
	{
		{0.25,2100},{90,2100},{125,2100}
	}
};
double r[3];

char sans[4][20] = 
{
	"letter","packet","parcel","not mailable"
};

int main()
{
	while(1)
	{
		bool sign = 0;
		for(int i=0;i<3;i++)
		{
			scanf("%lf",&r[i]);
			if(r[i]>E)
				sign = 1;
		}
		if(!sign)break;
		
		sort(r,r+3);
		int ans = 3;
		for(int i=0;i<3;i++)
		{
			bool flag = 0;
			for(int j=0;j<3;j++)
			{
				if(!((r[j] >= stdd[i][j][0]-E) && (r[j] <= stdd[i][j][1]+E)))
				{
					flag=1;break;
				}
			}
			if(!flag)
			{
				if(i)
				{
					int j;
					for(j=0;j<3;j++)
					{
						if(r[j] > stdd[i-1][j][1])
							break;
					}
					if(j == 3)
						flag = 1;
				}
				if(i == 2)
				{
					double sum = 0;
					for(int j=0;j<2;j++)
						sum += (r[j]*2);
					sum += r[2];
					if(sum > 2100)
						flag = 1;
				}
			}
			if(!flag)
			{
				ans = i;break;
			}
		}
	//	printf("%d\n",ans);
		printf("%s\n",sans[ans]);
	}
	return 0;
}

/*
2011-01-23

16:36 - have a little idea.

61486 happyhappy H Accepted 0 KB 4 ms C++ 1233 B 2011-01-23 17:12:29 
题目不清楚 然后 自己猜了一下。 
*/
