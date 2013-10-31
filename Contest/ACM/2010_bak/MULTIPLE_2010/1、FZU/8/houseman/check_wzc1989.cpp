#include<iostream>
#include<algorithm>
#include<assert.h>

using namespace std;

const int MAX = 1000+50;

typedef pair<int,int>PII;

int n,d;
PII p[MAX];

int main()
{
	int t,cas=0;
	int i,j;

	freopen("in","r",stdin);
	freopen("out_c","w",stdout);


	scanf("%d",&t);
	while (t--)
	{
		cas++;

		scanf("%d%d",&n,&d);
		assert(1<=n && n<=1000);
		assert(1<=d && d<=1000000);
		for (i=0;i<n;i++)
		{
			scanf("%d",&p[i].first);
			p[i].second=i;
		}

		sort(p,p+n);

		int mx=0;
		for (i=0;i<n-1;i++)
			mx=max(mx,abs(p[i].second-p[i+1].second));
		int ans;
		if (d<mx)
			ans=-1;
		else
		{
			if (n==1)ans=0;
			else
			ans=abs(p[0].second-p[n-1].second)+d-mx;
		}
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}