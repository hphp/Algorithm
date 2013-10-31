//2010-05-10--20:18
//-20:33
//-22:00
//9:25--
#include <stdio.h>
#include <stdlib.h>
#define N 16
#define IsEven(x) (((x)%2 == 0 )? 1:0)
#define MAX 1000000.0
//#define convert(x,sign) ((sign==0)?(x):(-(x)))
//#define avl(a,b,x,y) ((gcd(a+b,b) == 1)?(((a)*(y))-((b)*(x))):-1)
//#define dsign(a) (((a)==0)?-1:((a)<0?1:0))

typedef int BigInt;

int gcdr[N][N][2];// 0 + 1 -
int wcw[N][N][2][2];// 0 + 1 -

BigInt gcd(BigInt x, BigInt y)

{

    if(x < y)

        return gcd(y, x);

    if(y == 0)

        return x;

    else

    {

        if(IsEven(x))

        {

            if(IsEven(y))

                return (gcd(x >> 1, y >> 1) << 1);

            else

                return gcd(x >> 1, y);

        }

        else

        {

            if(IsEven(y))

                return gcd(x, y >> 1);

            else

                return gcd(y, x - y);

        }

    }

}

void booling()
{
	for(int i = 1; i <= 15 ; i ++)
	{
		for(int j = -i ; j <= 0; j ++ )
		{
			gcdr[i][j][1] = gcd(i,j+i);// - j 
		}
		for(int j = 1; j <= i; j ++ )
		{
			gcdr[i][j][0] = gcd(i,j);// + j ;
		}
	}	
}

int avl(int a,int b,int x, int y )
{
	if(gcd(a+b,b) == 1)
	{
		return a*y-b*x;	
	}
}

int dsign(int a)
{
	if(a == 0)
		return -1;
	if(a < 0)
		return 1;
	return 0;
}

int convert(int x,int sign)
{
	if(sign == 1)	
		x = -x;
		return x;
}

int ssign[2] = {0,1};
char p[2][100] = {"Amr","Xay"};
// sign : 0 + 1 -   flag : 0 a 1 x
int dp(int x,int y,int sign , int flag)
{
	int rx = convert(x,sign);
//	printf("%d %d %s\n",rx,y,p[flag]);
	if(wcw[x][y][flag][sign] != -1)
		return wcw[x][y][flag][sign];
		
	int win = 0;
	int limy = y;
	int limx1 = -y;
	int limx0 = y+1;
	
	if(y == 1)
	{
		limy ++;
		limx0 --;
		limx1 ++;
	}
	if(flag == 1)
	{
		double mx = -MAX;
		int a = -1 , b = -1;
		for(int j = 1 ; j < limy ; j ++)
		{
			for(int i = -limx1 ; i <= 0 ; i ++)
			{
				if(dsign(avl(i,j,rx,y)) == ssign[flag])
				{
	//				printf("strange : %d %d %d %d %d %d\n",i,j,rx,y,avl(i,j,rx,y),dsign(avl(i,j,rx,y)),ssign[flag]);
	//				system("pause");
					if(i * 1.0 / j > mx)
					{
						mx = i*1.0/j;
						a = i;
						b = j;
					}
				}
			}
			for(int i = 1 ; i < limx0 ; i ++)
			{
				if(dsign(avl(i,j,rx,y)) == ssign[flag])
				{
					if(i * 1.0 / j > mx)
					{
						mx = i*1.0/j;
						a = i;
						b = j;
					}
				}
			}
		}
		if(mx > -MAX)
		{
			int ss = 0;
			if(a < 0)
				ss = 1;
			if(dp(a,b,ss,1-flag) == 0)
			{
				wcw[x][y][flag][sign] = 1;
			}
			else
				wcw[x][y][flag][sign] = 0;
		}
		else
		{
			wcw[x][y][flag][sign] = 0;
		}
//		printf("%d %d %d %d %d %d\n",a,b,x,y,sign,wcw[x][y][flag][sign]);
	}
	else if(flag == 0 )
	{
		for(int j = 1 ; j < limy ; j ++)
		{
			for(int i = -limx1 ; i <= 0 ; i ++)
			{
				
				if(dsign(avl(i,j,rx,y)) == ssign[flag])
				{
		//			printf("strange : %d %d %d %d %d %d %d\n",i,j,rx,y,avl(i,j,rx,y),dsign(avl(i,j,rx,y)),ssign[flag]);
					if(dp(-i,j,1,1-flag) == 0)
					{
						win = 1;
					}
				}
			}
			for(int i = 1 ; i < limx0; i ++)
			{
				if(dsign(avl(i,j,rx,y)) == ssign[flag])
				{
					if(dp(i,j,0,1-flag) == 0)
					{
						win = 1;
					}
				}
			}
		}
		wcw[x][y][flag][sign] = win;
	}
//	printf("%d %d %s %d\n",rx,y,p[flag],wcw[x][y][flag][sign]);
	return wcw[x][y][flag][sign];
}

char name[100];
int n;

int main()
{
	booling();
	int a,b;
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%s",&n,name);
		int flag = 1;
		for(int i=0;i<=15;i++)
			for(int j=0;j<=i;j++)
				for(int k =0 ; k < 2; k ++)
					for(int kk =0 ; kk < 2 ; kk ++)
						wcw[j][i][k][kk] = -1;
		
		if(name[0] == 'A')
			flag = 0;
			
		int win = 0;
		
		for(int i = 0 ; i < n ; i ++)
		{
			scanf("%d %d",&a,&b);
			rec[i].x = a;
			rec[i].y = b;
		}
		for(int i=0; i < n ; i ++)
		{
		 	int a = rec[i].x;
			int b = rec[i].y;
			if(dp())
		}
		
		if(win == 0)
			printf("%s\n",p[1-flag]);
		else printf("%s\n",p[flag]);
	}
	return 0;
}
