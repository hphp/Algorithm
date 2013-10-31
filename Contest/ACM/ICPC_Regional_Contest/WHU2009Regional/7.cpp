#include <stdio.h>

#define V1 510
#define V2 51

int v1, v2, n;
int max[2][V1][V2][2], q;

int main()
{
	int test = 1;
	while (1)
	{
		scanf("%d %d %d", &v1, &v2, &n);
		if(!(v1 || v2 ||n))break;
		q = 0;
		for (int i = 0; i <= v1; i++)
			for (int j = 0; j <= v2; j++)
				for (int k = 0; k < 2; k++)
					max[0][i][j][k] = -1;
		max[0][0][0][0] = 0;

		for (int cc = 0; cc < n; cc++)
		{
			int p, v, sign;
			scanf("%d %d %d", &p, &v, &sign);
			
			for (int i = 0; i <= v1; i++)
				for (int j = 0; j <= v2; j++)
					for (int k = 0; k < 2; k++)
					{
						if(sign == 1)
							max[1-q][i][j][k] = -1;
						else
							max[1-q][i][j][k] = max[q][i][j][k];
					}
		
			for (int i = 0; i <= v1; i++)
				for (int j = 0; j <= v2; j++)
					for (int k = 0; k < 2; k++)
					{
						if (i >= p && max[q][i-p][j][k]!=-1)
						{
							int t = max[q][i-p][j][k] + v;
							if (t > max[1-q][i][j][k])
								max[1-q][i][j][k] = t;
						}

						if(j >= p && max[q][i][j-p][k]!=-1)
						{
							int t  = max[q][i][j-p][k]+v;	
							if(t > max[1-q][i][j][k])
								max[1-q][i][j][k]  = t;
						}

						if(k==1 && max[q][i][j][0] != -1)
						{
							int t =max[q][i][j][0] + v;
							if(max[1-q][i][j][k] < t)
								max[1-q][i][j][k] = t;
						}
					}
			q = 1-q;
		}
		int mxmx = -1;
		for(int i=0;i<=v1;i++)
			for(int j=0;j<=v2;j++)
				for(int k=0;k<2;k++)
					if(max[q][i][j][k]>mxmx)
						mxmx = max[q][i][j][k];
		printf("Case %d: %d\n\n",test++,mxmx);
	}
}
