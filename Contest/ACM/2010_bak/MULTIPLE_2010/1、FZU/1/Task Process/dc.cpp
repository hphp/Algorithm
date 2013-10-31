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


int cas=50;
int n,x,y;
int va[55],vb[55];

void case_1()
{
	n=RandRange(1,50);
	x=RandRange(1,200);
	y=RandRange(1,200);

	int i;
	for (i=0;i<n;i++)
	{
		va[i]=RandRange(1,1000);
		vb[i]=RandRange(1,1000);
	}

	printf("%d %d %d\n",n,x,y);
	for (i=0;i<n;i++)
		printf("%d %d\n",va[i],vb[i]);
}

void case_2()
{
	n=RandRange(1,50);
	x=RandRange(1,200);
	y=RandRange(1,200);

	int i;
	for (i=0;i<n;i++)
	{
		int ty=RandRange(0,3);
		switch(ty)
		{
			case 0:  //0 0
				va[i]=RandRange(50,300);
				vb[i]=RandRange(50,300);
			break;
			case 1: //0 1
				va[i]=RandRange(50,400);
				vb[i]=RandRange(500,1000);
			break;
			case 2: //1 0
				va[i]=RandRange(700,1000);
				vb[i]=RandRange(50,450);
			break;
			case 3: //1 1
				va[i]=RandRange(800,1000);
				vb[i]=RandRange(900,1000);
			break;
		}
	}

	printf("%d %d %d\n",n,x,y);
	for (i=0;i<n;i++)
		printf("%d %d\n",va[i],vb[i]);
}


int main()
{
    int i;
    srand(time(NULL));
    freopen("in","w",stdout);
    printf("%d\n",cas);

    while (cas--)
    {
		if (RandRange(0,1)==1)
			case_2();
		else
			case_1();

    }
    return 0;
}
