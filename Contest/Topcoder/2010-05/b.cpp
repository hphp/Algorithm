#include <string>
using namespace std;
#define STM 65556
#define avl(a) ((a)>=0&&(a)<=n?1:0)
#define N 52
#define C 16

int sign[C];

class DoorsGame
{
	private:
		int ones[STM];
		int cn[STM][2];
		int f;
		int best[STM][2];
		int cl[N][2],vst[N];//cl 2 0:自己和大的，1：自己和小的 
		int n,sumc;
		int stm;
		int fstm;
		void booling();
		void init();
		void dfs(int);
	public:
		int dp(int,int);
		int determineOutcome(string,int);
};

void DoorsGame::booling()
{
	for(int i=0;i<STM;i++)
	{
		int cnt = 0;
		for(int j=0;j<C;j++)
			if(i&(1<<j))
				cnt ++;
		ones[i] = cnt;
	}
}

void DoorsGame::init()
{
	sumc = 0;
	for(int i=0;i<C;i++)
		sign[i] = 0;
	for(int i=0;i<STM;i++)
	{
		best[i][0] = best[i][1] = sumc+1;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<2;j++)
			cn[i][j] = 0;
		vst[i] = 0;
	}
}

int mv[2] = {1,-1};

void DoorsGame::dfs(int cur)
{
	printf("cur;%d\n",cur);
	vst[cur] = 1;
	for(int j=0;j<2;j++)
	{
		int nn = cur + mv[j];
		printf("hello %d\n",nn);
		if(avl(nn) && vst[nn] == 0 && (cl[cur][j] >= 0) && (stm & (1<<cl[cur][j])))
		{
			dfs(nn);
		}
	}
}

int DoorsGame::dp(int cur , int flag)
{
	if(best[cur][flag] != sumc + 1)
		return best[cur][flag];
	int bb = -N,mm=0;
	if(cn[cur][flag] == 1)
	{
		if(cn[cur][1-flag] == 1)
			best[cur][flag] = 0;
		else best[cur][flag] = ones[cur];
	}
	else
	{
		for(int i=0;i<C;i++)
		{
			if(sign[i] && ((cur & (1<<i)) == 0))
			{
				int tmp = dp((cur | (1<<i)),1-flag);
				if(tmp < 0 && tmp > bb)
					bb = tmp;
				else if(tmp > 0)
					if(mm < tmp)
						mm = tmp;
			}
		}
		if(bb == -N)
			bb = mm;
		best[cur][flag] = -bb;
	}
	return best[cur][flag];
}
int DoorsGame::determineOutcome(string s,int f)
{
	int size = s.length();
	n = size;
	cl[0][1] = -1;
	for(int i = 0 ; i < size; i ++)
	{
		cl[i][0] = s[i]-'A';
		cl[i+1][1] = s[i]-'A';
		if(sign[cl[i+1][1]]==0)
			sumc ++;
		sign[cl[i+1][1]]=1;
	}
	cl[n][0] = -1;
	fstm = 0;
	for(int i=0;i<C;i++)
		if(sign[i])
			fstm = fstm | (1<<i);
/*	for(int i=0;i<=n;i++)
		printf("%d ",cl[i][0]);
		printf("\n");*/
	booling();
	init();
	for(int i=0;i<=fstm;i++)
	{
		stm = i;
		for(int j=0;j<=n;j++)
			vst[f] = 0;
		dfs(0);
		if(vst[f])
		{
			cn[i][0] = 1;
			printf("i:%d\n",i);
		}
		printf("\n");
		for(int j=0;j<=n;j++)
			vst[f] = 0;
		dfs(n);
		if(vst[f])
		{
			cn[i][1] = 1;
			printf("1:i:%d\n",i);
		}
		printf("\n");
	}
	return dp(0,0);
}

int main()
{
	char s[N];
	int n;
	while(scanf("%s%d",s,&n)!=EOF)
	{	
		DoorsGame a = DoorsGame();
		printf("%d\n",a.determineOutcome(s,n));
	}
	return 0;
}
