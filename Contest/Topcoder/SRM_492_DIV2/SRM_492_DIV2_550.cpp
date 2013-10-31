#include <vector>
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
int x[100];
class TimeTravellingGardener
{
	public:
		int determineUsage(vector <int> d, vector <int> h)
		{
			int n = d.size();
			n++;
			x[0] = 1;
			for(int i=1;i<n;i++)
				x[i] = x[i-1]+d[i-1];
			int ans = n-1;
			for(int i=1;i<n;i++)
			{
				bool flag = 0;
				int cnt = 0;
				if(h[0])
					cnt++;
				for(int j=1;j<i;j++)
				{
					if(h[j]*x[i] < x[j]*h[i])
					{
						flag = 1;
						break;
					}
					else
					{
						if((x[j]*h[i]) == (x[i]*h[j]));
						else cnt ++;
					}
				}
				if(!flag)
				for(int j=i+1;j<n;j++)
				{
					if(h[j]*x[i] < x[j]*h[i])
					{
						flag = 1;
						break;
					}
					else
					{
						if((x[j]*h[i]) == (x[i]*h[j]));
						else cnt ++;
					}
				}
				if(!flag)
				{
					ans = Min(cnt,ans);
				}
			}
			for(int i=n-2;i>=0;i--)
			{
				bool flag = 0;
				int xx = x[n-1]-x[i];
				int yy = h[i];
				int cnt = 0;
				if(h[n-1])
					cnt++;
				for(int j=n-2;j>i;j--)
				{
					int xxx = x[n-1]-x[j];
					int yyy = h[j];
					if(yyy*xx < xxx*yy)
					{
						flag = 1;
						break;
					}
					else
					{
						if(yyy*xx == xxx*yy);
						else cnt ++;
					}
				}
				if(!flag)
				for(int j=i-1;j>=0;j--)
				{
					int xxx = x[n-1]-x[j];
					int yyy = h[j];
					if(yyy*xx < xxx*yy)
					{
						flag = 1;
						break;
					}
					else
					{
						if(yyy*xx == xxx*yy);
						else cnt ++;
					}
				}
				if(!flag)
				{
					ans = Min(cnt,ans);
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(h[i] > h[j])
					{
						int xx = x[j]-x[i];
						int yy = h[i]-h[j];
						bool flag = 0;
						int cnt = 0;
						for(int k=0;k<j;k++)
						{
							int xxx = x[j]-x[k];
							int yyy = h[k]-h[j];
							if(yyy*xx < xxx*yy)
							{
								flag = 1;
								break;
							}
							else
							{
								if(yyy*xx == xxx*yy);
								else cnt++;
							}
						}
						if(!flag)
						for(int k=j+1;k<n;k++)
						{
							int xxx = x[k]-x[j];
							int yyy = h[j]-h[k];
							if(yyy*xx < xxx*yy)
							{
								flag = 1;
								break;
							}
							else
							{
								if(h[j]*xx <= xxx*yy)
								{
									flag = 1;break;
								}
								if(yyy*xx == xxx*yy);
								else cnt++;
							}
						}
						if(!flag)
							ans = Min(ans,cnt);
					}
					else
					{
						int xx = x[j]-x[i];
						int yy = h[j]-h[i];
						bool flag = 0;
						int cnt = 0;
						for(int k=0;k<j;k++)
						{
							int xxx = x[j]-x[k];
							int yyy = h[j]-h[k];
							if(yyy*xx < xxx*yy)
							{
								flag = 1;
								break;
							}
							else
							{
								if(h[j]*xx <= xxx*yy)
								{
									flag = 1;break;
								}
								if(yyy*xx == xxx*yy);
								else cnt++;
							}
						}
						if(!flag)
						for(int k=j+1;k<n;k++)
						{
							int xxx = x[k]-x[j];
							int yyy = h[k]-h[j];
							if(yyy*xx < xxx*yy)
							{
								flag = 1;
								break;
							}
							else
							{
								if(yyy*xx == xxx*yy);
								else cnt++;
							}
						}
						if(!flag)
							ans = Min(ans,cnt);
					}
				}
			}
			return ans;
		}	
};

/*
2011-02-01
10:14 - 10:26
11:08 finish coding.
*/
