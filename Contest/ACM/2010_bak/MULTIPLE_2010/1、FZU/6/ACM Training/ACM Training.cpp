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

#define two(i) (1<<(i))


const int MAXN= 8;
const int MAXM= 20;
const int MAXS= 1<<(MAXN-1);
const int MAXT= 1000000;
const int INF = 100000000;

int n,m,t,cl,sn;
int occ[MAXM][MAXN];
map<int,int>M;
int c0;
int g[MAXS][MAXS];

void dfs(int state)
{
	M[state]=0;
	int i;
	for (i=0;i<cl;i++)
		if ((state&two(i))==0)
		{
			int ns=(state>>(i+1))|c0;
			if (M.find(ns)==M.end())
				dfs(ns);
		}
}

void outputBits(int v,int n)
{
	int i;
	int dig[20];
	for (i=0;i<n;i++) dig[i]=v%2,v/=2;
	for (i=0;i<n;i++) printf("%d",dig[n-1-i]);
}


struct Matrix
{
	vector< vector<int> >mat;
	int n;

	Matrix(){}

	Matrix(int N)
	{
		n=N;
		mat.resize(n);
		for (int i=0;i<n;i++) mat[i].resize(n);
	}

	void set(int N)
	{
		n=N;
		mat.resize(n);
		for (int i=0;i<n;i++) mat[i].resize(n);
	}

	void set(int arr[][MAXS],int N)
	{
		n=N;
		mat.resize(n);
		int i,j;
		for (i=0;i<n;i++)
		{
			mat[i].resize(n);
			for (j=0;j<n;j++)
				mat[i][j]=arr[i][j];
		}
	}

	Matrix(const Matrix&rhs)
	{
		n=rhs.n;		
		mat=rhs.mat;
	}

	void One()
	{
		int i,j;
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
				mat[i][j]=(i==j)?0:INF;
		}

	Matrix mul(const Matrix &rhs)
	{
		Matrix ret(n);
		int i,j,k;
		for (i=0;i<n;i++)
			for (j=0;j<n;j++)
			{
				ret.mat[i][j]=INF;
				for (k=0;k<n;k++)
					if (mat[i][k]!=INF && rhs.mat[k][j]!=INF)
						ret.mat[i][j]=min(ret.mat[i][j],mat[i][k]+rhs.mat[k][j]);	
			}
			
		return ret;
	}
	
	Matrix pow(int T)
	{
		Matrix ret(n);
		ret.One();
		Matrix coe(*this);		
		while (T)
		{
			if (T&1) ret=ret.mul(coe);
			coe=coe.mul(coe);
			T>>=1;
		}
		return ret;
	}

	void output()
	{
		int i,j;
		for (i=0;i<n;i++,putchar('\n'))
			for (j=0;j<n;j++)
				printf("%d ",(mat[i][j]==INF)?-1:mat[i][j]);
	}
};

Matrix ma,mb;

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);

	int ta,cas=0;
	int i,j,k;

	scanf("%d",&ta);
	while (ta--)
	{
		cas++;
		scanf("%d%d%d",&m,&n,&t);
		assert(1<=n && n<=MAXN);
		assert(1<=m && m<=MAXM);
		assert(1<=t && t<=MAXT);

		for (i=0;i<m;i++) 
			for (j=0;j<n;j++)
		{
				scanf("%d",&occ[i][j]);
			assert(0<=occ[i][j] && occ[i][j]<=1);
		}
		
		if (n==1)
		{
			printf("Case %d: %d\n",cas,t);
			continue;
		}
		
		cl=n-1;
		M.clear();
		c0=0;
		for (k=0;k<m;k++)
			for (i=0;i<n;i++)
				if (occ[k][i]==1)
				for (j=0;j<i;j++)
				 if (occ[k][j]==1)
					c0|=two(i-j-1);		
				
		dfs(c0);
		map<int,int>::iterator it;
		sn=0;
		for (it=M.begin();it!=M.end();it++)
			(*it).second=sn++;
		int sta=M[c0];

		for (i=0;i<sn;i++)
			for (j=0;j<sn;j++)
				if (j==sta)
					g[i][j]=n;
				else
					g[i][j]=INF;

		for (it=M.begin();it!=M.end();it++)
		{
			int state=(*it).first;
			int ms=(*it).second;
			for (i=0;i<cl;i++)
				if ((state&two(i))==0)
				{
					int ns=(state>>(i+1))|c0;
					int mns=M[ns];
					g[ms][mns]=min(g[ms][mns],i+1);
				}
		}
		
//		printf("n=%d,m=%d,t=%d\n",n,m,t);
//		printf("c0=%d=",c0);
//		outputBits(c0,cl);putchar('\n');
//		for (it=M.begin();it!=M.end();it++)
//		{
//			printf("state %d=",it->second);
//			outputBits(it->first,cl);
//			putchar('\n');
//		}
//		printf("\ngraph size=%d:\n",sn);
//		for (i=0;i<sn;i++,putchar('\n'))
//			for (j=0;j<sn;j++)
//				printf("%2d ",(g[i][j]==INF)?-1:g[i][j]);


		int ans=INF;

		if (g[sta][sta]==1)
		{
			ans=t-1;
		}
		else
		{
			ma.set(g,sn);
			ma=ma.pow(t-1);
			//ma.output();
			for (i=0;i<sn;i++)
			ans=min(ans,ma.mat[sta][i]);
		}

		printf("Case %d: %d\n",cas,ans+n);

	}
	return 0;
}

/*
2 1 3
1
0

1 4 2
1 1 1 1

2 2 2
1 0
0 1


5 8 10
1 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0

5 8 2
0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 1
0 0 0 0 1 0 0 0
0 0 0 0 0 0 1 0

2 3 2
1 0 1
1 0 0
*/