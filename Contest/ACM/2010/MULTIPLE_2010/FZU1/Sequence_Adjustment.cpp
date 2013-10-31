#include <stdio.h>
#include <algorithm>
#define MAX 100000000000000000LL
#define N 10100000
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

typedef long long Int;
int n;

int main()
{
	int tc;
	scanf("%d",&tc);
	int tt = 1;
	while(tc--)
	{
		scanf("%d",&n);
		Int a = 0;
		Int mn  = MAX;
		Int mx  = 0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a);
			mx = Max(a,mx);
			mn = Min(a,mn);
		}
		printf("Case %d: %lld %lld\n",tt++,mx-mn,mx-mn+1);
	}
}
/*
这道题题意比较直白,就是问给你N个整数,每次能对一个区间加/减1，问至少需要几步才能使数字都一样,并求出可能的最终数字.
首先,如果我们固定最终的数字x的话,是很方便写出一个O(N)的贪心的(注意到up和down交叉肯定可以消掉,所以up和down是交替的,于是可以有O(N)枚举贪心).
然后容易发现,能够构成最终数字的肯定在序列的极值之间.
于是如果暴力的话,我们可以大概用O(N*序列极值范围)的复杂度来完成.当然我们还可以做得更快.我们可以将序列的值排序,然后从
小到大对每一个高度O(1)计算其步数,并可以判断两个高度之间是否存在最优解.这样排序完之后的复杂度即是O(N).具体我们可以先
维护两个值,即在当前高度为cur_height,费用为cur_v时,小于等于此高度的位置形成的块数为down,大于此高度的位置形成的块数为up,
那么对于新高度new_height来说,费用new_v=cur_v+(down-up)*(new_height-cur_height).
这里感谢hhanger的友情验题以及秒杀~~~
*/
