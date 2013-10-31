#include <string>
#include <vector>
#include <algorithm>
#define MAX (1<<28)
using namespace std;
#define N 51

struct Pair
{
	string order;
	int r[2][N];
	int cnt[2];
}p[N];
int cp;

int STD[N];

bool cmp(int a , int b)
{
	if(STD[a] > STD[b])
		return 1;
	return 0;
}

class PalindromeGame
{
	private:
	bool palindrome(string a, string b)
	{
		int len = a.length();
		int i = 0 , j = len-1;
		while(i < len)	
		{
			if(a[i]!=b[j])
				break;
			i++,j--;
		}
		if(i < len)
			return 0;
		return 1;
	}

	bool selfP(string a)
	{
		int len = a.length();
		int i =0 , j = len - 1;
		while(i <= j)	
		{
			if(a[i]!=a[j])	
				break;
			i++,j--;
		}
		if(i <= j)
			return 0;
		return 1;
	}

	void init()
	{
		for(int i=0;i<N;i++)	
			for(int j=0;j<2;j++)
				p[i].cnt[j] = 0 , p[i].order = "";
		cp = 0 ;
	}
	public:
		int getMaximum(vector <string> f, vector<int> b)
		{
			int n = f.size();
			for(int i =0 ;i < n ; i ++)
				STD[i] = b[i];
			int m = f[0].length();
			init();
			for(int i = 0 ; i < n ;i ++)
			{
				int j = 0 ;
				for(j=0;j<cp;j++)
				{
					if(f[i] == p[j].order)
					{
						p[j].r[0][p[j].cnt[0]++] = i;
						break;
					}
					else if(palindrome(f[i],p[j].order))
					{
						p[j].r[1][p[j].cnt[1]++] = i;
						break;
					}
				}
				if(j == cp)
				{
					p[cp].order = f[i];
					p[cp].r[0][p[cp].cnt[0] ++] = i;
					cp++;
				}
			}
			for(int i=0;i<cp;i++)
				for(int j=0;j<2;j++)
				{
					sort(p[i].r[j],p[i].r[j] + p[i].cnt[j] , cmp);
				}
			int ans = -MAX; 
			for(int i =0 ;i  < n ; i++)
			{
				if(selfP(f[i]))
				{
					int tmp = b[i];
					for(int j=0;j<cp;j++)
					{
						int c1 = p[j].cnt[0] , c2 = p[j].cnt[1];
						int k = 0 , kk = 0 ;
						if(c2 == 0)
						{
							if(selfP(p[j].order))
							{
								while(k < c1-1)
								{
									if(p[j].r[0][k] == i)
									{
										k++ ; continue;	
									}
									if(p[j].r[0][k+1] == i)
									{
										if(k+2>=c1)break;
										int tt = b[p[j].r[0][k]] + b[p[j].r[0][k+2]];
										if(tt > 0)
											tmp += tt;
										else break;
										k = k+3;
									}
									else
									{						
										int tt = b[p[j].r[0][k]] + b[p[j].r[0][k+1]];
										if(tt > 0)
											tmp += tt;
										else break;
										k+=2;
									}
								}
							}
						}
						else
						{
							while((k<c1) && (kk<c2))
							{
								if(p[j].r[0][k] == i)
								{
									k++;continue;	
								}
								if(p[j].r[1][kk] == i)
								{
									kk++;continue;	
								}
								int tt = STD[p[j].r[0][k]]+STD[p[j].r[1][kk]];
								if(tt >= 0)
								{
									tmp += tt;
								}
								else break;
								k++,kk++;
							}
						}
					}
					if(ans < tmp)
						ans = tmp;
				}
			}
			int tmp = 0;
			for(int j=0;j<cp;j++)
			{
				int c1 = p[j].cnt[0] , c2 = p[j].cnt[1];
				int k = 0 , kk = 0 ;
				if(c2 == 0)
				{
					if(selfP(p[j].order))
					{
						while(k < c1-1)
						{
							int tt = b[p[j].r[0][k]] + b[p[j].r[0][k+1]];
							if(tt > 0)
								tmp += tt;
							else break;
							k+=2;
						}
					}
				}
				else
				{
					while((k<c1) && (kk<c2))
					{
						int tt = STD[p[j].r[0][k]]+STD[p[j].r[1][kk]];
						if(tt >= 0)
						{
							tmp += tt;
						}
						else break;
						k++,kk++;
					}
				}
			}
			if(ans < tmp)
				ans = tmp;
			if(ans == -MAX)
				ans = 0;
			return ans;
		}
};
