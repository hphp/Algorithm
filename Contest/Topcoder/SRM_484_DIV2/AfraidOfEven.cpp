#include <vector>
#include <stdio.h>

#define MAX 4294967296LL
#define N 53
using namespace std;

typedef long long Int;
Int rec[N];
class AfraidOfEven
{
	public:
		vector <int> restoreProgression(vector <int> seq)
		{
			int size = seq.size();
			Int a[4] = {0};
			for(int i=0;i<2;i++)
				a[i] = seq[i];
			a[2] = seq[size-2];
			a[3] = seq[size-1];
			bool flag = 0;
			while(a[0] < MAX)
			{
				a[1] = seq[1];
				while(a[1] < MAX)
				{
					a[2] = seq[size-2];
					while(a[2] <MAX)
					{
						a[3] = seq[size-1];
						while(a[3] < MAX)
						{
							if(a[2]+a[1] == a[0] + a[3])
							{
								int tt = 2;
								rec[0] = a[0];
								rec[1] = a[1];
								for(tt=2;tt<size-2;tt++)
								{
									rec[tt] = rec[tt-1]*2-rec[tt-2];
									if((rec[tt]% seq[tt]!=0))
										break;
								}
								rec[size-2] = a[2];
								rec[size-1] = a[3];
								if((rec[size-2]+rec[size-2] == rec[size-1]+rec[size-3]) && (tt==size-2))
								{
									flag = 1;
									break;
								}
							}
							a[3] += a[3];
						}
						if(flag)break;
						a[2] += a[2];
					}
					if(flag)break;
					a[1] += a[1];
				}
				if(flag)break;
				a[0] += a[0];
			}
			vector<int> ans;
			ans.clear();
/*			for(int i=0;i<4;i++)
				printf("%lld ",a[i]);
			printf("hei\n");*/
			ans.push_back((int)a[0]);
			ans.push_back((int)a[1]);
			for(int i=2;i<size-2;i++)
			{
				int cur = (int)(ans[i-1]+ans[i-1] - ans[i-2]);
				ans.push_back(cur);
			}
			ans.push_back((int)a[2]);
			ans.push_back((int)a[3]);
			return ans;
		}
};
/*
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		vector<int> seq;
		seq.clear();
		int a;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			seq.push_back(a);
		}
		AfraidOfEven aa = AfraidOfEven();
		vector<int> ans = (aa.restoreProgression(seq));
		int size = ans.size();
		for(int i=0;i<size;i++)
		printf("%d ",ans[i]);
	}
}*/
