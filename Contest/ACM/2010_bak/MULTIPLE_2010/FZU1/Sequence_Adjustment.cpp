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
���������Ƚ�ֱ��,�����ʸ���N������,ÿ���ܶ�һ�������/��1����������Ҫ��������ʹ���ֶ�һ��,��������ܵ���������.
����,������ǹ̶����յ�����x�Ļ�,�Ǻܷ���д��һ��O(N)��̰�ĵ�(ע�⵽up��down����϶���������,����up��down�ǽ����,���ǿ�����O(N)ö��̰��).
Ȼ�����׷���,�ܹ������������ֵĿ϶������еļ�ֵ֮��.
������������Ļ�,���ǿ��Դ����O(N*���м�ֵ��Χ)�ĸ��Ӷ������.��Ȼ���ǻ��������ø���.���ǿ��Խ����е�ֵ����,Ȼ���
С�����ÿһ���߶�O(1)�����䲽��,�������ж������߶�֮���Ƿ�������Ž�.����������֮��ĸ��Ӷȼ���O(N).�������ǿ�����
ά������ֵ,���ڵ�ǰ�߶�Ϊcur_height,����Ϊcur_vʱ,С�ڵ��ڴ˸߶ȵ�λ���γɵĿ���Ϊdown,���ڴ˸߶ȵ�λ���γɵĿ���Ϊup,
��ô�����¸߶�new_height��˵,����new_v=cur_v+(down-up)*(new_height-cur_height).
�����лhhanger�����������Լ���ɱ~~~
*/
