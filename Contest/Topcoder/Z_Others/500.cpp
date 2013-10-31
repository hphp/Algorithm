#include <vector>
#include <string>
#include <string.h>
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
#define NN 1001000

int win[NN] = {0};
bool vst[NN] = {0};

string ans[3] = 
{
	"Romeo","Draw","Strangelet"
};
int n,k,l;

int dp(int m)
{
	int st = m-k+1;
	if(st <= 0)
		st = 1;
	for(int i = st; i <= m ; i ++)
	{
		int len = i + k - 1;
		if(len > n)
			break;
		int am = i+len - m ;
		if(am == l)
			return 1;
	}
	int draw = -1;
	for(int i = st;i<=m;i++)
	{
		int len = i + k - 1;
		if(len > n)
			break;
		int am = i+len - m ;
		if((am < 1) || (am > n))continue;
		int s = Min(am,l);
		int b = am+l - s;
		int dis = b-s+1;
		if(dis <= k)
		{
			int mm = Min(s-1,n-b);
			int part = (k - dis)/2;
			if((k-dis)%2 == 0)
			{
				if(mm >= part)
					;
				else draw = 0;
			}
			else
				draw = 0;
		}
		else
			draw = 0;
	}
	return draw;
/*	if(win[m] != -2)
		return win[m];
	vst[m] = 1;
	bool draw = 0;
	int st = m - k + 1;
	if(st <= 0)
		st = 1;
	for(int i=st;i<=m;i++)
	{
		int len = i+k-1;
		if((len >= m) && (len <= n))
		{
			int am = i + len - m;
			if(am == l)
			{
				win[m] = 1;
				return 1;
			}
			if(vst[am])
			{
				draw = 1;
			}
			else
			{
				int aa = dp(am);
				if(aa == 0)
					draw = 1;
				if(aa == -1)
				{
					win[m] = 1;
					return 1;
				}
			}
		}
	}
	if(draw)
	{
		win[m] = 0;
		return 0;
	}
	win[m] = -1;
	return -1;
*/
}

class StonesGame
{
	public:
		string winner(int N, int M, int K, int L)
		{
			if(M == L)
				return ans[0];
			for(int i=0;i<=N;i++)
				vst[i] = 0 , win[i] = -2;
			n = N , k = K , l = L;
			int dd = dp(M);
			if(dd == 1)
				return ans[0];
			else if(dd == 0)
				return ans[1];
			else
				return ans[2];
		}	
};

/*
2011-01-24
15:10-15:59 
这道题挺简单的，想法比较好，但是有些笨拙，可以有更简单的方法。 
*/
