#include <stdio.h>
#define NN 1000000
bool np[NN];
int p[NN];

class PrimeContainers
{
	public:
		int containerSize(int N)
		{
			for(int i=2;i<NN;i++)
			{
				if(!np[i])
					for(int j=2;j*i<NN;j++)
						np[i*j] = 1;
			}
			int cnt =0;
			for(int i=2;i<NN;i++)
				if(!np[i])
				{
					p[cnt] = i;
					cnt++;
				}
			int ans = 0;
			for(int i=0;;i++)
			{
				if(N<(1<<i))break;
				int t = N/(1<<i);
				if(t == 1)break;
				bool flag = 0;
				int j =0 ;
				for(;j<cnt;j++)
				{
					if(p[j] >= t)break;
					if(t%p[j]==0)
					{
						flag = 1;
						break;
					}
				}
				if(flag == 0)
					ans++;
			}
			return ans;
		}
};
