#include <stdio.h>
#define N 51
#define K 5
#define STM 1953135
#define MOD 1000000007

int kind[2][STM];
int ans[N][K];
int pow[10];
int bit[STM][9],last[STM],mx[STM];

int KK = 2;
int flag = 0;

void booling()
{
	pow[0] = 1;
	for(int i=1;i<=9;i++)
	{
		pow[i] = pow[i-1]*KK;
	}
	for(int i=0;i<STM;i++)
	{
		int st = 0;
		int tmp = i;
		while(tmp)
		{
			bit[i][st] = tmp%KK;
			if(mx[i] < bit[i][st])
			{
				mx[i] = bit[i][st];
			}
			if(bit[i][st])
			{
				last[i] = st;
			}
			tmp /= KK;
			st ++;
		}
	}
}

void insert(int stm ,int nextp,int kk,int minus)
{
	int st = 0;
	int rp = 0;
	int nextstm = 0;
	while(st < nextp)
	{
		int ori = st;
		while(bit[stm][st] <= minus)
			st ++;
		if(st > ori)
		{
			rp ++;
		}
		nextstm += (bit[stm][st]-minus)*pow[rp];
		rp ++;
		st ++;
	}
	nextstm += kk*pow[rp];
	rp ++;
	while(st < last[stm]+1)
	{
		int ori = st;
		while(bit[stm][st] <= minus && st < last[stm]+1)
			st ++;
		if(st == last[stm]+1)
		{
//			printf("possible\n");
			break;
		}
		if(st > ori)
		{
			rp ++;
		}
		nextstm += (bit[stm][st]-minus)*pow[rp];
		rp ++;
		st ++;
	}
	kind[1-flag][nextstm] += kind[flag][stm];
//	if(kind[1-flag][nextstm] > 0)
	{
//		printf("%d\n",kind[1-flag][nextstm]);
	}
	kind[1-flag][nextstm] %= MOD;
}

void dealing()
{
	flag = 0;
	for(int j=0;j<STM;j++)
		kind[0][j] = kind[1][j] = 0;
	kind[0][1] = 1;
	int tmpbit[9];
	for(int i=1;i<N;i++)
	{
		ans[i][KK-1] = 0;
		for(int j=0;j<STM;j++)
		{
			ans[i][KK-1] += kind[flag][j];
			ans[i][KK-1] %= MOD;
		}
		for(int j=1;j<STM;j++)
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
				for(int k=0;k<=last[j];k++)
				{
					if(tmpbit[k] <= add)
					{
						sign = 1;
						continue;	
					}
					if(tmpbit[k] > add && sign == 0)
					{
						insert(j,k,most,add);
					}
					if(tmpbit[k] > add)
					{
						sign = 0;	
					}
				}
				if(tmpbit[last[j]] > add)
				{
					insert(j,last[j]+1,most,add);	
				}
			}
		}
		for(int j=1;j<STM;j++)
		{
			kind[flag][j] = kind[1-flag][j];
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
