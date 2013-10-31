#include <vector>
#include <string>
using namespace std;
#define N 51
#define M 1010
int kind[N][M];
bool ifn[M] = {0};
void prime()
{
	ifn[1] = 1;
	ifn[2] = 0;
	ifn[3] = 0;
	for(int i=2;i<M;i++)
	{
		if(!ifn[i])
		for(int j=2;i*j<M;j++)
			ifn[i*j] = 1;
	}
}

class ColorfulCards
{
	public:
		vector <int> theCards(int n, string c)
		{
			prime();
			int m = c.length();
			for(int i=0;i<=m;i++)
				for(int j=0;j<=n;j++)
					kind[i][j] = 0;
			kind[0][0] = 1;
			for(int i=0;i<=m;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(kind[i-1][j-1])
					{
						if(ifn[j])
						{
							if(c[i-1] == 'B')
							{
								kind[i][j] = 1;
							}
						}
						else
						{
							if(c[i-1] == 'R')
							{
								kind[i][j] = 1;
							}
						}
					}
					if(kind[i][j-1])
						kind[i][j] = 1;
			/*	if(kind[i][j])
					{
						printf("%d %d\n",i,j);
					}*/
				}
			}
			int rans[100];
			int led = n+1;
			for(int i=m;i>0;i--)
			{
				int ed = -1;
				int cnt = 0,ans = -1;
				for(int j=1;j<led;j++)
				{
					if(kind[i][j] && kind[i-1][j-1])
					{
						if((ifn[j]) && (c[i-1] == 'B'))
						{
							ed = j;
							ans = ed;
							cnt ++;
						}
						else if((!ifn[j]) && (c[i-1] == 'R'))
						{
							ed = j;
							ans = ed;
							cnt ++;
						}
					}
				}
				led = ed;
				if(cnt == 1)
					rans[i] = ans;
				else rans[i] = -1;
			}
			vector<int> ans;
			for(int i=1;i<=m;i++)
				ans.push_back(rans[i]);
			return ans;
		}	
};
/*
int main()
{
	while(scanf("%d%s",&n,&s)!=EOF)
	{
		vector ans = 
	}
	return 0;
}*/
