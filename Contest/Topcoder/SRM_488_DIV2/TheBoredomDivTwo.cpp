class TheBoredomeDivTwo
{
	public:
		int find(int n,int m,int j,int b)
		{
			int cnt = n;
			if(j>=1&&j<=n);
			else cnt++;
			if(b!=j)
			{
				if(b>n&&b<=n+m)cnt++;
			}
			return cnt;
		}
};
