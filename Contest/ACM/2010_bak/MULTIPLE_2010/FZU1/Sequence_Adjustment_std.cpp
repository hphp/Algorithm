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

#define mp make_pair
typedef pair<int,int>PII;


int countbit(int n) {return (n==0)?0:1+countbit(n&(n-1));}
int lowbit(int n) {return n&(n^(n-1));}
string toString(ll v) { ostringstream sout;sout<<v;return sout.str();}
string toString(int v) { ostringstream sout;sout<<v;return sout.str();}
int Rand16(){return rand();}
int Rand32(){return rand()*rand();}
double DRand(){return (double)rand()/RAND_MAX;}
int RandRange(int f,int r){return f+(int)(DRand()*(r-f)+0.5);}

const int MAXN = 100000;
const int MAXV = 1000000000;
int da[MAXN];
PII pa[MAXN];
int n;


ll calc(int arr[],int m)
{	
	ll ans=0;
	int pv=0;
	int pt=0;
	int cv;
	int i,j;
	for (i=0;i<n;i++)
	{
		if (arr[i]<=m) //up
		{
			if (pt==0)
			{
				ans+=max(0,m-arr[i]-pv);								
			}
			else
			{
				ans+=m-arr[i];
				pt=0;
			}
			pv=m-arr[i];
		}
		else  //down
		{
			if (pt==1)
			{
				ans+=max(0,arr[i]-m-pv);
			}
			else
			{
				ans+=arr[i]-m;
				pt=1;
			}
			pv=arr[i]-m;
		}
	}

	return ans;
}




int main()
{
	int i,j,k,u,v;
	int t,cas=0;

	//freopen("final_in","r",stdin);
	//freopen("out-1","w",stdout);

	scanf("%d",&t);
	while (t--)
	{
		cas++;
		scanf("%d",&n);
		assert(1<=n && n<=MAXN);

		for (i=0;i<n;i++) 
		{
			scanf("%d",&da[i]);
			assert(da[i]>=0 && da[i]<=MAXV);
			pa[i].first=da[i];
			pa[i].second=i;
		}		
		sort(pa,pa+n);

		if (n==1)	//n=1,easy
		{
			cout<<"Case "<<cas<<": "<<0<<" "<<1<<endl;
			continue;
		}

		//x--up
		//y--down
		//last--last height
		//lev --cur height
		//cur --cur ans
		//ans --best ans
		int x,y,last,lev,st;
		x=1,y=0,last=pa[0].first-1;
		ll cur=calc(da,pa[0].first-1);
		ll ans;
		ll times=1;
		ans=cur;

			
		//test
		//vector<int>res;

		for (i=0;i<n;i=j)
		{			
			lev=pa[i].first;
			cur+=(ll)(y-x)*(lev-last);
			st=lev-last;
			
			if (cur<ans)
			{
				ans=cur;
				times=1;
			//	res.clear();
			//	res.push_back(lev);
			}
			else
				if (cur==ans)	
				{
					times+=st;
					//for (j=last+1;j<=lev;j++)
					//	res.push_back(j);
				}
				
			last=lev;

			//printf("at lev=%d,ans=%I64d\n",lev,cur);

			for (j=i;j<n && pa[j].first==lev;j++);			

			int f,r;
			for (k=i;k<j;k=u)
			{
				f=r=pa[k].second;
				for (u=k+1;u<j;u++)
					if (pa[u].second==r+1)
					{
						r=pa[u].second;
					}
					else break;
				
				int ty;
				//judge type
				if (f>0 && r<n-1)  //at mid
				{
					ty=(da[f-1]>lev)*2+(da[r+1]>lev);
					switch(ty)
					{
						case 0:
							x--;y--;
							break;
						case 1:case 2:
							break;
						case 3:
							x++;y++;
							break;
					}
				}
				else		//at begin or end
				{
					if (f==0)
					{
						if (r==n-1)
							ty=2;
						else
							ty=da[r+1]>lev;
					}
					else
					{
						ty=da[f-1]>lev;
					}

					switch(ty)
					{
						case 0:
							x--;
							break;
						case 1:
							y++;
							break;
						case 2:
							x--;y++;
							break;
					}
				}
			}
		}

		cout<<"Case "<<cas<<": "<<ans<<" "<<times<<endl;
		//for (i=0;i<res.size();i++) printf("%d ",res[i]);putchar('\n');
			
	}

	return 0;
}
