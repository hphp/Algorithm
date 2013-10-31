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


int n,Q;
deque<int>data;


void top(int v)
{
	deque<int>::iterator it;
	for (it=data.begin();it!=data.end();it++ )
		if ( (*it)==v)
			break;
	data.erase(it);
	data.push_front(v);
}

int query(int v)
{
	int i;
	for (i=0;i<data.size();i++)
		if (v==data[i])
			return i+1;
	return -1;
}

int rank(int v)
{
	return data[v-1];
}

int main()
{
	freopen("in","r",stdin);
	freopen("bfout","w",stdout);

	int t,cas=0;
	char buffer[20];
	int v,ans;

	scanf("%d",&t);
	while (t--)
	{
		cas++;
		printf("Case %d:\n",cas);
		scanf("%d%d",&n,&Q);
		data.clear();
		for (int i=1;i<=n;i++)
			data.push_back(i);
		while (Q--)
		{
			scanf("%s%d",buffer,&v);
			assert(1<=v && v<=n);
			switch(buffer[0])
			{
			case 'T':
				top(v);
				break;
			case 'Q':				
				ans=query(v);
				printf("%d\n",ans);
				break;
			case 'R':
				ans=rank(v);
				printf("%d\n",ans);
				break;
			}
		}
	}
	return 0;
}
