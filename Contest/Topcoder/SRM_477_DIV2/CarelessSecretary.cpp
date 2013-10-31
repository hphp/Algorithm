#define NN 1010
#include <stdio.h>
#define KK 13
#define STM (1<<13)
#define MOD 1000000007

typedef long long Int;
Int kind[KK][STM];
int state = 0;
int bit[STM];
void init_bit()
{
	for(int i=0;i<STM;i++)
	{
		int cnt = 0;
		for(int j=0;j<=KK;j++)
			if(i&(1<<j))
				cnt++;
		bit[i] = cnt;
	}
}

Int C[NN][KK] = {0};
Int A[NN][NN] = {0};

void Cinit()
{
	A[0][0] = 1;
	C[0][0] = 1;
	for(int i=1;i<NN;i++)
	{
		C[i][0] = 1;
		A[i][0] = 1;
		for(int j=1;j<NN&&j<=i;j++)
		{
			C[i][j] = C[i-1][j] + C[i-1][j-1];
			C[i][j] %= MOD;
			A[i][j] = A[i][j-1]*(i-j+1);
			A[i][j] %= MOD;
		}
	}
}

class CarelessSecretary
{
	private:
		void init(int);
	public:
		int howMany(int N,int K)
		{
			Cinit();
//			init_bit();
			state = 1<<((K+1)>N?N:(K+1));
			init(K);
			for(int i=1;i<=K;i++)
			{
				for(int j = 1;j<state;j++)
				{
					int cc = 0;
					for(int k=1;k<=K;k++)
					{
						if((j&(1<<(k-1))) && (i!=k))
						{
							kind[i][j] += kind[i-1][j-(1<<(k-1))];
							kind[i][j] %= MOD;
							cc++;
						}
					}
					if(j&(1<<(i-1)))cc++;
					int left = ((N-K)-(i-1-cc));
					if(j&(1<<K))
					{
						kind[i][j] += (kind[i-1][j]*left%MOD);
						kind[i][j] %= MOD;
					}
				}
			}
/*			printf("please input");
			int a,b;
			while((scanf("%d %d",&a,&b)!=EOF) && (a>=0))
			{
				printf("%lld\n",kind[a][b]);
			}
			printf("ok:end");
*/
			Int ans = 0;
			for(int j=0;j<state;j++)
			{
				int less = 0;
				for(int kk=0;kk<=K;kk++)
					if(j&(1<<kk))
						less++;
				if(less > K)continue;

				Int tmp = (kind[K][j]*A[N-K][N-K])%MOD;
				//if(tmp)
				//	printf("kind[%d][%d]%lld C[%d][%d]%lld A[%d]:%lld\n",K,j,kind[K][j],N-K,less,C[N-K][less],N-K,A[N-K][N-K]);
				ans += tmp, ans%=MOD;
			}
			return (int)ans;
		}
};

void CarelessSecretary::init(int K)
{
	for(int i=0;i<=K;i++)
		for(int j=0;j<=state;j++)
			kind[i][j] = 0;
	kind[0][0] = 1;
	kind[0][1<<K] = 1;
}
/*
int main()
{
	int a,b;
//	Cinit();
	while(scanf("%d %d",&a,&b)!=EOF)


	{
//		printf("hi:%lld %lld\n",C[a][b],A[a][b]);
		CarelessSecretary cc = CarelessSecretary();
		printf("%d\n",cc.howMany(a,b));
	}
}*/
