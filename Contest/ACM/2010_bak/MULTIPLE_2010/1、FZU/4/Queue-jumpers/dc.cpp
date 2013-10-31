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


int countbit(int n)
{
    return (n==0)?0:1+countbit(n&(n-1));
}
int lowbit(int n)
{
    return n&(n^(n-1));
}
string toString(ll v)
{
    ostringstream sout;
    sout<<v;
    return sout.str();
}
string toString(int v)
{
    ostringstream sout;
    sout<<v;
    return sout.str();
}
int Rand16()
{
    return rand();
}
int Rand32()
{
    return rand()*rand();
}
double DRand()
{
    return (double)rand()/RAND_MAX;
}
int RandRange(int f,int r)
{
    return f+(int)(DRand()*(r-f)+0.5);
}



int cas=8;
int n,q;

void random_dc()
{
    int i;
    n=RandRange(1,50);
    q=RandRange(1,100);
    printf("%d %d\n",n,q);
    for (i=0; i<q; i++)
    {
        int ty=RandRange(0,2);
        int v=RandRange(1,n);
        switch (ty)
        {
        case 0:
            printf("Top %d\n",v);
            break;
        case 1:
            printf("Query %d\n",v);
            break;
        case 2:
            printf("Rank %d\n",v);
            break;
        }
    }
}



void case_1()
{
	 int i;
	 map<int,int>CM;
    n=RandRange(1,20000);
    q=RandRange(1,min(1000,2000000/n));
    printf("%d %d\n",n,q);
    for (i=1; i<=q; i++)
    {
		int v;
        while (true)
		{
			v=RandRange(1,n);
			if (CM[v]<i/n+1)
				break;
		}

		CM[v]++;
        switch (i%2)
        {
        case 0:
            printf("Top %d\n",v);
            break;
        case 1:
            printf("Query %d\n",v);
            break;
        case 2:
            printf("Rank %d\n",v);
            break;
        }
    }
}

void case_2()
{
	 int i;
    n=100000000;
    q=100000;
    printf("%d %d\n",n,q);
	int offset=n/2+RandRange(0,100);
	int v;
    for (i=1; i<=q; i++)
    {
		if (i%2)
			v=offset-(i+1)/2;
		else
			v=offset+i/2;

        switch (i%2)
        {
        case 0:
            printf("Top %d\n",v);
            break;
        case 1:
            printf("Query %d\n",v);
            break;
        case 2:
            printf("Rank %d\n",v);
            break;
        }
    }
}

int main()
{
    int i;
    srand(time(NULL));
    freopen("in","w",stdout);
    printf("%d\n",cas);
    while (cas--)
    {
        random_dc();
		//case_1();

    }
    return 0;
}
