typedef long long  Int;
int num(Int cur)
{
	int ans = 0;
	while(cur)
	{
		ans += cur%10;
		cur/=10;	
	}
	return ans;
}
class ChildlessNumbers
{
	public:
		int howMany(int a,int b)
		{
			int ans = 0;
			for(int i=a;i<=b;i++)
			{
				bool flag = 0;
				for(int j=1;j<=1000;j++)
				{
					Int c = (Int)i*(Int)j;
					if(num(c) == j)
					{
						flag = 1;
						break;
					}
				}
				if(!flag)
					ans++;
			}
			return ans;
		}
};
