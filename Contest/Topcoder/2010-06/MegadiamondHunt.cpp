#include <iostream>
#define MAX (1<<28)
#include <string>
#define N 60
using namespace std;
#define Max(a,b) ((a)>(b)?(a):(b))
#define mth(i,j) ((mine[i] == '<' && mine[j]=='>')?1:0)
int mx[N][N][N/2];
int mxx[N][N];
class MegadiamondHunt
{
	public:
		
	int getValue(string mine)
	{
		int len = mine.length();
		int ll = len/2+1;
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
				for(int k=0;k<ll;k++)
				mx[i][j][k] = -MAX;
		for(int i=0;i<len-1;i++)
		{
			if(mth(i,i+1))
			{
				mx[i][i+1][1] = 0;
				mx[i][i+1][0] = 1;
			}
		}
		int mxmx = 0;
		for(int k = 3;k< len;k+=2)
		{
			for(int i=0;i+k<len;i++)
			{
				int j = i+k;
				if(mth(i,j))
				{
					for(int nn=0;nn<k&&nn<ll;nn++)
					{
						if(mx[i+1][j-1][nn] >=0 )
							mx[i][j][nn+1] = Max(mx[i][j][nn+1],mx[i+1][j-1][nn]);
						for(int jj=i+2;jj<j-1;jj+=2)
						{
							if(mx[i+1][jj][nn] >=0 && mx[jj+1][j][0] >=0)
								mx[i][j][nn+1] = Max(mx[i][j][nn],mx[i+1][jj][nn] + mx[jj+1][j][0]);
							if(mx[i+1][jj][nn] >=0 && mx[jj+1][j][0] >=0)
								mx[i][j][nn+1] = Max(mx[i][j][nn],mx[jj+1][j][nn] + mx[i][jj][0]);
						}
					}
/*					for(int nn=0;nn<k&&nn<ll;nn++)
					{
						if(mx[i+1][j-1][nn] >=0 )
							mx[i][j][0] = Max(mx[i][j][nn],mx[i+1][j-1][nn] + (nn+1)*(nn+1));
						for(int jj=i+2;jj<j-1;jj+=2)
						{
							if(mx[i+1][jj][nn] >=0 )
							mx[i][j][0] = Max(mx[i][j][nn],mx[i+1][jj][nn]+ (nn+1)*(nn+1));
						}
						if(mx[i][j][nn+1] > mxmx)
						{
							mxmx = mx[i][j][nn+1];	
						}
					}*/
					for(int nn=0;nn<k&&nn<ll;nn++)
						for(int kk=i+1;kk<j-1;kk++)
						{
							int tmp = mx[i][kk][nn] + mx[kk+1][j][0];
							if(mx[i][kk][nn] >= 0 && mx[kk+1][j][0] >= 0)
								if(tmp > mx[i][j][nn])	
								{
									mx[i][j][nn] = tmp;	
								}
							tmp = mx[i][kk][0] + mx[kk+1][j][nn];
							if(mx[i][kk][0] >= 0 && mx[kk+1][j][nn] >=0)
							if(tmp > mx[i][j][nn])	
							{
								mx[i][j][nn] = tmp;	
							}
						}
					for(int nn=0;nn<k&&nn<ll;nn++)
						if(mx[i][j][nn] + nn*nn > mx[i][j][0])
						{
							mx[i][j][0] = 	mx[i][j][nn] + nn*nn ;
						}
				}
			}
		}
		for(int i=0;i<len;i++)
			for(int j=i+1;j<len;j++)
				for(int nn=0;nn<ll;nn++)
				{
					if(mx[i][j][nn] > mxmx)
					{
						mxmx = mx[i][j][nn];
					}
				}
		for(int i=0;i<len;i++)
			for(int j=0;j<len;j++)
			{
				mxx[i][j] = -MAX;
				for(int nn=0;nn<ll;nn++)
					mxx[i][j] = Max(mxx[i][j],mx[i][j][nn]);
			}
		for(int k=1;k<len;k+=1)
		{
			for(int i=0;i+k<len;i++)
			{
				int j = i + k;
				for(int k1=i+1;k1<j-1;k1++)	
				{
					for(int k2=k1+1;k2<j;k2++)
					{
						if(mxx[i][k1] >= 0 && mxx[k2][j] > 0)	
						{
							int tmp = mxx[i][k1] + mxx[k2][j];
							if(tmp > mxx[i][j])
								mxx[i][j] = tmp;
						}
					}
				}
			}
		}
		for(int i=0;i<len;i++)
			for(int j=i+1;j<len;j++)
				{
					if(mxx[i][j] > mxmx)
					{
						mxmx = mxx[i][j];
					}
				}
	/*	int a,b,c;
		while(scanf("%d %d %d",&a,&b,&c)!=EOF&&(a||b||c))
		{
			printf("%d\n",mx[a][b][c]);	
			
			printf("%d\n",mxx[a][b]);
			
		}*/
		return mxmx;
	}
};

/*int main()
{
	string s;
	while(cin >> s)	
	{
		MegadiamondHunt m = MegadiamondHunt();
		cout << m.getValue(s) << endl;
	}
	return 0;
}*/
/*
         1         2         3         4 
<<<<<<><><><<<<>>><><><<>><<<><<>><<<>>><<<<<>>>>>
01234567890123456789012345678901234567890123456789
*/
