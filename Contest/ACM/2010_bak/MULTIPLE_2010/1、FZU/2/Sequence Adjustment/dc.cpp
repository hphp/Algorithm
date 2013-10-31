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



int n;
int cas=1;
int arr[100000+50];

void gen_1()
{
	int low=RandRange(0,100);
	int high=RandRange(100000000,1000000000);
	int i;
	for (i=0;i<n;i++)
		if (i%2)
		{
			low=low+RandRange(0,3000);
			arr[i]=low;
		}
		else
		{
			high=high-RandRange(0,3000);
			arr[i]=high;
		}
}

void gen_2()
{
	int low=RandRange(0,100);
	int high=RandRange(100000000,1000000000);
	int i;
	for (i=0;i<n;i++)
	{
			low=low+1;
			arr[i]=low;
	}

	for (i=0;i<n;i++)
	{
		int a=RandRange(0,n-1);
		int b=RandRange(0,n-1);
		swap(arr[a],arr[b]);
	}
}

void gen_3()
{
	int x=RandRange(10000000,10000000+5000);
	arr[0]=arr[n-1]=x;
	int i;
	int part=-(n-2)/2;
	for (i=1;i<n-1;i++)
	{
		arr[i]=x+part;
		part++;
	}
}


void gen_4()
{
	int x=RandRange(10000000,10000000+5000);
	int k=2;//RandRange(5,10);
	int i;
	int low=-n/k;
	int high=n/k;
	int offset=1;
	int part=low;
	int flag=1;
	int times=RandRange(2,3);
	arr[0]=arr[n-1]=x;
	for (i=1;i<n-1;i++)
	{		
		if ((i%(n/3)==0) && times)
		{
			arr[i]=x+RandRange(-5,5);
			times--;
			continue;
		}
		arr[i]=x+part;
		part+=flag*offset;
		if (part>=high)
			flag=-1;
		if (part<=low)
			flag=1;
	}
}

int main()
{
	int i,j;

	srand(time(NULL));

	//freopen("in","w",stdout);
	printf("%d\n",cas);
	while (cas--)
	{
		n=100000;//RandRange(50000,100000);
		
		//for (i=0;i<n;i++) arr[i]=RandRange(100000,100000+9000);
		
		gen_4();

		printf("%d\n",n);
		for (i=0;i<n;i++) 
			printf("%d ",arr[i]);putchar('\n');
	}

	return 0;
}
