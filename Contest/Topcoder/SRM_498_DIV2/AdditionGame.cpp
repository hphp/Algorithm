class AdditionGame
{
	public:
		int getMaximumPoints(int a,int b,int c,int n)
		{
			int r[3] = {0};
			r[0]= a,r[1] = b,r[2] = c;
			int ans = 0;
			for(int i=0;i<n;i++)
			{
				int mx = 0,rr=0;
				for(int j=0;j<3;j++)
					if(mx < r[j])
						mx = r[j],rr = j;
				ans += mx;
				if(r[rr]>=1)
					r[rr]--;
			}
			return ans;
		}
};
