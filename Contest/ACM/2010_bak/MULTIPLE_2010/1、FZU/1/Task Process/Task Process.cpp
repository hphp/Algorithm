#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <assert.h>

using namespace std;
typedef long long ll;

const double PI=acos(-1.0);
const double eps=1e-11;

#define dump(x) cerr<<#x<<" = "<<(x)<<endl;
#define foreach(c,itr) for (__typeof( (c).begin() ) itr=(c).begin();itr!=(c).end() ;itr++ )


int countbit(int n) {return (n==0)?0:1+countbit(n&(n-1));}
int lowbit(int n) {return n&(n^(n-1));}
string toString(ll v) { ostringstream sout;sout<<v;return sout.str();}
string toString(int v) { ostringstream sout;sout<<v;return sout.str();}
int Rand16(){return rand();}
int Rand32(){return rand()*rand();}
double DRand(){return (double)rand()/RAND_MAX;}
int RandRange(int f,int r){return f+(int)(DRand()*(r-f)+0.5);}

typedef pair<int,int>PII;


int n,x,y;
PII vxy[55];
int dp[55][205];

bool solve(int T)
{
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	int i,j,k;
	int cx,cy;

	//simple test
	cx=cy=0;
	for (i=0;i<n;i++)
		cx+=T/vxy[i].first,cy+=T/vxy[i].second;
	if (cx<x || cy<y)
		return false;

	for (i=0;i<n;i++)
	{
		if (dp[i][x]==y)
			return true;

		int va=vxy[i].first;
		int vb=vxy[i].second;

		for (j=0;j<=x;j++)
			if (dp[i][j]!=-1)
			{
				for (k=0 ;k<=T/va && j+k<=x;k++)
				{
					int ny=min(y-dp[i][j],(T-k*va)/vb);
					if (dp[i+1][j+k]<dp[i][j]+ny)
						dp[i+1][j+k]=dp[i][j]+ny;
				}
			}
	}
	return (dp[n][x]==y);
}

int main()
{
	int t,cas=0;
	int i,j;

//	freopen("in","r",stdin);
//	freopen("out","w",stdout);

	scanf("%d",&t);
	while (t--)
	{
		cas++;
		scanf("%d%d%d",&n,&x,&y);
		assert(1<=n && n<=50);
		assert(1<=x && x<=200);
		assert(1<=y && y<=200);

		for (i=0;i<n;i++)
		{
			scanf("%d%d",&vxy[i].first,&vxy[i].second);
			assert(1<=vxy[i].first && vxy[i].first<=1000);
			assert(1<=vxy[i].second && vxy[i].second<=1000);
		}

		sort(vxy,vxy+n);

		int lo=0,hi=1000*(x+y);
		int mid;

		while (lo<=hi)
		{
			mid=(lo+hi)/2;
			if (solve(mid))
				hi=mid-1;
			else
				lo=mid+1;
		}

		printf("Case %d: %d\n",cas,lo);
	}
	return 0;
}
