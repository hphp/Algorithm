#include <stdio.h>
#define N 10100000
	int use[N];
	
class ChildlessNumbers
{
	
	private:
		int NUM(int i)
		{
			int cur = i;
			int sum =0;
			while(cur)
			{
				sum += cur%10;
				cur/=10;	
			}
			return sum;
		}
	public:
		int howMany(int A, int B)
		{
			int cnt =0;
			for(int i=A;i<=B;i++)
			{
				int flag =0;
				for(int j=1;j<=1000;j++)
				{
					int cur = i*j;
					if(NUM(cur) == j)
					{
						flag = 1;break;	
					}
				}
				cnt += flag;
			}
			return B-A+1-cnt;
		}
};
