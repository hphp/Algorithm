#include <vector>
#include <stdio.h>
#define N 1010
#include <memory.h>
typedef double Int;
using namespace std;

Int avl[N][N];
void dp_init()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			avl[i][j] = 0;
}

class RandomAppleEasy
{
	public:
		double theRed(vector <int> red , vector<int> green)
		{
			int n = red.size();
			//printf("n:%d\n",n);
			int sum = 0;
			int sumr = 0;
			for(int i=0;i<n;i++)
				sum += red[i] + green[i],sumr+=red[i];
			dp_init();
			avl[0][0] = 1;
			for(int i=0;i<n;i++)
			{
				int part = (red[i]+green[i]);
				for(int k = sum-part;k>=0;k--)
				{
					for(int kk=sumr-red[i];kk>=0;kk--)
						avl[k+part][kk+red[i]] += avl[k][kk];
				}
			}
			double p = 0;
			for(int i=1;i<=sum;i++)
				for(int j=1;j<=sumr;j++)
					p += avl[i][j]*j*1.0/i;
			Int sumc = 1;
			for(int i=0;i<n;i++)
				sumc*=2;
			sumc -= 1;
			/*printf("p:%.6lf\n",p);
			printf("sumc:%.6lf\n",sumc);*/
			p/=(sumc);
			return p;
		}
};
/*
int main()
{
	int n;
	int a;
	while(scanf("%d",&n)!=EOF)
	{
		vector <int> red,green;
		red.clear();
		green.clear();
		for(int i=0;i<n;i++)
		{
			
			scanf("%d",&a);
			red.push_back(a);
		}
		for(int i=0;i<n;i++)
		{
			
			scanf("%d",&a);
			green.push_back(a);
		}
		RandomAppleEasy r = RandomAppleEasy();
		//printf("%.6lf\n",r.theRed(red,green));
	}
}*/
/*
2010-11-13
06:40-06:46
06:46-07:00
07:00-07:38
代码敲的很快，但是很快就没过systemtest
然后开始调，觉得long long 不够，换成double，仍然不行
然后又觉得avl的第二维有些大，换的小了些，仍然不行
自己测试，开始的时候由于memset没有将所有的avl值赋值成0。所以苦苦调试。
当样例n是40时候开始出现问题，打印sumc(sumc = (1<<n)-1)，发现越界、应该是位运算的问题，改成double型也不行。改成连乘的形式结果接近。
交上WA
发现样例没有过……。。。。。
sumc连乘之后应该减掉1
07:42总结结束
 */
