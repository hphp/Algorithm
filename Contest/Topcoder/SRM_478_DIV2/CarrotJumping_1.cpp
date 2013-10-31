#define MOD 1000000007LL
#define Min(a,b) ((a)<(b)?(a):(b))
#define N 100001
#define MAXN 200001
typedef long long Int;
class CarrotJumping
{
	public:
	int theJump(int init)
	{
		Int part = 4*init+3;
		int Mn = N;
		for(int i=1;i<MAXN;i++)
		{
			Int cur = MOD*i;
			int n = cur % part;
			int m = cur/part;
			if(m >= n)
				Mn = Min(m,Mn);
		}
		if(Mn < N)
			return Mn;
		else return -1;
	}
};
/*
int main()
{
	for(int )
}*/
