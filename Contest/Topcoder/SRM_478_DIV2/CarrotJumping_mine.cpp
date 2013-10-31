
#define N 300001
#define MOD 1000000007LL
typedef long long Int;

class CarrotJumping
{
	public:
		int theJump(int init)
		{
			Int tmp = (init+1LL)%MOD;
			int k = 1;
			for(;k<N;k++)
			{
				tmp *= 2;
				tmp %= MOD;
				if(tmp % MOD == 1)
				{
					break;	
				}
			}
			if(k == N)
				return -1;
			else
			{
				for(int i=k;i>=0;i--)
					if(((k-i)&1) == 0)
					{
						if((k-i)/2 >= i)
							return (k-i)/2;
					}
return -1;
			}
		}
};
