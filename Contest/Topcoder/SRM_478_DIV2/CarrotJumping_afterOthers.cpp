#define MOD 1000000007LL
#define N 300001
typedef long long Int;
class CarrotJumping
{
	public:
	int theJump(int init)
	{
		Int tmp = (2*(Int)init + 2LL)%MOD;
		int k = 1;
		for(k=2;k<N;k++)
		{
			tmp *= (2*init+2LL);tmp%=MOD;
			if((tmp % MOD  == 1))
				return (((k%3)==0)?(k/3):(1+k/3));
		}
		return -1;
	}
};
/*
int main()
{
	for(int )
}*/
