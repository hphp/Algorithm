#include <stdio.h>
#include <algorithm>
#define N 11000

int rl[N],rh[N];

bool cmp(int a,int b)
{
	return a>b;	
}

int nl,nh;

int main()
{
	while(scanf("%d %d",&nh,&nl)!=EOF)
	{
		//for(int i=0;i<N;i++)
	//		h[i] = 0;
		for(int i=0;i<nh;i++)
		{
			scanf("%d",&rh[i]);
		//	h[rh[i]]++;	
		}
		for(int i=0;i<nl;i++)
		{
			scanf("%d",&rl[i]);	
		}
		std::sort(rl,rl+nl);
		std::sort(rh,rh+nh);
		int ph = nh-1,pl = nl-1;
		int cnt = 0;
		while(ph >= 0 && pl >= 0)
		{
			while(pl >=0 && rl[pl]>=rh[ph])
			{
				pl--;
			}
			if(pl<0)break;
			cnt += 2;
			ph--;
			pl--;
		}
		cnt += ph+1;
		printf("%d\n",cnt);
	}
	return 0;
}
