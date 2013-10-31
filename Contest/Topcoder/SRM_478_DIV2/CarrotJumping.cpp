#define MOD 1000000007LL
#define N 100001
typedef long long Int;
class CarrotJumping
{
	public:
	int theJump(int init)
	{
		Int part = 4*init+3;
		int Mn = 1;
		bool flag = 0;
		for(Mn = 1;Mn < N; Mn ++)
		{
			for(int n=0;n<=Mn;n++)
			{
				if(((Mn+n)*part + n)%MOD == 0)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
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
