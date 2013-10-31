#include <stdio.h>
#include <vector>
#include <map>
#define MAX (1<<28)
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int ff = 1000000001;
#define N 110
struct H
{
	int s,e;
}h[N];


int mn[N][2];
int mv[2] = {1,2};
void init(int cnt)
{
	for(int i=0;i<cnt;i++)
		for(int k=0;k<2;k++)
			mn[i][k] = MAX;
	mn[0][0] = 0;
}

class RabbitJumping
{
	public:
		int getMinimum(vector<int> holes,int lJ)
		{
			map<int,int> bingo;
			int n = holes.size();
			int cnt = 0;
			h[cnt].s = -1;
			h[cnt].e = -1;
			cnt++;
			for(int i=0;i<n;i++)
			{
				bingo[holes[i]] = 1;
				if((!i) ||(holes[i] != holes[i-1] + 1))
				{
					h[cnt].e = holes[i-1];
					cnt++;
					h[cnt].s = holes[i];
				}
			}
			if(n)
			{
			h[cnt++].e = holes[n-1];
			}
	/*		h[cnt].s = ff;
			h[cnt].e = ff-1;
			cnt++;*/
			if(cnt <= 1)
				return -1;
			init(cnt);
			for(int i=1;i<cnt;i++)
			{
				for(int k=0;k<2;k++)	
				{
					int curp = h[i].e + mv[k];
					if(bingo[curp])continue;
					for(int j=0;j<i;j++)
					{
						for(int kk=0;kk<2;kk++)
						{
							int pj = (h[j].e + mv[kk]);
							int b = curp-lJ;
							if((b&1) != (pj&1))continue;
							if(bingo[pj])continue;
							if(mn[j][kk] >= MAX)continue;
							//							if((pj&1) == (curp&1))
							{
								for(int kkk=0;kkk<2;kkk++)
								{
									int pkkk = h[j+1].s - mv[kkk];
									if(b == pkkk)
									{
										if(bingo[pkkk])
											continue;
										if((b>=pj) && (b<=pkkk))
											mn[i][k] = Min(mn[i][k],mn[j][kk] + 1);
									}
									else if(b < pkkk)
									{
									//									if((!bingo[pkkk]) && (pkkk&1) == (curp&1))
										if((b>=pj) && (b <= pkkk))
										{
											mn[i][k] = Min(mn[i][k],mn[j][kk] + 1);
										}
									}
								}
							}
						}
					}
				}
			}
			int ans = MAX;
			for(int k=0;k<2;k++)
			{
				if(mn[cnt-1][k] < MAX)
				{
					int pj = h[cnt-1].e + mv[k];
					if((pj & 1) == (ff&1))
					{
						if(pj <= ff)
							ans = Min(mn[cnt-1][k],ans);
					}
				}
			}
			for(iny)
			if(mn[cnt-1][0] >= MAX)
				mn[cnt-1][0] = -1;
			return mn[cnt-1][0];
		}
};

int main()
{
	int n,lj;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int>	holes;
		for(int i=0;i<n;i++)
		{
			int a;
			scanf("%d",&a);
			holes.push_back(a);
		}
		scanf("%d",&lj);
		RabbitJumping rj = RabbitJumping();
		printf("%d\n",rj.getMinimum(holes,lj));
	}
}
