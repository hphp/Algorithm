#include <stdio.h>
#include <string.h>
#include <string>
#define Min(a,b) ((a)<(b)?(a):(b))
#include <vector>
using namespace std;
#define N 60
int paint[N][N];
int dmx[N][N];
int rmx[N][N];
class Painting
{
	public:
	int largestBrush(vector <string> p)
	{
		int n = p.size();
		int m = p[0].length();
		for(int i = n-1;i>=0;i--)
		{
			for(int j=m-1;j>=0;j--)
			{
				if(p[i][j] == 'W')
				{
					dmx[i][j] = rmx[i][j] = 0;
					continue;
				}
				if(j == m-1)
					rmx[i][j] = 1;
				else rmx[i][j] = rmx[i][j+1]+1;
				if(i == n-1)
					dmx[i][j] = 1;
				else dmx[i][j] = dmx[i+1][j]+1;
			}
		}
		
		int s = 1;
		int e = Min(n,m) + 1;
		
		while(s + 1 < e)
		{
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++)
					paint[i][j] = 0;
			int mid = (s+e)/2;
			int flag = 0;
			for(int i=0;i<=n-mid;i++)
			{
				for(int j=0;j<=m-mid;j++)
				{
					if(p[i][j] == 'W')continue;
					if((dmx[i][j] >= mid) && (rmx[i][j] >= mid))
					{
						int ss = 0;
						for(int ii=i;ii<i+mid;ii++)
						{
							for(int jj=j;jj<j+mid;jj++)
							{
								if(p[ii][jj] == 'W')
								{
									ss = 1;
									break;	
								}
							}
							if(ss)break;
						}
						if(!ss)
						{
							for(int ii=i;ii<i+mid;ii++)
							{
								for(int jj=j;jj<j+mid;jj++)
								{
										paint[ii][jj] = 1;
								}
							}
						}
					}
					else if(paint[i][j] != 1)
					{
						flag = 1;break;
					}
				}
				if(flag == 1)break;
			}
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
					if(p[i][j] == 'B')
					{
						if(!paint[i][j])
						{
							flag = 1;break;
						}
					}
				if(flag)break;
			}
			if(flag)
			{
				e = mid;
			}
			else s = mid;
		}
		return s;
	}
};

/*
2011-01-23
01:12-01:48 submit
failed system test --- what a pity ....

2011-01-23
 {"BBBBBW", 
 "BBBWBW", 
 "BBBBBB", 
 "BBBBBB", 
 "BBBBBB", 
 "BBBBWB"}
发现 一个问题，就是dmx 和rmx 不能把下面的所有都覆盖到，脑子真是进水了~呵呵~还感觉挺清醒的呢~
09:00 - 09 : 14 改了两次 提交两次才过~遇到问题先好好想想哈~已经改了很多了，但是仍然不够，继续努力 小丫~ 
*/
