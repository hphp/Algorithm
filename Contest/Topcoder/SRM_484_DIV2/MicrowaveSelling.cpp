

int t(int num)
{
	int tmp = num;
	int cnt = 0;
	while(tmp)
	{
		int cur = tmp%10;
		if(cur != 9)
			return cnt;
	tmp/=10;	
	cnt ++;
	}
	return cnt;
}

class MicrowaveSelling
{
	public :
		int mostAttractivePrice(int minPrice,int maxPrice)
		{
			int mxmx = -1;
			int ans = maxPrice;
			for(int i=maxPrice;i>=minPrice;i--)	
			{
				if(t(i) > mxmx)
				{
					mxmx = t(i);
					ans = i;
				}
			}
			return ans;
		}
};
