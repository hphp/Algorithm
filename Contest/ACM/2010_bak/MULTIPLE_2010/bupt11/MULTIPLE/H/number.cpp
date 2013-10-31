#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=12000000;
int prime[maxn],pl=0;
bool is[maxn];
void makelist(int l,int u)
{
	int i,j,k;
	int su=(int)sqrt(1.0*u),d=u-l+1;
	memset(is,0,sizeof(is));
	for (i=l&1;i<d;i+=2)is[i]=1;
	for (i=3;i<=su;i+=2)
	{
		//if (j>l&&is[i-l])continue;
		j=(l/i)*i;
		if (j<l)j+=i;
		if (j==i)j+=i;
		j-=l;
		for (;j<d;j+=i)is[j]=1;
	}
	if (l<=1)is[1-l]=1;
	if (l<=2)is[2-l]=0;
	pl=0;memset(prime,0,sizeof(prime));
	for (i=0;i<d;i++)
	{
		if (!is[i])prime[pl++]=i+l;
	}
}
int main()
{
	int i,j,k;
	//freopen("C://numbers.txt.","w",stdout);
	makelist(30000000,40000000);
	for (i=0;i<pl;i++)
	{
		printf("%d\n",prime[i]);
	}
	return 0;
}
