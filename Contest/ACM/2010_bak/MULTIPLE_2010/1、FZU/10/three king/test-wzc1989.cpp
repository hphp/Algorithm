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

int countbit(int n) {return (n==0)?0:1+countbit(n&(n-1));}
int lowbit(int n) {return n&(n^(n-1));}
string toString(ll v) { ostringstream sout;sout<<v;return sout.str();}
string toString(int v) { ostringstream sout;sout<<v;return sout.str();}
int Rand16(){return rand();}
int Rand32(){return rand()*rand();}
double DRand(){return (double)rand()/RAND_MAX;}
int RandRange(int f,int r){return f+(int)(DRand()*(r-f)+0.5);} 
void shuffle(int cards[], int n)
{
    while (n > 1)
    {
        int  k;
        int  tmp;
        // Swap a random unshuffled card with the top-most card
        k = rand() % n;
        n--;
        tmp = cards[n];
        cards[n] = cards[k];
        cards[k] = tmp;
    }
}

#define two(i) (1<<(i))

const int MAX = 50+5;
const int dir[][2]=
{
	{0,1},{0,-1},{1,0},{-1,0}
};

int n,m;
char bo[MAX][MAX];
int dp[MAX][MAX][1<<5];

struct STATE
{
	int x,y,s,c;
};

void sim(STATE & cur)
{
	cur.c=0;
	int i,j;
	for (i=cur.x-5;i<=cur.x+5;i++)
		for (j=cur.y-5;j<=cur.y+5;j++)
	{
		if (i<0 || i>=n || j<0 || j>=m || bo[i][j]=='#') continue;
		int dis=abs(i-cur.x)+abs(j-cur.y);
		switch(bo[i][j])
		{
			case 'A':
				if (dis<=2 && ( (cur.s&two(0))==0) )
				{
					cur.s|=two(0);
					cur.c+=1;
				}
				break;
			case 'B':
				if (dis<=3 && ( (cur.s&two(1))==0) )
				{
					cur.s|=two(1);
					cur.c+=2;
				}
				break;
			case 'C':
				if (dis<=0 && ( (cur.s&two(2))==0) )
				{
					cur.s|=two(2);
					cur.c+=3;
				}
				break;
			case 'D':
				if (dis<=2 && ( (cur.s&two(3))==0) )
				{
					cur.s|=two(3);
					cur.c+=4;
				}
				break;
			case 'E':
				if (dis<=1 && ( (cur.s&two(4))==0) )
				{
					cur.s|=two(4);
					cur.c+=5;
				}
				break;			
		}
	}
}

queue<STATE>Q;

int BFS()
{
	memset(dp,-1,sizeof(dp));
	int i,j,d;
	while (!Q.empty()) Q.pop();

	STATE cur,end,tmp;
	for (i=0;i<n;i++)
		for (j=0;j<m;j++)
			if (bo[i][j]=='$')
	{
		cur.x=i;
		cur.y=j;
		cur.c=0;
		cur.s=0;
		bo[i][j]='.';
	}
			else if (bo[i][j]=='!')
			{
				end.x=i;
				end.y=j;
				end.s=0;
				end.c=0;
				bo[i][j]='.';
			}

	//sim(cur);
	Q.push(cur);
	dp[cur.x][cur.y][cur.s]=cur.c;

	while (!Q.empty())
	{
		cur=Q.front();
		cur.c=0;
		Q.pop();
		for (d=0;d<4;d++)
		{
			tmp=cur;
			tmp.x+=dir[d][0];
			tmp.y+=dir[d][1];
			if (tmp.x<0 || tmp.x==n || 
				tmp.y<0 || tmp.y==m ||
				(bo[tmp.x][tmp.y]!='.' && 
				bo[tmp.x][tmp.y]!='C'))
				continue;
		//	printf("tmp.x=%d,tmp.y=%d,tmp.s=%d,tmp.c=%d\n",tmp.x,tmp.y,tmp.s,tmp.c);
			sim(tmp);
		//	printf("tmp.x=%d,tmp.y=%d,tmp.s=%d,tmp.c=%d\n",tmp.x,tmp.y,tmp.s,tmp.c);
			if ( (dp[tmp.x][tmp.y][tmp.s]!=-1) && (dp[tmp.x][tmp.y][tmp.s]<=dp[cur.x][cur.y][cur.s]+tmp.c ) ) continue;
			dp[tmp.x][tmp.y][tmp.s]=dp[cur.x][cur.y][cur.s]+tmp.c;
			Q.push(tmp);
		}
	}

	int ans=-1;
	for (i=0;i<two(5);i++)
		if (dp[end.x][end.y][i]!=-1)
		{
			if (ans==-1)
				ans=dp[end.x][end.y][i];
			else
				ans=min(ans,dp[end.x][end.y][i]);
		}
	return ans;
}

int main()
{
	int t,cas=0;
	freopen("in","r",stdin);
	freopen("out-1","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		cas++;
		scanf("%d%d",&n,&m);
		int i;
		for (i=0;i<n;i++)
			scanf("%s",bo[i]);

		int ans=BFS();
		printf("Case %d: %d\n",cas,ans);
	}
	return 0;
}