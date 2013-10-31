#include <stdio.h>
#define N 51
#define K 5
#define STM 1953135
#define MOD 1000000007

int kind[2][STM];
int ans[N][K];
int pow[10];
int bit[STM][9],last[2][STM],mx[STM];

int KK = 5;
int flag = 0;

void booling()
{
	pow[0] = 1;
	for(int i=1;i<=9;i++)
	{
		pow[i] = pow[i-1]*KK;
	}
	for(int i=0;i<pow[9];i++)
	{
		int st = 0;
		int tmp = i;
		int sign = 0;
		while(tmp)
		{
			bit[i][st] = tmp%KK;
			if(mx[i] < bit[i][st])
			{
				mx[i] = bit[i][st];
			}
			if(bit[i][st] > 0)
			{
				last[0][i] = st;
			}
			tmp /= KK;
			st ++;
		}
//		if(sign  == 1)break;
	}
	//printf("hei last : %d\n",last[1]);
}

void insert(int stm ,int nextp,int kk,int minus,int bingo)
{
	int st = 0;
	int rp = 0;
	int nextstm = 0;
	while(st < nextp)
	{
		int ori = st;
		while(bit[stm][st] <= minus && st < nextp)
			st ++;
		if(st > ori)
		{
			rp ++;
		}
		if(st == nextp)
		{
			break;
		}
		nextstm += (bit[stm][st]-minus)*pow[rp];
		rp ++;
		st ++;
	}
	nextstm += kk*pow[rp];
	rp ++;
	while(st < last[flag][stm]+1)
	{
		int ori = st;
		while(bit[stm][st] <= minus && st < last[flag][stm]+1)
			st ++;
		if(st > ori)
		{
			rp ++;
		}
		if(st == last[flag][stm]+1)
		{
			rp ++;
			break;
		}
		nextstm += (bit[stm][st]-minus)*pow[rp];
		rp ++;
		st ++;
	}

	kind[1-flag][nextstm] += kind[flag][stm];
	kind[1-flag][nextstm] %= MOD;
	last[1-flag][nextstm] = rp-1;
	if(bingo == 1)
	{
//		printf("kind: %d last:%d nextstm:%d\n",kind[1-flag][nextstm],last[1-flag][nextstm],nextstm);
	}
}

void dealing()
{
//	printf("nnd %d\n",last[1]);
	flag = 0;
	for(int j=0;j<STM;j++)
		kind[0][j] = kind[1][j] = 0;
	kind[0][1] = 1;
	int tmpbit[9];
	for(int i=1;i<N;i++)
	{
		ans[i][KK-1] = 0;
		for(int j=0;j<pow[9];j++)
		{
			ans[i][KK-1] += kind[flag][j];
			ans[i][KK-1] %= MOD;
		}
		for(int j=1;j<pow[9];j++)
		{
			if(kind[flag][j]!=0)
			{
				for(int k=0;k<9;k++)
				{
					tmpbit[k] = bit[j][k];	
				}
				int sign = 0;
				int most = mx[j];
				int add = 1;
				if(mx[j] < KK-1)
				{
					add = 0;
					most = mx[j]+1;
				}
				int bingo = 0;
				if(j == 1 && i == 1)
					bingo = 1;
				for(int k=0;k<=last[flag][j];k++)
				{
					if(tmpbit[k] <= 0)
					{
						sign = 1;
						continue;	
					}
					if(tmpbit[k] > 0 && sign == 0)
					{
						insert(j,k,most,add,bingo);
					}
					if(tmpbit[k] > 0)
					{
						sign = 0;	
					}
				}
				if(tmpbit[last[flag][j]] > 0)
				{
					insert(j,last[flag][j]+1,most,add,bingo);	
				}
			}
		}
		for(int j=1;j<pow[9];j++)
		{
			kind[flag][j] = kind[1-flag][j];
			last[flag][j] = last[1-flag][j];
			kind[1-flag][j] = 0;
		}
	}
}

int main()
{
	freopen("1001.in","r",stdin);
	freopen("1001.out","w",stdout);
	booling();
	dealing();
	int n,k;
	for(int i=0;i<N;i++)
	{
		printf("%d,",ans[i][KK-1]);
	}
	return 0;
}
